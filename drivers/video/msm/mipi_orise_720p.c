//720p lcd driver

/* Copyright (c) 2012, Code Aurora Forum. All rights reserved.
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

#include "msm_fb.h"
#include "mipi_dsi.h"
#include "mipi_orise.h"
#include "mdp4.h"

#include <mach/gpio.h>				//for 8064gpio
#include <linux/mfd/pm8xxx/pm8921.h>	//for 8921

#define PM8921_GPIO_BASE		NR_GPIO_IRQS
#define PM8921_GPIO_PM_TO_SYS(pm_gpio)	(pm_gpio - 1 + PM8921_GPIO_BASE)

#define MIPI_STOD13_EN		0

#define MIPI_CMD_INIT

static struct mipi_dsi_panel_platform_data *mipi_orise_pdata;

static struct dsi_buf orise_tx_buf;
static struct dsi_buf orise_rx_buf;

static char exit_sleep[2] = {0x11, 0x00}; /* DTYPE_DCS_WRITE */
static char display_on[2] = {0x29, 0x00}; /* DTYPE_DCS_WRITE */

#ifdef MIPI_CMD_INIT
static char level2_command_set[3] = {
	0xf0, 	//level2 command enable
	0x5a, 0x5a, 
};

static char mtp_key_set[3] = {
	0xf1, 	//MTP key enable
	0x5a, 0x5a,
};

static char panel_condition_set_1[39] = {
	0xf8, 	//foward
	0x19, 0x31, 0x00, 0x00, 0x00, 0x8b, 0x00, 0x39, 0x75, 0x0f, 0x25, 0x07, 0x67, 0x00, 0x00,
	0x00, 0x00, 0x04, 0x07, 0x67, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x20, 0x67, 0xc0, 0xc1,
	0x01, 0x81, 0xc1, 0x00, 0xc3, 0xf6, 0xf6, 0xc1,
};

static char panel_condition_set_2[4] = {
	0xf2,
	0x80, 0x03, 0x0d,
};

static char gamma_condition_set[26] = {
	0xfa,
	0x01, 0x71, 0x31, 0x7b, 0xa4, 0xb6, 0x95, 0xa9, 0xbc, 0xa2, 0xbb, 0xc9, 0xb6, 0x91, 0xa3,
	0x8b, 0xad, 0xb6, 0xa9, 0x00, 0xd6, 0x00, 0xbe, 0x00, 0xfc,
};

static char gamma_set_update[2] = {
	0xf7, 
	0x03,
};

static char etc_source_control[4] = {
	0xf6,	//source control
	0x00, 0x02, 0x00,
};

static char etc_pentile_control_1[10] = {
	0xb6,	//pentile control 1
	0x0c, 0x02, 0x03, 0x32, 0xff, 0x44, 0x44, 0xc0, 0x00,
};

static char etc_pentile_control_2[15] = {
	0xd9,	//pentile control 2
	0x14, 0x40, 0x0c, 0xcb, 0xce, 0x6e, 0xc4, 0x07, 0x40, 0x41, 0xd0, 0x00, 0x60, 0x19,
};

static char etc_mipi_control_1[6] = {
	0xe1,	//MIPI control 1
	0x10, 0x1c, 0x17, 0x08, 0x1d,
};

static char etc_mipi_control_2[7] = {
	0xe2,	//MIPI control 2
	0xed, 0x07, 0xc3, 0x13, 0x0d, 0x03,
};

static char etc_mipi_control_3[2] = {
	0xe3,	//MIPI control 3
	0x40,
};

static char etc_mipi_control_4[8] = {
	0xe4,	//MIPI control 4
	0x00, 0x00, 0x14, 0x80, 0x00, 0x00, 0x00,
};

static char etc_power_control[8] = {
	0xf4,	//power control
	0xcf, 0x0a, 0x15, 0x10, 0x19, 0x33, 0x02,
};

static char etc_luminance_control[3] = {
	0xb1,	//luminance 300cd~210cd
//	0x04, 0x81,	//5.4	1
	0x04, 0x8b,	//4.4	11
//	0x04, 0x95,	//3.4	21
};

//////////////////////////////////////////////
static struct dsi_cmd_desc cmd_level2_command_set[] = {
		{DTYPE_DCS_LWRITE, 1, 0, 0, 10,
			sizeof(level2_command_set), level2_command_set},
};

static struct dsi_cmd_desc cmd_mtp_key_set[] = {
		{DTYPE_DCS_LWRITE, 1, 0, 0, 10,
			sizeof(mtp_key_set), mtp_key_set},
};

