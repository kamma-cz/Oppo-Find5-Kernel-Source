/* Copyright (c) 2010-2012, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/interrupt.h>
#include <mach/irqs.h>
#include <linux/io.h>
#include <linux/clk.h>
#include <linux/ioport.h>
#include <linux/platform_device.h>
#include <linux/gpio.h>
#include <linux/err.h>
#include <linux/fs.h>
#include <linux/debugfs.h>

#define MSM_HOTSWAP_IRQ     72

extern void set_need_pin_process_flag(int flag) ;

static struct resource msm_hotswap_resources[] = {
	{
		.start	= MSM_GPIO_TO_INT(MSM_HOTSWAP_IRQ),
		.end	= MSM_GPIO_TO_INT(MSM_HOTSWAP_IRQ),
		.flags	= IORESOURCE_IRQ,
	},
};

static struct platform_device msm_hotswap_device = {
	.name = "msm_hotswap",
	.id = -1,
	.num_resources = ARRAY_SIZE(msm_hotswap_resources),
	.resource = msm_hotswap_resources,
};

static int hotswap_irqvalue = -1 ;
static irqreturn_t hotswap_parse_irq(int irq_num, void *data)
{
	int irqvalue = 0 ;
	irqvalue = gpio_get_value(MSM_HOTSWAP_IRQ) ;

	//set_need_pin_process_flag(0) ;

	pr_info("hotswap irq :[%d,%d].\n", irqvalue,hotswap_irqvalue);

	hotswap_irqvalue = irqvalue ;
	
	return IRQ_HANDLED;
}

static int msm_hotswap_probe(struct platform_device *pdev)
{
	int rc = 0;
	struct resource   *hotswapirq;

	hotswapirq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
	if (!hotswapirq) {
		pr_err("%s: no hotswap irq resource.\n", __func__);
		rc = -ENODEV;
		goto hotswap_free_device;
	}


	rc = request_irq(hotswapirq->start,hotswap_parse_irq,IRQF_TRIGGER_RISING|IRQF_TRIGGER_FALLING, "msm_hotswap", 0);

	return rc;

hotswap_free_device:
	return rc;
}


static struct platform_driver msm_hotswap_driver = {
	.probe = msm_hotswap_probe,
	.driver = {
		.name = "msm_hotswap",
		.owner = THIS_MODULE,
	},
};

static int __init msm_hotswap_init(void)
{

	platform_device_register(&msm_hotswap_device);

	return platform_driver_register(&msm_hotswap_driver);
}
module_init(msm_hotswap_init);

static void __exit msm_hotswap_exit(void)
{
	platform_driver_unregister(&msm_hotswap_driver);
}
module_exit(msm_hotswap_exit);

MODULE_DESCRIPTION("msm hotswap 1.0 driver");
MODULE_VERSION("msm hotswap driver 1.0");
MODULE_LICENSE("GPL v2");
