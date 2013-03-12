/* Copyright (c) 2011-2012, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _ARCH_ARM_MACH_MSM_MDM2_H
#define _ARCH_ARM_MACH_MSM_MDM2_H

struct mdm_vddmin_resource {
	int rpm_id;
	int ap2mdm_vddmin_gpio;
	unsigned int modes;
	unsigned int drive_strength;
	int mdm2ap_vddmin_gpio;
};

struct mdm_platform_data {
	char *mdm_version;
	int ramdump_delay_ms;
	int soft_reset_inverted;
	int early_power_on;
	int sfr_query;
	int no_powerdown_after_ramdumps;
	struct mdm_vddmin_resource *vddmin_resource;
	struct platform_device *peripheral_platform_device;
	const unsigned int ramdump_timeout_ms;
	#ifdef CONFIG_VENDOR_EDIT
	/* DuYuanHua@OnLineRD.AirService.MDM, 2012/09/26, Add for shutthing down MDM slow */
	int send_shdn;
	#endif /* VENDOR_EDIT */
};

#endif

