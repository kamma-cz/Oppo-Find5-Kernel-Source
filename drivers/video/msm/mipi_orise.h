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


#ifndef MIPI_ORISE_H
#define MIPI_ORISE_H
/* OPPO 2012-11-27 huyu Add for lcd restart */  
#ifndef CONFIG_VENDOR_EDIT
int mipi_orise_device_register(struct msm_panel_info *pinfo,
					u32 channel, u32 panel);
#else
int mipi_orise_device_register_1080p(struct msm_panel_info *pinfo,
					u32 channel, u32 panel);
int mipi_orise_device_register_720p(struct msm_panel_info *pinfo,
					u32 channel, u32 panel);
#endif
/* OPPO 2012-11-27 huyu Add for lcd restart */  
#endif  /* MIPI_ORISE_H */