static struct dsi_cmd_desc cmd_panel_condition_set[] = {
		{DTYPE_DCS_LWRITE, 1, 0, 0, 10,
			sizeof(panel_condition_set_1), panel_condition_set_1},
		{DTYPE_DCS_LWRITE, 1, 0, 0, 10,
			sizeof(panel_condition_set_2), panel_condition_set_2},
};

static struct dsi_cmd_desc cmd_gamma_condition_set[] = {
		{DTYPE_DCS_LWRITE, 1, 0, 0, 10,
			sizeof(gamma_condition_set), gamma_condition_set},
};

static struct dsi_cmd_desc cmd_gamma_set_update[] = {
		{DTYPE_DCS_WRITE1, 1, 0, 0, 10,
			sizeof(gamma_set_update), gamma_set_update},
};

static struct dsi_cmd_desc cmd_etc_source_control[] = {
		{DTYPE_DCS_LWRITE, 1, 0, 0, 10,
			sizeof(etc_source_control), etc_source_control},
};

static struct dsi_cmd_desc cmd_etc_control[] = {
		{DTYPE_DCS_LWRITE, 1, 0, 0, 10,
			sizeof(etc_pentile_control_1), etc_pentile_control_1},
		{DTYPE_DCS_LWRITE, 1, 0, 0, 10,
			sizeof(etc_pentile_control_2), etc_pentile_control_2},
		{DTYPE_DCS_LWRITE, 1, 0, 0, 10,
			sizeof(etc_mipi_control_1), etc_mipi_control_1},
		{DTYPE_DCS_LWRITE, 1, 0, 0, 10,
			sizeof(etc_mipi_control_2), etc_mipi_control_2},
		{DTYPE_DCS_WRITE1, 1, 0, 0, 10,
			sizeof(etc_mipi_control_3), etc_mipi_control_3},
		{DTYPE_DCS_LWRITE, 1, 0, 0, 10,
			sizeof(etc_mipi_control_4), etc_mipi_control_4},
};

static struct dsi_cmd_desc cmd_etc_power_control[] = {
		{DTYPE_DCS_LWRITE, 1, 0, 0, 10,
			sizeof(etc_power_control), etc_power_control},
};

static struct dsi_cmd_desc cmd_etc_luminance_control[] = {
		{DTYPE_DCS_LWRITE, 1, 0, 0, 10,
			sizeof(etc_luminance_control), etc_luminance_control},
};

static struct dsi_cmd_desc cmd_exit_sleep[] = {
	{DTYPE_DCS_WRITE, 1, 0, 0, 10,
		sizeof(exit_sleep), exit_sleep},
};


static struct dsi_cmd_desc cmd_display_on[] = {
	{DTYPE_DCS_WRITE, 1, 0, 0, 10,
		sizeof(display_on), display_on},
};
#endif

static void mipi_init_cmd(struct msm_fb_data_type *mfd);

static int mipi_orise_lcd_on(struct platform_device *pdev)
{
	struct msm_fb_data_type *mfd;
	struct mipi_panel_info *mipi;
	struct msm_panel_info *pinfo;

	mfd = platform_get_drvdata(pdev);

	if (!mfd)
		return -ENODEV;
	if (mfd->key != MFD_KEY)
		return -EINVAL;

	pinfo = &mfd->panel_info;
	mipi  = &mfd->panel_info.mipi;

	mipi_init_cmd(mfd);

	printk("720p mipi_orise_lcd_on complete\n");
	return 0;
}

static int mipi_orise_lcd_off(struct platform_device *pdev)
{
	struct msm_fb_data_type *mfd;
	mfd = platform_get_drvdata(pdev);	
	if (!mfd)
		return -ENODEV;
	if (mfd->key != MFD_KEY)
		return -EINVAL;
	
	printk("720p mipi_orise_lcd_off complete\n");

	return 0;
}

static void mipi_orise_set_backlight(struct msm_fb_data_type *mfd)
{
}

static void mipi_init_cmd(struct msm_fb_data_type *mfd)
{
#ifdef MIPI_CMD_INIT
	mipi_dsi_cmds_tx(&orise_tx_buf, cmd_level2_command_set,
		ARRAY_SIZE(cmd_level2_command_set));
	mipi_dsi_cmds_tx(&orise_tx_buf, cmd_mtp_key_set,
		ARRAY_SIZE(cmd_mtp_key_set));
	mipi_dsi_cmds_tx(&orise_tx_buf, cmd_exit_sleep,
		ARRAY_SIZE(cmd_exit_sleep));
	mdelay(10);
	mipi_dsi_cmds_tx(&orise_tx_buf, cmd_panel_condition_set,
		ARRAY_SIZE(cmd_panel_condition_set));
	mipi_dsi_cmds_tx(&orise_tx_buf, cmd_gamma_condition_set,
		ARRAY_SIZE(cmd_gamma_condition_set));
	mipi_dsi_cmds_tx(&orise_tx_buf, cmd_gamma_set_update,
		ARRAY_SIZE(cmd_gamma_set_update));
	//ETC Condition Set
	mipi_dsi_cmds_tx(&orise_tx_buf, cmd_etc_source_control,
		ARRAY_SIZE(cmd_etc_source_control));
	mipi_dsi_cmds_tx(&orise_tx_buf, cmd_etc_control,
		ARRAY_SIZE(cmd_etc_control));
	mipi_dsi_cmds_tx(&orise_tx_buf, cmd_etc_power_control,
		ARRAY_SIZE(cmd_etc_power_control));
	mdelay(120);
	//Smart Dynamic ELVSS Set
	mipi_dsi_cmds_tx(&orise_tx_buf, cmd_etc_luminance_control,
		ARRAY_SIZE(cmd_etc_luminance_control));
	mipi_dsi_cmds_tx(&orise_tx_buf, cmd_display_on,
		ARRAY_SIZE(cmd_display_on));
#endif
}

extern int get_pcb_version(void);
static int __devinit mipi_orise_lcd_probe(struct platform_device *pdev)
{
	struct msm_fb_data_type *mfd;
	struct mipi_panel_info *mipi;
	struct platform_device *current_pdev;
	static struct mipi_dsi_phy_ctrl *phy_settings;
	int rc = 0;
	

	if (pdev->id == 0) {
		mipi_orise_pdata = pdev->dev.platform_data;

		if (mipi_orise_pdata
			&& mipi_orise_pdata->phy_ctrl_settings) {
			phy_settings = (mipi_orise_pdata->phy_ctrl_settings);
		}
		return 0;
	}

	current_pdev = msm_fb_add_device(pdev);

	if (current_pdev) {
		mfd = platform_get_drvdata(current_pdev);
		if (!mfd)
			return -ENODEV;
		if (mfd->key != MFD_KEY)
			return -EINVAL;

		mipi  = &mfd->panel_info.mipi;

		if (phy_settings != NULL)
			mipi->dsi_phy_db = phy_settings;
	}

	rc = gpio_request(MIPI_STOD13_EN, "MIPI_STOD13_EN#");
	if (rc < 0) {
		pr_err("MIPI GPIO STOD13_EN request failed: %d\n", rc);
		return -ENODEV;
	}
	rc = gpio_direction_output(MIPI_STOD13_EN, 0);
	if (rc < 0) {
		pr_err("MIPI GPIO STOD13_EN set failed: %d\n", rc);
		return -ENODEV;
	}

	return 0;
}

static struct platform_driver this_driver = {
	.probe = mipi_orise_lcd_probe,
	.driver = {
		.name = "mipi_orise",
	},
};

static struct msm_fb_panel_data orise_panel_data = {
	.on = mipi_orise_lcd_on,
	.off = mipi_orise_lcd_off,
	.set_backlight = mipi_orise_set_backlight,
};

static int ch_used[3];

int mipi_orise_device_register_720p(struct msm_panel_info *pinfo,
					u32 channel, u32 panel)
{
	struct platform_device *pdev = NULL;
	int ret;

	if ((channel >= 3) || ch_used[channel])
		return -ENODEV;

	ch_used[channel] = TRUE;

	pdev = platform_device_alloc("mipi_orise", (panel << 8)|channel);
	if (!pdev)
		return -ENOMEM;

	orise_panel_data.panel_info = *pinfo;

	ret = platform_device_add_data(pdev, &orise_panel_data,
		sizeof(orise_panel_data));
	if (ret) {
		printk(KERN_ERR
		  "%s: platform_device_add_data failed!\n", __func__);
		goto err_device_put;
	}

	ret = platform_device_add(pdev);
	if (ret) {
		printk(KERN_ERR
		  "%s: platform_device_register failed!\n", __func__);
		goto err_device_put;
	}

	return 0;

err_device_put:
	platform_device_put(pdev);
	return ret;
}

static int __init mipi_orise_lcd_init(void)
{
	mipi_dsi_buf_alloc(&orise_tx_buf, DSI_BUF_SIZE);
	mipi_dsi_buf_alloc(&orise_rx_buf, DSI_BUF_SIZE);

	printk("huyu----%s: --\n", __func__);
	if(get_pcb_version() < 20 )
	{
		printk("huyu----%s: lcd is 720p!--\n", __func__);
		return platform_driver_register(&this_driver);

	}

	return 0;

}

module_init(mipi_orise_lcd_init);


