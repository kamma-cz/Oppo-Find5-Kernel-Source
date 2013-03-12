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
 *
 */

#include "msm_sensor.h"
#define SENSOR_NAME "s5k8aay"
#define PLATFORM_DRIVER_NAME "msm_camera_s5k8aay"
#define s5k8aay_obj s5k8aay_##obj


DEFINE_MUTEX(s5k8aay_mut);
static struct msm_sensor_ctrl_t s5k8aay_s_ctrl;

static struct msm_camera_i2c_reg_conf s5k8aay_720p_settings[] = {
//$MIPI[Width:1280,Height:960,Format:YUV422,Lane:1,ErrorCheck:0,PolarityData:0,PolarityClock:0,Buffer:2]

//============================================================
//	 00.History
//============================================================
//	 2011 : EVT1
//	 20111109 : LSI CSE Standard
//	 20111110 : Shading, AWB, Contrast Tuning
//	 20111114 : AE Weight Tuning
//	 20111229 : BPC Tuning, Shading Tuning
//	 20120128 : CCM Tuning, AE Weight Tuning, AE Target Tuning
//	 20120319 : Skintone Test, CCM Tuning
//	 20120320 : ColorShading Tuning, Modify TnP Setting
//	 20120323 : CCM Tuning, AWB Grid offset Tuning
//	 20120330 : Modigy AWB indoor boundary & AWB Grid offset
//	 20120402 : SKT VT-Call Tuning
//	 20120404 : NearGray Tuning
//	 20120406 : Shading Alpha Tuning
//	 20120407 : Outdoor Skintone Tuning
//============================================================


//*************************************/
// 01.Start Setting					  */
//*************************************/
        {0xFCFC, 0xD000,},
        {0x0010, 0x0001,},// S/W Reset */
        {0xFCFC, 0x0000,},
        {0x0000, 0x0000,},// Simmian bug workaround */

        {0xFCFC, 0xD000,},
        {0x1030, 0x0000,},// contint_host_int */
        {0x0014, 0x0001,},

//*************************************/
// 02.Analog Setting & ASP Control    */
//*************************************/

//*************************************/
// 03.Trap and Patch                  */
//*************************************/
// Start of Patch data */
        {0x0028, 0x7000,},
        {0x002A, 0x2470,},
        {0x0F12, 0xB510,},
        {0x0F12, 0x490E,},
        {0x0F12, 0x480E,},
        {0x0F12, 0xF000,},
        {0x0F12, 0xF9ED,},
        {0x0F12, 0x490E,},
        {0x0F12, 0x480E,},
        {0x0F12, 0xF000,},
        {0x0F12, 0xF9E9,},
        {0x0F12, 0x490E,},
        {0x0F12, 0x480E,},
        {0x0F12, 0x6341,},
        {0x0F12, 0x490E,},
        {0x0F12, 0x480F,},
        {0x0F12, 0xF000,},
        {0x0F12, 0xF9E2,},
        {0x0F12, 0x490E,},
        {0x0F12, 0x480F,},
        {0x0F12, 0xF000,},
        {0x0F12, 0xF9DE,},
        {0x0F12, 0x490E,},
        {0x0F12, 0x480F,},
        {0x0F12, 0xF000,},
        {0x0F12, 0xF9DA,},
        {0x0F12, 0x480E,},
        {0x0F12, 0x490F,},
        {0x0F12, 0x6448,},
        {0x0F12, 0xBC10,},
        {0x0F12, 0xBC08,},
        {0x0F12, 0x4718,},
        {0x0F12, 0x27CC,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x8EDD,},
        {0x0F12, 0x0000,},
        {0x0F12, 0x2744,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x8725,},
        {0x0F12, 0x0000,},
        {0x0F12, 0x26E4,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x0080,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x2638,},
        {0x0F12, 0x7000,},
        {0x0F12, 0xA6EF,},
        {0x0F12, 0x0000,},
        {0x0F12, 0x2604,},
        {0x0F12, 0x7000,},
        {0x0F12, 0xA0F1,},
        {0x0F12, 0x0000,},
        {0x0F12, 0x25D0,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x058F,},
        {0x0F12, 0x0000,},
        {0x0F12, 0x24E4,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x0000,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x403E,},
        {0x0F12, 0xE92D,},
        {0x0F12, 0x00DD,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x2000,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x1002,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x0F86,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x00DC,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x200A,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x1000,},
        {0x0F12, 0xE28D,},
        {0x0F12, 0x0E3F,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x00DB,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x2001,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x1002,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x0F86,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x00D4,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE5DD,},
        {0x0F12, 0x00C3,},
        {0x0F12, 0xE350,},
        {0x0F12, 0x0027,},
        {0x0F12, 0x1A00,},
        {0x0F12, 0x0001,},
        {0x0F12, 0xE5DD,},
        {0x0F12, 0x003C,},
        {0x0F12, 0xE350,},
        {0x0F12, 0x0024,},
        {0x0F12, 0x1A00,},
        {0x0F12, 0x02E0,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x1000,},
        {0x0F12, 0xE5D0,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE351,},
        {0x0F12, 0x0003,},
        {0x0F12, 0x1A00,},
        {0x0F12, 0x12D4,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x10B8,},
        {0x0F12, 0xE1D1,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE351,},
        {0x0F12, 0x001C,},
        {0x0F12, 0x0A00,},
        {0x0F12, 0x1000,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x1000,},
        {0x0F12, 0xE5C0,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x1002,},
        {0x0F12, 0xE28D,},
        {0x0F12, 0x0015,},
        {0x0F12, 0xEA00,},
        {0x0F12, 0x2000,},
        {0x0F12, 0xE5D1,},
        {0x0F12, 0x3001,},
        {0x0F12, 0xE5D1,},
        {0x0F12, 0x3403,},
        {0x0F12, 0xE182,},
        {0x0F12, 0xC2A8,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x2080,},
        {0x0F12, 0xE08C,},
        {0x0F12, 0xE7B4,},
        {0x0F12, 0xE1D2,},
        {0x0F12, 0x039E,},
        {0x0F12, 0xE004,},
        {0x0F12, 0xE80F,},
        {0x0F12, 0xE3E0,},
        {0x0F12, 0x4624,},
        {0x0F12, 0xE00E,},
        {0x0F12, 0x47B4,},
        {0x0F12, 0xE1C2,},
        {0x0F12, 0x4004,},
        {0x0F12, 0xE280,},
        {0x0F12, 0xC084,},
        {0x0F12, 0xE08C,},
        {0x0F12, 0x47B4,},
        {0x0F12, 0xE1DC,},
        {0x0F12, 0x0493,},
        {0x0F12, 0xE004,},
        {0x0F12, 0x4624,},
        {0x0F12, 0xE00E,},
        {0x0F12, 0x47B4,},
        {0x0F12, 0xE1CC,},
        {0x0F12, 0xC8B4,},
        {0x0F12, 0xE1D2,},
        {0x0F12, 0x039C,},
        {0x0F12, 0xE003,},
        {0x0F12, 0x3623,},
        {0x0F12, 0xE00E,},
        {0x0F12, 0x38B4,},
        {0x0F12, 0xE1C2,},
        {0x0F12, 0x0001,},
        {0x0F12, 0xE280,},
        {0x0F12, 0x1002,},
        {0x0F12, 0xE281,},
        {0x0F12, 0x0004,},
        {0x0F12, 0xE350,},
        {0x0F12, 0xFFE7,},
        {0x0F12, 0xBAFF,},
        {0x0F12, 0x403E,},
        {0x0F12, 0xE8BD,},
        {0x0F12, 0xFF1E,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x4010,},
        {0x0F12, 0xE92D,},
        {0x0F12, 0x00AB,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x0248,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x00B2,},
        {0x0F12, 0xE1D0,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE350,},
        {0x0F12, 0x0004,},
        {0x0F12, 0x0A00,},
        {0x0F12, 0x0080,},
        {0x0F12, 0xE310,},
        {0x0F12, 0x0002,},
        {0x0F12, 0x1A00,},
        {0x0F12, 0x1234,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x0001,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x0DB2,},
        {0x0F12, 0xE1C1,},
        {0x0F12, 0x4010,},
        {0x0F12, 0xE8BD,},
        {0x0F12, 0xFF1E,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x4010,},
        {0x0F12, 0xE92D,},
        {0x0F12, 0x4000,},
        {0x0F12, 0xE590,},
        {0x0F12, 0x0004,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x009F,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x0214,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE5D0,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE350,},
        {0x0F12, 0x0002,},
        {0x0F12, 0x0A00,},
        {0x0F12, 0x0004,},
        {0x0F12, 0xE594,},
        {0x0F12, 0x00A0,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x0004,},
        {0x0F12, 0xE584,},
        {0x0F12, 0x4010,},
        {0x0F12, 0xE8BD,},
        {0x0F12, 0xFF1E,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x4070,},
        {0x0F12, 0xE92D,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE590,},
        {0x0F12, 0x0800,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x0820,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x4041,},
        {0x0F12, 0xE280,},
        {0x0F12, 0x01E0,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x11B8,},
        {0x0F12, 0xE1D0,},
        {0x0F12, 0x51B6,},
        {0x0F12, 0xE1D0,},
        {0x0F12, 0x0005,},
        {0x0F12, 0xE041,},
        {0x0F12, 0x0094,},
        {0x0F12, 0xE000,},
        {0x0F12, 0x1D11,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x008D,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x11C0,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x1000,},
        {0x0F12, 0xE5D1,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE351,},
        {0x0F12, 0x0000,},
        {0x0F12, 0x0A00,},
        {0x0F12, 0x00A0,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x21A8,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x3FB0,},
        {0x0F12, 0xE1D2,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE353,},
        {0x0F12, 0x0003,},
        {0x0F12, 0x0A00,},
        {0x0F12, 0x31A4,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x5BB2,},
        {0x0F12, 0xE1C3,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE085,},
        {0x0F12, 0xCBB4,},
        {0x0F12, 0xE1C3,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE351,},
        {0x0F12, 0x0000,},
        {0x0F12, 0x0A00,},
        {0x0F12, 0x0080,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x1DBC,},
        {0x0F12, 0xE1D2,},
        {0x0F12, 0x3EB4,},
        {0x0F12, 0xE1D2,},
        {0x0F12, 0x2EB2,},
        {0x0F12, 0xE1D2,},
        {0x0F12, 0x0193,},
        {0x0F12, 0xE001,},
        {0x0F12, 0x0092,},
        {0x0F12, 0xE000,},
        {0x0F12, 0x2811,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x0194,},
        {0x0F12, 0xE001,},
        {0x0F12, 0x0092,},
        {0x0F12, 0xE000,},
        {0x0F12, 0x11A1,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x01A0,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x0072,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x1160,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x02B4,},
        {0x0F12, 0xE1C1,},
        {0x0F12, 0x4070,},
        {0x0F12, 0xE8BD,},
        {0x0F12, 0xFF1E,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x4010,},
        {0x0F12, 0xE92D,},
        {0x0F12, 0x006E,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x2148,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x14B0,},
        {0x0F12, 0xE1D2,},
        {0x0F12, 0x0080,},
        {0x0F12, 0xE311,},
        {0x0F12, 0x0005,},
        {0x0F12, 0x0A00,},
        {0x0F12, 0x013C,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x00B0,},
        {0x0F12, 0xE1D0,},
        {0x0F12, 0x0001,},
        {0x0F12, 0xE350,},
        {0x0F12, 0x0001,},
        {0x0F12, 0x9A00,},
        {0x0F12, 0x0001,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xEA00,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x3110,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE5C3,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE5D3,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE350,},
        {0x0F12, 0x0003,},
        {0x0F12, 0x0A00,},
        {0x0F12, 0x0080,},
        {0x0F12, 0xE3C1,},
        {0x0F12, 0x110C,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x04B0,},
        {0x0F12, 0xE1C2,},
        {0x0F12, 0x00B2,},
        {0x0F12, 0xE1C1,},
        {0x0F12, 0x4010,},
        {0x0F12, 0xE8BD,},
        {0x0F12, 0xFF1E,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x41F0,},
        {0x0F12, 0xE92D,},
        {0x0F12, 0x1000,},
        {0x0F12, 0xE590,},
        {0x0F12, 0xC801,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0xC82C,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x1004,},
        {0x0F12, 0xE590,},
        {0x0F12, 0x1801,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x1821,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x4008,},
        {0x0F12, 0xE590,},
        {0x0F12, 0x500C,},
        {0x0F12, 0xE590,},
        {0x0F12, 0x2004,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x3005,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x000C,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x004E,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x60A0,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x00B2,},
        {0x0F12, 0xE1D6,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE350,},
        {0x0F12, 0x000E,},
        {0x0F12, 0x0A00,},
        {0x0F12, 0x00B8,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x05B4,},
        {0x0F12, 0xE1D0,},
        {0x0F12, 0x0002,},
        {0x0F12, 0xE350,},
        {0x0F12, 0x000A,},
        {0x0F12, 0x1A00,},
        {0x0F12, 0x70AC,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x10F4,},
        {0x0F12, 0xE1D6,},
        {0x0F12, 0x26B0,},
        {0x0F12, 0xE1D7,},
        {0x0F12, 0x00F0,},
        {0x0F12, 0xE1D4,},
        {0x0F12, 0x0044,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x00B0,},
        {0x0F12, 0xE1C4,},
        {0x0F12, 0x26B0,},
        {0x0F12, 0xE1D7,},
        {0x0F12, 0x10F6,},
        {0x0F12, 0xE1D6,},
        {0x0F12, 0x00F0,},
        {0x0F12, 0xE1D5,},
        {0x0F12, 0x003F,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x00B0,},
        {0x0F12, 0xE1C5,},
        {0x0F12, 0x41F0,},
        {0x0F12, 0xE8BD,},
        {0x0F12, 0xFF1E,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x4010,},
        {0x0F12, 0xE92D,},
        {0x0F12, 0x4000,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x1004,},
        {0x0F12, 0xE594,},
        {0x0F12, 0x0040,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x00B0,},
        {0x0F12, 0xE1D0,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE350,},
        {0x0F12, 0x0008,},
        {0x0F12, 0x0A00,},
        {0x0F12, 0x005C,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x3001,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x2068,},
        {0x0F12, 0xE590,},
        {0x0F12, 0x0054,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x1005,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x0032,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE584,},
        {0x0F12, 0x4010,},
        {0x0F12, 0xE8BD,},
        {0x0F12, 0xFF1E,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE594,},
        {0x0F12, 0x0030,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE584,},
        {0x0F12, 0xFFF9,},
        {0x0F12, 0xEAFF,},
        {0x0F12, 0x28E8,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x3370,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x1272,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x1728,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x112C,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x28EC,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x122C,},
        {0x0F12, 0x7000,},
        {0x0F12, 0xF200,},
        {0x0F12, 0xD000,},
        {0x0F12, 0x2340,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x0E2C,},
        {0x0F12, 0x7000,},
        {0x0F12, 0xF400,},
        {0x0F12, 0xD000,},
        {0x0F12, 0x0CDC,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x20D4,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x06D4,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x4778,},
        {0x0F12, 0x46C0,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0xC091,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x0467,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x2FA7,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0xCB1F,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x058F,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0xA0F1,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xF004,},
        {0x0F12, 0xE51F,},
        {0x0F12, 0xD14C,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x2B43,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x8725,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x6777,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x8E49,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x8EDD,},
        {0x0F12, 0x0000,},
        {0x0F12, 0x96FF,},
        {0x0F12, 0x0000,},
        {0x0F12, 0x0001,},
        {0x0F12, 0x0000,},
// End of Patch Data(Last : 700027C2h) */
// Total Size 852 (0x0354)             */
// Addr : 2470 , Size : 850(352h)      */

//==================================================================================
// 04.Analog Setting & APS Control
//==================================================================================
//This register is for FACTORY ONLY. 
//If you change it without prior notification
//YOU are RESPONSIBLE for the FAILURE that will happen in the future
        {0x0028, 0x7000,},
        {0x002A, 0x0E38,},
        {0x0F12, 0x0476,},	//senHal_RegCompBiasNormSf //CDS bias
        {0x0F12, 0x0476,},	//senHal_RegCompBiasYAv //CDS bias
        {0x002A, 0x0AA0,},
        {0x0F12, 0x0001,},	//setot_bUseDigitalHbin //1-Digital, 0-Analog
        {0x002A, 0x0E2C,},
        {0x0F12, 0x0001,},	//senHal_bUseAnalogVerAv //2-Adding/averaging, 1-Y-Avg, 0-PLA
        {0x002A, 0x0E66,},
        {0x0F12, 0x0001,},	//senHal_RegBlstEnNorm
        {0x002A, 0x1250,},
        {0x0F12, 0xFFFF,}, 	//senHal_Bls_nSpExpLines
        {0x002A, 0x1202,},
        {0x0F12, 0x0010,}, 	//senHal_Dblr_VcoFreqMHZ
//ADLC Filter
        {0x002A, 0x1288,},
        {0x0F12, 0x020F,},	//gisp_dadlc_ResetFilterValue
        {0x0F12, 0x1C02,},	//gisp_dadlc_SteadyFilterValue
        {0x0F12, 0x0006,},	//gisp_dadlc_NResetIIrFrames	

//*************************************/
// 05.OTP Control                     */
//*************************************/
        {0x002A, 0x3378,},
        {0x0F12, 0x0000,},// Tune_TP_bReMultGainsByNvm */

//*********************************************************************************
// 06.GAS (Grid Anti-Shading)                                                     
//*********************************************************************************
        {0x002A, 0x1326,},
        {0x0F12, 0x0000,},	// gisp_gos_Enable 
        {0x002A, 0x063A,},
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_0__0_ Horizon 
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_0__1_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_0__2_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_0__3_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_1__0_ IncandA 
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_1__1_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_1__2_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_1__3_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_2__0_ WW      
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_2__1_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_2__2_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_2__3_         
        {0x0F12, 0x00E8,},	// TVAR_ash_GASAlpha_3__0_ CW      
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_3__1_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_3__2_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_3__3_         
        {0x0F12, 0x00C8,},	// TVAR_ash_GASAlpha_4__0_ D50     
        {0x0F12, 0x00F8,},	// TVAR_ash_GASAlpha_4__1_         
        {0x0F12, 0x00F8,},	// TVAR_ash_GASAlpha_4__2_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_4__3_         
        {0x0F12, 0x00F0,},	// TVAR_ash_GASAlpha_5__0_ D65     
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_5__1_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_5__2_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_5__3_         
        {0x0F12, 0x00F0,},	// TVAR_ash_GASAlpha_6__0_ D75     
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_6__1_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_6__2_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_6__3_         
        {0x002A, 0x067A,},
        {0x0F12, 0x0000,},	// ash_GASBeta_0__0_ Horizon 
        {0x0F12, 0x0000,},	// ash_GASBeta_0__1_         
        {0x0F12, 0x0000,},	// ash_GASBeta_0__2_         
        {0x0F12, 0x0000,},	// ash_GASBeta_0__3_         
        {0x0F12, 0x0000,},	// ash_GASBeta_1__0_ IncandA 
        {0x0F12, 0x0000,},	// ash_GASBeta_1__1_         
        {0x0F12, 0x0000,},	// ash_GASBeta_1__2_         
        {0x0F12, 0x0000,},	// ash_GASBeta_1__3_         
        {0x0F12, 0x0000,},	// ash_GASBeta_2__0_ WW      
        {0x0F12, 0x0000,},	// ash_GASBeta_2__1_         
        {0x0F12, 0x0000,},	// ash_GASBeta_2__2_         
        {0x0F12, 0x0000,},	// ash_GASBeta_2__3_         
        {0x0F12, 0x0000,},	// ash_GASBeta_3__0_ CW      
        {0x0F12, 0x0000,},	// ash_GASBeta_3__1_         
        {0x0F12, 0x0000,},	// ash_GASBeta_3__2_         
        {0x0F12, 0x0000,},	// ash_GASBeta_3__3_         
        {0x0F12, 0x0000,},	// ash_GASBeta_4__0_ D50     
        {0x0F12, 0x0000,},	// ash_GASBeta_4__1_         
        {0x0F12, 0x0000,},	// ash_GASBeta_4__2_         
        {0x0F12, 0x0000,},	// ash_GASBeta_4__3_         
        {0x0F12, 0x0000,},	// ash_GASBeta_5__0_ D65     
        {0x0F12, 0x0000,},	// ash_GASBeta_5__1_         
        {0x0F12, 0x0000,},	// ash_GASBeta_5__2_         
        {0x0F12, 0x0000,},	// ash_GASBeta_5__3_         
        {0x0F12, 0x0000,},	// ash_GASBeta_6__0_ D75     
        {0x0F12, 0x0000,},	// ash_GASBeta_6__1_         
        {0x0F12, 0x0000,},	// ash_GASBeta_6__2_         
        {0x0F12, 0x0000,},	// ash_GASBeta_6__3_         
        {0x002A, 0x06BA,},
        {0x0F12, 0x0001,},	//ash_bLumaMode 
        {0x002A, 0x0632,},
        {0x0F12, 0x0100,},	// ash_CGrasAlphas_0_ 
        {0x0F12, 0x0100,},	// ash_CGrasAlphas_1_ 
        {0x0F12, 0x0100,},	// ash_CGrasAlphas_2_ 
        {0x0F12, 0x0100,},	// ash_CGrasAlphas_3_ 
        {0x002A, 0x0672,},
        {0x0F12, 0x0100,},	// TVAR_ash_GASOutdoorAlpha_0_ 
        {0x0F12, 0x0100,},	// TVAR_ash_GASOutdoorAlpha_1_ 
        {0x0F12, 0x0100,},	// TVAR_ash_GASOutdoorAlpha_2_ 
        {0x0F12, 0x0100,},	// TVAR_ash_GASOutdoorAlpha_3_ 
        {0x002A, 0x06B2,},
        {0x0F12, 0x0000,},	// ash_GASOutdoorBeta_0_ 
        {0x0F12, 0x0000,},	// ash_GASOutdoorBeta_1_ 
        {0x0F12, 0x0000,},	// ash_GASOutdoorBeta_2_ 
        {0x0F12, 0x0000,},	// ash_GASOutdoorBeta_3_ 
        {0x002A, 0x06D0,},
        {0x0F12, 0x000D,},	// ash_uParabolicScalingA
        {0x0F12, 0x000F,},	// ash_uParabolicScalingB
        {0x002A, 0x06CC,},
        {0x0F12, 0x0280,},	// ash_uParabolicCenterX 
        {0x0F12, 0x01E0,},	// ash_uParabolicCenterY 
        {0x002A, 0x06C6,},
        {0x0F12, 0x0001,},	// ash_bParabolicEstimation 
        {0x002A, 0x0624,},
        {0x0F12, 0x009D,},	// TVAR_ash_AwbAshCord_0_ Horizon 
        {0x0F12, 0x00D5,},	// TVAR_ash_AwbAshCord_1_ IncandA 
        {0x0F12, 0x0103,},	// TVAR_ash_AwbAshCord_2_ WW      
        {0x0F12, 0x0128,},	// TVAR_ash_AwbAshCord_3_ CW      
        {0x0F12, 0x0166,},	// TVAR_ash_AwbAshCord_4_ D50     
        {0x0F12, 0x0193,},	// TVAR_ash_AwbAshCord_5_ D65     
        {0x0F12, 0x01A0,},	// TVAR_ash_AwbAshCord_6_ D75  

        {0x002A, 0x347C,},
        {0x0F12, 0x013B,},	// 011A 012F Tune_wbt_GAS_0_   
        {0x0F12, 0x0116,},	// 011A 0111 Tune_wbt_GAS_1_   
        {0x0F12, 0x00D9,},	// 00EE 00D6 Tune_wbt_GAS_2_   
        {0x0F12, 0x00A6,},	// 00C1 009E Tune_wbt_GAS_3_   
        {0x0F12, 0x0082,},	// 009E 007A Tune_wbt_GAS_4_   
        {0x0F12, 0x006C,},	// 008A 0064 Tune_wbt_GAS_5_   
        {0x0F12, 0x0065,},	// 0083 005D Tune_wbt_GAS_6_   
        {0x0F12, 0x006C,},	// 008A 0063 Tune_wbt_GAS_7_   
        {0x0F12, 0x0080,},	// 009E 007B Tune_wbt_GAS_8_   
        {0x0F12, 0x00A3,},	// 00BF 00A3 Tune_wbt_GAS_9_   
        {0x0F12, 0x00D4,},	// 00E5 00E3 Tune_wbt_GAS_10_  
        {0x0F12, 0x010D,},	// 00F9 013B Tune_wbt_GAS_11_  
        {0x0F12, 0x012E,},	// 0124 018B Tune_wbt_GAS_12_  
        {0x0F12, 0x0138,},	// 0126 012B Tune_wbt_GAS_13_  
        {0x0F12, 0x0104,},	// 010E 00F6 Tune_wbt_GAS_14_  
        {0x0F12, 0x00BE,},	// 00D3 00B2 Tune_wbt_GAS_15_  
        {0x0F12, 0x0088,},	// 009F 007B Tune_wbt_GAS_16_  
        {0x0F12, 0x0062,},	// 007C 0057 Tune_wbt_GAS_17_  
        {0x0F12, 0x004D,},	// 0068 0042 Tune_wbt_GAS_18_  
        {0x0F12, 0x0046,},	// 0061 0039 Tune_wbt_GAS_19_  
        {0x0F12, 0x004C,},	// 0068 003F Tune_wbt_GAS_20_  
        {0x0F12, 0x0060,},	// 007E 0053 Tune_wbt_GAS_21_  
        {0x0F12, 0x0084,},	// 00A3 007A Tune_wbt_GAS_22_  
        {0x0F12, 0x00B8,},	// 00C9 00B6 Tune_wbt_GAS_23_  
        {0x0F12, 0x00F9,},	// 00F0 0110 Tune_wbt_GAS_24_  
        {0x0F12, 0x012C,},	// 0131 016A Tune_wbt_GAS_25_  
        {0x0F12, 0x011A,},	// 011C 0114 Tune_wbt_GAS_26_  
        {0x0F12, 0x00DB,},	// 00EB 00D4 Tune_wbt_GAS_27_  
        {0x0F12, 0x0093,},	// 00AA 008F Tune_wbt_GAS_28_  
        {0x0F12, 0x005F,},	// 0075 005A Tune_wbt_GAS_29_  
        {0x0F12, 0x003C,},	// 0053 0035 Tune_wbt_GAS_30_  
        {0x0F12, 0x0027,},	// 003F 0020 Tune_wbt_GAS_31_  
        {0x0F12, 0x0020,},	// 0038 0019 Tune_wbt_GAS_32_  
        {0x0F12, 0x0026,},	// 0040 001F Tune_wbt_GAS_33_  
        {0x0F12, 0x003A,},	// 0055 0032 Tune_wbt_GAS_34_  
        {0x0F12, 0x005C,},	// 007A 0056 Tune_wbt_GAS_35_  
        {0x0F12, 0x008E,},	// 00A6 008E Tune_wbt_GAS_36_  
        {0x0F12, 0x00D2,},	// 00D5 00E6 Tune_wbt_GAS_37_  
        {0x0F12, 0x010E,},	// 0126 0142 Tune_wbt_GAS_38_  
        {0x0F12, 0x0101,},	// 00F6 0102 Tune_wbt_GAS_39_  
        {0x0F12, 0x00BF,},	// 00C0 00BE Tune_wbt_GAS_40_  
        {0x0F12, 0x0077,},	// 007D 0077 Tune_wbt_GAS_41_  
        {0x0F12, 0x0044,},	// 004D 0045 Tune_wbt_GAS_42_  
        {0x0F12, 0x0023,},	// 002C 0022 Tune_wbt_GAS_43_  
        {0x0F12, 0x0011,},	// 001B 000D Tune_wbt_GAS_44_  
        {0x0F12, 0x000C,},	// 0017 0006 Tune_wbt_GAS_45_  
        {0x0F12, 0x0010,},	// 001B 000A Tune_wbt_GAS_46_  
        {0x0F12, 0x0022,},	// 002D 001D Tune_wbt_GAS_47_  
        {0x0F12, 0x0043,},	// 004E 003F Tune_wbt_GAS_48_  
        {0x0F12, 0x0074,},	// 0080 0075 Tune_wbt_GAS_49_  
        {0x0F12, 0x00B7,},	// 00C1 00CC Tune_wbt_GAS_50_  
        {0x0F12, 0x00F7,},	// 00FF 0126 Tune_wbt_GAS_51_  
        {0x0F12, 0x00FC,},	// 00EA 00FB Tune_wbt_GAS_52_  
        {0x0F12, 0x00B7,},	// 00B0 00B7 Tune_wbt_GAS_53_  
        {0x0F12, 0x006F,},	// 006D 0070 Tune_wbt_GAS_54_  
        {0x0F12, 0x003C,},	// 003D 003D Tune_wbt_GAS_55_  
        {0x0F12, 0x001C,},	// 001E 001B Tune_wbt_GAS_56_  
        {0x0F12, 0x000A,},	// 000F 0007 Tune_wbt_GAS_57_  
        {0x0F12, 0x0004,},	// 000A 0000 Tune_wbt_GAS_58_  
        {0x0F12, 0x000A,},	// 0010 0004 Tune_wbt_GAS_59_  
        {0x0F12, 0x001B,},	// 001E 0015 Tune_wbt_GAS_60_  
        {0x0F12, 0x003B,},	// 003E 0034 Tune_wbt_GAS_61_  
        {0x0F12, 0x006C,},	// 006F 006A Tune_wbt_GAS_62_  
        {0x0F12, 0x00B0,},	// 00B2 00C0 Tune_wbt_GAS_63_  
        {0x0F12, 0x00F2,},	// 00F1 011B Tune_wbt_GAS_64_  
        {0x0F12, 0x00EF,},	// 00E0 0102 Tune_wbt_GAS_65_  
        {0x0F12, 0x00AB,},	// 00A6 00BA Tune_wbt_GAS_66_  
        {0x0F12, 0x0065,},	// 0063 0073 Tune_wbt_GAS_67_  
        {0x0F12, 0x0034,},	// 0033 0040 Tune_wbt_GAS_68_  
        {0x0F12, 0x0015,},	// 0016 001D Tune_wbt_GAS_69_  
        {0x0F12, 0x0004,},	// 0008 0009 Tune_wbt_GAS_70_  
        {0x0F12, 0x0000,},	// 0003 0001 Tune_wbt_GAS_71_  
        {0x0F12, 0x0004,},	// 0009 0006 Tune_wbt_GAS_72_  
        {0x0F12, 0x0013,},	// 0016 0017 Tune_wbt_GAS_73_  
        {0x0F12, 0x0033,},	// 0035 0039 Tune_wbt_GAS_74_  
        {0x0F12, 0x0063,},	// 0066 006F Tune_wbt_GAS_75_  
        {0x0F12, 0x00A5,},	// 00A7 00C8 Tune_wbt_GAS_76_  
        {0x0F12, 0x00E5,},	// 00E9 011E Tune_wbt_GAS_77_  
        {0x0F12, 0x00F7,},	// 00D5 0111 Tune_wbt_GAS_78_  
        {0x0F12, 0x00B4,},	// 009D 00C8 Tune_wbt_GAS_79_  
        {0x0F12, 0x006D,},	// 005D 0081 Tune_wbt_GAS_80_  
        {0x0F12, 0x003C,},	// 002F 004D Tune_wbt_GAS_81_  
        {0x0F12, 0x001C,},	// 0010 0028 Tune_wbt_GAS_82_  
        {0x0F12, 0x000B,},	// 0004 0014 Tune_wbt_GAS_83_  
        {0x0F12, 0x0005,},	// 0001 000B Tune_wbt_GAS_84_  
        {0x0F12, 0x000A,},	// 0005 0010 Tune_wbt_GAS_85_  
        {0x0F12, 0x001B,},	// 0013 0022 Tune_wbt_GAS_86_  
        {0x0F12, 0x003B,},	// 0031 0047 Tune_wbt_GAS_87_  
        {0x0F12, 0x006B,},	// 005F 007E Tune_wbt_GAS_88_  
        {0x0F12, 0x00AD,},	// 00A1 00D8 Tune_wbt_GAS_89_  
        {0x0F12, 0x00ED,},	// 00DF 0131 Tune_wbt_GAS_90_  
        {0x0F12, 0x010B,},	// 00E9 0129 Tune_wbt_GAS_91_  
        {0x0F12, 0x00CB,},	// 00B2 00E4 Tune_wbt_GAS_92_  
        {0x0F12, 0x0085,},	// 006F 009E Tune_wbt_GAS_93_  
        {0x0F12, 0x0051,},	// 003F 0068 Tune_wbt_GAS_94_  
        {0x0F12, 0x002F,},	// 0020 0041 Tune_wbt_GAS_95_  
        {0x0F12, 0x001C,},	// 000F 002B Tune_wbt_GAS_96_  
        {0x0F12, 0x0016,},	// 000B 0023 Tune_wbt_GAS_97_  
        {0x0F12, 0x001C,},	// 0010 0028 Tune_wbt_GAS_98_  
        {0x0F12, 0x002E,},	// 0021 003B Tune_wbt_GAS_99_  
        {0x0F12, 0x004F,},	// 0041 0063 Tune_wbt_GAS_100_ 
        {0x0F12, 0x0081,},	// 0071 00A0 Tune_wbt_GAS_101_ 
        {0x0F12, 0x00C4,},	// 00B4 00FD Tune_wbt_GAS_102_ 
        {0x0F12, 0x0102,},	// 00F6 015A Tune_wbt_GAS_103_ 
        {0x0F12, 0x0119,},	// 00F9 014A Tune_wbt_GAS_104_ 
        {0x0F12, 0x00DF,},	// 00C2 010D Tune_wbt_GAS_105_ 
        {0x0F12, 0x009B,},	// 0082 00CA Tune_wbt_GAS_106_ 
        {0x0F12, 0x0067,},	// 0053 008F Tune_wbt_GAS_107_ 
        {0x0F12, 0x0045,},	// 0033 0066 Tune_wbt_GAS_108_ 
        {0x0F12, 0x0030,},	// 0021 004F Tune_wbt_GAS_109_ 
        {0x0F12, 0x0029,},	// 001C 0048 Tune_wbt_GAS_110_ 
        {0x0F12, 0x002F,},	// 0022 004E Tune_wbt_GAS_111_ 
        {0x0F12, 0x0043,},	// 0035 0067 Tune_wbt_GAS_112_ 
        {0x0F12, 0x0066,},	// 0056 008F Tune_wbt_GAS_113_ 
        {0x0F12, 0x0098,},	// 0087 00D1 Tune_wbt_GAS_114_ 
        {0x0F12, 0x00D9,},	// 00CA 0132 Tune_wbt_GAS_115_ 
        {0x0F12, 0x010F,},	// 0107 018D Tune_wbt_GAS_116_ 
        {0x0F12, 0x0138,},	// 0108 0159 Tune_wbt_GAS_117_ 
        {0x0F12, 0x010C,},	// 00E0 0141 Tune_wbt_GAS_118_ 
        {0x0F12, 0x00CB,},	// 00A2 0103 Tune_wbt_GAS_119_ 
        {0x0F12, 0x0097,},	// 0072 00C9 Tune_wbt_GAS_120_ 
        {0x0F12, 0x0073,},	// 0052 009E Tune_wbt_GAS_121_ 
        {0x0F12, 0x005C,},	// 0040 0087 Tune_wbt_GAS_122_ 
        {0x0F12, 0x0054,},	// 003A 007D Tune_wbt_GAS_123_ 
        {0x0F12, 0x005B,},	// 0041 0087 Tune_wbt_GAS_124_ 
        {0x0F12, 0x0070,},	// 0055 00A2 Tune_wbt_GAS_125_ 
        {0x0F12, 0x0096,},	// 0077 00D4 Tune_wbt_GAS_126_ 
        {0x0F12, 0x00C9,},	// 00A8 011A Tune_wbt_GAS_127_ 
        {0x0F12, 0x0106,},	// 00E7 017D Tune_wbt_GAS_128_ 
        {0x0F12, 0x012D,},	// 011E 01CF Tune_wbt_GAS_129_ 
        {0x0F12, 0x0147,},	// 0123 0181 Tune_wbt_GAS_130_ 
        {0x0F12, 0x012F,},	// 0100 0169 Tune_wbt_GAS_131_ 
        {0x0F12, 0x00F8,},	// 00CB 0140 Tune_wbt_GAS_132_ 
        {0x0F12, 0x00C5,},	// 009A 0106 Tune_wbt_GAS_133_ 
        {0x0F12, 0x00A1,},	// 0079 00DD Tune_wbt_GAS_134_ 
        {0x0F12, 0x008B,},	// 0067 00C5 Tune_wbt_GAS_135_ 
        {0x0F12, 0x0083,},	// 0060 00BE Tune_wbt_GAS_136_ 
        {0x0F12, 0x008B,},	// 0068 00C8 Tune_wbt_GAS_137_ 
        {0x0F12, 0x00A0,},	// 007B 00E6 Tune_wbt_GAS_138_ 
        {0x0F12, 0x00C2,},	// 009D 011B Tune_wbt_GAS_139_ 
        {0x0F12, 0x00F3,},	// 00CD 015F Tune_wbt_GAS_140_ 
        {0x0F12, 0x0124,},	// 0108 01BC Tune_wbt_GAS_141_ 
        {0x0F12, 0x0139,},	// 0131 0206 Tune_wbt_GAS_142_ 
        {0x0F12, 0x0093,},	// 006C 00A8 Tune_wbt_GAS_143_ 
        {0x0F12, 0x007E,},	// 006E 008F Tune_wbt_GAS_144_ 
        {0x0F12, 0x0062,},	// 005D 006F Tune_wbt_GAS_145_ 
        {0x0F12, 0x004D,},	// 004C 0054 Tune_wbt_GAS_146_ 
        {0x0F12, 0x003E,},	// 0040 0041 Tune_wbt_GAS_147_ 
        {0x0F12, 0x0034,},	// 0037 0036 Tune_wbt_GAS_148_ 
        {0x0F12, 0x0030,},	// 0035 0033 Tune_wbt_GAS_149_ 
        {0x0F12, 0x0032,},	// 0036 0037 Tune_wbt_GAS_150_ 
        {0x0F12, 0x003B,},	// 003F 0045 Tune_wbt_GAS_151_ 
        {0x0F12, 0x0049,},	// 004B 005A Tune_wbt_GAS_152_ 
        {0x0F12, 0x005C,},	// 0053 007A Tune_wbt_GAS_153_ 
        {0x0F12, 0x0077,},	// 0053 00AA Tune_wbt_GAS_154_ 
        {0x0F12, 0x008A,},	// 0070 00E2 Tune_wbt_GAS_155_ 
        {0x0F12, 0x0093,},	// 0075 009E Tune_wbt_GAS_156_ 
        {0x0F12, 0x0077,},	// 006D 007D Tune_wbt_GAS_157_ 
        {0x0F12, 0x0059,},	// 0056 005A Tune_wbt_GAS_158_ 
        {0x0F12, 0x0042,},	// 0043 0041 Tune_wbt_GAS_159_ 
        {0x0F12, 0x0032,},	// 0037 002E Tune_wbt_GAS_160_ 
        {0x0F12, 0x0027,},	// 002F 0022 Tune_wbt_GAS_161_ 
        {0x0F12, 0x0024,},	// 002C 001F Tune_wbt_GAS_162_ 
        {0x0F12, 0x0026,},	// 002F 0022 Tune_wbt_GAS_163_ 
        {0x0F12, 0x002F,},	// 0038 0030 Tune_wbt_GAS_164_ 
        {0x0F12, 0x003D,},	// 0045 0044 Tune_wbt_GAS_165_ 
        {0x0F12, 0x0052,},	// 004E 0063 Tune_wbt_GAS_166_ 
        {0x0F12, 0x006E,},	// 0055 0091 Tune_wbt_GAS_167_ 
        {0x0F12, 0x008B,},	// 007F 00CB Tune_wbt_GAS_168_ 
        {0x0F12, 0x0083,},	// 0077 0093 Tune_wbt_GAS_169_ 
        {0x0F12, 0x0064,},	// 0062 006D Tune_wbt_GAS_170_ 
        {0x0F12, 0x0046,},	// 004A 004A Tune_wbt_GAS_171_ 
        {0x0F12, 0x0030,},	// 0037 0031 Tune_wbt_GAS_172_ 
        {0x0F12, 0x0020,},	// 002A 001E Tune_wbt_GAS_173_ 
        {0x0F12, 0x0016,},	// 0021 0013 Tune_wbt_GAS_174_ 
        {0x0F12, 0x0011,},	// 001E 000F Tune_wbt_GAS_175_ 
        {0x0F12, 0x0014,},	// 0021 0013 Tune_wbt_GAS_176_ 
        {0x0F12, 0x001E,},	// 002B 001F Tune_wbt_GAS_177_ 
        {0x0F12, 0x002D,},	// 003B 0034 Tune_wbt_GAS_178_ 
        {0x0F12, 0x0041,},	// 0046 0051 Tune_wbt_GAS_179_ 
        {0x0F12, 0x005D,},	// 0051 007C Tune_wbt_GAS_180_ 
        {0x0F12, 0x007C,},	// 007F 00B7 Tune_wbt_GAS_181_ 
        {0x0F12, 0x0077,},	// 0062 008A Tune_wbt_GAS_182_ 
        {0x0F12, 0x0057,},	// 004B 0061 Tune_wbt_GAS_183_ 
        {0x0F12, 0x0039,},	// 0034 003E Tune_wbt_GAS_184_ 
        {0x0F12, 0x0024,},	// 0022 0026 Tune_wbt_GAS_185_ 
        {0x0F12, 0x0014,},	// 0014 0013 Tune_wbt_GAS_186_ 
        {0x0F12, 0x000A,},	// 000E 0008 Tune_wbt_GAS_187_ 
        {0x0F12, 0x0007,},	// 000C 0004 Tune_wbt_GAS_188_ 
        {0x0F12, 0x0009,},	// 000D 0007 Tune_wbt_GAS_189_ 
        {0x0F12, 0x0012,},	// 0016 0013 Tune_wbt_GAS_190_ 
        {0x0F12, 0x0021,},	// 0024 0027 Tune_wbt_GAS_191_ 
        {0x0F12, 0x0036,},	// 0036 0045 Tune_wbt_GAS_192_ 
        {0x0F12, 0x0051,},	// 004E 0070 Tune_wbt_GAS_193_ 
        {0x0F12, 0x0070,},	// 0069 00A7 Tune_wbt_GAS_194_ 
        {0x0F12, 0x0077,},	// 005F 0085 Tune_wbt_GAS_195_ 
        {0x0F12, 0x0056,},	// 0048 005D Tune_wbt_GAS_196_ 
        {0x0F12, 0x0038,},	// 002F 003A Tune_wbt_GAS_197_ 
        {0x0F12, 0x0022,},	// 001C 0021 Tune_wbt_GAS_198_ 
        {0x0F12, 0x0013,},	// 0010 0010 Tune_wbt_GAS_199_ 
        {0x0F12, 0x0009,},	// 000B 0004 Tune_wbt_GAS_200_ 
        {0x0F12, 0x0005,},	// 0008 0000 Tune_wbt_GAS_201_ 
        {0x0F12, 0x0008,},	// 000B 0003 Tune_wbt_GAS_202_ 
        {0x0F12, 0x0011,},	// 0010 000E Tune_wbt_GAS_203_ 
        {0x0F12, 0x0020,},	// 001E 0021 Tune_wbt_GAS_204_ 
        {0x0F12, 0x0035,},	// 0031 003F Tune_wbt_GAS_205_ 
        {0x0F12, 0x0051,},	// 0049 006B Tune_wbt_GAS_206_ 
        {0x0F12, 0x0071,},	// 0066 00A1 Tune_wbt_GAS_207_ 
        {0x0F12, 0x006E,},	// 005B 0089 Tune_wbt_GAS_208_ 
        {0x0F12, 0x004E,},	// 0043 0060 Tune_wbt_GAS_209_ 
        {0x0F12, 0x0032,},	// 002B 003D Tune_wbt_GAS_210_ 
        {0x0F12, 0x001C,},	// 0019 0023 Tune_wbt_GAS_211_ 
        {0x0F12, 0x000D,},	// 000C 0012 Tune_wbt_GAS_212_ 
        {0x0F12, 0x0004,},	// 0007 0006 Tune_wbt_GAS_213_ 
        {0x0F12, 0x0000,},	// 0004 0002 Tune_wbt_GAS_214_ 
        {0x0F12, 0x0003,},	// 0007 0005 Tune_wbt_GAS_215_ 
        {0x0F12, 0x000B,},	// 000D 0011 Tune_wbt_GAS_216_ 
        {0x0F12, 0x001A,},	// 001B 0025 Tune_wbt_GAS_217_ 
        {0x0F12, 0x002F,},	// 002E 0043 Tune_wbt_GAS_218_ 
        {0x0F12, 0x0049,},	// 0046 0070 Tune_wbt_GAS_219_ 
        {0x0F12, 0x0068,},	// 0062 00A4 Tune_wbt_GAS_220_ 
        {0x0F12, 0x0072,},	// 0052 0091 Tune_wbt_GAS_221_ 
        {0x0F12, 0x0053,},	// 003D 0067 Tune_wbt_GAS_222_ 
        {0x0F12, 0x0037,},	// 0026 0044 Tune_wbt_GAS_223_ 
        {0x0F12, 0x0021,},	// 0014 002B Tune_wbt_GAS_224_ 
        {0x0F12, 0x0012,},	// 0007 0019 Tune_wbt_GAS_225_ 
        {0x0F12, 0x0009,},	// 0002 000D Tune_wbt_GAS_226_ 
        {0x0F12, 0x0005,},	// 0001 0009 Tune_wbt_GAS_227_ 
        {0x0F12, 0x0008,},	// 0002 000C Tune_wbt_GAS_228_ 
        {0x0F12, 0x0010,},	// 0007 0018 Tune_wbt_GAS_229_ 
        {0x0F12, 0x001F,},	// 0015 002D Tune_wbt_GAS_230_ 
        {0x0F12, 0x0034,},	// 0028 004B Tune_wbt_GAS_231_ 
        {0x0F12, 0x004E,},	// 0040 007B Tune_wbt_GAS_232_ 
        {0x0F12, 0x006C,},	// 005C 00B0 Tune_wbt_GAS_233_ 
        {0x0F12, 0x007F,},	// 005E 00A1 Tune_wbt_GAS_234_ 
        {0x0F12, 0x0060,},	// 0049 0077 Tune_wbt_GAS_235_ 
        {0x0F12, 0x0043,},	// 0030 0054 Tune_wbt_GAS_236_ 
        {0x0F12, 0x002D,},	// 001E 003B Tune_wbt_GAS_237_ 
        {0x0F12, 0x001D,},	// 0010 0029 Tune_wbt_GAS_238_ 
        {0x0F12, 0x0013,},	// 0009 001C Tune_wbt_GAS_239_ 
        {0x0F12, 0x0010,},	// 0007 0018 Tune_wbt_GAS_240_ 
        {0x0F12, 0x0013,},	// 0009 001B Tune_wbt_GAS_241_ 
        {0x0F12, 0x001C,},	// 0012 0029 Tune_wbt_GAS_242_ 
        {0x0F12, 0x002B,},	// 0020 003F Tune_wbt_GAS_243_ 
        {0x0F12, 0x0040,},	// 0032 005F Tune_wbt_GAS_244_ 
        {0x0F12, 0x005A,},	// 004B 008F Tune_wbt_GAS_245_ 
        {0x0F12, 0x0079,},	// 0069 00C6 Tune_wbt_GAS_246_ 
        {0x0F12, 0x0082,},	// 0066 00B1 Tune_wbt_GAS_247_ 
        {0x0F12, 0x0066,},	// 004E 008E Tune_wbt_GAS_248_ 
        {0x0F12, 0x0049,},	// 0037 006D Tune_wbt_GAS_249_ 
        {0x0F12, 0x0035,},	// 0026 0050 Tune_wbt_GAS_250_ 
        {0x0F12, 0x0025,},	// 0019 003D Tune_wbt_GAS_251_ 
        {0x0F12, 0x001B,},	// 0011 0031 Tune_wbt_GAS_252_ 
        {0x0F12, 0x0017,},	// 000F 002F Tune_wbt_GAS_253_ 
        {0x0F12, 0x0019,},	// 0012 0032 Tune_wbt_GAS_254_ 
        {0x0F12, 0x0023,},	// 001B 0042 Tune_wbt_GAS_255_ 
        {0x0F12, 0x0033,},	// 0028 0058 Tune_wbt_GAS_256_ 
        {0x0F12, 0x0046,},	// 003B 007A Tune_wbt_GAS_257_ 
        {0x0F12, 0x0060,},	// 0054 00AC Tune_wbt_GAS_258_ 
        {0x0F12, 0x007B,},	// 0072 00E5 Tune_wbt_GAS_259_ 
        {0x0F12, 0x0092,},	// 006A 00BD Tune_wbt_GAS_260_ 
        {0x0F12, 0x007C,},	// 0058 00AA Tune_wbt_GAS_261_ 
        {0x0F12, 0x0060,},	// 0041 008B Tune_wbt_GAS_262_ 
        {0x0F12, 0x004B,},	// 0030 006E Tune_wbt_GAS_263_ 
        {0x0F12, 0x003C,},	// 0025 005A Tune_wbt_GAS_264_ 
        {0x0F12, 0x0032,},	// 001E 004F Tune_wbt_GAS_265_ 
        {0x0F12, 0x002D,},	// 001B 004B Tune_wbt_GAS_266_ 
        {0x0F12, 0x0030,},	// 001F 0052 Tune_wbt_GAS_267_ 
        {0x0F12, 0x0039,},	// 0027 0062 Tune_wbt_GAS_268_ 
        {0x0F12, 0x0049,},	// 0034 007D Tune_wbt_GAS_269_ 
        {0x0F12, 0x005D,},	// 0046 00A2 Tune_wbt_GAS_270_ 
        {0x0F12, 0x0076,},	// 005D 00D6 Tune_wbt_GAS_271_ 
        {0x0F12, 0x008C,},	// 0078 010C Tune_wbt_GAS_272_ 
        {0x0F12, 0x009F,},	// 007C 00E5 Tune_wbt_GAS_273_ 
        {0x0F12, 0x008F,},	// 006A 00C7 Tune_wbt_GAS_274_ 
        {0x0F12, 0x0077,},	// 0055 00B1 Tune_wbt_GAS_275_ 
        {0x0F12, 0x0061,},	// 0043 0093 Tune_wbt_GAS_276_ 
        {0x0F12, 0x0052,},	// 0037 007F Tune_wbt_GAS_277_ 
        {0x0F12, 0x0048,},	// 0030 0074 Tune_wbt_GAS_278_ 
        {0x0F12, 0x0043,},	// 002E 0071 Tune_wbt_GAS_279_ 
        {0x0F12, 0x0047,},	// 0030 0077 Tune_wbt_GAS_280_ 
        {0x0F12, 0x0050,},	// 0039 0089 Tune_wbt_GAS_281_ 
        {0x0F12, 0x005E,},	// 0045 00A7 Tune_wbt_GAS_282_ 
        {0x0F12, 0x0071,},	// 0056 00CC Tune_wbt_GAS_283_ 
        {0x0F12, 0x0086,},	// 006C 00FE Tune_wbt_GAS_284_ 
        {0x0F12, 0x0097,},	// 0084 0132 Tune_wbt_GAS_285_ 
        {0x0F12, 0x0093,},	// 006E 00A8 Tune_wbt_GAS_286_ 
        {0x0F12, 0x007C,},	// 006D 008D Tune_wbt_GAS_287_ 
        {0x0F12, 0x005F,},	// 005B 006C Tune_wbt_GAS_288_ 
        {0x0F12, 0x0049,},	// 0046 004E Tune_wbt_GAS_289_ 
        {0x0F12, 0x003A,},	// 003A 003C Tune_wbt_GAS_290_ 
        {0x0F12, 0x0030,},	// 0033 0032 Tune_wbt_GAS_291_ 
        {0x0F12, 0x002C,},	// 002D 002D Tune_wbt_GAS_292_ 
        {0x0F12, 0x002F,},	// 0032 0032 Tune_wbt_GAS_293_ 
        {0x0F12, 0x0037,},	// 0039 0040 Tune_wbt_GAS_294_ 
        {0x0F12, 0x0045,},	// 0047 0056 Tune_wbt_GAS_295_ 
        {0x0F12, 0x005A,},	// 004F 0076 Tune_wbt_GAS_296_ 
        {0x0F12, 0x0075,},	// 0050 00A8 Tune_wbt_GAS_297_ 
        {0x0F12, 0x008A,},	// 006E 00E6 Tune_wbt_GAS_298_ 
        {0x0F12, 0x0094,},	// 0077 00A2 Tune_wbt_GAS_299_ 
        {0x0F12, 0x0077,},	// 006C 007C Tune_wbt_GAS_300_ 
        {0x0F12, 0x0057,},	// 0054 0059 Tune_wbt_GAS_301_ 
        {0x0F12, 0x0040,},	// 0040 003E Tune_wbt_GAS_302_ 
        {0x0F12, 0x002F,},	// 0033 002A Tune_wbt_GAS_303_ 
        {0x0F12, 0x0024,},	// 002B 0020 Tune_wbt_GAS_304_ 
        {0x0F12, 0x0020,},	// 0027 001B Tune_wbt_GAS_305_ 
        {0x0F12, 0x0023,},	// 002A 0020 Tune_wbt_GAS_306_ 
        {0x0F12, 0x002D,},	// 0034 002D Tune_wbt_GAS_307_ 
        {0x0F12, 0x003B,},	// 0041 0042 Tune_wbt_GAS_308_ 
        {0x0F12, 0x0051,},	// 004C 0061 Tune_wbt_GAS_309_ 
        {0x0F12, 0x006E,},	// 0052 0092 Tune_wbt_GAS_310_ 
        {0x0F12, 0x008C,},	// 007E 00CE Tune_wbt_GAS_311_ 
        {0x0F12, 0x0085,},	// 0078 0094 Tune_wbt_GAS_312_ 
        {0x0F12, 0x0066,},	// 0063 006F Tune_wbt_GAS_313_ 
        {0x0F12, 0x0046,},	// 0049 004B Tune_wbt_GAS_314_ 
        {0x0F12, 0x002F,},	// 0035 002F Tune_wbt_GAS_315_ 
        {0x0F12, 0x001F,},	// 0028 001D Tune_wbt_GAS_316_ 
        {0x0F12, 0x0014,},	// 001E 0011 Tune_wbt_GAS_317_ 
        {0x0F12, 0x000F,},	// 001B 000D Tune_wbt_GAS_318_ 
        {0x0F12, 0x0012,},	// 001F 0012 Tune_wbt_GAS_319_ 
        {0x0F12, 0x001C,},	// 0028 001D Tune_wbt_GAS_320_ 
        {0x0F12, 0x002B,},	// 0037 0033 Tune_wbt_GAS_321_ 
        {0x0F12, 0x0040,},	// 0044 0051 Tune_wbt_GAS_322_ 
        {0x0F12, 0x005C,},	// 0050 007F Tune_wbt_GAS_323_ 
        {0x0F12, 0x007D,},	// 0080 00BA Tune_wbt_GAS_324_ 
        {0x0F12, 0x007A,},	// 0064 008B Tune_wbt_GAS_325_ 
        {0x0F12, 0x005A,},	// 004E 0064 Tune_wbt_GAS_326_ 
        {0x0F12, 0x003A,},	// 0035 0040 Tune_wbt_GAS_327_ 
        {0x0F12, 0x0024,},	// 0021 0025 Tune_wbt_GAS_328_ 
        {0x0F12, 0x0014,},	// 0013 0013 Tune_wbt_GAS_329_ 
        {0x0F12, 0x0009,},	// 000D 0007 Tune_wbt_GAS_330_ 
        {0x0F12, 0x0006,},	// 000B 0003 Tune_wbt_GAS_331_ 
        {0x0F12, 0x0008,},	// 000C 0006 Tune_wbt_GAS_332_ 
        {0x0F12, 0x0011,},	// 0014 0012 Tune_wbt_GAS_333_ 
        {0x0F12, 0x0020,},	// 0022 0027 Tune_wbt_GAS_334_ 
        {0x0F12, 0x0036,},	// 0036 0046 Tune_wbt_GAS_335_ 
        {0x0F12, 0x0051,},	// 004D 0073 Tune_wbt_GAS_336_ 
        {0x0F12, 0x0072,},	// 006B 00AB Tune_wbt_GAS_337_ 
        {0x0F12, 0x007B,},	// 0066 008B Tune_wbt_GAS_338_ 
        {0x0F12, 0x0059,},	// 004C 0062 Tune_wbt_GAS_339_ 
        {0x0F12, 0x003A,},	// 0032 003F Tune_wbt_GAS_340_ 
        {0x0F12, 0x0023,},	// 001E 0023 Tune_wbt_GAS_341_ 
        {0x0F12, 0x0012,},	// 0010 0010 Tune_wbt_GAS_342_ 
        {0x0F12, 0x0008,},	// 000A 0004 Tune_wbt_GAS_343_ 
        {0x0F12, 0x0004,},	// 0007 0000 Tune_wbt_GAS_344_ 
        {0x0F12, 0x0007,},	// 000B 0003 Tune_wbt_GAS_345_ 
        {0x0F12, 0x000F,},	// 0010 000E Tune_wbt_GAS_346_ 
        {0x0F12, 0x001F,},	// 001E 0022 Tune_wbt_GAS_347_ 
        {0x0F12, 0x0035,},	// 0032 0041 Tune_wbt_GAS_348_ 
        {0x0F12, 0x0051,},	// 004B 006E Tune_wbt_GAS_349_ 
        {0x0F12, 0x0072,},	// 006B 00A4 Tune_wbt_GAS_350_ 
        {0x0F12, 0x0073,},	// 0061 008E Tune_wbt_GAS_351_ 
        {0x0F12, 0x0053,},	// 0049 0065 Tune_wbt_GAS_352_ 
        {0x0F12, 0x0034,},	// 002F 0040 Tune_wbt_GAS_353_ 
        {0x0F12, 0x001D,},	// 001B 0025 Tune_wbt_GAS_354_ 
        {0x0F12, 0x000E,},	// 000E 0013 Tune_wbt_GAS_355_ 
        {0x0F12, 0x0004,},	// 0008 0006 Tune_wbt_GAS_356_ 
        {0x0F12, 0x0000,},	// 0004 0001 Tune_wbt_GAS_357_ 
        {0x0F12, 0x0002,},	// 0008 0005 Tune_wbt_GAS_358_ 
        {0x0F12, 0x000A,},	// 000D 0010 Tune_wbt_GAS_359_ 
        {0x0F12, 0x001A,},	// 001C 0025 Tune_wbt_GAS_360_ 
        {0x0F12, 0x002F,},	// 002F 0044 Tune_wbt_GAS_361_ 
        {0x0F12, 0x004A,},	// 0047 0074 Tune_wbt_GAS_362_ 
        {0x0F12, 0x006A,},	// 0067 00AA Tune_wbt_GAS_363_ 
        {0x0F12, 0x0077,},	// 005A 0097 Tune_wbt_GAS_364_ 
        {0x0F12, 0x0058,},	// 0043 006D Tune_wbt_GAS_365_ 
        {0x0F12, 0x0039,},	// 002B 0048 Tune_wbt_GAS_366_ 
        {0x0F12, 0x0022,},	// 0017 002D Tune_wbt_GAS_367_ 
        {0x0F12, 0x0012,},	// 0009 0019 Tune_wbt_GAS_368_ 
        {0x0F12, 0x0008,},	// 0004 000E Tune_wbt_GAS_369_ 
        {0x0F12, 0x0004,},	// 0002 0009 Tune_wbt_GAS_370_ 
        {0x0F12, 0x0007,},	// 0004 000C Tune_wbt_GAS_371_ 
        {0x0F12, 0x000F,},	// 0008 0018 Tune_wbt_GAS_372_ 
        {0x0F12, 0x001E,},	// 0016 002E Tune_wbt_GAS_373_ 
        {0x0F12, 0x0034,},	// 002A 004E Tune_wbt_GAS_374_ 
        {0x0F12, 0x004F,},	// 0042 007D Tune_wbt_GAS_375_ 
        {0x0F12, 0x006F,},	// 005F 00B5 Tune_wbt_GAS_376_ 
        {0x0F12, 0x0083,},	// 0066 00A6 Tune_wbt_GAS_377_ 
        {0x0F12, 0x0064,},	// 0050 007C Tune_wbt_GAS_378_ 
        {0x0F12, 0x0045,},	// 0035 0058 Tune_wbt_GAS_379_ 
        {0x0F12, 0x002E,},	// 0022 003E Tune_wbt_GAS_380_ 
        {0x0F12, 0x001D,},	// 0013 0029 Tune_wbt_GAS_381_ 
        {0x0F12, 0x0012,},	// 000A 001D Tune_wbt_GAS_382_ 
        {0x0F12, 0x000F,},	// 0008 0018 Tune_wbt_GAS_383_ 
        {0x0F12, 0x0011,},	// 000B 001B Tune_wbt_GAS_384_ 
        {0x0F12, 0x001A,},	// 0014 0028 Tune_wbt_GAS_385_ 
        {0x0F12, 0x002A,},	// 0021 003F Tune_wbt_GAS_386_ 
        {0x0F12, 0x003F,},	// 0035 0062 Tune_wbt_GAS_387_ 
        {0x0F12, 0x005B,},	// 004D 0093 Tune_wbt_GAS_388_ 
        {0x0F12, 0x007B,},	// 006E 00CC Tune_wbt_GAS_389_ 
        {0x0F12, 0x0087,},	// 006E 00B9 Tune_wbt_GAS_390_ 
        {0x0F12, 0x006A,},	// 0057 0094 Tune_wbt_GAS_391_ 
        {0x0F12, 0x004B,},	// 003E 0071 Tune_wbt_GAS_392_ 
        {0x0F12, 0x0036,},	// 002B 0052 Tune_wbt_GAS_393_ 
        {0x0F12, 0x0025,},	// 001C 003D Tune_wbt_GAS_394_ 
        {0x0F12, 0x0019,},	// 0013 0031 Tune_wbt_GAS_395_ 
        {0x0F12, 0x0015,},	// 0011 002D Tune_wbt_GAS_396_ 
        {0x0F12, 0x0017,},	// 0013 0031 Tune_wbt_GAS_397_ 
        {0x0F12, 0x0022,},	// 001D 0040 Tune_wbt_GAS_398_ 
        {0x0F12, 0x0031,},	// 002B 0058 Tune_wbt_GAS_399_ 
        {0x0F12, 0x0045,},	// 003D 007B Tune_wbt_GAS_400_ 
        {0x0F12, 0x0060,},	// 0057 00AE Tune_wbt_GAS_401_ 
        {0x0F12, 0x007D,},	// 0077 00EA Tune_wbt_GAS_402_ 
        {0x0F12, 0x0096,},	// 0072 00C2 Tune_wbt_GAS_403_ 
        {0x0F12, 0x007F,},	// 005F 00AE Tune_wbt_GAS_404_ 
        {0x0F12, 0x0061,},	// 0047 008E Tune_wbt_GAS_405_ 
        {0x0F12, 0x004B,},	// 0035 006F Tune_wbt_GAS_406_ 
        {0x0F12, 0x003B,},	// 0028 0059 Tune_wbt_GAS_407_ 
        {0x0F12, 0x002F,},	// 0020 004E Tune_wbt_GAS_408_ 
        {0x0F12, 0x002A,},	// 001D 0049 Tune_wbt_GAS_409_ 
        {0x0F12, 0x002D,},	// 0020 004F Tune_wbt_GAS_410_ 
        {0x0F12, 0x0036,},	// 0029 005E Tune_wbt_GAS_411_ 
        {0x0F12, 0x0046,},	// 0035 007A Tune_wbt_GAS_412_ 
        {0x0F12, 0x005B,},	// 0047 009F Tune_wbt_GAS_413_ 
        {0x0F12, 0x0075,},	// 0060 00D5 Tune_wbt_GAS_414_ 
        {0x0F12, 0x008D,},	// 007D 010C Tune_wbt_GAS_415_ 
        {0x0F12, 0x00A1,},	// 0084 00E5 Tune_wbt_GAS_416_ 
        {0x0F12, 0x0091,},	// 0072 00C8 Tune_wbt_GAS_417_ 
        {0x0F12, 0x0077,},	// 005B 00B0 Tune_wbt_GAS_418_ 
        {0x0F12, 0x0060,},	// 0046 0091 Tune_wbt_GAS_419_ 
        {0x0F12, 0x0050,},	// 003A 007D Tune_wbt_GAS_420_ 
        {0x0F12, 0x0044,},	// 0031 0070 Tune_wbt_GAS_421_ 
        {0x0F12, 0x0040,},	// 002E 006D Tune_wbt_GAS_422_ 
        {0x0F12, 0x0043,},	// 0032 0074 Tune_wbt_GAS_423_ 
        {0x0F12, 0x004C,},	// 0039 0086 Tune_wbt_GAS_424_ 
        {0x0F12, 0x005A,},	// 0046 00A4 Tune_wbt_GAS_425_ 
        {0x0F12, 0x006D,},	// 0056 00CA Tune_wbt_GAS_426_ 
        {0x0F12, 0x0084,},	// 006E 00FE Tune_wbt_GAS_427_ 
        {0x0F12, 0x0094,},	// 0087 0134 Tune_wbt_GAS_428_ 
        {0x0F12, 0x0072,},	// 004C 009F Tune_wbt_GAS_429_ 
        {0x0F12, 0x0063,},	// 004C 0089 Tune_wbt_GAS_430_ 
        {0x0F12, 0x004C,},	// 0041 0067 Tune_wbt_GAS_431_ 
        {0x0F12, 0x003A,},	// 002F 004E Tune_wbt_GAS_432_ 
        {0x0F12, 0x002D,},	// 0024 003E Tune_wbt_GAS_433_ 
        {0x0F12, 0x0025,},	// 001D 0033 Tune_wbt_GAS_434_ 
        {0x0F12, 0x0023,},	// 001B 0031 Tune_wbt_GAS_435_ 
        {0x0F12, 0x0025,},	// 001E 0036 Tune_wbt_GAS_436_ 
        {0x0F12, 0x002C,},	// 0024 0045 Tune_wbt_GAS_437_ 
        {0x0F12, 0x0038,},	// 0032 0058 Tune_wbt_GAS_438_ 
        {0x0F12, 0x004A,},	// 0037 0074 Tune_wbt_GAS_439_ 
        {0x0F12, 0x005F,},	// 0038 00A0 Tune_wbt_GAS_440_ 
        {0x0F12, 0x006B,},	// 004C 00C9 Tune_wbt_GAS_441_ 
        {0x0F12, 0x0079,},	// 005B 0098 Tune_wbt_GAS_442_ 
        {0x0F12, 0x0065,},	// 0056 0077 Tune_wbt_GAS_443_ 
        {0x0F12, 0x004A,},	// 0041 0055 Tune_wbt_GAS_444_ 
        {0x0F12, 0x0037,},	// 0030 003C Tune_wbt_GAS_445_ 
        {0x0F12, 0x0029,},	// 0026 002A Tune_wbt_GAS_446_ 
        {0x0F12, 0x0021,},	// 001F 0022 Tune_wbt_GAS_447_ 
        {0x0F12, 0x001D,},	// 001C 001F Tune_wbt_GAS_448_ 
        {0x0F12, 0x001F,},	// 001F 0024 Tune_wbt_GAS_449_ 
        {0x0F12, 0x0027,},	// 0027 0030 Tune_wbt_GAS_450_ 
        {0x0F12, 0x0033,},	// 0033 0044 Tune_wbt_GAS_451_ 
        {0x0F12, 0x0044,},	// 003C 0060 Tune_wbt_GAS_452_ 
        {0x0F12, 0x005E,},	// 0041 008B Tune_wbt_GAS_453_ 
        {0x0F12, 0x006E,},	// 0060 00B2 Tune_wbt_GAS_454_ 
        {0x0F12, 0x006A,},	// 005E 0088 Tune_wbt_GAS_455_ 
        {0x0F12, 0x0055,},	// 004F 0065 Tune_wbt_GAS_456_ 
        {0x0F12, 0x003A,},	// 003A 0044 Tune_wbt_GAS_457_ 
        {0x0F12, 0x0028,},	// 002A 002C Tune_wbt_GAS_458_ 
        {0x0F12, 0x001A,},	// 001D 001B Tune_wbt_GAS_459_ 
        {0x0F12, 0x0011,},	// 0016 0012 Tune_wbt_GAS_460_ 
        {0x0F12, 0x000D,},	// 0014 000F Tune_wbt_GAS_461_ 
        {0x0F12, 0x000F,},	// 0016 0013 Tune_wbt_GAS_462_ 
        {0x0F12, 0x0017,},	// 0021 001E Tune_wbt_GAS_463_ 
        {0x0F12, 0x0024,},	// 002D 0032 Tune_wbt_GAS_464_ 
        {0x0F12, 0x0035,},	// 0038 004E Tune_wbt_GAS_465_ 
        {0x0F12, 0x004E,},	// 0040 0078 Tune_wbt_GAS_466_ 
        {0x0F12, 0x0061,},	// 0066 00A2 Tune_wbt_GAS_467_ 
        {0x0F12, 0x0061,},	// 004A 007F Tune_wbt_GAS_468_ 
        {0x0F12, 0x004A,},	// 003C 005B Tune_wbt_GAS_469_ 
        {0x0F12, 0x0031,},	// 0028 0039 Tune_wbt_GAS_470_ 
        {0x0F12, 0x001E,},	// 0019 0021 Tune_wbt_GAS_471_ 
        {0x0F12, 0x0011,},	// 000D 0012 Tune_wbt_GAS_472_ 
        {0x0F12, 0x0008,},	// 0008 0007 Tune_wbt_GAS_473_ 
        {0x0F12, 0x0005,},	// 0007 0004 Tune_wbt_GAS_474_ 
        {0x0F12, 0x0007,},	// 0007 0006 Tune_wbt_GAS_475_ 
        {0x0F12, 0x000E,},	// 000F 0012 Tune_wbt_GAS_476_ 
        {0x0F12, 0x001B,},	// 001C 0024 Tune_wbt_GAS_477_ 
        {0x0F12, 0x002D,},	// 002C 0041 Tune_wbt_GAS_478_ 
        {0x0F12, 0x0045,},	// 0042 006A Tune_wbt_GAS_479_ 
        {0x0F12, 0x0059,},	// 0054 0092 Tune_wbt_GAS_480_ 
        {0x0F12, 0x0062,},	// 004B 007B Tune_wbt_GAS_481_ 
        {0x0F12, 0x004B,},	// 003C 0057 Tune_wbt_GAS_482_ 
        {0x0F12, 0x0031,},	// 0027 0036 Tune_wbt_GAS_483_ 
        {0x0F12, 0x001E,},	// 0017 001E Tune_wbt_GAS_484_ 
        {0x0F12, 0x0010,},	// 000C 000F Tune_wbt_GAS_485_ 
        {0x0F12, 0x0008,},	// 0007 0003 Tune_wbt_GAS_486_ 
        {0x0F12, 0x0004,},	// 0006 0000 Tune_wbt_GAS_487_ 
        {0x0F12, 0x0006,},	// 0008 0002 Tune_wbt_GAS_488_ 
        {0x0F12, 0x000E,},	// 000D 000D Tune_wbt_GAS_489_ 
        {0x0F12, 0x001B,},	// 001A 0020 Tune_wbt_GAS_490_ 
        {0x0F12, 0x002E,},	// 002B 003C Tune_wbt_GAS_491_ 
        {0x0F12, 0x0046,},	// 0041 0067 Tune_wbt_GAS_492_ 
        {0x0F12, 0x005A,},	// 0054 008D Tune_wbt_GAS_493_ 
        {0x0F12, 0x005B,},	// 0049 007E Tune_wbt_GAS_494_ 
        {0x0F12, 0x0045,},	// 003A 005A Tune_wbt_GAS_495_ 
        {0x0F12, 0x002C,},	// 0025 0038 Tune_wbt_GAS_496_ 
        {0x0F12, 0x001A,},	// 0015 0022 Tune_wbt_GAS_497_ 
        {0x0F12, 0x000C,},	// 000A 0013 Tune_wbt_GAS_498_ 
        {0x0F12, 0x0003,},	// 0005 0006 Tune_wbt_GAS_499_ 
        {0x0F12, 0x0000,},	// 0003 0001 Tune_wbt_GAS_500_ 
        {0x0F12, 0x0002,},	// 0006 0004 Tune_wbt_GAS_501_ 
        {0x0F12, 0x0009,},	// 000B 000F Tune_wbt_GAS_502_ 
        {0x0F12, 0x0016,},	// 0018 0023 Tune_wbt_GAS_503_ 
        {0x0F12, 0x0029,},	// 0029 003E Tune_wbt_GAS_504_ 
        {0x0F12, 0x0040,},	// 003E 006A Tune_wbt_GAS_505_ 
        {0x0F12, 0x0054,},	// 0050 0091 Tune_wbt_GAS_506_ 
        {0x0F12, 0x005F,},	// 0044 0085 Tune_wbt_GAS_507_ 
        {0x0F12, 0x004A,},	// 0033 0060 Tune_wbt_GAS_508_ 
        {0x0F12, 0x0031,},	// 0021 0041 Tune_wbt_GAS_509_ 
        {0x0F12, 0x001F,},	// 0011 002A Tune_wbt_GAS_510_ 
        {0x0F12, 0x0010,},	// 0005 0019 Tune_wbt_GAS_511_ 
        {0x0F12, 0x0008,},	// 0002 000D Tune_wbt_GAS_512_ 
        {0x0F12, 0x0004,},	// 0001 0008 Tune_wbt_GAS_513_ 
        {0x0F12, 0x0007,},	// 0003 000A Tune_wbt_GAS_514_ 
        {0x0F12, 0x000E,},	// 0008 0016 Tune_wbt_GAS_515_ 
        {0x0F12, 0x001B,},	// 0014 002A Tune_wbt_GAS_516_ 
        {0x0F12, 0x002E,},	// 0025 0047 Tune_wbt_GAS_517_ 
        {0x0F12, 0x0045,},	// 0039 0074 Tune_wbt_GAS_518_ 
        {0x0F12, 0x0059,},	// 004D 009A Tune_wbt_GAS_519_ 
        {0x0F12, 0x006C,},	// 0050 0097 Tune_wbt_GAS_520_ 
        {0x0F12, 0x0057,},	// 0041 0070 Tune_wbt_GAS_521_ 
        {0x0F12, 0x003E,},	// 002C 0052 Tune_wbt_GAS_522_ 
        {0x0F12, 0x002A,},	// 001C 003C Tune_wbt_GAS_523_ 
        {0x0F12, 0x001B,},	// 0011 0028 Tune_wbt_GAS_524_ 
        {0x0F12, 0x0012,},	// 0009 001D Tune_wbt_GAS_525_ 
        {0x0F12, 0x000F,},	// 0008 0019 Tune_wbt_GAS_526_ 
        {0x0F12, 0x0011,},	// 000A 001A Tune_wbt_GAS_527_ 
        {0x0F12, 0x0019,},	// 0012 0026 Tune_wbt_GAS_528_ 
        {0x0F12, 0x0027,},	// 001F 003B Tune_wbt_GAS_529_ 
        {0x0F12, 0x0039,},	// 002F 005A Tune_wbt_GAS_530_ 
        {0x0F12, 0x0050,},	// 0045 0089 Tune_wbt_GAS_531_ 
        {0x0F12, 0x0063,},	// 005A 00AF Tune_wbt_GAS_532_ 
        {0x0F12, 0x006F,},	// 0056 00A7 Tune_wbt_GAS_533_ 
        {0x0F12, 0x005C,},	// 0048 0088 Tune_wbt_GAS_534_ 
        {0x0F12, 0x0044,},	// 0035 006B Tune_wbt_GAS_535_ 
        {0x0F12, 0x0031,},	// 0026 0050 Tune_wbt_GAS_536_ 
        {0x0F12, 0x0023,},	// 0019 003D Tune_wbt_GAS_537_ 
        {0x0F12, 0x0019,},	// 0012 0032 Tune_wbt_GAS_538_ 
        {0x0F12, 0x0016,},	// 0011 002E Tune_wbt_GAS_539_ 
        {0x0F12, 0x0017,},	// 0012 0030 Tune_wbt_GAS_540_ 
        {0x0F12, 0x0020,},	// 001B 003E Tune_wbt_GAS_541_ 
        {0x0F12, 0x002E,},	// 0027 0052 Tune_wbt_GAS_542_ 
        {0x0F12, 0x0040,},	// 0037 0073 Tune_wbt_GAS_543_ 
        {0x0F12, 0x0055,},	// 004C 00A1 Tune_wbt_GAS_544_ 
        {0x0F12, 0x0064,},	// 0060 00C7 Tune_wbt_GAS_545_ 
        {0x0F12, 0x007E,},	// 0058 00AE Tune_wbt_GAS_546_ 
        {0x0F12, 0x0071,},	// 0050 00A4 Tune_wbt_GAS_547_ 
        {0x0F12, 0x0059,},	// 003D 0088 Tune_wbt_GAS_548_ 
        {0x0F12, 0x0046,},	// 002E 006D Tune_wbt_GAS_549_ 
        {0x0F12, 0x0039,},	// 0023 0059 Tune_wbt_GAS_550_ 
        {0x0F12, 0x002F,},	// 001C 004D Tune_wbt_GAS_551_ 
        {0x0F12, 0x002A,},	// 001B 0049 Tune_wbt_GAS_552_ 
        {0x0F12, 0x002D,},	// 001D 004E Tune_wbt_GAS_553_ 
        {0x0F12, 0x0035,},	// 0024 005B Tune_wbt_GAS_554_ 
        {0x0F12, 0x0043,},	// 002F 0073 Tune_wbt_GAS_555_ 
        {0x0F12, 0x0054,},	// 003E 0095 Tune_wbt_GAS_556_ 
        {0x0F12, 0x0069,},	// 0052 00C4 Tune_wbt_GAS_557_ 
        {0x0F12, 0x0074,},	// 0062 00E9 Tune_wbt_GAS_558_ 
        {0x0F12, 0x0083,},	// 0060 00D5 Tune_wbt_GAS_559_ 
        {0x0F12, 0x007D,},	// 0057 00C1 Tune_wbt_GAS_560_ 
        {0x0F12, 0x0068,},	// 0048 00AB Tune_wbt_GAS_561_ 
        {0x0F12, 0x0055,},	// 0039 008D Tune_wbt_GAS_562_ 
        {0x0F12, 0x0048,},	// 002E 0079 Tune_wbt_GAS_563_ 
        {0x0F12, 0x003E,},	// 0028 0070 Tune_wbt_GAS_564_ 
        {0x0F12, 0x003A,},	// 0027 006A Tune_wbt_GAS_565_ 
        {0x0F12, 0x003D,},	// 0029 006F Tune_wbt_GAS_566_ 
        {0x0F12, 0x0045,},	// 002F 0080 Tune_wbt_GAS_567_ 
        {0x0F12, 0x0051,},	// 0039 0096 Tune_wbt_GAS_568_ 
        {0x0F12, 0x0061,},	// 0047 00B9 Tune_wbt_GAS_569_ 
        {0x0F12, 0x0072,},	// 0059 00E2 Tune_wbt_GAS_570_ 
        {0x0F12, 0x0077,},	// 0067 010F Tune_wbt_GAS_571_ 
        {0x002A, 0x1348,},
        {0x0F12, 0x0001,},	// gisp_gras_Enable 

//==================================================================================
// 07. Analog Setting 2 
//==================================================================================   
//This register is for FACTORY ONLY. 
//If you change it without prior notification
//YOU are RESPONSIBLE for the FAILURE that will happen in the future      
        {0x002A, 0x1278,},
        {0x0F12, 0xAAF0,},	//gisp_dadlc_config //Ladlc mode average
        {0x002A, 0x3370,},
        {0x0F12, 0x0000,},	//afit_bUseNormBrForAfit //0:Noise Index, 1:Normal Brightness

//*************************************/
// 08.AF Setting                      */
//*************************************/

//*************************************/
// 09.AWB-BASIC setting               */
//*************************************/

// For WB Calibration */
        {0x002A, 0x0B36,},
        {0x0F12, 0x0005,},// awbb_IndoorGrZones_ZInfo_m_GridStep */
        {0x002A, 0x0B3A,},
        {0x0F12, 0x00F3,},// awbb_IndoorGrZones_ZInfo_m_BMin */
        {0x0F12, 0x02CB,},// awbb_IndoorGrZones_ZInfo_m_BMax */
        {0x002A, 0x0B38,},
        {0x0F12, 0x0010,},// awbb_IndoorGrZones_ZInfo_m_GridSz */
        {0x002A, 0x0AE6,},
        {0x0F12, 0x0385,},// 0352 03E1 awbb_IndoorGrZones_m_BGrid_0__m_left   */
        {0x0F12, 0x03D8,},// 038C 0413 awbb_IndoorGrZones_m_BGrid_0__m_right  */
        {0x0F12, 0x032A,},// 0321 039E awbb_IndoorGrZones_m_BGrid_1__m_left   */
        {0x0F12, 0x03C5,},// 03A6 0416 awbb_IndoorGrZones_m_BGrid_1__m_right  */
        {0x0F12, 0x02F5,},// 02EC 0367 awbb_IndoorGrZones_m_BGrid_2__m_left   */
        {0x0F12, 0x039D,},// 03A0 03F3 awbb_IndoorGrZones_m_BGrid_2__m_right  */
        {0x0F12, 0x02D3,},// 02CA 032D awbb_IndoorGrZones_m_BGrid_3__m_left   */
        {0x0F12, 0x0372,},// 038D 03C5 awbb_IndoorGrZones_m_BGrid_3__m_right  */
        {0x0F12, 0x02B1,},// 02A8 02FD awbb_IndoorGrZones_m_BGrid_4__m_left   */
        {0x0F12, 0x033E,},// 036E 038F awbb_IndoorGrZones_m_BGrid_4__m_right  */
        {0x0F12, 0x028A,},// 0281 02D3 awbb_IndoorGrZones_m_BGrid_5__m_left   */
        {0x0F12, 0x0322,},// 0344 0365 awbb_IndoorGrZones_m_BGrid_5__m_right  */
        {0x0F12, 0x0268,},// 025F 02AA awbb_IndoorGrZones_m_BGrid_6__m_left   */
        {0x0F12, 0x02FD,},// 0327 033E awbb_IndoorGrZones_m_BGrid_6__m_right  */
        {0x0F12, 0x0248,},// 023F 028D awbb_IndoorGrZones_m_BGrid_7__m_left   */
        {0x0F12, 0x02EF,},// 0302 0310 awbb_IndoorGrZones_m_BGrid_7__m_right  */
        {0x0F12, 0x022F,},// 0226 0271 awbb_IndoorGrZones_m_BGrid_8__m_left   */
        {0x0F12, 0x02D5,},// 02DC 02F1 awbb_IndoorGrZones_m_BGrid_8__m_right  */
        {0x0F12, 0x0219,},// 0210 025A awbb_IndoorGrZones_m_BGrid_9__m_left   */
        {0x0F12, 0x02C2,},// 02B9 02D2 awbb_IndoorGrZones_m_BGrid_9__m_right  */
        {0x0F12, 0x0206,},// 01FD 0249 awbb_IndoorGrZones_m_BGrid_10__m_left  */
        {0x0F12, 0x02A3,},// 029A 02B9 awbb_IndoorGrZones_m_BGrid_10__m_right */
        {0x0F12, 0x01F0,},// 01E7 0238 awbb_IndoorGrZones_m_BGrid_11__m_left  */
        {0x0F12, 0x0286,},// 027D 02A2 awbb_IndoorGrZones_m_BGrid_11__m_right */
        {0x0F12, 0x01E3,},// 01DA 021B awbb_IndoorGrZones_m_BGrid_12__m_left  */
        {0x0F12, 0x0268,},// 025F 0289 awbb_IndoorGrZones_m_BGrid_12__m_right */
        {0x0F12, 0x01D6,},// 01CD 0200 awbb_IndoorGrZones_m_BGrid_13__m_left  */
        {0x0F12, 0x024E,},// 0245 026C awbb_IndoorGrZones_m_BGrid_13__m_right */
        {0x0F12, 0x01DD,},// 01D4 01FC awbb_IndoorGrZones_m_BGrid_14__m_left  */
        {0x0F12, 0x022A,},// 0221 024F awbb_IndoorGrZones_m_BGrid_14__m_right */
        {0x0F12, 0x0210,},// 0207 021E awbb_IndoorGrZones_m_BGrid_15__m_left  */
        {0x0F12, 0x01F2,},// 01E9 022C awbb_IndoorGrZones_m_BGrid_15__m_right */
        {0x0F12, 0x0000,},// 0000 0000 awbb_IndoorGrZones_m_BGrid_16__m_left  */
        {0x0F12, 0x0000,},// 0000 0000 awbb_IndoorGrZones_m_BGrid_16__m_right */
        {0x0F12, 0x0000,},// 0000 0000 awbb_IndoorGrZones_m_BGrid_17__m_left  */
        {0x0F12, 0x0000,},// 0000 0000 awbb_IndoorGrZones_m_BGrid_17__m_right */
        {0x0F12, 0x0000,},// 0000 0000 awbb_IndoorGrZones_m_BGrid_18__m_left  */
        {0x0F12, 0x0000,},// 0000 0000 awbb_IndoorGrZones_m_BGrid_18__m_right */
        {0x0F12, 0x0000,},// 0000 0000 awbb_IndoorGrZones_m_BGrid_19__m_left  */
        {0x0F12, 0x0000,},// 0000 0000 awbb_IndoorGrZones_m_BGrid_19__m_right */

        {0x002A, 0x0BAA,},
        {0x0F12, 0x0006,},// awbb_LowBrGrZones_ZInfo_m_GridStep */
        {0x002A, 0x0BAE,},
        {0x0F12, 0x00CC,},// 010E awbb_LowBrGrZones_ZInfo_m_BMin */
        {0x0F12, 0x02F3,},// 02E9 awbb_LowBrGrZones_ZInfo_m_BMax */
        {0x002A, 0x0BAC,},
        {0x0F12, 0x000A,},// 0009 awbb_LowBrGrZones_ZInfo_m_GridSz */
        {0x002A, 0x0B7A,},
        {0x0F12, 0x036C,},// 0374 038C awbb_LowBrGrZones_m_BGrid_0__m_left   */
        {0x0F12, 0x03C6,},// 03CE 03DA awbb_LowBrGrZones_m_BGrid_0__m_right  */
        {0x0F12, 0x02EE,},// 02F6 030E awbb_LowBrGrZones_m_BGrid_1__m_left   */
        {0x0F12, 0x03F9,},// 0401 03E9 awbb_LowBrGrZones_m_BGrid_1__m_right  */
        {0x0F12, 0x02BE,},// 02C6 02A2 awbb_LowBrGrZones_m_BGrid_2__m_left   */
        {0x0F12, 0x03DF,},// 03E7 03C2 awbb_LowBrGrZones_m_BGrid_2__m_right  */
        {0x0F12, 0x027A,},// 0282 0259 awbb_LowBrGrZones_m_BGrid_3__m_left   */
        {0x0F12, 0x03AE,},// 03B6 038A awbb_LowBrGrZones_m_BGrid_3__m_right  */
        {0x0F12, 0x0234,},// 023C 0218 awbb_LowBrGrZones_m_BGrid_4__m_left   */
        {0x0F12, 0x0376,},// 037E 0352 awbb_LowBrGrZones_m_BGrid_4__m_right  */
        {0x0F12, 0x0204,},// 020C 01F4 awbb_LowBrGrZones_m_BGrid_5__m_left   */
        {0x0F12, 0x033E,},// 0346 02E1 awbb_LowBrGrZones_m_BGrid_5__m_right  */
        {0x0F12, 0x01E0,},// 01E8 01D7 awbb_LowBrGrZones_m_BGrid_6__m_left   */
        {0x0F12, 0x02CD,},// 02D5 028E awbb_LowBrGrZones_m_BGrid_6__m_right  */
        {0x0F12, 0x01C3,},// 01CB 01CB awbb_LowBrGrZones_m_BGrid_7__m_left   */
        {0x0F12, 0x027A,},// 0282 0258 awbb_LowBrGrZones_m_BGrid_7__m_right  */
        {0x0F12, 0x01B7,},// 01BF 022B awbb_LowBrGrZones_m_BGrid_8__m_left   */
        {0x0F12, 0x0244,},// 024C 01CC awbb_LowBrGrZones_m_BGrid_8__m_right  */
        {0x0F12, 0x01FE,},// 01F8 0000 awbb_LowBrGrZones_m_BGrid_9__m_left   */
        {0x0F12, 0x01DD,},// 0201 0000 awbb_LowBrGrZones_m_BGrid_9__m_right  */
        {0x0F12, 0x0000,},// 0000 0000 awbb_LowBrGrZones_m_BGrid_10__m_left  */
        {0x0F12, 0x0000,},// 0000 0000 awbb_LowBrGrZones_m_BGrid_10__m_right */
        {0x0F12, 0x0000,},// 0000 0000 awbb_LowBrGrZones_m_BGrid_11__m_left  */
        {0x0F12, 0x0000,},// 0000 0000 awbb_LowBrGrZones_m_BGrid_11__m_right */
        {0x002A, 0x0B70,},
        {0x0F12, 0x0005,},// awbb_OutdoorGrZones_ZInfo_m_GridStep */
        {0x002A, 0x0B74,},
        {0x0F12, 0x01E3,},// awbb_OutdoorGrZones_ZInfo_m_BMin */
        {0x0F12, 0x0270,},// awbb_OutdoorGrZones_ZInfo_m_BMax */
        {0x002A, 0x0B72,},
        {0x0F12, 0x0006,},// awbb_OutdoorGrZones_ZInfo_m_GridSz */
        {0x002A, 0x0B40,},
        {0x0F12, 0x028A,},// 029E awbb_OutdoorGrZones_m_BGrid_0__m_left   */
        {0x0F12, 0x02A1,},// 02C8 awbb_OutdoorGrZones_m_BGrid_0__m_right  */
        {0x0F12, 0x0263,},// 0281 awbb_OutdoorGrZones_m_BGrid_1__m_left   */
        {0x0F12, 0x02C0,},// 02C8 awbb_OutdoorGrZones_m_BGrid_1__m_right  */
        {0x0F12, 0x024C,},// 0266 awbb_OutdoorGrZones_m_BGrid_2__m_left   */
        {0x0F12, 0x02BE,},// 02AC awbb_OutdoorGrZones_m_BGrid_2__m_right  */
        {0x0F12, 0x023D,},// 0251 awbb_OutdoorGrZones_m_BGrid_3__m_left   */
        {0x0F12, 0x02A6,},// 028E awbb_OutdoorGrZones_m_BGrid_3__m_right  */
        {0x0F12, 0x0243,},// 023D awbb_OutdoorGrZones_m_BGrid_4__m_left   */
        {0x0F12, 0x0289,},// 0275 awbb_OutdoorGrZones_m_BGrid_4__m_right  */
        {0x0F12, 0x026F,},// 0228 awbb_OutdoorGrZones_m_BGrid_5__m_left   */
        {0x0F12, 0x025D,},// 025D awbb_OutdoorGrZones_m_BGrid_5__m_right  */
        {0x0F12, 0x0000,},// 0228 awbb_OutdoorGrZones_m_BGrid_6__m_left   */
        {0x0F12, 0x0000,},// 0243 awbb_OutdoorGrZones_m_BGrid_6__m_right  */
        {0x0F12, 0x0000,},// 0000 awbb_OutdoorGrZones_m_BGrid_7__m_left   */
        {0x0F12, 0x0000,},// 0000 awbb_OutdoorGrZones_m_BGrid_7__m_right  */
        {0x0F12, 0x0000,},// 0000 awbb_OutdoorGrZones_m_BGrid_8__m_left   */
        {0x0F12, 0x0000,},// 0000 awbb_OutdoorGrZones_m_BGrid_8__m_right  */
        {0x0F12, 0x0000,},// 0000 awbb_OutdoorGrZones_m_BGrid_9__m_left   */
        {0x0F12, 0x0000,},// 0000 awbb_OutdoorGrZones_m_BGrid_9__m_right  */
        {0x0F12, 0x0000,},// 0000 awbb_OutdoorGrZones_m_BGrid_10__m_left  */
        {0x0F12, 0x0000,},// 0000 awbb_OutdoorGrZones_m_BGrid_10__m_right */
        {0x0F12, 0x0000,},// 0000 awbb_OutdoorGrZones_m_BGrid_11__m_left  */
        {0x0F12, 0x0000,},// 0000 awbb_OutdoorGrZones_m_BGrid_11__m_right */
        {0x002A, 0x0BC8,},
        {0x0F12, 0x0005,},// awbb_CWSkinZone_ZInfo_m_GridStep */
        {0x002A, 0x0BCC,},
        {0x0F12, 0x010F,},// awbb_CWSkinZone_ZInfo_m_BMin */
        {0x0F12, 0x018F,},// awbb_CWSkinZone_ZInfo_m_BMax */
        {0x002A, 0x0BCA,},
        {0x0F12, 0x0005,},// awbb_CWSkinZone_ZInfo_m_GridSz */
        {0x002A, 0x0BB4,},
        {0x0F12, 0x03E7,},// awbb_CWSkinZone_m_BGrid_0__m_left  */
        {0x0F12, 0x03F8,},// awbb_CWSkinZone_m_BGrid_0__m_right */
        {0x0F12, 0x03A7,},// awbb_CWSkinZone_m_BGrid_1__m_left  */
        {0x0F12, 0x03FC,},// awbb_CWSkinZone_m_BGrid_1__m_right */
        {0x0F12, 0x0352,},// awbb_CWSkinZone_m_BGrid_2__m_left  */
        {0x0F12, 0x03D0,},// awbb_CWSkinZone_m_BGrid_2__m_right */
        {0x0F12, 0x0322,},// awbb_CWSkinZone_m_BGrid_3__m_left  */
        {0x0F12, 0x039E,},// awbb_CWSkinZone_m_BGrid_3__m_right */
        {0x0F12, 0x032B,},// awbb_CWSkinZone_m_BGrid_4__m_left  */
        {0x0F12, 0x034D,},// awbb_CWSkinZone_m_BGrid_4__m_right */
        {0x002A, 0x0BE6,},
        {0x0F12, 0x0006,},// awbb_DLSkinZone_ZInfo_m_GridStep */
        {0x002A, 0x0BEA,},
        {0x0F12, 0x019E,},// awbb_DLSkinZone_ZInfo_m_BMin */
        {0x0F12, 0x0257,},// awbb_DLSkinZone_ZInfo_m_BMax */
        {0x002A, 0x0BE8,},
        {0x0F12, 0x0004,},// awbb_DLSkinZone_ZInfo_m_GridSz */
        {0x002A, 0x0BD2,},
        {0x0F12, 0x030B,},// awbb_DLSkinZone_m_BGrid_0__m_left  */
        {0x0F12, 0x0323,},// awbb_DLSkinZone_m_BGrid_0__m_right */
        {0x0F12, 0x02C3,},// awbb_DLSkinZone_m_BGrid_1__m_left  */
        {0x0F12, 0x030F,},// awbb_DLSkinZone_m_BGrid_1__m_right */
        {0x0F12, 0x0288,},// awbb_DLSkinZone_m_BGrid_2__m_left  */
        {0x0F12, 0x02E5,},// awbb_DLSkinZone_m_BGrid_2__m_right */
        {0x0F12, 0x026A,},// awbb_DLSkinZone_m_BGrid_3__m_left  */
        {0x0F12, 0x02A2,},// awbb_DLSkinZone_m_BGrid_3__m_right */
        {0x0F12, 0x0000,},// awbb_DLSkinZone_m_BGrid_4__m_left  */
        {0x0F12, 0x0000,},// awbb_DLSkinZone_m_BGrid_4__m_right */
        {0x002A, 0x0C2C,},
        {0x0F12, 0x0139,},// awbb_IntcR */
        {0x0F12, 0x0122,},// awbb_IntcB */
        {0x002A, 0x0BFC,},
        {0x0F12, 0x0378,},// 03AD awbb_IndoorWP_0__r */
        {0x0F12, 0x011E,},// 013F awbb_IndoorWP_0__b */
        {0x0F12, 0x02F0,},// 0341 awbb_IndoorWP_1__r */
        {0x0F12, 0x0184,},// 017B awbb_IndoorWP_1__b */
        {0x0F12, 0x0313,},// 038D awbb_IndoorWP_2__r */
        {0x0F12, 0x0158,},// 014B awbb_IndoorWP_2__b */
        {0x0F12, 0x02BA,},// 02C3 awbb_IndoorWP_3__r */
        {0x0F12, 0x01BA,},// 01CC awbb_IndoorWP_3__b */
        {0x0F12, 0x0231,},// 0241 awbb_IndoorWP_4__r */
        {0x0F12, 0x0252,},// 027F awbb_IndoorWP_4__b */
        {0x0F12, 0x0237,},// 0241 awbb_IndoorWP_5__r */
        {0x0F12, 0x024C,},// 027F awbb_IndoorWP_5__b */
        {0x0F12, 0x020F,},// 0214 awbb_IndoorWP_6__r */
        {0x0F12, 0x0279,},// 02A8 awbb_IndoorWP_6__b */
        {0x0F12, 0x0268,},// 0270 255 awbb_OutdoorWP_r */
        {0x0F12, 0x021A,},// 0210 25B awbb_OutdoorWP_b */
        {0x002A, 0x0C4C,},
        {0x0F12, 0x0450,},// awbb_MvEq_RBthresh */
        {0x002A, 0x0C58,},
        {0x0F12, 0x059C,},// awbb_MvEq_RBthresh */
        {0x002A, 0x0BF8,},
        {0x0F12, 0x01AE,},// awbb_LowTSep_m_RminusB */
        {0x002A, 0x0C28,},
        {0x0F12, 0x0000,},// awbb_SkinPreference */
        {0x002A, 0x0CAC,},
        {0x0F12, 0x0050,},// awbb_OutDMaxIncr */
        {0x002A, 0x0C28,},
        {0x0F12, 0x0000,},// awbb_SkinPreference */ 

        {0x002A, 0x20BA,},
        {0x0F12, 0x0006,},// Lowtemp bypass */

        {0x002A, 0x0D0E,},
        {0x0F12, 0x00B8,},// awbb_GridCoeff_R_2 */
        {0x0F12, 0x00B2,},// awbb_GridCoeff_B_2 */
        {0x002A, 0x0CFE,},
        {0x0F12, 0x0FAB,},// 0FAB awbb_GridConst_2_0_ */
        {0x0F12, 0x0FF5,},// 0FF5 0FF5 awbb_GridConst_2_1_ */
        {0x0F12, 0x10BB,},// 10BB 10BB awbb_GridConst_2_2_ */
        {0x0F12, 0x1117,},// 1117 1123 1153 awbb_GridConst_2_3_ */
        {0x0F12, 0x116D,},// 116D 11C5 awbb_GridConst_2_4_ */
        {0x0F12, 0x11D5,},// 122A awbb_GridConst_2_5_ */
        {0x0F12, 0x00A9,},// awbb_GridCoeff_R_1 */
        {0x0F12, 0x00C0,},// awbb_GridCoeff_B_1 */
        {0x002A, 0x0CF8,},
        {0x0F12, 0x02CC,},// awbb_GridConst_1_0_ */
        {0x0F12, 0x031E,},// awbb_GridConst_1_1_ */
        {0x0F12, 0x0359,},// awbb_GridConst_1_2_ */

        {0x002A, 0x0CB0,},
        {0x0F12, 0x0030,},// 0000 awbb_GridCorr_R_0__0_ */
        {0x0F12, 0x0040,},// 0000 awbb_GridCorr_R_0__1_ */
        {0x0F12, 0x0060,},// 0078 awbb_GridCorr_R_0__2_ */
        {0x0F12, 0x0040,},// 00AA awbb_GridCorr_R_0__3_ */
        {0x0F12, 0x0008,},// 0000 awbb_GridCorr_R_0__4_ */
        {0x0F12, 0x0008,},// 0000 awbb_GridCorr_R_0__5_ */

        {0x0F12, 0x0030,},// 0000 awbb_GridCorr_R_1__0_ */
        {0x0F12, 0x0040,},// 0096 awbb_GridCorr_R_1__1_ */
        {0x0F12, 0x0060,},// 0000 awbb_GridCorr_R_1__2_ */
        {0x0F12, 0x0040,},// 0000 awbb_GridCorr_R_1__3_ */
        {0x0F12, 0x0008,},// 0000 awbb_GridCorr_R_1__4_ */
        {0x0F12, 0x0008,},// 0000 awbb_GridCorr_R_1__5_ */

        {0x0F12, 0x0030,},// 00E6 awbb_GridCorr_R_2__0_ */
        {0x0F12, 0x0040,},// 0000 awbb_GridCorr_R_2__1_ */
        {0x0F12, 0x0060,},// 0000 awbb_GridCorr_R_2__2_ */
        {0x0F12, 0x0040,},// 0000 awbb_GridCorr_R_2__3_ */
        {0x0F12, 0x0008,},// 0000 awbb_GridCorr_R_2__4_ */
        {0x0F12, 0x0008,},// 0000 awbb_GridCorr_R_2__5_ */

        {0x0F12, 0x0018,},// 0000 awbb_GridCorr_B_0__0_ */
        {0x0F12, 0x0000,},// 0000 awbb_GridCorr_B_0__1_ */
        {0x0F12, 0x0000,},// 0064 awbb_GridCorr_B_0__2_ */
        {0x0F12, 0x0000,},// 0000 awbb_GridCorr_B_0__3_ */
        {0x0F12, 0xFF80,},// 0000 awbb_GridCorr_B_0__4_ */
        {0x0F12, 0xFEC0,},// 0000 awbb_GridCorr_B_0__5_ */

        {0x0F12, 0x0018,},// 0000 awbb_GridCorr_B_1__0_ */
        {0x0F12, 0x0000,},// 0032 awbb_GridCorr_B_1__1_ */
        {0x0F12, 0x0000,},// 0000 awbb_GridCorr_B_1__2_ */
        {0x0F12, 0x0000,},// 0000 awbb_GridCorr_B_1__3_ */
        {0x0F12, 0xFF80,},// FF38 awbb_GridCorr_B_1__4_ */
        {0x0F12, 0xFEC0,},// 0000 awbb_GridCorr_B_1__5_ */

        {0x0F12, 0x0018,},// 0000 awbb_GridCorr_B_2__0_ */
        {0x0F12, 0x0000,},// 0032 awbb_GridCorr_B_2__1_ */
        {0x0F12, 0x0000,},// 0000 awbb_GridCorr_B_2__2_ */
        {0x0F12, 0x0000,},// 0000 awbb_GridCorr_B_2__3_ */
        {0x0F12, 0xFF80,},// 0000 awbb_GridCorr_B_2__4_ */
        {0x0F12, 0xFEC0,},// 0000 awbb_GridCorr_B_2__5_ */

        {0x002A, 0x0D30,},
        {0x0F12, 0x0002,},// awbb_GridEnable */

        {0x002A, 0x3372,},
        {0x0F12, 0x0001,},// awbb_bUseOutdoorGrid */
        {0x0F12, 0x0000,},// awbb_OutdoorGridCorr_R */
        {0x0F12, 0x0000,},// awbb_OutdoorGridCorr_B */

// For Outdoor Detector */
        {0x002A, 0x0C86,},
        {0x0F12, 0x0005,},// awbb_OutdoorDetectionZone_ZInfo_m_GridSz */
        {0x002A, 0x0C70,},
        {0x0F12, 0xFF7B,},// awbb_OutdoorDetectionZone_m_BGrid_0__m_left */
        {0x0F12, 0x00CE,},// awbb_OutdoorDetectionZone_m_BGrid_0__m_right */
        {0x0F12, 0xFF23,},// awbb_OutdoorDetectionZone_m_BGrid_1__m_left */
        {0x0F12, 0x010D,},// awbb_OutdoorDetectionZone_m_BGrid_1__m_right */
        {0x0F12, 0xFEF3,},// awbb_OutdoorDetectionZone_m_BGrid_2__m_left */
        {0x0F12, 0x012C,},// awbb_OutdoorDetectionZone_m_BGrid_2__m_right */
        {0x0F12, 0xFED7,},// awbb_OutdoorDetectionZone_m_BGrid_3__m_left */
        {0x0F12, 0x014E,},// awbb_OutdoorDetectionZone_m_BGrid_3__m_right */
        {0x0F12, 0xFEBB,},// awbb_OutdoorDetectionZone_m_BGrid_4__m_left */
        {0x0F12, 0x0162,},// awbb_OutdoorDetectionZone_m_BGrid_4__m_right */
        {0x0F12, 0x1388,},// awbb_OutdoorDetectionZone_ZInfo_m_AbsGridStep */
        {0x002A, 0x0C8A,},
        {0x0F12, 0x4ACB,},// awbb_OutdoorDetectionZone_ZInfo_m_MaxNB */
        {0x002A, 0x0C88,},
        {0x0F12, 0x0A7C,},// awbb_OutdoorDetectionZone_ZInfo_m_NBoffs */

        {0x002A, 0x0CA0,},
        {0x0F12, 0x0030,}, //awbb_GnCurPntImmunity

        {0x002A, 0x0CA4,},
        {0x0F12, 0x0030,}, //awbb_GnCurPntLongJump
        {0x0F12, 0x0180,}, //awbb_GainsMaxMove
        {0x0F12, 0x0002,}, //awbb_GnMinMatchToJump

//==================================================================================
// 10.Clock Setting
//==================================================================================
// Input Clock (Mclk) 
        {0x002A, 0x012E,},
        {0x0F12, 0x5DC0,},	// REG_TC_IPRM_InClockLSBs 
        {0x0F12, 0x0000,},	// REG_TC_IPRM_InClockMSBs 
        {0x002A, 0x0146,},
        {0x0F12, 0x0000,},	// REG_TC_IPRM_UseNPviClocks 
        {0x0F12, 0x0001,},	// REG_TC_IPRM_UseNMipiClocks

// System Clock & Output clock (Pclk)
        {0x002A, 0x014C,},
        {0x0F12, 0x2AF8,},	// REG_TC_IPRM_OpClk4KHz_0 
        {0x002A, 0x0152,},
        {0x0F12, 0x55F0,},	// REG_TC_IPRM_MinOutRate4KHz_0 
        {0x002A, 0x014E,},
        {0x0F12, 0x55F0,},	// REG_TC_IPRM_MaxOutRate4KHz_0 
        {0x0F12, 0x00FA,},

        {0x002A, 0x0164,},
        {0x0F12, 0x0001,},	// REG_TC_IPRM_InitParamsUpdated 

//*************************************/
// 11.Auto Flicker Detection          */
//*************************************/
        {0x0028, 0x7000,},
        {0x002A, 0x03F4,},
        {0x0F12, 0x0001,},//REG_SF_USER_FlickerQuant */
        {0x0F12, 0x0001,},//REG_SF_USER_FlickerQuantChanged */
        {0x002A, 0x0408,},
        {0x0F12, 0x067F,},//REG_TC_DBG_AutoAlgEnBits all AA are on */

//*************************************/
// 12.AE Setting                      */
//*************************************/

        {0x002A, 0x0D40,},
        {0x0F12, 0x0038,}, //TVAR_ae_BrAve */

// For LT Calibration */
        {0x002A, 0x0D46,},
        {0x0F12, 0x000F,},// ae_StatMode */

        {0x002A, 0x0440,},
        {0x0F12, 0x3410,},// lt_uMaxExp_0_ */
        {0x002A, 0x0444,},
        {0x0F12, 0x6820,},// lt_uMaxExp_1_ */
        {0x002A, 0x0448,},
        {0x0F12, 0x8227,},// lt_uMaxExp_2_ */
        {0x002A, 0x044C,},
        {0x0F12, 0xC350,},// lt_uMaxExp_3_ */
        {0x002A, 0x0450,},
        {0x0F12, 0x3410,},// lt_uCapMaxExp_0_ */
        {0x002A, 0x0454,},
        {0x0F12, 0x6820,},// lt_uCapMaxExp_1_ */
        {0x002A, 0x0458,},
        {0x0F12, 0x8227,},// lt_uCapMaxExp_2_ */
        {0x002A, 0x045C,},
        {0x0F12, 0xC350,},// lt_uCapMaxExp_3_ */
        {0x002A, 0x0460,},
        {0x0F12, 0x01B0,},// lt_uMaxAnGain_0_ */
        {0x0F12, 0x01B0,},// lt_uMaxAnGain_1_ */
        {0x0F12, 0x0280,},// lt_uMaxAnGain_2_ */
        {0x0F12, 0x0700,},// lt_uMaxAnGain_3_ */
        {0x0F12, 0x0100,},// B0 0100 lt_uMaxDigGain */
        {0x0F12, 0x3000,},// lt_uMaxTotGain */
        {0x002A, 0x042E,},
        {0x0F12, 0x012E,},// lt_uLimitHigh */
        {0x0F12, 0x00D5,},// lt_uLimitLow */
        {0x002A, 0x0DE0,},
        {0x0F12, 0x0002,},// ae_Fade2BlackEnable F2B off, F2W on */

// For Illum Type Calibration */
// WRITE #SARR_IllumType_0_  0078 */
// WRITE #SARR_IllumType_1_  00C3 */
// WRITE #SARR_IllumType_2_  00E9 */
// WRITE #SARR_IllumType_3_  0128 */
// WRITE #SARR_IllumType_4_  016F */
// WRITE #SARR_IllumType_5_  0195 */
// WRITE #SARR_IllumType_6_  01A4 */
// WRITE #SARR_IllumTypeF_0_  0100 */
// WRITE #SARR_IllumTypeF_1_  0100 */
// WRITE #SARR_IllumTypeF_2_  0110 */
// WRITE #SARR_IllumTypeF_3_  00E5 */
// WRITE #SARR_IllumTypeF_4_  0100 */
// WRITE #SARR_IllumTypeF_5_  00ED */
// WRITE #SARR_IllumTypeF_6_  00ED */

        {0x002A, 0x0D38,},// bp_uMaxBrightnessFactor */
        {0x0F12, 0x019C,},
        {0x002A, 0x0D3E,},// bp_uMinBrightnessFactor */
        {0x0F12, 0x02A0,},

//*********************************************************************************
// 13.AE Weight (Normal)                                                           
//*********************************************************************************
        {0x002A, 0x0D4E,},
        {0x0F12, 0x0100,}, //ae_WeightTbl_16_0_  
        {0x0F12, 0x0001,}, //ae_WeightTbl_16_1_  
        {0x0F12, 0x0100,}, //ae_WeightTbl_16_2_  
        {0x0F12, 0x0001,}, //ae_WeightTbl_16_3_  
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_4_  
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_5_  
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_6_  
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_7_  
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_8_  
        {0x0F12, 0x0201,}, //ae_WeightTbl_16_9_  
        {0x0F12, 0x0202,}, //ae_WeightTbl_16_10_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_11_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_12_ 
        {0x0F12, 0x0303,}, //ae_WeightTbl_16_13_ 
        {0x0F12, 0x0303,}, //ae_WeightTbl_16_14_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_15_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_16_ 
        {0x0F12, 0x0503,}, //ae_WeightTbl_16_17_ 
        {0x0F12, 0x0305,}, //ae_WeightTbl_16_18_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_19_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_20_ 
        {0x0F12, 0x0402,}, //ae_WeightTbl_16_21_ 
        {0x0F12, 0x0204,}, //ae_WeightTbl_16_22_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_23_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_24_ 
        {0x0F12, 0x0201,}, //ae_WeightTbl_16_25_ 
        {0x0F12, 0x0102,}, //ae_WeightTbl_16_26_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_27_ 
        {0x0F12, 0x0100,}, //ae_WeightTbl_16_28_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_29_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_30_ 
        {0x0F12, 0x0001,}, //ae_WeightTbl_16_31_ 

//*************************************/
// 14.Flash Setting                   */
//*************************************/

//*************************************/
// 15.CCM Setting                     */
//*************************************/

        {0x002A, 0x33A4,},
        {0x0F12, 0x01D0,},//01D0// Tune_wbt_BaseCcms_0__0_  */
        {0x0F12, 0xFFA1,},//FFA1// Tune_wbt_BaseCcms_0__1_  */
        {0x0F12, 0xFFFA,},//FFFA// Tune_wbt_BaseCcms_0__2_  */
        {0x0F12, 0xFF6F,},//FF6F// Tune_wbt_BaseCcms_0__3_  */
        {0x0F12, 0x0140,},//0140// Tune_wbt_BaseCcms_0__4_  */
        {0x0F12, 0xFF49,},//FF49// Tune_wbt_BaseCcms_0__5_  */
        {0x0F12, 0xFFC1,},//FFC1// Tune_wbt_BaseCcms_0__6_  */
        {0x0F12, 0x001F,},//001F// Tune_wbt_BaseCcms_0__7_  */
        {0x0F12, 0x01BD,},//01BD// Tune_wbt_BaseCcms_0__8_  */
        {0x0F12, 0x013F,},//013F// Tune_wbt_BaseCcms_0__9_  */
        {0x0F12, 0x00E1,},//00E1// Tune_wbt_BaseCcms_0__10_ */
        {0x0F12, 0xFF43,},//FF43// Tune_wbt_BaseCcms_0__11_ */
        {0x0F12, 0x0191,},//0191// Tune_wbt_BaseCcms_0__12_ */
        {0x0F12, 0xFFC0,},//FFC0// Tune_wbt_BaseCcms_0__13_ */
        {0x0F12, 0x01B7,},//01B7// Tune_wbt_BaseCcms_0__14_ */
        {0x0F12, 0xFF30,},//FF30// Tune_wbt_BaseCcms_0__15_ */
        {0x0F12, 0x015F,},//015F// Tune_wbt_BaseCcms_0__16_ */
        {0x0F12, 0x0106,},//0106// Tune_wbt_BaseCcms_0__17_ */
        {0x0F12, 0x01D0,},//01D0// Tune_wbt_BaseCcms_1__0_  */
        {0x0F12, 0xFFA1,},//FFA1// Tune_wbt_BaseCcms_1__1_  */
        {0x0F12, 0xFFFA,},//FFFA// Tune_wbt_BaseCcms_1__2_  */
        {0x0F12, 0xFF6F,},//FF6F// Tune_wbt_BaseCcms_1__3_  */
        {0x0F12, 0x0140,},//0140// Tune_wbt_BaseCcms_1__4_  */
        {0x0F12, 0xFF49,},//FF49// Tune_wbt_BaseCcms_1__5_  */
        {0x0F12, 0xFFC1,},//FFC1// Tune_wbt_BaseCcms_1__6_  */
        {0x0F12, 0x001F,},//001F// Tune_wbt_BaseCcms_1__7_  */
        {0x0F12, 0x01BD,},//01BD// Tune_wbt_BaseCcms_1__8_  */
        {0x0F12, 0x013F,},//013F// Tune_wbt_BaseCcms_1__9_  */
        {0x0F12, 0x00E1,},//00E1// Tune_wbt_BaseCcms_1__10_ */
        {0x0F12, 0xFF43,},//FF43// Tune_wbt_BaseCcms_1__11_ */
        {0x0F12, 0x0191,},//0191// Tune_wbt_BaseCcms_1__12_ */
        {0x0F12, 0xFFC0,},//FFC0// Tune_wbt_BaseCcms_1__13_ */
        {0x0F12, 0x01B7,},//01B7// Tune_wbt_BaseCcms_1__14_ */
        {0x0F12, 0xFF30,},//FF30// Tune_wbt_BaseCcms_1__15_ */
        {0x0F12, 0x015F,},//015F// Tune_wbt_BaseCcms_1__16_ */
        {0x0F12, 0x0106,},//0106// Tune_wbt_BaseCcms_1__17_ */
        {0x0F12, 0x01C4,},//01C4// 01F3 01C2 01D0 Tune_wbt_BaseCcms_2__0_  */
        {0x0F12, 0xFFAB,},//FFAB// FFCB FF93 FFA1 Tune_wbt_BaseCcms_2__1_  */
        {0x0F12, 0xFFFC,},//FFFC// 0031 001C FFFA Tune_wbt_BaseCcms_2__2_  */
        {0x0F12, 0xFF6E,},//FF6E// FF6F Tune_wbt_BaseCcms_2__3_  */
        {0x0F12, 0x0145,},//0145// 0140 Tune_wbt_BaseCcms_2__4_  */
        {0x0F12, 0xFF4A,},//FF4A// FF49 Tune_wbt_BaseCcms_2__5_  */
        {0x0F12, 0xFFE1,},//FFE1// FFE3 FFC1 Tune_wbt_BaseCcms_2__6_  */
        {0x0F12, 0xFFF6,},//FFF6// FFF9 001F Tune_wbt_BaseCcms_2__7_  */
        {0x0F12, 0x01BD,},//01BD// 01C1 01BD Tune_wbt_BaseCcms_2__8_  */
        {0x0F12, 0x013E,},//013E// 013F Tune_wbt_BaseCcms_2__9_  */
        {0x0F12, 0x00E4,},//00E4// 00E1 Tune_wbt_BaseCcms_2__10_ */
        {0x0F12, 0xFF46,},//FF46// FF43 Tune_wbt_BaseCcms_2__11_ */
        {0x0F12, 0x0190,},//0190// 0191 Tune_wbt_BaseCcms_2__12_ */
        {0x0F12, 0xFFBC,},//FFBC// FFC0 Tune_wbt_BaseCcms_2__13_ */
        {0x0F12, 0x01B5,},//01B5// 01B7 Tune_wbt_BaseCcms_2__14_ */
        {0x0F12, 0xFF30,},//FF30// FF30 Tune_wbt_BaseCcms_2__15_ */
        {0x0F12, 0x015E,},//015E// 015F Tune_wbt_BaseCcms_2__16_ */
        {0x0F12, 0x0103,},//0103// 0106 Tune_wbt_BaseCcms_2__17_ */
        {0x0F12, 0x01C4,},//01C4// 01D0 Tune_wbt_BaseCcms_3__0_  */
        {0x0F12, 0xFFAB,},//FFAB// FFA1 Tune_wbt_BaseCcms_3__1_  */
        {0x0F12, 0xFFFC,},//FFFC// FFFA Tune_wbt_BaseCcms_3__2_  */
        {0x0F12, 0xFF6E,},//FF6E// FF6F Tune_wbt_BaseCcms_3__3_  */
        {0x0F12, 0x0145,},//0145// 0140 Tune_wbt_BaseCcms_3__4_  */
        {0x0F12, 0xFF4A,},//FF4A// FF49 Tune_wbt_BaseCcms_3__5_  */
        {0x0F12, 0xFFE1,},//FFE1// FFE3 Tune_wbt_BaseCcms_3__6_  */
        {0x0F12, 0xFFF6,},//FFF6// FFF9 Tune_wbt_BaseCcms_3__7_  */
        {0x0F12, 0x01BD,},//01BD// 01C1 Tune_wbt_BaseCcms_3__8_  */
        {0x0F12, 0x013E,},//013E// 013F Tune_wbt_BaseCcms_3__9_  */
        {0x0F12, 0x00E4,},//00E4// 00E1 Tune_wbt_BaseCcms_3__10_ */
        {0x0F12, 0xFF46,},//FF46// FF43 Tune_wbt_BaseCcms_3__11_ */
        {0x0F12, 0x0190,},//0190// 0191 Tune_wbt_BaseCcms_3__12_ */
        {0x0F12, 0xFFBC,},//FFBC// FFC0 Tune_wbt_BaseCcms_3__13_ */
        {0x0F12, 0x01B5,},//01B5// 01B7 Tune_wbt_BaseCcms_3__14_ */
        {0x0F12, 0xFF30,},//FF30// FF30 Tune_wbt_BaseCcms_3__15_ */
        {0x0F12, 0x015E,},//015E// 015F Tune_wbt_BaseCcms_3__16_ */
        {0x0F12, 0x0103,},//0103// 0106 Tune_wbt_BaseCcms_3__17_ */
        {0x0F12, 0x01C6,},//01C6// 01BF 01E9 01C7 01BF 01C7 01BF Tune_wbt_BaseCcms_4__0_  */
        {0x0F12, 0xFFC2,},//FFC2// FFBF FFE4 FFA5 FFBF FFA5 FFBF Tune_wbt_BaseCcms_4__1_  */
        {0x0F12, 0x0004,},//0004// FFFE 0031 0006 FFFE 0006 FFFE Tune_wbt_BaseCcms_4__2_  */
        {0x0F12, 0xFF6F,},//FF6F// FF6D FF6F FF6D Tune_wbt_BaseCcms_4__3_  */
        {0x0F12, 0x01C9,},//01C9// 01B4 01C9 01B4 Tune_wbt_BaseCcms_4__4_  */
        {0x0F12, 0xFF4F,},//FF4F// FF66 FF4F FF66 Tune_wbt_BaseCcms_4__5_  */
        {0x0F12, 0xFFDB,},//FFDB// FFCA FFDB FFCA Tune_wbt_BaseCcms_4__6_  */
        {0x0F12, 0xFFC0,},//FFC0// FFCE FFC0 FFCE Tune_wbt_BaseCcms_4__7_  */
        {0x0F12, 0x019D,},//019D// 017B 019D 017B Tune_wbt_BaseCcms_4__8_  */
        {0x0F12, 0x0136,},//0136// Tune_wbt_BaseCcms_4__9_  */
        {0x0F12, 0x0132,},//0132// Tune_wbt_BaseCcms_4__10_ */
        {0x0F12, 0xFF85,},//FF85// Tune_wbt_BaseCcms_4__11_ */
        {0x0F12, 0x018B,},//018B// Tune_wbt_BaseCcms_4__12_ */
        {0x0F12, 0xFF73,},//FF73// Tune_wbt_BaseCcms_4__13_ */
        {0x0F12, 0x0191,},//0191// Tune_wbt_BaseCcms_4__14_ */
        {0x0F12, 0xFF3F,},//FF3F// Tune_wbt_BaseCcms_4__15_ */
        {0x0F12, 0x015B,},//015B// Tune_wbt_BaseCcms_4__16_ */
        {0x0F12, 0x00D0,},//00D0// Tune_wbt_BaseCcms_4__17_ */
        {0x0F12, 0x01C6,},//01C6// 01BF 01E9 01C7 01BF 01C7 01BF Tune_wbt_BaseCcms_5__0_  */
        {0x0F12, 0xFFC2,},//FFC2// FFBF FFE4 FFA5 FFBF FFA5 FFBF Tune_wbt_BaseCcms_5__1_  */
        {0x0F12, 0x0004,},//0004// FFFE 0031 0006 FFFE 0006 FFFE Tune_wbt_BaseCcms_5__2_  */
        {0x0F12, 0xFF6F,},//FF6F// FF6D FF6F FF6D Tune_wbt_BaseCcms_5__3_  */
        {0x0F12, 0x01C9,},//01C9// 01B4 01C9 01B4 Tune_wbt_BaseCcms_5__4_  */
        {0x0F12, 0xFF4F,},//FF4F// FF66 FF4F FF66 Tune_wbt_BaseCcms_5__5_  */
        {0x0F12, 0xFFDB,},//FFDB// FFCA FFDB FFCA FFE7 FFCA Tune_wbt_BaseCcms_5__6_  */
        {0x0F12, 0xFFC0,},//FFC0// FFCE FFC0 FFCE FFC2 FFCE Tune_wbt_BaseCcms_5__7_  */
        {0x0F12, 0x019D,},//019D// 017B 019D 017B 018C 017B Tune_wbt_BaseCcms_5__8_  */
        {0x0F12, 0x0136,},//0136// Tune_wbt_BaseCcms_5__9_  */
        {0x0F12, 0x0132,},//0132// Tune_wbt_BaseCcms_5__10_ */
        {0x0F12, 0xFF85,},//FF85// Tune_wbt_BaseCcms_5__11_ */
        {0x0F12, 0x018B,},//018B// Tune_wbt_BaseCcms_5__12_ */
        {0x0F12, 0xFF73,},//FF73// Tune_wbt_BaseCcms_5__13_ */
        {0x0F12, 0x0191,},//0191// Tune_wbt_BaseCcms_5__14_ */
        {0x0F12, 0xFF3F,},//FF3F// Tune_wbt_BaseCcms_5__15_ */
        {0x0F12, 0x015B,},//015B// Tune_wbt_BaseCcms_5__16_ */
        {0x0F12, 0x00D0,},//00D0// Tune_wbt_BaseCcms_5__17_ */
        {0x002A, 0x3380,},
        {0x0F12, 0x01D6,}, //023C// 021B 021B 023D 01E9 01C7 01BF 01AC Tune_wbt_OutdoorCcm_0_   */
        {0x0F12, 0xFF94,}, //FFE0// FFE9 0010 0038 FFE4 FFA5 FFBF FFD7 Tune_wbt_OutdoorCcm_1_   */
        {0x0F12, 0xFFCC,}, //0052// 0050 0073 0085 0031 0006 FFFE 0019 Tune_wbt_OutdoorCcm_2_   */
        {0x0F12, 0xFF1F,}, //FF6F// FF6D Tune_wbt_OutdoorCcm_3_   */
        {0x0F12, 0x021F,}, //01C9// 01B4 Tune_wbt_OutdoorCcm_4_   */
        {0x0F12, 0xFF1F,}, //FF4F// FF66 Tune_wbt_OutdoorCcm_5_   */
        {0x0F12, 0xFFE4,}, //0000// FFE9 FFDB FFD5 FFD5 FFE7 FFCA Tune_wbt_OutdoorCcm_6_   */
        {0x0F12, 0xFFED,}, //FFA4// FFBA FFC0 FFD6 FFD6 FFC2 FFCE Tune_wbt_OutdoorCcm_7_   */
        {0x0F12, 0x01C8,}, //01A5// 01AC 019D 018D 018D 018C 017B Tune_wbt_OutdoorCcm_8_   */
        {0x0F12, 0x010F,}, //0125// 0132 Tune_wbt_OutdoorCcm_9_   */
        {0x0F12, 0x0150,}, //013B// 012E Tune_wbt_OutdoorCcm_10_  */
        {0x0F12, 0xFF16,}, //FF8D// FF8D Tune_wbt_OutdoorCcm_11_  */
        {0x0F12, 0x0210,}, //018B// Tune_wbt_OutdoorCcm_12_  */
        {0x0F12, 0xFF5D,}, //FF73// Tune_wbt_OutdoorCcm_13_  */
        {0x0F12, 0x0244,}, //0191// Tune_wbt_OutdoorCcm_14_  */
        {0x0F12, 0xFF10,}, //FF3F// Tune_wbt_OutdoorCcm_15_  */
        {0x0F12, 0x0190,}, //015B// Tune_wbt_OutdoorCcm_16_  */
        {0x0F12, 0x0145,}, //00D0// Tune_wbt_OutdoorCcm_17_  */
        {0x002A, 0x0612,},
        {0x0F12, 0x009D,},// SARR_AwbCcmCord_0_       */
        {0x0F12, 0x00D5,},// SARR_AwbCcmCord_1_       */
        {0x0F12, 0x0103,},// SARR_AwbCcmCord_2_       */
        {0x0F12, 0x0128,},// SARR_AwbCcmCord_3_       */
        {0x0F12, 0x0166,},// SARR_AwbCcmCord_4_       */
        {0x0F12, 0x0193,},// SARR_AwbCcmCord_5_       */

//*************************************/
// 17.GAMMA                           */
//*************************************/
// For Pre Post Gamma Calibration */
        {0x002A, 0x0538,},
        {0x0F12, 0x0000,},// seti_uGammaLutPreDemNoBin_0_   */
        {0x0F12, 0x001F,},// seti_uGammaLutPreDemNoBin_1_   */
        {0x0F12, 0x0035,},// seti_uGammaLutPreDemNoBin_2_   */
        {0x0F12, 0x005A,},// seti_uGammaLutPreDemNoBin_3_   */
        {0x0F12, 0x0095,},// seti_uGammaLutPreDemNoBin_4_   */
        {0x0F12, 0x00E6,},// seti_uGammaLutPreDemNoBin_5_   */
        {0x0F12, 0x0121,},// seti_uGammaLutPreDemNoBin_6_   */
        {0x0F12, 0x0139,},// seti_uGammaLutPreDemNoBin_7_   */
        {0x0F12, 0x0150,},// seti_uGammaLutPreDemNoBin_8_   */
        {0x0F12, 0x0177,},// seti_uGammaLutPreDemNoBin_9_   */
        {0x0F12, 0x019A,},// seti_uGammaLutPreDemNoBin_10_  */
        {0x0F12, 0x01BB,},// seti_uGammaLutPreDemNoBin_11_  */
        {0x0F12, 0x01DC,},// seti_uGammaLutPreDemNoBin_12_  */
        {0x0F12, 0x0219,},// seti_uGammaLutPreDemNoBin_13_  */
        {0x0F12, 0x0251,},// seti_uGammaLutPreDemNoBin_14_  */
        {0x0F12, 0x02B3,},// seti_uGammaLutPreDemNoBin_15_  */
        {0x0F12, 0x030A,},// seti_uGammaLutPreDemNoBin_16_  */
        {0x0F12, 0x035F,},// seti_uGammaLutPreDemNoBin_17_  */
        {0x0F12, 0x03B1,},// seti_uGammaLutPreDemNoBin_18_  */
        {0x0F12, 0x03FF,},// seti_uGammaLutPreDemNoBin_19_  */
        {0x0F12, 0x0000,},// seti_uGammaLutPostDemNoBin_0_  */
        {0x0F12, 0x0001,},// seti_uGammaLutPostDemNoBin_1_  */
        {0x0F12, 0x0001,},// seti_uGammaLutPostDemNoBin_2_  */
        {0x0F12, 0x0002,},// seti_uGammaLutPostDemNoBin_3_  */
        {0x0F12, 0x0004,},// seti_uGammaLutPostDemNoBin_4_  */
        {0x0F12, 0x000A,},// seti_uGammaLutPostDemNoBin_5_  */
        {0x0F12, 0x0012,},// seti_uGammaLutPostDemNoBin_6_  */
        {0x0F12, 0x0016,},// seti_uGammaLutPostDemNoBin_7_  */
        {0x0F12, 0x001A,},// seti_uGammaLutPostDemNoBin_8_  */
        {0x0F12, 0x0024,},// seti_uGammaLutPostDemNoBin_9_  */
        {0x0F12, 0x0031,},// seti_uGammaLutPostDemNoBin_10_ */
        {0x0F12, 0x003E,},// seti_uGammaLutPostDemNoBin_11_ */
        {0x0F12, 0x004E,},// seti_uGammaLutPostDemNoBin_12_ */
        {0x0F12, 0x0075,},// seti_uGammaLutPostDemNoBin_13_ */
        {0x0F12, 0x00A8,},// seti_uGammaLutPostDemNoBin_14_ */
        {0x0F12, 0x0126,},// seti_uGammaLutPostDemNoBin_15_ */
        {0x0F12, 0x01BE,},// seti_uGammaLutPostDemNoBin_16_ */
        {0x0F12, 0x0272,},// seti_uGammaLutPostDemNoBin_17_ */
        {0x0F12, 0x0334,},// seti_uGammaLutPostDemNoBin_18_ */
        {0x0F12, 0x03FF,},// seti_uGammaLutPostDemNoBin_19_ */

// For Gamma Calibration */

        {0x002A, 0x0498,},
        {0x0F12, 0x0000,},// SARR_usDualGammaLutRGBIndoor_0__0_   */
        {0x0F12, 0x0002,},// SARR_usDualGammaLutRGBIndoor_0__1_   */
        {0x0F12, 0x0007,},// SARR_usDualGammaLutRGBIndoor_0__2_   */
        {0x0F12, 0x001D,},// SARR_usDualGammaLutRGBIndoor_0__3_   */
        {0x0F12, 0x006E,},// SARR_usDualGammaLutRGBIndoor_0__4_   */
        {0x0F12, 0x00D3,},// SARR_usDualGammaLutRGBIndoor_0__5_   */
        {0x0F12, 0x0127,},// SARR_usDualGammaLutRGBIndoor_0__6_   */
        {0x0F12, 0x014C,},// SARR_usDualGammaLutRGBIndoor_0__7_   */
        {0x0F12, 0x016E,},// SARR_usDualGammaLutRGBIndoor_0__8_   */
        {0x0F12, 0x01A5,},// SARR_usDualGammaLutRGBIndoor_0__9_   */
        {0x0F12, 0x01D3,},// SARR_usDualGammaLutRGBIndoor_0__10_  */
        {0x0F12, 0x01FB,},// SARR_usDualGammaLutRGBIndoor_0__11_  */
        {0x0F12, 0x021F,},// SARR_usDualGammaLutRGBIndoor_0__12_  */
        {0x0F12, 0x0260,},// SARR_usDualGammaLutRGBIndoor_0__13_  */
        {0x0F12, 0x029A,},// SARR_usDualGammaLutRGBIndoor_0__14_  */
        {0x0F12, 0x02F7,},// SARR_usDualGammaLutRGBIndoor_0__15_  */
        {0x0F12, 0x034D,},// SARR_usDualGammaLutRGBIndoor_0__16_  */
        {0x0F12, 0x0395,},// SARR_usDualGammaLutRGBIndoor_0__17_  */
        {0x0F12, 0x03CE,},// SARR_usDualGammaLutRGBIndoor_0__18_  */
        {0x0F12, 0x03FF,},// SARR_usDualGammaLutRGBIndoor_0__19_  */
        {0x0F12, 0x0000,},// SARR_usDualGammaLutRGBOutdoor_0__0_  */
        {0x0F12, 0x0004,},// SARR_usDualGammaLutRGBOutdoor_0__1_  */
        {0x0F12, 0x000C,},// SARR_usDualGammaLutRGBOutdoor_0__2_  */
        {0x0F12, 0x0024,},// SARR_usDualGammaLutRGBOutdoor_0__3_  */
        {0x0F12, 0x006E,},// SARR_usDualGammaLutRGBOutdoor_0__4_  */
        {0x0F12, 0x00D1,},// SARR_usDualGammaLutRGBOutdoor_0__5_  */
        {0x0F12, 0x0119,},// SARR_usDualGammaLutRGBOutdoor_0__6_  */
        {0x0F12, 0x0139,},// SARR_usDualGammaLutRGBOutdoor_0__7_  */
        {0x0F12, 0x0157,},// SARR_usDualGammaLutRGBOutdoor_0__8_  */
        {0x0F12, 0x018E,},// SARR_usDualGammaLutRGBOutdoor_0__9_  */
        {0x0F12, 0x01C3,},// SARR_usDualGammaLutRGBOutdoor_0__10_ */
        {0x0F12, 0x01F3,},// SARR_usDualGammaLutRGBOutdoor_0__11_ */
        {0x0F12, 0x021F,},// SARR_usDualGammaLutRGBOutdoor_0__12_ */
        {0x0F12, 0x0269,},// SARR_usDualGammaLutRGBOutdoor_0__13_ */
        {0x0F12, 0x02A6,},// SARR_usDualGammaLutRGBOutdoor_0__14_ */
        {0x0F12, 0x02FF,},// SARR_usDualGammaLutRGBOutdoor_0__15_ */
        {0x0F12, 0x0351,},// SARR_usDualGammaLutRGBOutdoor_0__16_ */
        {0x0F12, 0x0395,},// SARR_usDualGammaLutRGBOutdoor_0__17_ */
        {0x0F12, 0x03CE,},// SARR_usDualGammaLutRGBOutdoor_0__18_ */
        {0x0F12, 0x03FF,},// SARR_usDualGammaLutRGBOutdoor_0__19_ */

//*************************************/
// 16.AFIT                            */
//*************************************/
        {0x002A, 0x3370,},
        {0x0F12, 0x0000,},// afit_bUseNormBrForAfit */

        {0x002A, 0x06D4,},
        {0x0F12, 0x0032,},// afit_uNoiseIndInDoor_0_ */
        {0x0F12, 0x0078,},// afit_uNoiseIndInDoor_1_ */
        {0x0F12, 0x00C8,},// afit_uNoiseIndInDoor_2_ */
        {0x0F12, 0x0190,},// afit_uNoiseIndInDoor_3_ */
        {0x0F12, 0x028C,},// afit_uNoiseIndInDoor_4_ */

        {0x002A, 0x0734,},
        {0x0F12, 0x0000,},// AfitBaseVals_0__0_  Brightness[0] */
        {0x0F12, 0x0000,},// AfitBaseVals_0__1_  Contrast[0] */
        {0x0F12, 0x0000,},// AfitBaseVals_0__2_  Saturation[0] */
        {0x0F12, 0x0000,},// AfitBaseVals_0__3_  Sharp_Blur[0] */
        {0x0F12, 0x0000,},// AfitBaseVals_0__4_  */
        {0x0F12, 0x0078,},// AfitBaseVals_0__5_  */
        {0x0F12, 0x012C,},// AfitBaseVals_0__6_  */
        {0x0F12, 0x03FF,},// AfitBaseVals_0__7_  */
        {0x0F12, 0x0014,},// AfitBaseVals_0__8_  */
        {0x0F12, 0x0064,},// AfitBaseVals_0__9_  */
        {0x0F12, 0x000C,},// AfitBaseVals_0__10_ */
        {0x0F12, 0x0010,},// AfitBaseVals_0__11_ */
        {0x0F12, 0x01E6,},// AfitBaseVals_0__12_ */
        {0x0F12, 0x0000,},// AfitBaseVals_0__13_ */
        {0x0F12, 0x0070,},// AfitBaseVals_0__14_ */
        {0x0F12, 0x01FF,},// AfitBaseVals_0__15_ */
        {0x0F12, 0x0144,},// AfitBaseVals_0__16_ */
        {0x0F12, 0x000F,},// AfitBaseVals_0__17_ */
        {0x0F12, 0x000A,},// AfitBaseVals_0__18_ */
        {0x0F12, 0x0073,},// AfitBaseVals_0__19_ */
        {0x0F12, 0x0087,},// AfitBaseVals_0__20_ */
        {0x0F12, 0x0014,},// AfitBaseVals_0__21_ */
        {0x0F12, 0x000A,},// AfitBaseVals_0__22_ */
        {0x0F12, 0x0023,},// AfitBaseVals_0__23_ */
        {0x0F12, 0x001E,},// AfitBaseVals_0__24_ */
        {0x0F12, 0x0014,},// AfitBaseVals_0__25_ */
        {0x0F12, 0x000A,},// AfitBaseVals_0__26_ */
        {0x0F12, 0x0023,},// AfitBaseVals_0__27_ */
        {0x0F12, 0x0046,},// AfitBaseVals_0__28_ */
        {0x0F12, 0x2B32,},// AfitBaseVals_0__29_ */
        {0x0F12, 0x0601,},// AfitBaseVals_0__30_ */
        {0x0F12, 0x0000,},// AfitBaseVals_0__31_ */
        {0x0F12, 0x0000,},// AfitBaseVals_0__32_ */
        {0x0F12, 0x0000,},// AfitBaseVals_0__33_ */
        {0x0F12, 0x00FF,},// AfitBaseVals_0__34_ */
        {0x0F12, 0x07FF,},// AfitBaseVals_0__35_ */
        {0x0F12, 0xFFFF,},// AfitBaseVals_0__36_ */
        {0x0F12, 0x0000,},// AfitBaseVals_0__37_ */
        {0x0F12, 0x050D,},// AfitBaseVals_0__38_ */
        {0x0F12, 0x1E80,},// AfitBaseVals_0__39_ */
        {0x0F12, 0x0000,},// AfitBaseVals_0__40_ */
        {0x0F12, 0x1408,},// 1408 AfitBaseVals_0__41_ iNearGrayDesat[0] */
        {0x0F12, 0x0214,},// AfitBaseVals_0__42_ */
        {0x0F12, 0xFF01,},// AfitBaseVals_0__43_ */
        {0x0F12, 0x180F,},// AfitBaseVals_0__44_ */
        {0x0F12, 0x0001,},// AfitBaseVals_0__45_ */
        {0x0F12, 0x0000,},// AfitBaseVals_0__46_ */
        {0x0F12, 0x8003,},// AfitBaseVals_0__47_ */
        {0x0F12, 0x0094,},// AfitBaseVals_0__48_ */
        {0x0F12, 0x0580,},// AfitBaseVals_0__49_ */
        {0x0F12, 0x0280,},// AfitBaseVals_0__50_ */
        {0x0F12, 0x0310,},// AfitBaseVals_0__51_ iClustThresh_H[0] iClustMulT_H[0] */
        {0x0F12, 0x3186,},// AfitBaseVals_0__52_ */
        {0x0F12, 0x707E,},// AfitBaseVals_0__53_ */
        {0x0F12, 0x0A02,},// AfitBaseVals_0__54_ */
        {0x0F12, 0x080A,},// AfitBaseVals_0__55_ */
        {0x0F12, 0x0500,},// AfitBaseVals_0__56_ */
        {0x0F12, 0x032D,},// AfitBaseVals_0__57_ */
        {0x0F12, 0x324E,},// AfitBaseVals_0__58_ */
        {0x0F12, 0x001E,},// AfitBaseVals_0__59_ */
        {0x0F12, 0x0200,},// AfitBaseVals_0__60_ */
        {0x0F12, 0x0103,},// AfitBaseVals_0__61_ */
        {0x0F12, 0x010C,},// AfitBaseVals_0__62_ */
        {0x0F12, 0x9696,},// AfitBaseVals_0__63_ */
        {0x0F12, 0x4646,},// AfitBaseVals_0__64_ */
        {0x0F12, 0x0802,},// AfitBaseVals_0__65_ */
        {0x0F12, 0x0802,},// AfitBaseVals_0__66_ */
        {0x0F12, 0x0000,},// AfitBaseVals_0__67_ */
        {0x0F12, 0x030F,},// AfitBaseVals_0__68_ */
        {0x0F12, 0x3202,},// AfitBaseVals_0__69_ */
        {0x0F12, 0x0F1E,},// AfitBaseVals_0__70_ */
        {0x0F12, 0x020F,},// AfitBaseVals_0__71_ */
        {0x0F12, 0x0103,},// AfitBaseVals_0__72_ */
        {0x0F12, 0x010C,},// AfitBaseVals_0__73_ */
        {0x0F12, 0x9696,},// AfitBaseVals_0__74_ */
        {0x0F12, 0x4646,},// AfitBaseVals_0__75_ */
        {0x0F12, 0x0802,},// AfitBaseVals_0__76_ */
        {0x0F12, 0x0802,},// AfitBaseVals_0__77_ */
        {0x0F12, 0x0000,},// AfitBaseVals_0__78_ */
        {0x0F12, 0x030F,},// AfitBaseVals_0__79_ */
        {0x0F12, 0x3202,},// AfitBaseVals_0__80_ */
        {0x0F12, 0x0F1E,},// AfitBaseVals_0__81_ */
        {0x0F12, 0x020F,},// AfitBaseVals_0__82_ */
        {0x0F12, 0x0003,},// AfitBaseVals_0__83_ */
        {0x0F12, 0x0000,},// AfitBaseVals_1__0_  Brightness[1] */
        {0x0F12, 0x0000,},// AfitBaseVals_1__1_  Contrast[1] */
        {0x0F12, 0x0000,},// AfitBaseVals_1__2_  Saturation[1] */
        {0x0F12, 0x0000,},// AfitBaseVals_1__3_  Sharp_Blur[1] */
        {0x0F12, 0x0000,},// AfitBaseVals_1__4_  */
        {0x0F12, 0x006A,},// AfitBaseVals_1__5_  */
        {0x0F12, 0x012C,},// AfitBaseVals_1__6_  */
        {0x0F12, 0x03FF,},// AfitBaseVals_1__7_  */
        {0x0F12, 0x0014,},// AfitBaseVals_1__8_  */
        {0x0F12, 0x0064,},// AfitBaseVals_1__9_  */
        {0x0F12, 0x000C,},// AfitBaseVals_1__10_ */
        {0x0F12, 0x0010,},// AfitBaseVals_1__11_ */
        {0x0F12, 0x01E6,},// AfitBaseVals_1__12_ */
        {0x0F12, 0x03FF,},// AfitBaseVals_1__13_ */
        {0x0F12, 0x0070,},// AfitBaseVals_1__14_ */
        {0x0F12, 0x007D,},// AfitBaseVals_1__15_ */
        {0x0F12, 0x0064,},// AfitBaseVals_1__16_ */
        {0x0F12, 0x0014,},// AfitBaseVals_1__17_ */
        {0x0F12, 0x000A,},// AfitBaseVals_1__18_ */
        {0x0F12, 0x0073,},// AfitBaseVals_1__19_ */
        {0x0F12, 0x0087,},// AfitBaseVals_1__20_ */
        {0x0F12, 0x0014,},// AfitBaseVals_1__21_ */
        {0x0F12, 0x000A,},// AfitBaseVals_1__22_ */
        {0x0F12, 0x0023,},// AfitBaseVals_1__23_ */
        {0x0F12, 0x001E,},// AfitBaseVals_1__24_ */
        {0x0F12, 0x0014,},// AfitBaseVals_1__25_ */
        {0x0F12, 0x000A,},// AfitBaseVals_1__26_ */
        {0x0F12, 0x0023,},// AfitBaseVals_1__27_ */
        {0x0F12, 0x001E,},// AfitBaseVals_1__28_ */
        {0x0F12, 0x2B32,},// AfitBaseVals_1__29_ */
        {0x0F12, 0x0601,},// AfitBaseVals_1__30_ */
        {0x0F12, 0x0000,},// AfitBaseVals_1__31_ */
        {0x0F12, 0x0000,},// AfitBaseVals_1__32_ */
        {0x0F12, 0x0000,},// AfitBaseVals_1__33_ */
        {0x0F12, 0x00FF,},// AfitBaseVals_1__34_ */
        {0x0F12, 0x07FF,},// AfitBaseVals_1__35_ */
        {0x0F12, 0xFFFF,},// AfitBaseVals_1__36_ */
        {0x0F12, 0x0000,},// AfitBaseVals_1__37_ */
        {0x0F12, 0x050D,},// AfitBaseVals_1__38_ */
        {0x0F12, 0x1E80,},// AfitBaseVals_1__39_ */
        {0x0F12, 0x0000,},// AfitBaseVals_1__40_ */
        {0x0F12, 0x1403,},// 1408 AfitBaseVals_1__41_ iNearGrayDesat[1] */
        {0x0F12, 0x0214,},// AfitBaseVals_1__42_ */
        {0x0F12, 0xFF01,},// AfitBaseVals_1__43_ */
        {0x0F12, 0x180F,},// AfitBaseVals_1__44_ */
        {0x0F12, 0x0002,},// AfitBaseVals_1__45_ */
        {0x0F12, 0x0000,},// AfitBaseVals_1__46_ */
        {0x0F12, 0x8003,},// AfitBaseVals_1__47_ */
        {0x0F12, 0x0080,},// AfitBaseVals_1__48_ */
        {0x0F12, 0x0080,},// AfitBaseVals_1__49_ */
        {0x0F12, 0x0180,},// AfitBaseVals_1__50_ */
        {0x0F12, 0x0310,},// AfitBaseVals_1__51_ iClustThresh_H[1] iClustMulT_H[1] */
        {0x0F12, 0x1E65,},// AfitBaseVals_1__52_ */
        {0x0F12, 0x1A24,},// AfitBaseVals_1__53_ */
        {0x0F12, 0x0A03,},// AfitBaseVals_1__54_ */
        {0x0F12, 0x080A,},// AfitBaseVals_1__55_ */
        {0x0F12, 0x0500,},// AfitBaseVals_1__56_ */
        {0x0F12, 0x032D,},// AfitBaseVals_1__57_ */
        {0x0F12, 0x324D,},// AfitBaseVals_1__58_ */
        {0x0F12, 0x001E,},// AfitBaseVals_1__59_ */
        {0x0F12, 0x0200,},// AfitBaseVals_1__60_ */
        {0x0F12, 0x0103,},// AfitBaseVals_1__61_ */
        {0x0F12, 0x010C,},// AfitBaseVals_1__62_ */
        {0x0F12, 0x9696,},// AfitBaseVals_1__63_ */
        {0x0F12, 0x2F34,},// AfitBaseVals_1__64_ */
        {0x0F12, 0x0504,},// AfitBaseVals_1__65_ */
        {0x0F12, 0x080F,},// AfitBaseVals_1__66_ */
        {0x0F12, 0x0000,},// AfitBaseVals_1__67_ */
        {0x0F12, 0x030F,},// AfitBaseVals_1__68_ */
        {0x0F12, 0x3208,},// AfitBaseVals_1__69_ */
        {0x0F12, 0x0F1E,},// AfitBaseVals_1__70_ */
        {0x0F12, 0x020F,},// AfitBaseVals_1__71_ */
        {0x0F12, 0x0103,},// AfitBaseVals_1__72_ */
        {0x0F12, 0x010C,},// AfitBaseVals_1__73_ */
        {0x0F12, 0x9696,},// AfitBaseVals_1__74_ */
        {0x0F12, 0x1414,},// AfitBaseVals_1__75_ */
        {0x0F12, 0x0504,},// AfitBaseVals_1__76_ */
        {0x0F12, 0x080F,},// AfitBaseVals_1__77_ */
        {0x0F12, 0x0000,},// AfitBaseVals_1__78_ */
        {0x0F12, 0x030F,},// AfitBaseVals_1__79_ */
        {0x0F12, 0x3208,},// AfitBaseVals_1__80_ */
        {0x0F12, 0x0F1E,},// AfitBaseVals_1__81_ */
        {0x0F12, 0x020F,},// AfitBaseVals_1__82_ */
        {0x0F12, 0x0003,},// AfitBaseVals_1__83_ */
        {0x0F12, 0x0000,},// AfitBaseVals_2__0_  Brightness[2] */
        {0x0F12, 0x0000,},// AfitBaseVals_2__1_  Contrast[2] */
        {0x0F12, 0xFFFC,},// 0000 AfitBaseVals_2__2_  Saturation[2] */
        {0x0F12, 0x0000,},// AfitBaseVals_2__3_  Sharp_Blur[2] */
        {0x0F12, 0x0000,},// AfitBaseVals_2__4_  */
        {0x0F12, 0x0064,},// AfitBaseVals_2__5_  */
        {0x0F12, 0x012C,},// AfitBaseVals_2__6_  */
        {0x0F12, 0x03FF,},// AfitBaseVals_2__7_  */
        {0x0F12, 0x0014,},// AfitBaseVals_2__8_  */
        {0x0F12, 0x0064,},// AfitBaseVals_2__9_  */
        {0x0F12, 0x000C,},// AfitBaseVals_2__10_ */
        {0x0F12, 0x0010,},// AfitBaseVals_2__11_ */
        {0x0F12, 0x01E6,},// AfitBaseVals_2__12_ */
        {0x0F12, 0x03FF,},// AfitBaseVals_2__13_ */
        {0x0F12, 0x0070,},// AfitBaseVals_2__14_ */
        {0x0F12, 0x007D,},// AfitBaseVals_2__15_ */
        {0x0F12, 0x0064,},// AfitBaseVals_2__16_ */
        {0x0F12, 0x0032,},// 0096 AfitBaseVals_2__17_ */
        {0x0F12, 0x0096,},// AfitBaseVals_2__18_ */
        {0x0F12, 0x0073,},// AfitBaseVals_2__19_ */
        {0x0F12, 0x0087,},// AfitBaseVals_2__20_ */
        {0x0F12, 0x0014,},// AfitBaseVals_2__21_ */
        {0x0F12, 0x0019,},// AfitBaseVals_2__22_ */
        {0x0F12, 0x0023,},// AfitBaseVals_2__23_ */
        {0x0F12, 0x001E,},// AfitBaseVals_2__24_ */
        {0x0F12, 0x0014,},// AfitBaseVals_2__25_ */
        {0x0F12, 0x0019,},// AfitBaseVals_2__26_ */
        {0x0F12, 0x0023,},// AfitBaseVals_2__27_ */
        {0x0F12, 0x001E,},// AfitBaseVals_2__28_ */
        {0x0F12, 0x2B32,},// AfitBaseVals_2__29_ */
        {0x0F12, 0x0601,},// AfitBaseVals_2__30_ */
        {0x0F12, 0x0000,},// AfitBaseVals_2__31_ */
        {0x0F12, 0x0000,},// AfitBaseVals_2__32_ */
        {0x0F12, 0x0000,},// AfitBaseVals_2__33_ */
        {0x0F12, 0x00FF,},// AfitBaseVals_2__34_ */
        {0x0F12, 0x07FF,},// AfitBaseVals_2__35_ */
        {0x0F12, 0xFFFF,},// AfitBaseVals_2__36_ */
        {0x0F12, 0x0000,},// AfitBaseVals_2__37_ */
        {0x0F12, 0x050D,},// AfitBaseVals_2__38_ */
        {0x0F12, 0x1E80,},// AfitBaseVals_2__39_ */
        {0x0F12, 0x0000,},// AfitBaseVals_2__40_ */
        {0x0F12, 0x0A03,},// 0A08 AfitBaseVals_2__41_ iNearGrayDesat[2] */
        {0x0F12, 0x0200,},// AfitBaseVals_2__42_ */
        {0x0F12, 0xFF01,},// AfitBaseVals_2__43_ */
        {0x0F12, 0x180F,},// AfitBaseVals_2__44_ */
        {0x0F12, 0x0002,},// AfitBaseVals_2__45_ */
        {0x0F12, 0x0000,},// AfitBaseVals_2__46_ */
        {0x0F12, 0x8003,},// AfitBaseVals_2__47_ */
        {0x0F12, 0x0080,},// AfitBaseVals_2__48_ */
        {0x0F12, 0x0080,},// AfitBaseVals_2__49_ */
        {0x0F12, 0x0180,},// AfitBaseVals_2__50_ */
        {0x0F12, 0x0210,},// AfitBaseVals_2__51_ iClustThresh_H[2] iClustMulT_H[2] */
        {0x0F12, 0x1E4B,},// AfitBaseVals_2__52_ */
        {0x0F12, 0x1A24,},// AfitBaseVals_2__53_ */
        {0x0F12, 0x0A05,},// AfitBaseVals_2__54_ */
        {0x0F12, 0x080A,},// AfitBaseVals_2__55_ */
        {0x0F12, 0x0500,},// AfitBaseVals_2__56_ */
        {0x0F12, 0x032D,},// AfitBaseVals_2__57_ */
        {0x0F12, 0x324D,},// AfitBaseVals_2__58_ */
        {0x0F12, 0x001E,},// AfitBaseVals_2__59_ */
        {0x0F12, 0x0200,},// AfitBaseVals_2__60_ */
        {0x0F12, 0x0103,},// AfitBaseVals_2__61_ */
        {0x0F12, 0x010C,},// AfitBaseVals_2__62_ */
        {0x0F12, 0x9696,},// AfitBaseVals_2__63_ */
        {0x0F12, 0x1E23,},// AfitBaseVals_2__64_ */
        {0x0F12, 0x0505,},// AfitBaseVals_2__65_ */
        {0x0F12, 0x080F,},// AfitBaseVals_2__66_ */
        {0x0F12, 0x0000,},// AfitBaseVals_2__67_ */
        {0x0F12, 0x030F,},// AfitBaseVals_2__68_ */
        {0x0F12, 0x3208,},// AfitBaseVals_2__69_ */
        {0x0F12, 0x0F1E,},// AfitBaseVals_2__70_ */
        {0x0F12, 0x020F,},// AfitBaseVals_2__71_ */
        {0x0F12, 0x0103,},// AfitBaseVals_2__72_ */
        {0x0F12, 0x010C,},// AfitBaseVals_2__73_ */
        {0x0F12, 0x9696,},// AfitBaseVals_2__74_ */
        {0x0F12, 0x1E23,},// AfitBaseVals_2__75_ */
        {0x0F12, 0x0505,},// AfitBaseVals_2__76_ */
        {0x0F12, 0x080F,},// AfitBaseVals_2__77_ */
        {0x0F12, 0x0000,},// AfitBaseVals_2__78_ */
        {0x0F12, 0x030F,},// AfitBaseVals_2__79_ */
        {0x0F12, 0x3208,},// AfitBaseVals_2__80_ */
        {0x0F12, 0x0F1E,},// AfitBaseVals_2__81_ */
        {0x0F12, 0x020F,},// AfitBaseVals_2__82_ */
        {0x0F12, 0x0003,},// AfitBaseVals_2__83_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__0_  Brightness[3] */
        {0x0F12, 0x0000,},// 0000 AfitBaseVals_3__1_  Contrast[3] */
        {0x0F12, 0xFFFA,},// AfitBaseVals_3__2_  Saturation[3] */
        {0x0F12, 0x0000,},// AfitBaseVals_3__3_  Sharp_Blur[3] */
        {0x0F12, 0x0000,},// AfitBaseVals_3__4_  */
        {0x0F12, 0x0064,},// AfitBaseVals_3__5_  */
        {0x0F12, 0x012C,},// AfitBaseVals_3__6_  */
        {0x0F12, 0x03FF,},// AfitBaseVals_3__7_  */
        {0x0F12, 0x0014,},// AfitBaseVals_3__8_  */
        {0x0F12, 0x0064,},// AfitBaseVals_3__9_  */
        {0x0F12, 0x000C,},// AfitBaseVals_3__10_ */
        {0x0F12, 0x0010,},// AfitBaseVals_3__11_ */
        {0x0F12, 0x01E6,},// AfitBaseVals_3__12_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__13_ */
        {0x0F12, 0x0070,},// AfitBaseVals_3__14_ */
        {0x0F12, 0x007D,},// AfitBaseVals_3__15_ */
        {0x0F12, 0x0064,},// AfitBaseVals_3__16_ */
        {0x0F12, 0x0032,},// 0096 AfitBaseVals_3__17_ */
        {0x0F12, 0x0096,},// AfitBaseVals_3__18_ */
        {0x0F12, 0x0073,},// AfitBaseVals_3__19_ */
        {0x0F12, 0x009F,},// AfitBaseVals_3__20_ */
        {0x0F12, 0x0028,},// AfitBaseVals_3__21_ */
        {0x0F12, 0x0028,},// AfitBaseVals_3__22_ */
        {0x0F12, 0x0023,},// AfitBaseVals_3__23_ */
        {0x0F12, 0x0037,},// AfitBaseVals_3__24_ */
        {0x0F12, 0x0028,},// AfitBaseVals_3__25_ */
        {0x0F12, 0x0028,},// AfitBaseVals_3__26_ */
        {0x0F12, 0x0023,},// AfitBaseVals_3__27_ */
        {0x0F12, 0x0037,},// AfitBaseVals_3__28_ */
        {0x0F12, 0x2B32,},// AfitBaseVals_3__29_ */
        {0x0F12, 0x0601,},// AfitBaseVals_3__30_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__31_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__32_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__33_ */
        {0x0F12, 0x00FF,},// AfitBaseVals_3__34_ */
        {0x0F12, 0x07A0,},// AfitBaseVals_3__35_ */
        {0x0F12, 0xFFFF,},// AfitBaseVals_3__36_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__37_ */
        {0x0F12, 0x050D,},// AfitBaseVals_3__38_ */
        {0x0F12, 0x1E80,},// AfitBaseVals_3__39_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__40_ */
        {0x0F12, 0x0A03,},// 0A08 AfitBaseVals_3__41_ iNearGrayDesat[3] */
        {0x0F12, 0x0200,},// AfitBaseVals_3__42_ */
        {0x0F12, 0xFF01,},// AfitBaseVals_3__43_ */
        {0x0F12, 0x180F,},// AfitBaseVals_3__44_ */
        {0x0F12, 0x0001,},// AfitBaseVals_3__45_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__46_ */
        {0x0F12, 0x8003,},// AfitBaseVals_3__47_ */
        {0x0F12, 0x0080,},// AfitBaseVals_3__48_ */
        {0x0F12, 0x0080,},// AfitBaseVals_3__49_ */
        {0x0F12, 0x0180,},// AfitBaseVals_3__50_ */
        {0x0F12, 0x0110,},// AfitBaseVals_3__51_ iClustThresh_H[3] iClustMulT_H[3] */
        {0x0F12, 0x1E32,},// AfitBaseVals_3__52_ */
        {0x0F12, 0x1A24,},// AfitBaseVals_3__53_ */
        {0x0F12, 0x0A05,},// AfitBaseVals_3__54_ */
        {0x0F12, 0x080A,},// AfitBaseVals_3__55_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__56_ */
        {0x0F12, 0x0328,},// AfitBaseVals_3__57_ */
        {0x0F12, 0x324C,},// AfitBaseVals_3__58_ */
        {0x0F12, 0x001E,},// AfitBaseVals_3__59_ */
        {0x0F12, 0x0200,},// AfitBaseVals_3__60_ */
        {0x0F12, 0x0103,},// AfitBaseVals_3__61_ */
        {0x0F12, 0x010C,},// AfitBaseVals_3__62_ */
        {0x0F12, 0x9696,},// AfitBaseVals_3__63_ */
        {0x0F12, 0x0F0F,},// AfitBaseVals_3__64_ */
        {0x0F12, 0x0307,},// AfitBaseVals_3__65_ */
        {0x0F12, 0x080F,},// AfitBaseVals_3__66_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__67_ */
        {0x0F12, 0x030F,},// AfitBaseVals_3__68_ */
        {0x0F12, 0x3208,},// AfitBaseVals_3__69_ */
        {0x0F12, 0x0F1E,},// AfitBaseVals_3__70_ */
        {0x0F12, 0x020F,},// AfitBaseVals_3__71_ */
        {0x0F12, 0x0103,},// AfitBaseVals_3__72_ */
        {0x0F12, 0x010C,},// AfitBaseVals_3__73_ */
        {0x0F12, 0x9696,},// AfitBaseVals_3__74_ */
        {0x0F12, 0x0F0F,},// AfitBaseVals_3__75_ */
        {0x0F12, 0x0307,},// AfitBaseVals_3__76_ */
        {0x0F12, 0x080F,},// AfitBaseVals_3__77_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__78_ */
        {0x0F12, 0x030F,},// AfitBaseVals_3__79_ */
        {0x0F12, 0x3208,},// AfitBaseVals_3__80_ */
        {0x0F12, 0x0F1E,},// AfitBaseVals_3__81_ */
        {0x0F12, 0x020F,},// AfitBaseVals_3__82_ */
        {0x0F12, 0x0003,},// AfitBaseVals_3__83_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__0_  Brightness[4] */
        {0x0F12, 0x0000,},// 0000 AfitBaseVals_4__1_  Contrast[4] */
        {0x0F12, 0xFFF8,},// AfitBaseVals_4__2_  Saturation[4] */
        {0x0F12, 0x0000,},// AfitBaseVals_4__3_  Sharp_Blur[4] */
        {0x0F12, 0x0000,},// AfitBaseVals_4__4_  */
        {0x0F12, 0x0028,},// AfitBaseVals_4__5_  */
        {0x0F12, 0x012C,},// AfitBaseVals_4__6_  */
        {0x0F12, 0x03FF,},// AfitBaseVals_4__7_  */
        {0x0F12, 0x0014,},// AfitBaseVals_4__8_  */
        {0x0F12, 0x0064,},// AfitBaseVals_4__9_  */
        {0x0F12, 0x000C,},// AfitBaseVals_4__10_ */
        {0x0F12, 0x0010,},// AfitBaseVals_4__11_ */
        {0x0F12, 0x01E6,},// AfitBaseVals_4__12_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__13_ */
        {0x0F12, 0x0070,},// AfitBaseVals_4__14_ */
        {0x0F12, 0x0087,},// AfitBaseVals_4__15_ */
        {0x0F12, 0x0073,},// AfitBaseVals_4__16_ */
        {0x0F12, 0x0032,},// 0096 AfitBaseVals_4__17_ */
        {0x0F12, 0x0096,},// AfitBaseVals_4__18_ */
        {0x0F12, 0x0073,},// AfitBaseVals_4__19_ */
        {0x0F12, 0x00B4,},// AfitBaseVals_4__20_ */
        {0x0F12, 0x0028,},// AfitBaseVals_4__21_ */
        {0x0F12, 0x0028,},// AfitBaseVals_4__22_ */
        {0x0F12, 0x0023,},// AfitBaseVals_4__23_ */
        {0x0F12, 0x0046,},// AfitBaseVals_4__24_ */
        {0x0F12, 0x0028,},// AfitBaseVals_4__25_ */
        {0x0F12, 0x0028,},// AfitBaseVals_4__26_ */
        {0x0F12, 0x0023,},// AfitBaseVals_4__27_ */
        {0x0F12, 0x0046,},// AfitBaseVals_4__28_ */
        {0x0F12, 0x2B23,},// AfitBaseVals_4__29_ */
        {0x0F12, 0x0601,},// AfitBaseVals_4__30_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__31_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__32_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__33_ */
        {0x0F12, 0x00FF,},// AfitBaseVals_4__34_ */
        {0x0F12, 0x0B84,},// AfitBaseVals_4__35_ */
        {0x0F12, 0xFFFF,},// AfitBaseVals_4__36_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__37_ */
        {0x0F12, 0x050D,},// AfitBaseVals_4__38_ */
        {0x0F12, 0x1E80,},// AfitBaseVals_4__39_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__40_ */
        {0x0F12, 0x0A03,},// 0A08 AfitBaseVals_4__41_ iNearGrayDesat[4] */
        {0x0F12, 0x0200,},// AfitBaseVals_4__42_ */
        {0x0F12, 0xFF01,},// AfitBaseVals_4__43_ */
        {0x0F12, 0x180F,},// AfitBaseVals_4__44_ */
        {0x0F12, 0x0001,},// AfitBaseVals_4__45_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__46_ */
        {0x0F12, 0x8003,},// AfitBaseVals_4__47_ */
        {0x0F12, 0x0080,},// AfitBaseVals_4__48_ */
        {0x0F12, 0x0080,},// AfitBaseVals_4__49_ */
        {0x0F12, 0x0180,},// AfitBaseVals_4__50_ */
        {0x0F12, 0x0110,},// AfitBaseVals_4__51_ iClustThresh_H[4] iClustMulT_H[4] */
        {0x0F12, 0x1E1E,},// AfitBaseVals_4__52_ */
        {0x0F12, 0x1419,},// AfitBaseVals_4__53_ */
        {0x0F12, 0x0A0A,},// AfitBaseVals_4__54_ */
        {0x0F12, 0x0800,},// AfitBaseVals_4__55_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__56_ */
        {0x0F12, 0x0328,},// AfitBaseVals_4__57_ */
        {0x0F12, 0x324C,},// AfitBaseVals_4__58_ */
        {0x0F12, 0x001E,},// AfitBaseVals_4__59_ */
        {0x0F12, 0x0200,},// AfitBaseVals_4__60_ */
        {0x0F12, 0x0103,},// AfitBaseVals_4__61_ */
        {0x0F12, 0x010C,},// AfitBaseVals_4__62_ */
        {0x0F12, 0x6464,},// AfitBaseVals_4__63_ */
        {0x0F12, 0x0F0F,},// AfitBaseVals_4__64_ */
        {0x0F12, 0x0307,},// AfitBaseVals_4__65_ */
        {0x0F12, 0x080F,},// AfitBaseVals_4__66_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__67_ */
        {0x0F12, 0x030F,},// AfitBaseVals_4__68_ */
        {0x0F12, 0x3208,},// AfitBaseVals_4__69_ */
        {0x0F12, 0x0F1E,},// AfitBaseVals_4__70_ */
        {0x0F12, 0x020F,},// AfitBaseVals_4__71_ */
        {0x0F12, 0x0103,},// AfitBaseVals_4__72_ */
        {0x0F12, 0x010C,},// AfitBaseVals_4__73_ */
        {0x0F12, 0x6464,},// AfitBaseVals_4__74_ */
        {0x0F12, 0x0F0F,},// AfitBaseVals_4__75_ */
        {0x0F12, 0x0307,},// AfitBaseVals_4__76_ */
        {0x0F12, 0x080F,},// AfitBaseVals_4__77_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__78_ */
        {0x0F12, 0x030F,},// AfitBaseVals_4__79_ */
        {0x0F12, 0x3208,},// AfitBaseVals_4__80_ */
        {0x0F12, 0x0F1E,},// AfitBaseVals_4__81_ */
        {0x0F12, 0x020F,},// AfitBaseVals_4__82_ */
        {0x0F12, 0x0003,},// AfitBaseVals_4__83_ */
        {0x0F12, 0x7F5E,},// ConstAfitBaseVals_0_ */
        {0x0F12, 0xFEEE,},// ConstAfitBaseVals_1_ */
        {0x0F12, 0xD9B7,},// ConstAfitBaseVals_2_ */
        {0x0F12, 0x0472,},// ConstAfitBaseVals_3_ */
        {0x0F12, 0x0001,},// ConstAfitBaseVals_4_ */

//*************************************/
// 18.JPEG Thumnail Setting           */
//*************************************/

//*************************************/
// 19.Input Size Setting              */
//*************************************/

//*********************************************************************************
// 20.Preview & Capture Configration Setting                                       
//*********************************************************************************
// Preview config[0] 640X480  15~7.5fps //
        {0x002A, 0x01BE,},
        {0x0F12, 0x0500,},	// REG_0TC_PCFG_usWidth 500:1280; 280:640
        {0x0F12, 0x03C0,},	// REG_0TC_PCFG_usHeight 3C0:960; 1E0:480 //yxq 0x03C0//0x02D0
        {0x0F12, 0x0005,},	// REG_0TC_PCFG_Format 5:YUV422; 7:RAW10  
        {0x002A, 0x01C8,},
        {0x0F12, 0x0000,},	// REG_0TC_PCFG_uClockInd 
        {0x002A, 0x01C4,},
        {0x0F12, 0x0042,},	// REG_0TC_PCFG_PVIMask 52:YUV422, 42:RAW10 
        {0x002A, 0x01D4,},
        {0x0F12, 0x0002,},	// REG_0TC_PCFG_FrRateQualityType  1b:FR(bin) 2b:Quality(no-bin) 
        {0x002A, 0x01D2,},
        {0x0F12, 0x0000,},	// REG_0TC_PCFG_usFrTimeType  0:dynamic; 1:fixed not accurate; 2:fixed accurate 
        {0x002A, 0x01D8,},
        {0x0F12, 0x03E8,},	// REG_0TC_PCFG_usMaxFrTimeMsecMult10  30fps-014D; 15fps-029A; 7.5-0535; 6.0-0682; 3.75-0A6A
        {0x002A, 0x01D6,},
        {0x0F12, 0x014D,},// REG_0TC_PCFG_usMinFrTimeMsecMult10 
        {0x002A, 0x01E8,},
        {0x0F12, 0x0003,},	// REG_0TC_PCFG_uPrevMirror 
        {0x0F12, 0x0000,},	// REG_0TC_PCFG_uCaptureMirror 

// Capture config[0] 1280x960  7.5fps 
        {0x002A, 0x02AE,},
        {0x0F12, 0x0001,},	// Capture mode AE On 
        {0x002A, 0x02B0,},
        {0x0F12, 0x0500,},	// REG_0TC_CCFG_usWidth 500:1280; 280:640
        {0x0F12, 0x03C0,},	// REG_0TC_CCFG_usHeight 3C0:960; 1E0:480 //yxq 0x03C0
        {0x0F12, 0x0005,},	// REG_0TC_CCFG_Format 5:YUV422; 7:RAW10  
        {0x002A, 0x02BA,},
        {0x0F12, 0x0000,},	// REG_0TC_CCFG_uClockInd
        {0x002A, 0x02B6,},
        {0x0F12, 0x0042,},	// REG_0TC_CCFG_PVIMask 52:YUV422; 42:RAW10 
        {0x002A, 0x02C6,},
        {0x0F12, 0x0002,},	// REG_0TC_CCFG_FrRateQualityType  1b:FR(bin) 2b:Quality(no-bin)
        {0x002A, 0x02C4,},
        {0x0F12, 0x0002,},	// REG_0TC_CCFG_usFrTimeType  0:dynamic; 1:fixed not accurate;  2:fixed accurate 
        {0x002A, 0x02CA,},
        {0x0F12, 0x014D,},	// REG_0TC_CCFG_usMaxFrTimeMsecMult10  30fps-014D; 15fps-029A; 7.5-0535; 6.0-0682; 3.75-0A6A 
        {0x002A, 0x02C8,},
        {0x0F12, 0x0000,},	// REG_0TC_CCFG_usMinFrTimeMsecMult10 
        
//*************************************/
// 21.Select Cofigration Display      */
//*************************************/
        {0x002A, 0x01A8,},
        {0x0F12, 0x0000,},// REG_TC_GP_ActivePreviewConfig */
        {0x002A, 0x01AA,},
        {0x0F12, 0x0001,},// REG_TC_GP_PreviewConfigChanged */
        {0x002A, 0x019E,},
        {0x0F12, 0x0001,},// REG_TC_GP_EnablePreview */
        {0x0F12, 0x0001,},// REG_TC_GP_EnablePreviewChanged */

        {0x0028, 0xD000,},
        {0x002A, 0x1000,},
        {0x0F12, 0x0001,},	// Set host interrupt 

};

static struct msm_camera_i2c_reg_conf s5k8aay_config_start_settings[] = {
	{0xFCFC, 0xD000,},
	{0x0010, 0x0001,},// S/W Reset */
	{0xFCFC, 0x0000,},
	{0x0000, 0x0000,},// Simmian bug workaround */

	{0xFCFC, 0xD000,},
	{0x1030, 0x0000,},// contint_host_int */
	{0x0014, 0x0001,},
};

static struct msm_camera_i2c_reg_conf s5k8aay_recommend_settings[] = {

//$MIPI[Width:1280,Height:960,Format:YUV422,Lane:1,ErrorCheck:0,PolarityData:0,PolarityClock:0,Buffer:2]

//============================================================
//	 00.History
//============================================================
//	 2011 : EVT1
//	 20111109 : LSI CSE Standard
//	 20111110 : Shading, AWB, Contrast Tuning
//	 20111114 : AE Weight Tuning
//	 20111229 : BPC Tuning, Shading Tuning
//	 20120128 : CCM Tuning, AE Weight Tuning, AE Target Tuning
//	 20120319 : Skintone Test, CCM Tuning
//	 20120320 : ColorShading Tuning, Modify TnP Setting
//	 20120323 : CCM Tuning, AWB Grid offset Tuning
//	 20120330 : Modigy AWB indoor boundary & AWB Grid offset
//	 20120402 : SKT VT-Call Tuning
//	 20120404 : NearGray Tuning
//	 20120406 : Shading Alpha Tuning
//	 20120407 : Outdoor Skintone Tuning
//============================================================


//*************************************/
// 01.Start Setting					  */
//*************************************/
/* Deleted by yxq 2012-08-04 start */
#if 0
        {0xFCFC, 0xD000,},
        {0x0010, 0x0001,},// S/W Reset */
        {0xFCFC, 0x0000,},
        {0x0000, 0x0000,},// Simmian bug workaround */

        {0xFCFC, 0xD000,},
        {0x1030, 0x0000,},// contint_host_int */
        {0x0014, 0x0001,},
#endif
/* Deleted by yxq 2012-08-04 end */

//*************************************/
// 02.Analog Setting & ASP Control    */
//*************************************/

//*************************************/
// 03.Trap and Patch                  */
//*************************************/
// Start of Patch data */
        {0x0028, 0x7000,},
        {0x002A, 0x2470,},
        {0x0F12, 0xB510,},
        {0x0F12, 0x490E,},
        {0x0F12, 0x480E,},
        {0x0F12, 0xF000,},
        {0x0F12, 0xF9ED,},
        {0x0F12, 0x490E,},
        {0x0F12, 0x480E,},
        {0x0F12, 0xF000,},
        {0x0F12, 0xF9E9,},
        {0x0F12, 0x490E,},
        {0x0F12, 0x480E,},
        {0x0F12, 0x6341,},
        {0x0F12, 0x490E,},
        {0x0F12, 0x480F,},
        {0x0F12, 0xF000,},
        {0x0F12, 0xF9E2,},
        {0x0F12, 0x490E,},
        {0x0F12, 0x480F,},
        {0x0F12, 0xF000,},
        {0x0F12, 0xF9DE,},
        {0x0F12, 0x490E,},
        {0x0F12, 0x480F,},
        {0x0F12, 0xF000,},
        {0x0F12, 0xF9DA,},
        {0x0F12, 0x480E,},
        {0x0F12, 0x490F,},
        {0x0F12, 0x6448,},
        {0x0F12, 0xBC10,},
        {0x0F12, 0xBC08,},
        {0x0F12, 0x4718,},
        {0x0F12, 0x27CC,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x8EDD,},
        {0x0F12, 0x0000,},
        {0x0F12, 0x2744,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x8725,},
        {0x0F12, 0x0000,},
        {0x0F12, 0x26E4,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x0080,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x2638,},
        {0x0F12, 0x7000,},
        {0x0F12, 0xA6EF,},
        {0x0F12, 0x0000,},
        {0x0F12, 0x2604,},
        {0x0F12, 0x7000,},
        {0x0F12, 0xA0F1,},
        {0x0F12, 0x0000,},
        {0x0F12, 0x25D0,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x058F,},
        {0x0F12, 0x0000,},
        {0x0F12, 0x24E4,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x0000,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x403E,},
        {0x0F12, 0xE92D,},
        {0x0F12, 0x00DD,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x2000,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x1002,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x0F86,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x00DC,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x200A,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x1000,},
        {0x0F12, 0xE28D,},
        {0x0F12, 0x0E3F,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x00DB,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x2001,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x1002,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x0F86,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x00D4,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE5DD,},
        {0x0F12, 0x00C3,},
        {0x0F12, 0xE350,},
        {0x0F12, 0x0027,},
        {0x0F12, 0x1A00,},
        {0x0F12, 0x0001,},
        {0x0F12, 0xE5DD,},
        {0x0F12, 0x003C,},
        {0x0F12, 0xE350,},
        {0x0F12, 0x0024,},
        {0x0F12, 0x1A00,},
        {0x0F12, 0x02E0,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x1000,},
        {0x0F12, 0xE5D0,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE351,},
        {0x0F12, 0x0003,},
        {0x0F12, 0x1A00,},
        {0x0F12, 0x12D4,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x10B8,},
        {0x0F12, 0xE1D1,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE351,},
        {0x0F12, 0x001C,},
        {0x0F12, 0x0A00,},
        {0x0F12, 0x1000,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x1000,},
        {0x0F12, 0xE5C0,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x1002,},
        {0x0F12, 0xE28D,},
        {0x0F12, 0x0015,},
        {0x0F12, 0xEA00,},
        {0x0F12, 0x2000,},
        {0x0F12, 0xE5D1,},
        {0x0F12, 0x3001,},
        {0x0F12, 0xE5D1,},
        {0x0F12, 0x3403,},
        {0x0F12, 0xE182,},
        {0x0F12, 0xC2A8,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x2080,},
        {0x0F12, 0xE08C,},
        {0x0F12, 0xE7B4,},
        {0x0F12, 0xE1D2,},
        {0x0F12, 0x039E,},
        {0x0F12, 0xE004,},
        {0x0F12, 0xE80F,},
        {0x0F12, 0xE3E0,},
        {0x0F12, 0x4624,},
        {0x0F12, 0xE00E,},
        {0x0F12, 0x47B4,},
        {0x0F12, 0xE1C2,},
        {0x0F12, 0x4004,},
        {0x0F12, 0xE280,},
        {0x0F12, 0xC084,},
        {0x0F12, 0xE08C,},
        {0x0F12, 0x47B4,},
        {0x0F12, 0xE1DC,},
        {0x0F12, 0x0493,},
        {0x0F12, 0xE004,},
        {0x0F12, 0x4624,},
        {0x0F12, 0xE00E,},
        {0x0F12, 0x47B4,},
        {0x0F12, 0xE1CC,},
        {0x0F12, 0xC8B4,},
        {0x0F12, 0xE1D2,},
        {0x0F12, 0x039C,},
        {0x0F12, 0xE003,},
        {0x0F12, 0x3623,},
        {0x0F12, 0xE00E,},
        {0x0F12, 0x38B4,},
        {0x0F12, 0xE1C2,},
        {0x0F12, 0x0001,},
        {0x0F12, 0xE280,},
        {0x0F12, 0x1002,},
        {0x0F12, 0xE281,},
        {0x0F12, 0x0004,},
        {0x0F12, 0xE350,},
        {0x0F12, 0xFFE7,},
        {0x0F12, 0xBAFF,},
        {0x0F12, 0x403E,},
        {0x0F12, 0xE8BD,},
        {0x0F12, 0xFF1E,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x4010,},
        {0x0F12, 0xE92D,},
        {0x0F12, 0x00AB,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x0248,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x00B2,},
        {0x0F12, 0xE1D0,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE350,},
        {0x0F12, 0x0004,},
        {0x0F12, 0x0A00,},
        {0x0F12, 0x0080,},
        {0x0F12, 0xE310,},
        {0x0F12, 0x0002,},
        {0x0F12, 0x1A00,},
        {0x0F12, 0x1234,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x0001,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x0DB2,},
        {0x0F12, 0xE1C1,},
        {0x0F12, 0x4010,},
        {0x0F12, 0xE8BD,},
        {0x0F12, 0xFF1E,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x4010,},
        {0x0F12, 0xE92D,},
        {0x0F12, 0x4000,},
        {0x0F12, 0xE590,},
        {0x0F12, 0x0004,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x009F,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x0214,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE5D0,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE350,},
        {0x0F12, 0x0002,},
        {0x0F12, 0x0A00,},
        {0x0F12, 0x0004,},
        {0x0F12, 0xE594,},
        {0x0F12, 0x00A0,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x0004,},
        {0x0F12, 0xE584,},
        {0x0F12, 0x4010,},
        {0x0F12, 0xE8BD,},
        {0x0F12, 0xFF1E,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x4070,},
        {0x0F12, 0xE92D,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE590,},
        {0x0F12, 0x0800,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x0820,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x4041,},
        {0x0F12, 0xE280,},
        {0x0F12, 0x01E0,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x11B8,},
        {0x0F12, 0xE1D0,},
        {0x0F12, 0x51B6,},
        {0x0F12, 0xE1D0,},
        {0x0F12, 0x0005,},
        {0x0F12, 0xE041,},
        {0x0F12, 0x0094,},
        {0x0F12, 0xE000,},
        {0x0F12, 0x1D11,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x008D,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x11C0,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x1000,},
        {0x0F12, 0xE5D1,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE351,},
        {0x0F12, 0x0000,},
        {0x0F12, 0x0A00,},
        {0x0F12, 0x00A0,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x21A8,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x3FB0,},
        {0x0F12, 0xE1D2,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE353,},
        {0x0F12, 0x0003,},
        {0x0F12, 0x0A00,},
        {0x0F12, 0x31A4,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x5BB2,},
        {0x0F12, 0xE1C3,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE085,},
        {0x0F12, 0xCBB4,},
        {0x0F12, 0xE1C3,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE351,},
        {0x0F12, 0x0000,},
        {0x0F12, 0x0A00,},
        {0x0F12, 0x0080,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x1DBC,},
        {0x0F12, 0xE1D2,},
        {0x0F12, 0x3EB4,},
        {0x0F12, 0xE1D2,},
        {0x0F12, 0x2EB2,},
        {0x0F12, 0xE1D2,},
        {0x0F12, 0x0193,},
        {0x0F12, 0xE001,},
        {0x0F12, 0x0092,},
        {0x0F12, 0xE000,},
        {0x0F12, 0x2811,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x0194,},
        {0x0F12, 0xE001,},
        {0x0F12, 0x0092,},
        {0x0F12, 0xE000,},
        {0x0F12, 0x11A1,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x01A0,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x0072,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x1160,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x02B4,},
        {0x0F12, 0xE1C1,},
        {0x0F12, 0x4070,},
        {0x0F12, 0xE8BD,},
        {0x0F12, 0xFF1E,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x4010,},
        {0x0F12, 0xE92D,},
        {0x0F12, 0x006E,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x2148,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x14B0,},
        {0x0F12, 0xE1D2,},
        {0x0F12, 0x0080,},
        {0x0F12, 0xE311,},
        {0x0F12, 0x0005,},
        {0x0F12, 0x0A00,},
        {0x0F12, 0x013C,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x00B0,},
        {0x0F12, 0xE1D0,},
        {0x0F12, 0x0001,},
        {0x0F12, 0xE350,},
        {0x0F12, 0x0001,},
        {0x0F12, 0x9A00,},
        {0x0F12, 0x0001,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xEA00,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x3110,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE5C3,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE5D3,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE350,},
        {0x0F12, 0x0003,},
        {0x0F12, 0x0A00,},
        {0x0F12, 0x0080,},
        {0x0F12, 0xE3C1,},
        {0x0F12, 0x110C,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x04B0,},
        {0x0F12, 0xE1C2,},
        {0x0F12, 0x00B2,},
        {0x0F12, 0xE1C1,},
        {0x0F12, 0x4010,},
        {0x0F12, 0xE8BD,},
        {0x0F12, 0xFF1E,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x41F0,},
        {0x0F12, 0xE92D,},
        {0x0F12, 0x1000,},
        {0x0F12, 0xE590,},
        {0x0F12, 0xC801,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0xC82C,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x1004,},
        {0x0F12, 0xE590,},
        {0x0F12, 0x1801,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x1821,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x4008,},
        {0x0F12, 0xE590,},
        {0x0F12, 0x500C,},
        {0x0F12, 0xE590,},
        {0x0F12, 0x2004,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x3005,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x000C,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x004E,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x60A0,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x00B2,},
        {0x0F12, 0xE1D6,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE350,},
        {0x0F12, 0x000E,},
        {0x0F12, 0x0A00,},
        {0x0F12, 0x00B8,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x05B4,},
        {0x0F12, 0xE1D0,},
        {0x0F12, 0x0002,},
        {0x0F12, 0xE350,},
        {0x0F12, 0x000A,},
        {0x0F12, 0x1A00,},
        {0x0F12, 0x70AC,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x10F4,},
        {0x0F12, 0xE1D6,},
        {0x0F12, 0x26B0,},
        {0x0F12, 0xE1D7,},
        {0x0F12, 0x00F0,},
        {0x0F12, 0xE1D4,},
        {0x0F12, 0x0044,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x00B0,},
        {0x0F12, 0xE1C4,},
        {0x0F12, 0x26B0,},
        {0x0F12, 0xE1D7,},
        {0x0F12, 0x10F6,},
        {0x0F12, 0xE1D6,},
        {0x0F12, 0x00F0,},
        {0x0F12, 0xE1D5,},
        {0x0F12, 0x003F,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x00B0,},
        {0x0F12, 0xE1C5,},
        {0x0F12, 0x41F0,},
        {0x0F12, 0xE8BD,},
        {0x0F12, 0xFF1E,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x4010,},
        {0x0F12, 0xE92D,},
        {0x0F12, 0x4000,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x1004,},
        {0x0F12, 0xE594,},
        {0x0F12, 0x0040,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x00B0,},
        {0x0F12, 0xE1D0,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE350,},
        {0x0F12, 0x0008,},
        {0x0F12, 0x0A00,},
        {0x0F12, 0x005C,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x3001,},
        {0x0F12, 0xE1A0,},
        {0x0F12, 0x2068,},
        {0x0F12, 0xE590,},
        {0x0F12, 0x0054,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0x1005,},
        {0x0F12, 0xE3A0,},
        {0x0F12, 0x0032,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE584,},
        {0x0F12, 0x4010,},
        {0x0F12, 0xE8BD,},
        {0x0F12, 0xFF1E,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE594,},
        {0x0F12, 0x0030,},
        {0x0F12, 0xEB00,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xE584,},
        {0x0F12, 0xFFF9,},
        {0x0F12, 0xEAFF,},
        {0x0F12, 0x28E8,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x3370,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x1272,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x1728,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x112C,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x28EC,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x122C,},
        {0x0F12, 0x7000,},
        {0x0F12, 0xF200,},
        {0x0F12, 0xD000,},
        {0x0F12, 0x2340,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x0E2C,},
        {0x0F12, 0x7000,},
        {0x0F12, 0xF400,},
        {0x0F12, 0xD000,},
        {0x0F12, 0x0CDC,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x20D4,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x06D4,},
        {0x0F12, 0x7000,},
        {0x0F12, 0x4778,},
        {0x0F12, 0x46C0,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0xC091,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x0467,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x2FA7,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0xCB1F,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x058F,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0xA0F1,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xF004,},
        {0x0F12, 0xE51F,},
        {0x0F12, 0xD14C,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x2B43,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x8725,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x6777,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x8E49,},
        {0x0F12, 0x0000,},
        {0x0F12, 0xC000,},
        {0x0F12, 0xE59F,},
        {0x0F12, 0xFF1C,},
        {0x0F12, 0xE12F,},
        {0x0F12, 0x8EDD,},
        {0x0F12, 0x0000,},
        {0x0F12, 0x96FF,},
        {0x0F12, 0x0000,},
        {0x0F12, 0x0001,},
        {0x0F12, 0x0000,},
// End of Patch Data(Last : 700027C2h) */
// Total Size 852 (0x0354)             */
// Addr : 2470 , Size : 850(352h)      */

//==================================================================================
// 04.Analog Setting & APS Control
//==================================================================================
//This register is for FACTORY ONLY. 
//If you change it without prior notification
//YOU are RESPONSIBLE for the FAILURE that will happen in the future
        {0x0028, 0x7000,},
        {0x002A, 0x0E38,},
        {0x0F12, 0x0476,},	//senHal_RegCompBiasNormSf //CDS bias
        {0x0F12, 0x0476,},	//senHal_RegCompBiasYAv //CDS bias
        {0x002A, 0x0AA0,},
        {0x0F12, 0x0001,},	//setot_bUseDigitalHbin //1-Digital, 0-Analog
        {0x002A, 0x0E2C,},
        {0x0F12, 0x0001,},	//senHal_bUseAnalogVerAv //2-Adding/averaging, 1-Y-Avg, 0-PLA
        {0x002A, 0x0E66,},
        {0x0F12, 0x0001,},	//senHal_RegBlstEnNorm
        {0x002A, 0x1250,},
        {0x0F12, 0xFFFF,}, 	//senHal_Bls_nSpExpLines
        {0x002A, 0x1202,},
        {0x0F12, 0x0010,}, 	//senHal_Dblr_VcoFreqMHZ
//ADLC Filter
        {0x002A, 0x1288,},
        {0x0F12, 0x020F,},	//gisp_dadlc_ResetFilterValue
        {0x0F12, 0x1C02,},	//gisp_dadlc_SteadyFilterValue
        {0x0F12, 0x0006,},	//gisp_dadlc_NResetIIrFrames	

//*************************************/
// 05.OTP Control                     */
//*************************************/
        {0x002A, 0x3378,},
        {0x0F12, 0x0000,},// Tune_TP_bReMultGainsByNvm */

//*********************************************************************************
// 06.GAS (Grid Anti-Shading)                                                     
//*********************************************************************************
        {0x002A, 0x1326,},
        {0x0F12, 0x0000,},	// gisp_gos_Enable 
        {0x002A, 0x063A,},
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_0__0_ Horizon 
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_0__1_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_0__2_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_0__3_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_1__0_ IncandA 
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_1__1_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_1__2_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_1__3_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_2__0_ WW      
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_2__1_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_2__2_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_2__3_         
        {0x0F12, 0x00E8,},	// TVAR_ash_GASAlpha_3__0_ CW      
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_3__1_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_3__2_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_3__3_         
        {0x0F12, 0x00C8,},	// TVAR_ash_GASAlpha_4__0_ D50     
        {0x0F12, 0x00F8,},	// TVAR_ash_GASAlpha_4__1_         
        {0x0F12, 0x00F8,},	// TVAR_ash_GASAlpha_4__2_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_4__3_         
        {0x0F12, 0x00F0,},	// TVAR_ash_GASAlpha_5__0_ D65     
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_5__1_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_5__2_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_5__3_         
        {0x0F12, 0x00F0,},	// TVAR_ash_GASAlpha_6__0_ D75     
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_6__1_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_6__2_         
        {0x0F12, 0x0100,},	// TVAR_ash_GASAlpha_6__3_         
        {0x002A, 0x067A,},
        {0x0F12, 0x0000,},	// ash_GASBeta_0__0_ Horizon 
        {0x0F12, 0x0000,},	// ash_GASBeta_0__1_         
        {0x0F12, 0x0000,},	// ash_GASBeta_0__2_         
        {0x0F12, 0x0000,},	// ash_GASBeta_0__3_         
        {0x0F12, 0x0000,},	// ash_GASBeta_1__0_ IncandA 
        {0x0F12, 0x0000,},	// ash_GASBeta_1__1_         
        {0x0F12, 0x0000,},	// ash_GASBeta_1__2_         
        {0x0F12, 0x0000,},	// ash_GASBeta_1__3_         
        {0x0F12, 0x0000,},	// ash_GASBeta_2__0_ WW      
        {0x0F12, 0x0000,},	// ash_GASBeta_2__1_         
        {0x0F12, 0x0000,},	// ash_GASBeta_2__2_         
        {0x0F12, 0x0000,},	// ash_GASBeta_2__3_         
        {0x0F12, 0x0000,},	// ash_GASBeta_3__0_ CW      
        {0x0F12, 0x0000,},	// ash_GASBeta_3__1_         
        {0x0F12, 0x0000,},	// ash_GASBeta_3__2_         
        {0x0F12, 0x0000,},	// ash_GASBeta_3__3_         
        {0x0F12, 0x0000,},	// ash_GASBeta_4__0_ D50     
        {0x0F12, 0x0000,},	// ash_GASBeta_4__1_         
        {0x0F12, 0x0000,},	// ash_GASBeta_4__2_         
        {0x0F12, 0x0000,},	// ash_GASBeta_4__3_         
        {0x0F12, 0x0000,},	// ash_GASBeta_5__0_ D65     
        {0x0F12, 0x0000,},	// ash_GASBeta_5__1_         
        {0x0F12, 0x0000,},	// ash_GASBeta_5__2_         
        {0x0F12, 0x0000,},	// ash_GASBeta_5__3_         
        {0x0F12, 0x0000,},	// ash_GASBeta_6__0_ D75     
        {0x0F12, 0x0000,},	// ash_GASBeta_6__1_         
        {0x0F12, 0x0000,},	// ash_GASBeta_6__2_         
        {0x0F12, 0x0000,},	// ash_GASBeta_6__3_         
        {0x002A, 0x06BA,},
        {0x0F12, 0x0001,},	//ash_bLumaMode 
        {0x002A, 0x0632,},
        {0x0F12, 0x0100,},	// ash_CGrasAlphas_0_ 
        {0x0F12, 0x0100,},	// ash_CGrasAlphas_1_ 
        {0x0F12, 0x0100,},	// ash_CGrasAlphas_2_ 
        {0x0F12, 0x0100,},	// ash_CGrasAlphas_3_ 
        {0x002A, 0x0672,},
        {0x0F12, 0x0100,},	// TVAR_ash_GASOutdoorAlpha_0_ 
        {0x0F12, 0x0100,},	// TVAR_ash_GASOutdoorAlpha_1_ 
        {0x0F12, 0x0100,},	// TVAR_ash_GASOutdoorAlpha_2_ 
        {0x0F12, 0x0100,},	// TVAR_ash_GASOutdoorAlpha_3_ 
        {0x002A, 0x06B2,},
        {0x0F12, 0x0000,},	// ash_GASOutdoorBeta_0_ 
        {0x0F12, 0x0000,},	// ash_GASOutdoorBeta_1_ 
        {0x0F12, 0x0000,},	// ash_GASOutdoorBeta_2_ 
        {0x0F12, 0x0000,},	// ash_GASOutdoorBeta_3_ 
        {0x002A, 0x06D0,},
        {0x0F12, 0x000D,},	// ash_uParabolicScalingA
        {0x0F12, 0x000F,},	// ash_uParabolicScalingB
        {0x002A, 0x06CC,},
        {0x0F12, 0x0280,},	// ash_uParabolicCenterX 
        {0x0F12, 0x01E0,},	// ash_uParabolicCenterY 
        {0x002A, 0x06C6,},
        {0x0F12, 0x0001,},	// ash_bParabolicEstimation 
        {0x002A, 0x0624,},
        {0x0F12, 0x009D,},	// TVAR_ash_AwbAshCord_0_ Horizon 
        {0x0F12, 0x00D5,},	// TVAR_ash_AwbAshCord_1_ IncandA 
        {0x0F12, 0x0103,},	// TVAR_ash_AwbAshCord_2_ WW      
        {0x0F12, 0x0128,},	// TVAR_ash_AwbAshCord_3_ CW      
        {0x0F12, 0x0166,},	// TVAR_ash_AwbAshCord_4_ D50     
        {0x0F12, 0x0193,},	// TVAR_ash_AwbAshCord_5_ D65     
        {0x0F12, 0x01A0,},	// TVAR_ash_AwbAshCord_6_ D75  

        {0x002A, 0x347C,},
        {0x0F12, 0x013B,},	// 011A 012F Tune_wbt_GAS_0_   
        {0x0F12, 0x0116,},	// 011A 0111 Tune_wbt_GAS_1_   
        {0x0F12, 0x00D9,},	// 00EE 00D6 Tune_wbt_GAS_2_   
        {0x0F12, 0x00A6,},	// 00C1 009E Tune_wbt_GAS_3_   
        {0x0F12, 0x0082,},	// 009E 007A Tune_wbt_GAS_4_   
        {0x0F12, 0x006C,},	// 008A 0064 Tune_wbt_GAS_5_   
        {0x0F12, 0x0065,},	// 0083 005D Tune_wbt_GAS_6_   
        {0x0F12, 0x006C,},	// 008A 0063 Tune_wbt_GAS_7_   
        {0x0F12, 0x0080,},	// 009E 007B Tune_wbt_GAS_8_   
        {0x0F12, 0x00A3,},	// 00BF 00A3 Tune_wbt_GAS_9_   
        {0x0F12, 0x00D4,},	// 00E5 00E3 Tune_wbt_GAS_10_  
        {0x0F12, 0x010D,},	// 00F9 013B Tune_wbt_GAS_11_  
        {0x0F12, 0x012E,},	// 0124 018B Tune_wbt_GAS_12_  
        {0x0F12, 0x0138,},	// 0126 012B Tune_wbt_GAS_13_  
        {0x0F12, 0x0104,},	// 010E 00F6 Tune_wbt_GAS_14_  
        {0x0F12, 0x00BE,},	// 00D3 00B2 Tune_wbt_GAS_15_  
        {0x0F12, 0x0088,},	// 009F 007B Tune_wbt_GAS_16_  
        {0x0F12, 0x0062,},	// 007C 0057 Tune_wbt_GAS_17_  
        {0x0F12, 0x004D,},	// 0068 0042 Tune_wbt_GAS_18_  
        {0x0F12, 0x0046,},	// 0061 0039 Tune_wbt_GAS_19_  
        {0x0F12, 0x004C,},	// 0068 003F Tune_wbt_GAS_20_  
        {0x0F12, 0x0060,},	// 007E 0053 Tune_wbt_GAS_21_  
        {0x0F12, 0x0084,},	// 00A3 007A Tune_wbt_GAS_22_  
        {0x0F12, 0x00B8,},	// 00C9 00B6 Tune_wbt_GAS_23_  
        {0x0F12, 0x00F9,},	// 00F0 0110 Tune_wbt_GAS_24_  
        {0x0F12, 0x012C,},	// 0131 016A Tune_wbt_GAS_25_  
        {0x0F12, 0x011A,},	// 011C 0114 Tune_wbt_GAS_26_  
        {0x0F12, 0x00DB,},	// 00EB 00D4 Tune_wbt_GAS_27_  
        {0x0F12, 0x0093,},	// 00AA 008F Tune_wbt_GAS_28_  
        {0x0F12, 0x005F,},	// 0075 005A Tune_wbt_GAS_29_  
        {0x0F12, 0x003C,},	// 0053 0035 Tune_wbt_GAS_30_  
        {0x0F12, 0x0027,},	// 003F 0020 Tune_wbt_GAS_31_  
        {0x0F12, 0x0020,},	// 0038 0019 Tune_wbt_GAS_32_  
        {0x0F12, 0x0026,},	// 0040 001F Tune_wbt_GAS_33_  
        {0x0F12, 0x003A,},	// 0055 0032 Tune_wbt_GAS_34_  
        {0x0F12, 0x005C,},	// 007A 0056 Tune_wbt_GAS_35_  
        {0x0F12, 0x008E,},	// 00A6 008E Tune_wbt_GAS_36_  
        {0x0F12, 0x00D2,},	// 00D5 00E6 Tune_wbt_GAS_37_  
        {0x0F12, 0x010E,},	// 0126 0142 Tune_wbt_GAS_38_  
        {0x0F12, 0x0101,},	// 00F6 0102 Tune_wbt_GAS_39_  
        {0x0F12, 0x00BF,},	// 00C0 00BE Tune_wbt_GAS_40_  
        {0x0F12, 0x0077,},	// 007D 0077 Tune_wbt_GAS_41_  
        {0x0F12, 0x0044,},	// 004D 0045 Tune_wbt_GAS_42_  
        {0x0F12, 0x0023,},	// 002C 0022 Tune_wbt_GAS_43_  
        {0x0F12, 0x0011,},	// 001B 000D Tune_wbt_GAS_44_  
        {0x0F12, 0x000C,},	// 0017 0006 Tune_wbt_GAS_45_  
        {0x0F12, 0x0010,},	// 001B 000A Tune_wbt_GAS_46_  
        {0x0F12, 0x0022,},	// 002D 001D Tune_wbt_GAS_47_  
        {0x0F12, 0x0043,},	// 004E 003F Tune_wbt_GAS_48_  
        {0x0F12, 0x0074,},	// 0080 0075 Tune_wbt_GAS_49_  
        {0x0F12, 0x00B7,},	// 00C1 00CC Tune_wbt_GAS_50_  
        {0x0F12, 0x00F7,},	// 00FF 0126 Tune_wbt_GAS_51_  
        {0x0F12, 0x00FC,},	// 00EA 00FB Tune_wbt_GAS_52_  
        {0x0F12, 0x00B7,},	// 00B0 00B7 Tune_wbt_GAS_53_  
        {0x0F12, 0x006F,},	// 006D 0070 Tune_wbt_GAS_54_  
        {0x0F12, 0x003C,},	// 003D 003D Tune_wbt_GAS_55_  
        {0x0F12, 0x001C,},	// 001E 001B Tune_wbt_GAS_56_  
        {0x0F12, 0x000A,},	// 000F 0007 Tune_wbt_GAS_57_  
        {0x0F12, 0x0004,},	// 000A 0000 Tune_wbt_GAS_58_  
        {0x0F12, 0x000A,},	// 0010 0004 Tune_wbt_GAS_59_  
        {0x0F12, 0x001B,},	// 001E 0015 Tune_wbt_GAS_60_  
        {0x0F12, 0x003B,},	// 003E 0034 Tune_wbt_GAS_61_  
        {0x0F12, 0x006C,},	// 006F 006A Tune_wbt_GAS_62_  
        {0x0F12, 0x00B0,},	// 00B2 00C0 Tune_wbt_GAS_63_  
        {0x0F12, 0x00F2,},	// 00F1 011B Tune_wbt_GAS_64_  
        {0x0F12, 0x00EF,},	// 00E0 0102 Tune_wbt_GAS_65_  
        {0x0F12, 0x00AB,},	// 00A6 00BA Tune_wbt_GAS_66_  
        {0x0F12, 0x0065,},	// 0063 0073 Tune_wbt_GAS_67_  
        {0x0F12, 0x0034,},	// 0033 0040 Tune_wbt_GAS_68_  
        {0x0F12, 0x0015,},	// 0016 001D Tune_wbt_GAS_69_  
        {0x0F12, 0x0004,},	// 0008 0009 Tune_wbt_GAS_70_  
        {0x0F12, 0x0000,},	// 0003 0001 Tune_wbt_GAS_71_  
        {0x0F12, 0x0004,},	// 0009 0006 Tune_wbt_GAS_72_  
        {0x0F12, 0x0013,},	// 0016 0017 Tune_wbt_GAS_73_  
        {0x0F12, 0x0033,},	// 0035 0039 Tune_wbt_GAS_74_  
        {0x0F12, 0x0063,},	// 0066 006F Tune_wbt_GAS_75_  
        {0x0F12, 0x00A5,},	// 00A7 00C8 Tune_wbt_GAS_76_  
        {0x0F12, 0x00E5,},	// 00E9 011E Tune_wbt_GAS_77_  
        {0x0F12, 0x00F7,},	// 00D5 0111 Tune_wbt_GAS_78_  
        {0x0F12, 0x00B4,},	// 009D 00C8 Tune_wbt_GAS_79_  
        {0x0F12, 0x006D,},	// 005D 0081 Tune_wbt_GAS_80_  
        {0x0F12, 0x003C,},	// 002F 004D Tune_wbt_GAS_81_  
        {0x0F12, 0x001C,},	// 0010 0028 Tune_wbt_GAS_82_  
        {0x0F12, 0x000B,},	// 0004 0014 Tune_wbt_GAS_83_  
        {0x0F12, 0x0005,},	// 0001 000B Tune_wbt_GAS_84_  
        {0x0F12, 0x000A,},	// 0005 0010 Tune_wbt_GAS_85_  
        {0x0F12, 0x001B,},	// 0013 0022 Tune_wbt_GAS_86_  
        {0x0F12, 0x003B,},	// 0031 0047 Tune_wbt_GAS_87_  
        {0x0F12, 0x006B,},	// 005F 007E Tune_wbt_GAS_88_  
        {0x0F12, 0x00AD,},	// 00A1 00D8 Tune_wbt_GAS_89_  
        {0x0F12, 0x00ED,},	// 00DF 0131 Tune_wbt_GAS_90_  
        {0x0F12, 0x010B,},	// 00E9 0129 Tune_wbt_GAS_91_  
        {0x0F12, 0x00CB,},	// 00B2 00E4 Tune_wbt_GAS_92_  
        {0x0F12, 0x0085,},	// 006F 009E Tune_wbt_GAS_93_  
        {0x0F12, 0x0051,},	// 003F 0068 Tune_wbt_GAS_94_  
        {0x0F12, 0x002F,},	// 0020 0041 Tune_wbt_GAS_95_  
        {0x0F12, 0x001C,},	// 000F 002B Tune_wbt_GAS_96_  
        {0x0F12, 0x0016,},	// 000B 0023 Tune_wbt_GAS_97_  
        {0x0F12, 0x001C,},	// 0010 0028 Tune_wbt_GAS_98_  
        {0x0F12, 0x002E,},	// 0021 003B Tune_wbt_GAS_99_  
        {0x0F12, 0x004F,},	// 0041 0063 Tune_wbt_GAS_100_ 
        {0x0F12, 0x0081,},	// 0071 00A0 Tune_wbt_GAS_101_ 
        {0x0F12, 0x00C4,},	// 00B4 00FD Tune_wbt_GAS_102_ 
        {0x0F12, 0x0102,},	// 00F6 015A Tune_wbt_GAS_103_ 
        {0x0F12, 0x0119,},	// 00F9 014A Tune_wbt_GAS_104_ 
        {0x0F12, 0x00DF,},	// 00C2 010D Tune_wbt_GAS_105_ 
        {0x0F12, 0x009B,},	// 0082 00CA Tune_wbt_GAS_106_ 
        {0x0F12, 0x0067,},	// 0053 008F Tune_wbt_GAS_107_ 
        {0x0F12, 0x0045,},	// 0033 0066 Tune_wbt_GAS_108_ 
        {0x0F12, 0x0030,},	// 0021 004F Tune_wbt_GAS_109_ 
        {0x0F12, 0x0029,},	// 001C 0048 Tune_wbt_GAS_110_ 
        {0x0F12, 0x002F,},	// 0022 004E Tune_wbt_GAS_111_ 
        {0x0F12, 0x0043,},	// 0035 0067 Tune_wbt_GAS_112_ 
        {0x0F12, 0x0066,},	// 0056 008F Tune_wbt_GAS_113_ 
        {0x0F12, 0x0098,},	// 0087 00D1 Tune_wbt_GAS_114_ 
        {0x0F12, 0x00D9,},	// 00CA 0132 Tune_wbt_GAS_115_ 
        {0x0F12, 0x010F,},	// 0107 018D Tune_wbt_GAS_116_ 
        {0x0F12, 0x0138,},	// 0108 0159 Tune_wbt_GAS_117_ 
        {0x0F12, 0x010C,},	// 00E0 0141 Tune_wbt_GAS_118_ 
        {0x0F12, 0x00CB,},	// 00A2 0103 Tune_wbt_GAS_119_ 
        {0x0F12, 0x0097,},	// 0072 00C9 Tune_wbt_GAS_120_ 
        {0x0F12, 0x0073,},	// 0052 009E Tune_wbt_GAS_121_ 
        {0x0F12, 0x005C,},	// 0040 0087 Tune_wbt_GAS_122_ 
        {0x0F12, 0x0054,},	// 003A 007D Tune_wbt_GAS_123_ 
        {0x0F12, 0x005B,},	// 0041 0087 Tune_wbt_GAS_124_ 
        {0x0F12, 0x0070,},	// 0055 00A2 Tune_wbt_GAS_125_ 
        {0x0F12, 0x0096,},	// 0077 00D4 Tune_wbt_GAS_126_ 
        {0x0F12, 0x00C9,},	// 00A8 011A Tune_wbt_GAS_127_ 
        {0x0F12, 0x0106,},	// 00E7 017D Tune_wbt_GAS_128_ 
        {0x0F12, 0x012D,},	// 011E 01CF Tune_wbt_GAS_129_ 
        {0x0F12, 0x0147,},	// 0123 0181 Tune_wbt_GAS_130_ 
        {0x0F12, 0x012F,},	// 0100 0169 Tune_wbt_GAS_131_ 
        {0x0F12, 0x00F8,},	// 00CB 0140 Tune_wbt_GAS_132_ 
        {0x0F12, 0x00C5,},	// 009A 0106 Tune_wbt_GAS_133_ 
        {0x0F12, 0x00A1,},	// 0079 00DD Tune_wbt_GAS_134_ 
        {0x0F12, 0x008B,},	// 0067 00C5 Tune_wbt_GAS_135_ 
        {0x0F12, 0x0083,},	// 0060 00BE Tune_wbt_GAS_136_ 
        {0x0F12, 0x008B,},	// 0068 00C8 Tune_wbt_GAS_137_ 
        {0x0F12, 0x00A0,},	// 007B 00E6 Tune_wbt_GAS_138_ 
        {0x0F12, 0x00C2,},	// 009D 011B Tune_wbt_GAS_139_ 
        {0x0F12, 0x00F3,},	// 00CD 015F Tune_wbt_GAS_140_ 
        {0x0F12, 0x0124,},	// 0108 01BC Tune_wbt_GAS_141_ 
        {0x0F12, 0x0139,},	// 0131 0206 Tune_wbt_GAS_142_ 
        {0x0F12, 0x0093,},	// 006C 00A8 Tune_wbt_GAS_143_ 
        {0x0F12, 0x007E,},	// 006E 008F Tune_wbt_GAS_144_ 
        {0x0F12, 0x0062,},	// 005D 006F Tune_wbt_GAS_145_ 
        {0x0F12, 0x004D,},	// 004C 0054 Tune_wbt_GAS_146_ 
        {0x0F12, 0x003E,},	// 0040 0041 Tune_wbt_GAS_147_ 
        {0x0F12, 0x0034,},	// 0037 0036 Tune_wbt_GAS_148_ 
        {0x0F12, 0x0030,},	// 0035 0033 Tune_wbt_GAS_149_ 
        {0x0F12, 0x0032,},	// 0036 0037 Tune_wbt_GAS_150_ 
        {0x0F12, 0x003B,},	// 003F 0045 Tune_wbt_GAS_151_ 
        {0x0F12, 0x0049,},	// 004B 005A Tune_wbt_GAS_152_ 
        {0x0F12, 0x005C,},	// 0053 007A Tune_wbt_GAS_153_ 
        {0x0F12, 0x0077,},	// 0053 00AA Tune_wbt_GAS_154_ 
        {0x0F12, 0x008A,},	// 0070 00E2 Tune_wbt_GAS_155_ 
        {0x0F12, 0x0093,},	// 0075 009E Tune_wbt_GAS_156_ 
        {0x0F12, 0x0077,},	// 006D 007D Tune_wbt_GAS_157_ 
        {0x0F12, 0x0059,},	// 0056 005A Tune_wbt_GAS_158_ 
        {0x0F12, 0x0042,},	// 0043 0041 Tune_wbt_GAS_159_ 
        {0x0F12, 0x0032,},	// 0037 002E Tune_wbt_GAS_160_ 
        {0x0F12, 0x0027,},	// 002F 0022 Tune_wbt_GAS_161_ 
        {0x0F12, 0x0024,},	// 002C 001F Tune_wbt_GAS_162_ 
        {0x0F12, 0x0026,},	// 002F 0022 Tune_wbt_GAS_163_ 
        {0x0F12, 0x002F,},	// 0038 0030 Tune_wbt_GAS_164_ 
        {0x0F12, 0x003D,},	// 0045 0044 Tune_wbt_GAS_165_ 
        {0x0F12, 0x0052,},	// 004E 0063 Tune_wbt_GAS_166_ 
        {0x0F12, 0x006E,},	// 0055 0091 Tune_wbt_GAS_167_ 
        {0x0F12, 0x008B,},	// 007F 00CB Tune_wbt_GAS_168_ 
        {0x0F12, 0x0083,},	// 0077 0093 Tune_wbt_GAS_169_ 
        {0x0F12, 0x0064,},	// 0062 006D Tune_wbt_GAS_170_ 
        {0x0F12, 0x0046,},	// 004A 004A Tune_wbt_GAS_171_ 
        {0x0F12, 0x0030,},	// 0037 0031 Tune_wbt_GAS_172_ 
        {0x0F12, 0x0020,},	// 002A 001E Tune_wbt_GAS_173_ 
        {0x0F12, 0x0016,},	// 0021 0013 Tune_wbt_GAS_174_ 
        {0x0F12, 0x0011,},	// 001E 000F Tune_wbt_GAS_175_ 
        {0x0F12, 0x0014,},	// 0021 0013 Tune_wbt_GAS_176_ 
        {0x0F12, 0x001E,},	// 002B 001F Tune_wbt_GAS_177_ 
        {0x0F12, 0x002D,},	// 003B 0034 Tune_wbt_GAS_178_ 
        {0x0F12, 0x0041,},	// 0046 0051 Tune_wbt_GAS_179_ 
        {0x0F12, 0x005D,},	// 0051 007C Tune_wbt_GAS_180_ 
        {0x0F12, 0x007C,},	// 007F 00B7 Tune_wbt_GAS_181_ 
        {0x0F12, 0x0077,},	// 0062 008A Tune_wbt_GAS_182_ 
        {0x0F12, 0x0057,},	// 004B 0061 Tune_wbt_GAS_183_ 
        {0x0F12, 0x0039,},	// 0034 003E Tune_wbt_GAS_184_ 
        {0x0F12, 0x0024,},	// 0022 0026 Tune_wbt_GAS_185_ 
        {0x0F12, 0x0014,},	// 0014 0013 Tune_wbt_GAS_186_ 
        {0x0F12, 0x000A,},	// 000E 0008 Tune_wbt_GAS_187_ 
        {0x0F12, 0x0007,},	// 000C 0004 Tune_wbt_GAS_188_ 
        {0x0F12, 0x0009,},	// 000D 0007 Tune_wbt_GAS_189_ 
        {0x0F12, 0x0012,},	// 0016 0013 Tune_wbt_GAS_190_ 
        {0x0F12, 0x0021,},	// 0024 0027 Tune_wbt_GAS_191_ 
        {0x0F12, 0x0036,},	// 0036 0045 Tune_wbt_GAS_192_ 
        {0x0F12, 0x0051,},	// 004E 0070 Tune_wbt_GAS_193_ 
        {0x0F12, 0x0070,},	// 0069 00A7 Tune_wbt_GAS_194_ 
        {0x0F12, 0x0077,},	// 005F 0085 Tune_wbt_GAS_195_ 
        {0x0F12, 0x0056,},	// 0048 005D Tune_wbt_GAS_196_ 
        {0x0F12, 0x0038,},	// 002F 003A Tune_wbt_GAS_197_ 
        {0x0F12, 0x0022,},	// 001C 0021 Tune_wbt_GAS_198_ 
        {0x0F12, 0x0013,},	// 0010 0010 Tune_wbt_GAS_199_ 
        {0x0F12, 0x0009,},	// 000B 0004 Tune_wbt_GAS_200_ 
        {0x0F12, 0x0005,},	// 0008 0000 Tune_wbt_GAS_201_ 
        {0x0F12, 0x0008,},	// 000B 0003 Tune_wbt_GAS_202_ 
        {0x0F12, 0x0011,},	// 0010 000E Tune_wbt_GAS_203_ 
        {0x0F12, 0x0020,},	// 001E 0021 Tune_wbt_GAS_204_ 
        {0x0F12, 0x0035,},	// 0031 003F Tune_wbt_GAS_205_ 
        {0x0F12, 0x0051,},	// 0049 006B Tune_wbt_GAS_206_ 
        {0x0F12, 0x0071,},	// 0066 00A1 Tune_wbt_GAS_207_ 
        {0x0F12, 0x006E,},	// 005B 0089 Tune_wbt_GAS_208_ 
        {0x0F12, 0x004E,},	// 0043 0060 Tune_wbt_GAS_209_ 
        {0x0F12, 0x0032,},	// 002B 003D Tune_wbt_GAS_210_ 
        {0x0F12, 0x001C,},	// 0019 0023 Tune_wbt_GAS_211_ 
        {0x0F12, 0x000D,},	// 000C 0012 Tune_wbt_GAS_212_ 
        {0x0F12, 0x0004,},	// 0007 0006 Tune_wbt_GAS_213_ 
        {0x0F12, 0x0000,},	// 0004 0002 Tune_wbt_GAS_214_ 
        {0x0F12, 0x0003,},	// 0007 0005 Tune_wbt_GAS_215_ 
        {0x0F12, 0x000B,},	// 000D 0011 Tune_wbt_GAS_216_ 
        {0x0F12, 0x001A,},	// 001B 0025 Tune_wbt_GAS_217_ 
        {0x0F12, 0x002F,},	// 002E 0043 Tune_wbt_GAS_218_ 
        {0x0F12, 0x0049,},	// 0046 0070 Tune_wbt_GAS_219_ 
        {0x0F12, 0x0068,},	// 0062 00A4 Tune_wbt_GAS_220_ 
        {0x0F12, 0x0072,},	// 0052 0091 Tune_wbt_GAS_221_ 
        {0x0F12, 0x0053,},	// 003D 0067 Tune_wbt_GAS_222_ 
        {0x0F12, 0x0037,},	// 0026 0044 Tune_wbt_GAS_223_ 
        {0x0F12, 0x0021,},	// 0014 002B Tune_wbt_GAS_224_ 
        {0x0F12, 0x0012,},	// 0007 0019 Tune_wbt_GAS_225_ 
        {0x0F12, 0x0009,},	// 0002 000D Tune_wbt_GAS_226_ 
        {0x0F12, 0x0005,},	// 0001 0009 Tune_wbt_GAS_227_ 
        {0x0F12, 0x0008,},	// 0002 000C Tune_wbt_GAS_228_ 
        {0x0F12, 0x0010,},	// 0007 0018 Tune_wbt_GAS_229_ 
        {0x0F12, 0x001F,},	// 0015 002D Tune_wbt_GAS_230_ 
        {0x0F12, 0x0034,},	// 0028 004B Tune_wbt_GAS_231_ 
        {0x0F12, 0x004E,},	// 0040 007B Tune_wbt_GAS_232_ 
        {0x0F12, 0x006C,},	// 005C 00B0 Tune_wbt_GAS_233_ 
        {0x0F12, 0x007F,},	// 005E 00A1 Tune_wbt_GAS_234_ 
        {0x0F12, 0x0060,},	// 0049 0077 Tune_wbt_GAS_235_ 
        {0x0F12, 0x0043,},	// 0030 0054 Tune_wbt_GAS_236_ 
        {0x0F12, 0x002D,},	// 001E 003B Tune_wbt_GAS_237_ 
        {0x0F12, 0x001D,},	// 0010 0029 Tune_wbt_GAS_238_ 
        {0x0F12, 0x0013,},	// 0009 001C Tune_wbt_GAS_239_ 
        {0x0F12, 0x0010,},	// 0007 0018 Tune_wbt_GAS_240_ 
        {0x0F12, 0x0013,},	// 0009 001B Tune_wbt_GAS_241_ 
        {0x0F12, 0x001C,},	// 0012 0029 Tune_wbt_GAS_242_ 
        {0x0F12, 0x002B,},	// 0020 003F Tune_wbt_GAS_243_ 
        {0x0F12, 0x0040,},	// 0032 005F Tune_wbt_GAS_244_ 
        {0x0F12, 0x005A,},	// 004B 008F Tune_wbt_GAS_245_ 
        {0x0F12, 0x0079,},	// 0069 00C6 Tune_wbt_GAS_246_ 
        {0x0F12, 0x0082,},	// 0066 00B1 Tune_wbt_GAS_247_ 
        {0x0F12, 0x0066,},	// 004E 008E Tune_wbt_GAS_248_ 
        {0x0F12, 0x0049,},	// 0037 006D Tune_wbt_GAS_249_ 
        {0x0F12, 0x0035,},	// 0026 0050 Tune_wbt_GAS_250_ 
        {0x0F12, 0x0025,},	// 0019 003D Tune_wbt_GAS_251_ 
        {0x0F12, 0x001B,},	// 0011 0031 Tune_wbt_GAS_252_ 
        {0x0F12, 0x0017,},	// 000F 002F Tune_wbt_GAS_253_ 
        {0x0F12, 0x0019,},	// 0012 0032 Tune_wbt_GAS_254_ 
        {0x0F12, 0x0023,},	// 001B 0042 Tune_wbt_GAS_255_ 
        {0x0F12, 0x0033,},	// 0028 0058 Tune_wbt_GAS_256_ 
        {0x0F12, 0x0046,},	// 003B 007A Tune_wbt_GAS_257_ 
        {0x0F12, 0x0060,},	// 0054 00AC Tune_wbt_GAS_258_ 
        {0x0F12, 0x007B,},	// 0072 00E5 Tune_wbt_GAS_259_ 
        {0x0F12, 0x0092,},	// 006A 00BD Tune_wbt_GAS_260_ 
        {0x0F12, 0x007C,},	// 0058 00AA Tune_wbt_GAS_261_ 
        {0x0F12, 0x0060,},	// 0041 008B Tune_wbt_GAS_262_ 
        {0x0F12, 0x004B,},	// 0030 006E Tune_wbt_GAS_263_ 
        {0x0F12, 0x003C,},	// 0025 005A Tune_wbt_GAS_264_ 
        {0x0F12, 0x0032,},	// 001E 004F Tune_wbt_GAS_265_ 
        {0x0F12, 0x002D,},	// 001B 004B Tune_wbt_GAS_266_ 
        {0x0F12, 0x0030,},	// 001F 0052 Tune_wbt_GAS_267_ 
        {0x0F12, 0x0039,},	// 0027 0062 Tune_wbt_GAS_268_ 
        {0x0F12, 0x0049,},	// 0034 007D Tune_wbt_GAS_269_ 
        {0x0F12, 0x005D,},	// 0046 00A2 Tune_wbt_GAS_270_ 
        {0x0F12, 0x0076,},	// 005D 00D6 Tune_wbt_GAS_271_ 
        {0x0F12, 0x008C,},	// 0078 010C Tune_wbt_GAS_272_ 
        {0x0F12, 0x009F,},	// 007C 00E5 Tune_wbt_GAS_273_ 
        {0x0F12, 0x008F,},	// 006A 00C7 Tune_wbt_GAS_274_ 
        {0x0F12, 0x0077,},	// 0055 00B1 Tune_wbt_GAS_275_ 
        {0x0F12, 0x0061,},	// 0043 0093 Tune_wbt_GAS_276_ 
        {0x0F12, 0x0052,},	// 0037 007F Tune_wbt_GAS_277_ 
        {0x0F12, 0x0048,},	// 0030 0074 Tune_wbt_GAS_278_ 
        {0x0F12, 0x0043,},	// 002E 0071 Tune_wbt_GAS_279_ 
        {0x0F12, 0x0047,},	// 0030 0077 Tune_wbt_GAS_280_ 
        {0x0F12, 0x0050,},	// 0039 0089 Tune_wbt_GAS_281_ 
        {0x0F12, 0x005E,},	// 0045 00A7 Tune_wbt_GAS_282_ 
        {0x0F12, 0x0071,},	// 0056 00CC Tune_wbt_GAS_283_ 
        {0x0F12, 0x0086,},	// 006C 00FE Tune_wbt_GAS_284_ 
        {0x0F12, 0x0097,},	// 0084 0132 Tune_wbt_GAS_285_ 
        {0x0F12, 0x0093,},	// 006E 00A8 Tune_wbt_GAS_286_ 
        {0x0F12, 0x007C,},	// 006D 008D Tune_wbt_GAS_287_ 
        {0x0F12, 0x005F,},	// 005B 006C Tune_wbt_GAS_288_ 
        {0x0F12, 0x0049,},	// 0046 004E Tune_wbt_GAS_289_ 
        {0x0F12, 0x003A,},	// 003A 003C Tune_wbt_GAS_290_ 
        {0x0F12, 0x0030,},	// 0033 0032 Tune_wbt_GAS_291_ 
        {0x0F12, 0x002C,},	// 002D 002D Tune_wbt_GAS_292_ 
        {0x0F12, 0x002F,},	// 0032 0032 Tune_wbt_GAS_293_ 
        {0x0F12, 0x0037,},	// 0039 0040 Tune_wbt_GAS_294_ 
        {0x0F12, 0x0045,},	// 0047 0056 Tune_wbt_GAS_295_ 
        {0x0F12, 0x005A,},	// 004F 0076 Tune_wbt_GAS_296_ 
        {0x0F12, 0x0075,},	// 0050 00A8 Tune_wbt_GAS_297_ 
        {0x0F12, 0x008A,},	// 006E 00E6 Tune_wbt_GAS_298_ 
        {0x0F12, 0x0094,},	// 0077 00A2 Tune_wbt_GAS_299_ 
        {0x0F12, 0x0077,},	// 006C 007C Tune_wbt_GAS_300_ 
        {0x0F12, 0x0057,},	// 0054 0059 Tune_wbt_GAS_301_ 
        {0x0F12, 0x0040,},	// 0040 003E Tune_wbt_GAS_302_ 
        {0x0F12, 0x002F,},	// 0033 002A Tune_wbt_GAS_303_ 
        {0x0F12, 0x0024,},	// 002B 0020 Tune_wbt_GAS_304_ 
        {0x0F12, 0x0020,},	// 0027 001B Tune_wbt_GAS_305_ 
        {0x0F12, 0x0023,},	// 002A 0020 Tune_wbt_GAS_306_ 
        {0x0F12, 0x002D,},	// 0034 002D Tune_wbt_GAS_307_ 
        {0x0F12, 0x003B,},	// 0041 0042 Tune_wbt_GAS_308_ 
        {0x0F12, 0x0051,},	// 004C 0061 Tune_wbt_GAS_309_ 
        {0x0F12, 0x006E,},	// 0052 0092 Tune_wbt_GAS_310_ 
        {0x0F12, 0x008C,},	// 007E 00CE Tune_wbt_GAS_311_ 
        {0x0F12, 0x0085,},	// 0078 0094 Tune_wbt_GAS_312_ 
        {0x0F12, 0x0066,},	// 0063 006F Tune_wbt_GAS_313_ 
        {0x0F12, 0x0046,},	// 0049 004B Tune_wbt_GAS_314_ 
        {0x0F12, 0x002F,},	// 0035 002F Tune_wbt_GAS_315_ 
        {0x0F12, 0x001F,},	// 0028 001D Tune_wbt_GAS_316_ 
        {0x0F12, 0x0014,},	// 001E 0011 Tune_wbt_GAS_317_ 
        {0x0F12, 0x000F,},	// 001B 000D Tune_wbt_GAS_318_ 
        {0x0F12, 0x0012,},	// 001F 0012 Tune_wbt_GAS_319_ 
        {0x0F12, 0x001C,},	// 0028 001D Tune_wbt_GAS_320_ 
        {0x0F12, 0x002B,},	// 0037 0033 Tune_wbt_GAS_321_ 
        {0x0F12, 0x0040,},	// 0044 0051 Tune_wbt_GAS_322_ 
        {0x0F12, 0x005C,},	// 0050 007F Tune_wbt_GAS_323_ 
        {0x0F12, 0x007D,},	// 0080 00BA Tune_wbt_GAS_324_ 
        {0x0F12, 0x007A,},	// 0064 008B Tune_wbt_GAS_325_ 
        {0x0F12, 0x005A,},	// 004E 0064 Tune_wbt_GAS_326_ 
        {0x0F12, 0x003A,},	// 0035 0040 Tune_wbt_GAS_327_ 
        {0x0F12, 0x0024,},	// 0021 0025 Tune_wbt_GAS_328_ 
        {0x0F12, 0x0014,},	// 0013 0013 Tune_wbt_GAS_329_ 
        {0x0F12, 0x0009,},	// 000D 0007 Tune_wbt_GAS_330_ 
        {0x0F12, 0x0006,},	// 000B 0003 Tune_wbt_GAS_331_ 
        {0x0F12, 0x0008,},	// 000C 0006 Tune_wbt_GAS_332_ 
        {0x0F12, 0x0011,},	// 0014 0012 Tune_wbt_GAS_333_ 
        {0x0F12, 0x0020,},	// 0022 0027 Tune_wbt_GAS_334_ 
        {0x0F12, 0x0036,},	// 0036 0046 Tune_wbt_GAS_335_ 
        {0x0F12, 0x0051,},	// 004D 0073 Tune_wbt_GAS_336_ 
        {0x0F12, 0x0072,},	// 006B 00AB Tune_wbt_GAS_337_ 
        {0x0F12, 0x007B,},	// 0066 008B Tune_wbt_GAS_338_ 
        {0x0F12, 0x0059,},	// 004C 0062 Tune_wbt_GAS_339_ 
        {0x0F12, 0x003A,},	// 0032 003F Tune_wbt_GAS_340_ 
        {0x0F12, 0x0023,},	// 001E 0023 Tune_wbt_GAS_341_ 
        {0x0F12, 0x0012,},	// 0010 0010 Tune_wbt_GAS_342_ 
        {0x0F12, 0x0008,},	// 000A 0004 Tune_wbt_GAS_343_ 
        {0x0F12, 0x0004,},	// 0007 0000 Tune_wbt_GAS_344_ 
        {0x0F12, 0x0007,},	// 000B 0003 Tune_wbt_GAS_345_ 
        {0x0F12, 0x000F,},	// 0010 000E Tune_wbt_GAS_346_ 
        {0x0F12, 0x001F,},	// 001E 0022 Tune_wbt_GAS_347_ 
        {0x0F12, 0x0035,},	// 0032 0041 Tune_wbt_GAS_348_ 
        {0x0F12, 0x0051,},	// 004B 006E Tune_wbt_GAS_349_ 
        {0x0F12, 0x0072,},	// 006B 00A4 Tune_wbt_GAS_350_ 
        {0x0F12, 0x0073,},	// 0061 008E Tune_wbt_GAS_351_ 
        {0x0F12, 0x0053,},	// 0049 0065 Tune_wbt_GAS_352_ 
        {0x0F12, 0x0034,},	// 002F 0040 Tune_wbt_GAS_353_ 
        {0x0F12, 0x001D,},	// 001B 0025 Tune_wbt_GAS_354_ 
        {0x0F12, 0x000E,},	// 000E 0013 Tune_wbt_GAS_355_ 
        {0x0F12, 0x0004,},	// 0008 0006 Tune_wbt_GAS_356_ 
        {0x0F12, 0x0000,},	// 0004 0001 Tune_wbt_GAS_357_ 
        {0x0F12, 0x0002,},	// 0008 0005 Tune_wbt_GAS_358_ 
        {0x0F12, 0x000A,},	// 000D 0010 Tune_wbt_GAS_359_ 
        {0x0F12, 0x001A,},	// 001C 0025 Tune_wbt_GAS_360_ 
        {0x0F12, 0x002F,},	// 002F 0044 Tune_wbt_GAS_361_ 
        {0x0F12, 0x004A,},	// 0047 0074 Tune_wbt_GAS_362_ 
        {0x0F12, 0x006A,},	// 0067 00AA Tune_wbt_GAS_363_ 
        {0x0F12, 0x0077,},	// 005A 0097 Tune_wbt_GAS_364_ 
        {0x0F12, 0x0058,},	// 0043 006D Tune_wbt_GAS_365_ 
        {0x0F12, 0x0039,},	// 002B 0048 Tune_wbt_GAS_366_ 
        {0x0F12, 0x0022,},	// 0017 002D Tune_wbt_GAS_367_ 
        {0x0F12, 0x0012,},	// 0009 0019 Tune_wbt_GAS_368_ 
        {0x0F12, 0x0008,},	// 0004 000E Tune_wbt_GAS_369_ 
        {0x0F12, 0x0004,},	// 0002 0009 Tune_wbt_GAS_370_ 
        {0x0F12, 0x0007,},	// 0004 000C Tune_wbt_GAS_371_ 
        {0x0F12, 0x000F,},	// 0008 0018 Tune_wbt_GAS_372_ 
        {0x0F12, 0x001E,},	// 0016 002E Tune_wbt_GAS_373_ 
        {0x0F12, 0x0034,},	// 002A 004E Tune_wbt_GAS_374_ 
        {0x0F12, 0x004F,},	// 0042 007D Tune_wbt_GAS_375_ 
        {0x0F12, 0x006F,},	// 005F 00B5 Tune_wbt_GAS_376_ 
        {0x0F12, 0x0083,},	// 0066 00A6 Tune_wbt_GAS_377_ 
        {0x0F12, 0x0064,},	// 0050 007C Tune_wbt_GAS_378_ 
        {0x0F12, 0x0045,},	// 0035 0058 Tune_wbt_GAS_379_ 
        {0x0F12, 0x002E,},	// 0022 003E Tune_wbt_GAS_380_ 
        {0x0F12, 0x001D,},	// 0013 0029 Tune_wbt_GAS_381_ 
        {0x0F12, 0x0012,},	// 000A 001D Tune_wbt_GAS_382_ 
        {0x0F12, 0x000F,},	// 0008 0018 Tune_wbt_GAS_383_ 
        {0x0F12, 0x0011,},	// 000B 001B Tune_wbt_GAS_384_ 
        {0x0F12, 0x001A,},	// 0014 0028 Tune_wbt_GAS_385_ 
        {0x0F12, 0x002A,},	// 0021 003F Tune_wbt_GAS_386_ 
        {0x0F12, 0x003F,},	// 0035 0062 Tune_wbt_GAS_387_ 
        {0x0F12, 0x005B,},	// 004D 0093 Tune_wbt_GAS_388_ 
        {0x0F12, 0x007B,},	// 006E 00CC Tune_wbt_GAS_389_ 
        {0x0F12, 0x0087,},	// 006E 00B9 Tune_wbt_GAS_390_ 
        {0x0F12, 0x006A,},	// 0057 0094 Tune_wbt_GAS_391_ 
        {0x0F12, 0x004B,},	// 003E 0071 Tune_wbt_GAS_392_ 
        {0x0F12, 0x0036,},	// 002B 0052 Tune_wbt_GAS_393_ 
        {0x0F12, 0x0025,},	// 001C 003D Tune_wbt_GAS_394_ 
        {0x0F12, 0x0019,},	// 0013 0031 Tune_wbt_GAS_395_ 
        {0x0F12, 0x0015,},	// 0011 002D Tune_wbt_GAS_396_ 
        {0x0F12, 0x0017,},	// 0013 0031 Tune_wbt_GAS_397_ 
        {0x0F12, 0x0022,},	// 001D 0040 Tune_wbt_GAS_398_ 
        {0x0F12, 0x0031,},	// 002B 0058 Tune_wbt_GAS_399_ 
        {0x0F12, 0x0045,},	// 003D 007B Tune_wbt_GAS_400_ 
        {0x0F12, 0x0060,},	// 0057 00AE Tune_wbt_GAS_401_ 
        {0x0F12, 0x007D,},	// 0077 00EA Tune_wbt_GAS_402_ 
        {0x0F12, 0x0096,},	// 0072 00C2 Tune_wbt_GAS_403_ 
        {0x0F12, 0x007F,},	// 005F 00AE Tune_wbt_GAS_404_ 
        {0x0F12, 0x0061,},	// 0047 008E Tune_wbt_GAS_405_ 
        {0x0F12, 0x004B,},	// 0035 006F Tune_wbt_GAS_406_ 
        {0x0F12, 0x003B,},	// 0028 0059 Tune_wbt_GAS_407_ 
        {0x0F12, 0x002F,},	// 0020 004E Tune_wbt_GAS_408_ 
        {0x0F12, 0x002A,},	// 001D 0049 Tune_wbt_GAS_409_ 
        {0x0F12, 0x002D,},	// 0020 004F Tune_wbt_GAS_410_ 
        {0x0F12, 0x0036,},	// 0029 005E Tune_wbt_GAS_411_ 
        {0x0F12, 0x0046,},	// 0035 007A Tune_wbt_GAS_412_ 
        {0x0F12, 0x005B,},	// 0047 009F Tune_wbt_GAS_413_ 
        {0x0F12, 0x0075,},	// 0060 00D5 Tune_wbt_GAS_414_ 
        {0x0F12, 0x008D,},	// 007D 010C Tune_wbt_GAS_415_ 
        {0x0F12, 0x00A1,},	// 0084 00E5 Tune_wbt_GAS_416_ 
        {0x0F12, 0x0091,},	// 0072 00C8 Tune_wbt_GAS_417_ 
        {0x0F12, 0x0077,},	// 005B 00B0 Tune_wbt_GAS_418_ 
        {0x0F12, 0x0060,},	// 0046 0091 Tune_wbt_GAS_419_ 
        {0x0F12, 0x0050,},	// 003A 007D Tune_wbt_GAS_420_ 
        {0x0F12, 0x0044,},	// 0031 0070 Tune_wbt_GAS_421_ 
        {0x0F12, 0x0040,},	// 002E 006D Tune_wbt_GAS_422_ 
        {0x0F12, 0x0043,},	// 0032 0074 Tune_wbt_GAS_423_ 
        {0x0F12, 0x004C,},	// 0039 0086 Tune_wbt_GAS_424_ 
        {0x0F12, 0x005A,},	// 0046 00A4 Tune_wbt_GAS_425_ 
        {0x0F12, 0x006D,},	// 0056 00CA Tune_wbt_GAS_426_ 
        {0x0F12, 0x0084,},	// 006E 00FE Tune_wbt_GAS_427_ 
        {0x0F12, 0x0094,},	// 0087 0134 Tune_wbt_GAS_428_ 
        {0x0F12, 0x0072,},	// 004C 009F Tune_wbt_GAS_429_ 
        {0x0F12, 0x0063,},	// 004C 0089 Tune_wbt_GAS_430_ 
        {0x0F12, 0x004C,},	// 0041 0067 Tune_wbt_GAS_431_ 
        {0x0F12, 0x003A,},	// 002F 004E Tune_wbt_GAS_432_ 
        {0x0F12, 0x002D,},	// 0024 003E Tune_wbt_GAS_433_ 
        {0x0F12, 0x0025,},	// 001D 0033 Tune_wbt_GAS_434_ 
        {0x0F12, 0x0023,},	// 001B 0031 Tune_wbt_GAS_435_ 
        {0x0F12, 0x0025,},	// 001E 0036 Tune_wbt_GAS_436_ 
        {0x0F12, 0x002C,},	// 0024 0045 Tune_wbt_GAS_437_ 
        {0x0F12, 0x0038,},	// 0032 0058 Tune_wbt_GAS_438_ 
        {0x0F12, 0x004A,},	// 0037 0074 Tune_wbt_GAS_439_ 
        {0x0F12, 0x005F,},	// 0038 00A0 Tune_wbt_GAS_440_ 
        {0x0F12, 0x006B,},	// 004C 00C9 Tune_wbt_GAS_441_ 
        {0x0F12, 0x0079,},	// 005B 0098 Tune_wbt_GAS_442_ 
        {0x0F12, 0x0065,},	// 0056 0077 Tune_wbt_GAS_443_ 
        {0x0F12, 0x004A,},	// 0041 0055 Tune_wbt_GAS_444_ 
        {0x0F12, 0x0037,},	// 0030 003C Tune_wbt_GAS_445_ 
        {0x0F12, 0x0029,},	// 0026 002A Tune_wbt_GAS_446_ 
        {0x0F12, 0x0021,},	// 001F 0022 Tune_wbt_GAS_447_ 
        {0x0F12, 0x001D,},	// 001C 001F Tune_wbt_GAS_448_ 
        {0x0F12, 0x001F,},	// 001F 0024 Tune_wbt_GAS_449_ 
        {0x0F12, 0x0027,},	// 0027 0030 Tune_wbt_GAS_450_ 
        {0x0F12, 0x0033,},	// 0033 0044 Tune_wbt_GAS_451_ 
        {0x0F12, 0x0044,},	// 003C 0060 Tune_wbt_GAS_452_ 
        {0x0F12, 0x005E,},	// 0041 008B Tune_wbt_GAS_453_ 
        {0x0F12, 0x006E,},	// 0060 00B2 Tune_wbt_GAS_454_ 
        {0x0F12, 0x006A,},	// 005E 0088 Tune_wbt_GAS_455_ 
        {0x0F12, 0x0055,},	// 004F 0065 Tune_wbt_GAS_456_ 
        {0x0F12, 0x003A,},	// 003A 0044 Tune_wbt_GAS_457_ 
        {0x0F12, 0x0028,},	// 002A 002C Tune_wbt_GAS_458_ 
        {0x0F12, 0x001A,},	// 001D 001B Tune_wbt_GAS_459_ 
        {0x0F12, 0x0011,},	// 0016 0012 Tune_wbt_GAS_460_ 
        {0x0F12, 0x000D,},	// 0014 000F Tune_wbt_GAS_461_ 
        {0x0F12, 0x000F,},	// 0016 0013 Tune_wbt_GAS_462_ 
        {0x0F12, 0x0017,},	// 0021 001E Tune_wbt_GAS_463_ 
        {0x0F12, 0x0024,},	// 002D 0032 Tune_wbt_GAS_464_ 
        {0x0F12, 0x0035,},	// 0038 004E Tune_wbt_GAS_465_ 
        {0x0F12, 0x004E,},	// 0040 0078 Tune_wbt_GAS_466_ 
        {0x0F12, 0x0061,},	// 0066 00A2 Tune_wbt_GAS_467_ 
        {0x0F12, 0x0061,},	// 004A 007F Tune_wbt_GAS_468_ 
        {0x0F12, 0x004A,},	// 003C 005B Tune_wbt_GAS_469_ 
        {0x0F12, 0x0031,},	// 0028 0039 Tune_wbt_GAS_470_ 
        {0x0F12, 0x001E,},	// 0019 0021 Tune_wbt_GAS_471_ 
        {0x0F12, 0x0011,},	// 000D 0012 Tune_wbt_GAS_472_ 
        {0x0F12, 0x0008,},	// 0008 0007 Tune_wbt_GAS_473_ 
        {0x0F12, 0x0005,},	// 0007 0004 Tune_wbt_GAS_474_ 
        {0x0F12, 0x0007,},	// 0007 0006 Tune_wbt_GAS_475_ 
        {0x0F12, 0x000E,},	// 000F 0012 Tune_wbt_GAS_476_ 
        {0x0F12, 0x001B,},	// 001C 0024 Tune_wbt_GAS_477_ 
        {0x0F12, 0x002D,},	// 002C 0041 Tune_wbt_GAS_478_ 
        {0x0F12, 0x0045,},	// 0042 006A Tune_wbt_GAS_479_ 
        {0x0F12, 0x0059,},	// 0054 0092 Tune_wbt_GAS_480_ 
        {0x0F12, 0x0062,},	// 004B 007B Tune_wbt_GAS_481_ 
        {0x0F12, 0x004B,},	// 003C 0057 Tune_wbt_GAS_482_ 
        {0x0F12, 0x0031,},	// 0027 0036 Tune_wbt_GAS_483_ 
        {0x0F12, 0x001E,},	// 0017 001E Tune_wbt_GAS_484_ 
        {0x0F12, 0x0010,},	// 000C 000F Tune_wbt_GAS_485_ 
        {0x0F12, 0x0008,},	// 0007 0003 Tune_wbt_GAS_486_ 
        {0x0F12, 0x0004,},	// 0006 0000 Tune_wbt_GAS_487_ 
        {0x0F12, 0x0006,},	// 0008 0002 Tune_wbt_GAS_488_ 
        {0x0F12, 0x000E,},	// 000D 000D Tune_wbt_GAS_489_ 
        {0x0F12, 0x001B,},	// 001A 0020 Tune_wbt_GAS_490_ 
        {0x0F12, 0x002E,},	// 002B 003C Tune_wbt_GAS_491_ 
        {0x0F12, 0x0046,},	// 0041 0067 Tune_wbt_GAS_492_ 
        {0x0F12, 0x005A,},	// 0054 008D Tune_wbt_GAS_493_ 
        {0x0F12, 0x005B,},	// 0049 007E Tune_wbt_GAS_494_ 
        {0x0F12, 0x0045,},	// 003A 005A Tune_wbt_GAS_495_ 
        {0x0F12, 0x002C,},	// 0025 0038 Tune_wbt_GAS_496_ 
        {0x0F12, 0x001A,},	// 0015 0022 Tune_wbt_GAS_497_ 
        {0x0F12, 0x000C,},	// 000A 0013 Tune_wbt_GAS_498_ 
        {0x0F12, 0x0003,},	// 0005 0006 Tune_wbt_GAS_499_ 
        {0x0F12, 0x0000,},	// 0003 0001 Tune_wbt_GAS_500_ 
        {0x0F12, 0x0002,},	// 0006 0004 Tune_wbt_GAS_501_ 
        {0x0F12, 0x0009,},	// 000B 000F Tune_wbt_GAS_502_ 
        {0x0F12, 0x0016,},	// 0018 0023 Tune_wbt_GAS_503_ 
        {0x0F12, 0x0029,},	// 0029 003E Tune_wbt_GAS_504_ 
        {0x0F12, 0x0040,},	// 003E 006A Tune_wbt_GAS_505_ 
        {0x0F12, 0x0054,},	// 0050 0091 Tune_wbt_GAS_506_ 
        {0x0F12, 0x005F,},	// 0044 0085 Tune_wbt_GAS_507_ 
        {0x0F12, 0x004A,},	// 0033 0060 Tune_wbt_GAS_508_ 
        {0x0F12, 0x0031,},	// 0021 0041 Tune_wbt_GAS_509_ 
        {0x0F12, 0x001F,},	// 0011 002A Tune_wbt_GAS_510_ 
        {0x0F12, 0x0010,},	// 0005 0019 Tune_wbt_GAS_511_ 
        {0x0F12, 0x0008,},	// 0002 000D Tune_wbt_GAS_512_ 
        {0x0F12, 0x0004,},	// 0001 0008 Tune_wbt_GAS_513_ 
        {0x0F12, 0x0007,},	// 0003 000A Tune_wbt_GAS_514_ 
        {0x0F12, 0x000E,},	// 0008 0016 Tune_wbt_GAS_515_ 
        {0x0F12, 0x001B,},	// 0014 002A Tune_wbt_GAS_516_ 
        {0x0F12, 0x002E,},	// 0025 0047 Tune_wbt_GAS_517_ 
        {0x0F12, 0x0045,},	// 0039 0074 Tune_wbt_GAS_518_ 
        {0x0F12, 0x0059,},	// 004D 009A Tune_wbt_GAS_519_ 
        {0x0F12, 0x006C,},	// 0050 0097 Tune_wbt_GAS_520_ 
        {0x0F12, 0x0057,},	// 0041 0070 Tune_wbt_GAS_521_ 
        {0x0F12, 0x003E,},	// 002C 0052 Tune_wbt_GAS_522_ 
        {0x0F12, 0x002A,},	// 001C 003C Tune_wbt_GAS_523_ 
        {0x0F12, 0x001B,},	// 0011 0028 Tune_wbt_GAS_524_ 
        {0x0F12, 0x0012,},	// 0009 001D Tune_wbt_GAS_525_ 
        {0x0F12, 0x000F,},	// 0008 0019 Tune_wbt_GAS_526_ 
        {0x0F12, 0x0011,},	// 000A 001A Tune_wbt_GAS_527_ 
        {0x0F12, 0x0019,},	// 0012 0026 Tune_wbt_GAS_528_ 
        {0x0F12, 0x0027,},	// 001F 003B Tune_wbt_GAS_529_ 
        {0x0F12, 0x0039,},	// 002F 005A Tune_wbt_GAS_530_ 
        {0x0F12, 0x0050,},	// 0045 0089 Tune_wbt_GAS_531_ 
        {0x0F12, 0x0063,},	// 005A 00AF Tune_wbt_GAS_532_ 
        {0x0F12, 0x006F,},	// 0056 00A7 Tune_wbt_GAS_533_ 
        {0x0F12, 0x005C,},	// 0048 0088 Tune_wbt_GAS_534_ 
        {0x0F12, 0x0044,},	// 0035 006B Tune_wbt_GAS_535_ 
        {0x0F12, 0x0031,},	// 0026 0050 Tune_wbt_GAS_536_ 
        {0x0F12, 0x0023,},	// 0019 003D Tune_wbt_GAS_537_ 
        {0x0F12, 0x0019,},	// 0012 0032 Tune_wbt_GAS_538_ 
        {0x0F12, 0x0016,},	// 0011 002E Tune_wbt_GAS_539_ 
        {0x0F12, 0x0017,},	// 0012 0030 Tune_wbt_GAS_540_ 
        {0x0F12, 0x0020,},	// 001B 003E Tune_wbt_GAS_541_ 
        {0x0F12, 0x002E,},	// 0027 0052 Tune_wbt_GAS_542_ 
        {0x0F12, 0x0040,},	// 0037 0073 Tune_wbt_GAS_543_ 
        {0x0F12, 0x0055,},	// 004C 00A1 Tune_wbt_GAS_544_ 
        {0x0F12, 0x0064,},	// 0060 00C7 Tune_wbt_GAS_545_ 
        {0x0F12, 0x007E,},	// 0058 00AE Tune_wbt_GAS_546_ 
        {0x0F12, 0x0071,},	// 0050 00A4 Tune_wbt_GAS_547_ 
        {0x0F12, 0x0059,},	// 003D 0088 Tune_wbt_GAS_548_ 
        {0x0F12, 0x0046,},	// 002E 006D Tune_wbt_GAS_549_ 
        {0x0F12, 0x0039,},	// 0023 0059 Tune_wbt_GAS_550_ 
        {0x0F12, 0x002F,},	// 001C 004D Tune_wbt_GAS_551_ 
        {0x0F12, 0x002A,},	// 001B 0049 Tune_wbt_GAS_552_ 
        {0x0F12, 0x002D,},	// 001D 004E Tune_wbt_GAS_553_ 
        {0x0F12, 0x0035,},	// 0024 005B Tune_wbt_GAS_554_ 
        {0x0F12, 0x0043,},	// 002F 0073 Tune_wbt_GAS_555_ 
        {0x0F12, 0x0054,},	// 003E 0095 Tune_wbt_GAS_556_ 
        {0x0F12, 0x0069,},	// 0052 00C4 Tune_wbt_GAS_557_ 
        {0x0F12, 0x0074,},	// 0062 00E9 Tune_wbt_GAS_558_ 
        {0x0F12, 0x0083,},	// 0060 00D5 Tune_wbt_GAS_559_ 
        {0x0F12, 0x007D,},	// 0057 00C1 Tune_wbt_GAS_560_ 
        {0x0F12, 0x0068,},	// 0048 00AB Tune_wbt_GAS_561_ 
        {0x0F12, 0x0055,},	// 0039 008D Tune_wbt_GAS_562_ 
        {0x0F12, 0x0048,},	// 002E 0079 Tune_wbt_GAS_563_ 
        {0x0F12, 0x003E,},	// 0028 0070 Tune_wbt_GAS_564_ 
        {0x0F12, 0x003A,},	// 0027 006A Tune_wbt_GAS_565_ 
        {0x0F12, 0x003D,},	// 0029 006F Tune_wbt_GAS_566_ 
        {0x0F12, 0x0045,},	// 002F 0080 Tune_wbt_GAS_567_ 
        {0x0F12, 0x0051,},	// 0039 0096 Tune_wbt_GAS_568_ 
        {0x0F12, 0x0061,},	// 0047 00B9 Tune_wbt_GAS_569_ 
        {0x0F12, 0x0072,},	// 0059 00E2 Tune_wbt_GAS_570_ 
        {0x0F12, 0x0077,},	// 0067 010F Tune_wbt_GAS_571_ 
        {0x002A, 0x1348,},
        {0x0F12, 0x0001,},	// gisp_gras_Enable 

//==================================================================================
// 07. Analog Setting 2 
//==================================================================================   
//This register is for FACTORY ONLY. 
//If you change it without prior notification
//YOU are RESPONSIBLE for the FAILURE that will happen in the future      
        {0x002A, 0x1278,},
        {0x0F12, 0xAAF0,},	//gisp_dadlc_config //Ladlc mode average
        {0x002A, 0x3370,},
        {0x0F12, 0x0000,},	//afit_bUseNormBrForAfit //0:Noise Index, 1:Normal Brightness

//*************************************/
// 08.AF Setting                      */
//*************************************/

//*************************************/
// 09.AWB-BASIC setting               */
//*************************************/

// For WB Calibration */
        {0x002A, 0x0B36,},
        {0x0F12, 0x0005,},// awbb_IndoorGrZones_ZInfo_m_GridStep */
        {0x002A, 0x0B3A,},
        {0x0F12, 0x00F3,},// awbb_IndoorGrZones_ZInfo_m_BMin */
        {0x0F12, 0x02CB,},// awbb_IndoorGrZones_ZInfo_m_BMax */
        {0x002A, 0x0B38,},
        {0x0F12, 0x0010,},// awbb_IndoorGrZones_ZInfo_m_GridSz */
        {0x002A, 0x0AE6,},
        {0x0F12, 0x0385,},// 0352 03E1 awbb_IndoorGrZones_m_BGrid_0__m_left   */
        {0x0F12, 0x03D8,},// 038C 0413 awbb_IndoorGrZones_m_BGrid_0__m_right  */
        {0x0F12, 0x032A,},// 0321 039E awbb_IndoorGrZones_m_BGrid_1__m_left   */
        {0x0F12, 0x03C5,},// 03A6 0416 awbb_IndoorGrZones_m_BGrid_1__m_right  */
        {0x0F12, 0x02F5,},// 02EC 0367 awbb_IndoorGrZones_m_BGrid_2__m_left   */
        {0x0F12, 0x039D,},// 03A0 03F3 awbb_IndoorGrZones_m_BGrid_2__m_right  */
        {0x0F12, 0x02D3,},// 02CA 032D awbb_IndoorGrZones_m_BGrid_3__m_left   */
        {0x0F12, 0x0372,},// 038D 03C5 awbb_IndoorGrZones_m_BGrid_3__m_right  */
        {0x0F12, 0x02B1,},// 02A8 02FD awbb_IndoorGrZones_m_BGrid_4__m_left   */
        {0x0F12, 0x033E,},// 036E 038F awbb_IndoorGrZones_m_BGrid_4__m_right  */
        {0x0F12, 0x028A,},// 0281 02D3 awbb_IndoorGrZones_m_BGrid_5__m_left   */
        {0x0F12, 0x0322,},// 0344 0365 awbb_IndoorGrZones_m_BGrid_5__m_right  */
        {0x0F12, 0x0268,},// 025F 02AA awbb_IndoorGrZones_m_BGrid_6__m_left   */
        {0x0F12, 0x02FD,},// 0327 033E awbb_IndoorGrZones_m_BGrid_6__m_right  */
        {0x0F12, 0x0248,},// 023F 028D awbb_IndoorGrZones_m_BGrid_7__m_left   */
        {0x0F12, 0x02EF,},// 0302 0310 awbb_IndoorGrZones_m_BGrid_7__m_right  */
        {0x0F12, 0x022F,},// 0226 0271 awbb_IndoorGrZones_m_BGrid_8__m_left   */
        {0x0F12, 0x02D5,},// 02DC 02F1 awbb_IndoorGrZones_m_BGrid_8__m_right  */
        {0x0F12, 0x0219,},// 0210 025A awbb_IndoorGrZones_m_BGrid_9__m_left   */
        {0x0F12, 0x02C2,},// 02B9 02D2 awbb_IndoorGrZones_m_BGrid_9__m_right  */
        {0x0F12, 0x0206,},// 01FD 0249 awbb_IndoorGrZones_m_BGrid_10__m_left  */
        {0x0F12, 0x02A3,},// 029A 02B9 awbb_IndoorGrZones_m_BGrid_10__m_right */
        {0x0F12, 0x01F0,},// 01E7 0238 awbb_IndoorGrZones_m_BGrid_11__m_left  */
        {0x0F12, 0x0286,},// 027D 02A2 awbb_IndoorGrZones_m_BGrid_11__m_right */
        {0x0F12, 0x01E3,},// 01DA 021B awbb_IndoorGrZones_m_BGrid_12__m_left  */
        {0x0F12, 0x0268,},// 025F 0289 awbb_IndoorGrZones_m_BGrid_12__m_right */
        {0x0F12, 0x01D6,},// 01CD 0200 awbb_IndoorGrZones_m_BGrid_13__m_left  */
        {0x0F12, 0x024E,},// 0245 026C awbb_IndoorGrZones_m_BGrid_13__m_right */
        {0x0F12, 0x01DD,},// 01D4 01FC awbb_IndoorGrZones_m_BGrid_14__m_left  */
        {0x0F12, 0x022A,},// 0221 024F awbb_IndoorGrZones_m_BGrid_14__m_right */
        {0x0F12, 0x0210,},// 0207 021E awbb_IndoorGrZones_m_BGrid_15__m_left  */
        {0x0F12, 0x01F2,},// 01E9 022C awbb_IndoorGrZones_m_BGrid_15__m_right */
        {0x0F12, 0x0000,},// 0000 0000 awbb_IndoorGrZones_m_BGrid_16__m_left  */
        {0x0F12, 0x0000,},// 0000 0000 awbb_IndoorGrZones_m_BGrid_16__m_right */
        {0x0F12, 0x0000,},// 0000 0000 awbb_IndoorGrZones_m_BGrid_17__m_left  */
        {0x0F12, 0x0000,},// 0000 0000 awbb_IndoorGrZones_m_BGrid_17__m_right */
        {0x0F12, 0x0000,},// 0000 0000 awbb_IndoorGrZones_m_BGrid_18__m_left  */
        {0x0F12, 0x0000,},// 0000 0000 awbb_IndoorGrZones_m_BGrid_18__m_right */
        {0x0F12, 0x0000,},// 0000 0000 awbb_IndoorGrZones_m_BGrid_19__m_left  */
        {0x0F12, 0x0000,},// 0000 0000 awbb_IndoorGrZones_m_BGrid_19__m_right */

        {0x002A, 0x0BAA,},
        {0x0F12, 0x0006,},// awbb_LowBrGrZones_ZInfo_m_GridStep */
        {0x002A, 0x0BAE,},
        {0x0F12, 0x00CC,},// 010E awbb_LowBrGrZones_ZInfo_m_BMin */
        {0x0F12, 0x02F3,},// 02E9 awbb_LowBrGrZones_ZInfo_m_BMax */
        {0x002A, 0x0BAC,},
        {0x0F12, 0x000A,},// 0009 awbb_LowBrGrZones_ZInfo_m_GridSz */
        {0x002A, 0x0B7A,},
        {0x0F12, 0x036C,},// 0374 038C awbb_LowBrGrZones_m_BGrid_0__m_left   */
        {0x0F12, 0x03C6,},// 03CE 03DA awbb_LowBrGrZones_m_BGrid_0__m_right  */
        {0x0F12, 0x02EE,},// 02F6 030E awbb_LowBrGrZones_m_BGrid_1__m_left   */
        {0x0F12, 0x03F9,},// 0401 03E9 awbb_LowBrGrZones_m_BGrid_1__m_right  */
        {0x0F12, 0x02BE,},// 02C6 02A2 awbb_LowBrGrZones_m_BGrid_2__m_left   */
        {0x0F12, 0x03DF,},// 03E7 03C2 awbb_LowBrGrZones_m_BGrid_2__m_right  */
        {0x0F12, 0x027A,},// 0282 0259 awbb_LowBrGrZones_m_BGrid_3__m_left   */
        {0x0F12, 0x03AE,},// 03B6 038A awbb_LowBrGrZones_m_BGrid_3__m_right  */
        {0x0F12, 0x0234,},// 023C 0218 awbb_LowBrGrZones_m_BGrid_4__m_left   */
        {0x0F12, 0x0376,},// 037E 0352 awbb_LowBrGrZones_m_BGrid_4__m_right  */
        {0x0F12, 0x0204,},// 020C 01F4 awbb_LowBrGrZones_m_BGrid_5__m_left   */
        {0x0F12, 0x033E,},// 0346 02E1 awbb_LowBrGrZones_m_BGrid_5__m_right  */
        {0x0F12, 0x01E0,},// 01E8 01D7 awbb_LowBrGrZones_m_BGrid_6__m_left   */
        {0x0F12, 0x02CD,},// 02D5 028E awbb_LowBrGrZones_m_BGrid_6__m_right  */
        {0x0F12, 0x01C3,},// 01CB 01CB awbb_LowBrGrZones_m_BGrid_7__m_left   */
        {0x0F12, 0x027A,},// 0282 0258 awbb_LowBrGrZones_m_BGrid_7__m_right  */
        {0x0F12, 0x01B7,},// 01BF 022B awbb_LowBrGrZones_m_BGrid_8__m_left   */
        {0x0F12, 0x0244,},// 024C 01CC awbb_LowBrGrZones_m_BGrid_8__m_right  */
        {0x0F12, 0x01FE,},// 01F8 0000 awbb_LowBrGrZones_m_BGrid_9__m_left   */
        {0x0F12, 0x01DD,},// 0201 0000 awbb_LowBrGrZones_m_BGrid_9__m_right  */
        {0x0F12, 0x0000,},// 0000 0000 awbb_LowBrGrZones_m_BGrid_10__m_left  */
        {0x0F12, 0x0000,},// 0000 0000 awbb_LowBrGrZones_m_BGrid_10__m_right */
        {0x0F12, 0x0000,},// 0000 0000 awbb_LowBrGrZones_m_BGrid_11__m_left  */
        {0x0F12, 0x0000,},// 0000 0000 awbb_LowBrGrZones_m_BGrid_11__m_right */
        {0x002A, 0x0B70,},
        {0x0F12, 0x0005,},// awbb_OutdoorGrZones_ZInfo_m_GridStep */
        {0x002A, 0x0B74,},
        {0x0F12, 0x01E3,},// awbb_OutdoorGrZones_ZInfo_m_BMin */
        {0x0F12, 0x0270,},// awbb_OutdoorGrZones_ZInfo_m_BMax */
        {0x002A, 0x0B72,},
        {0x0F12, 0x0006,},// awbb_OutdoorGrZones_ZInfo_m_GridSz */
        {0x002A, 0x0B40,},
        {0x0F12, 0x028A,},// 029E awbb_OutdoorGrZones_m_BGrid_0__m_left   */
        {0x0F12, 0x02A1,},// 02C8 awbb_OutdoorGrZones_m_BGrid_0__m_right  */
        {0x0F12, 0x0263,},// 0281 awbb_OutdoorGrZones_m_BGrid_1__m_left   */
        {0x0F12, 0x02C0,},// 02C8 awbb_OutdoorGrZones_m_BGrid_1__m_right  */
        {0x0F12, 0x024C,},// 0266 awbb_OutdoorGrZones_m_BGrid_2__m_left   */
        {0x0F12, 0x02BE,},// 02AC awbb_OutdoorGrZones_m_BGrid_2__m_right  */
        {0x0F12, 0x023D,},// 0251 awbb_OutdoorGrZones_m_BGrid_3__m_left   */
        {0x0F12, 0x02A6,},// 028E awbb_OutdoorGrZones_m_BGrid_3__m_right  */
        {0x0F12, 0x0243,},// 023D awbb_OutdoorGrZones_m_BGrid_4__m_left   */
        {0x0F12, 0x0289,},// 0275 awbb_OutdoorGrZones_m_BGrid_4__m_right  */
        {0x0F12, 0x026F,},// 0228 awbb_OutdoorGrZones_m_BGrid_5__m_left   */
        {0x0F12, 0x025D,},// 025D awbb_OutdoorGrZones_m_BGrid_5__m_right  */
        {0x0F12, 0x0000,},// 0228 awbb_OutdoorGrZones_m_BGrid_6__m_left   */
        {0x0F12, 0x0000,},// 0243 awbb_OutdoorGrZones_m_BGrid_6__m_right  */
        {0x0F12, 0x0000,},// 0000 awbb_OutdoorGrZones_m_BGrid_7__m_left   */
        {0x0F12, 0x0000,},// 0000 awbb_OutdoorGrZones_m_BGrid_7__m_right  */
        {0x0F12, 0x0000,},// 0000 awbb_OutdoorGrZones_m_BGrid_8__m_left   */
        {0x0F12, 0x0000,},// 0000 awbb_OutdoorGrZones_m_BGrid_8__m_right  */
        {0x0F12, 0x0000,},// 0000 awbb_OutdoorGrZones_m_BGrid_9__m_left   */
        {0x0F12, 0x0000,},// 0000 awbb_OutdoorGrZones_m_BGrid_9__m_right  */
        {0x0F12, 0x0000,},// 0000 awbb_OutdoorGrZones_m_BGrid_10__m_left  */
        {0x0F12, 0x0000,},// 0000 awbb_OutdoorGrZones_m_BGrid_10__m_right */
        {0x0F12, 0x0000,},// 0000 awbb_OutdoorGrZones_m_BGrid_11__m_left  */
        {0x0F12, 0x0000,},// 0000 awbb_OutdoorGrZones_m_BGrid_11__m_right */
        {0x002A, 0x0BC8,},
        {0x0F12, 0x0005,},// awbb_CWSkinZone_ZInfo_m_GridStep */
        {0x002A, 0x0BCC,},
        {0x0F12, 0x010F,},// awbb_CWSkinZone_ZInfo_m_BMin */
        {0x0F12, 0x018F,},// awbb_CWSkinZone_ZInfo_m_BMax */
        {0x002A, 0x0BCA,},
        {0x0F12, 0x0005,},// awbb_CWSkinZone_ZInfo_m_GridSz */
        {0x002A, 0x0BB4,},
        {0x0F12, 0x03E7,},// awbb_CWSkinZone_m_BGrid_0__m_left  */
        {0x0F12, 0x03F8,},// awbb_CWSkinZone_m_BGrid_0__m_right */
        {0x0F12, 0x03A7,},// awbb_CWSkinZone_m_BGrid_1__m_left  */
        {0x0F12, 0x03FC,},// awbb_CWSkinZone_m_BGrid_1__m_right */
        {0x0F12, 0x0352,},// awbb_CWSkinZone_m_BGrid_2__m_left  */
        {0x0F12, 0x03D0,},// awbb_CWSkinZone_m_BGrid_2__m_right */
        {0x0F12, 0x0322,},// awbb_CWSkinZone_m_BGrid_3__m_left  */
        {0x0F12, 0x039E,},// awbb_CWSkinZone_m_BGrid_3__m_right */
        {0x0F12, 0x032B,},// awbb_CWSkinZone_m_BGrid_4__m_left  */
        {0x0F12, 0x034D,},// awbb_CWSkinZone_m_BGrid_4__m_right */
        {0x002A, 0x0BE6,},
        {0x0F12, 0x0006,},// awbb_DLSkinZone_ZInfo_m_GridStep */
        {0x002A, 0x0BEA,},
        {0x0F12, 0x019E,},// awbb_DLSkinZone_ZInfo_m_BMin */
        {0x0F12, 0x0257,},// awbb_DLSkinZone_ZInfo_m_BMax */
        {0x002A, 0x0BE8,},
        {0x0F12, 0x0004,},// awbb_DLSkinZone_ZInfo_m_GridSz */
        {0x002A, 0x0BD2,},
        {0x0F12, 0x030B,},// awbb_DLSkinZone_m_BGrid_0__m_left  */
        {0x0F12, 0x0323,},// awbb_DLSkinZone_m_BGrid_0__m_right */
        {0x0F12, 0x02C3,},// awbb_DLSkinZone_m_BGrid_1__m_left  */
        {0x0F12, 0x030F,},// awbb_DLSkinZone_m_BGrid_1__m_right */
        {0x0F12, 0x0288,},// awbb_DLSkinZone_m_BGrid_2__m_left  */
        {0x0F12, 0x02E5,},// awbb_DLSkinZone_m_BGrid_2__m_right */
        {0x0F12, 0x026A,},// awbb_DLSkinZone_m_BGrid_3__m_left  */
        {0x0F12, 0x02A2,},// awbb_DLSkinZone_m_BGrid_3__m_right */
        {0x0F12, 0x0000,},// awbb_DLSkinZone_m_BGrid_4__m_left  */
        {0x0F12, 0x0000,},// awbb_DLSkinZone_m_BGrid_4__m_right */
        {0x002A, 0x0C2C,},
        {0x0F12, 0x0139,},// awbb_IntcR */
        {0x0F12, 0x0122,},// awbb_IntcB */
        {0x002A, 0x0BFC,},
        {0x0F12, 0x0378,},// 03AD awbb_IndoorWP_0__r */
        {0x0F12, 0x011E,},// 013F awbb_IndoorWP_0__b */
        {0x0F12, 0x02F0,},// 0341 awbb_IndoorWP_1__r */
        {0x0F12, 0x0184,},// 017B awbb_IndoorWP_1__b */
        {0x0F12, 0x0313,},// 038D awbb_IndoorWP_2__r */
        {0x0F12, 0x0158,},// 014B awbb_IndoorWP_2__b */
        {0x0F12, 0x02BA,},// 02C3 awbb_IndoorWP_3__r */
        {0x0F12, 0x01BA,},// 01CC awbb_IndoorWP_3__b */
        {0x0F12, 0x0231,},// 0241 awbb_IndoorWP_4__r */
        {0x0F12, 0x0252,},// 027F awbb_IndoorWP_4__b */
        {0x0F12, 0x0237,},// 0241 awbb_IndoorWP_5__r */
        {0x0F12, 0x024C,},// 027F awbb_IndoorWP_5__b */
        {0x0F12, 0x020F,},// 0214 awbb_IndoorWP_6__r */
        {0x0F12, 0x0279,},// 02A8 awbb_IndoorWP_6__b */
        {0x0F12, 0x0268,},// 0270 255 awbb_OutdoorWP_r */
        {0x0F12, 0x021A,},// 0210 25B awbb_OutdoorWP_b */
        {0x002A, 0x0C4C,},
        {0x0F12, 0x0450,},// awbb_MvEq_RBthresh */
        {0x002A, 0x0C58,},
        {0x0F12, 0x059C,},// awbb_MvEq_RBthresh */
        {0x002A, 0x0BF8,},
        {0x0F12, 0x01AE,},// awbb_LowTSep_m_RminusB */
        {0x002A, 0x0C28,},
        {0x0F12, 0x0000,},// awbb_SkinPreference */
        {0x002A, 0x0CAC,},
        {0x0F12, 0x0050,},// awbb_OutDMaxIncr */
        {0x002A, 0x0C28,},
        {0x0F12, 0x0000,},// awbb_SkinPreference */ 

        {0x002A, 0x20BA,},
        {0x0F12, 0x0006,},// Lowtemp bypass */

        {0x002A, 0x0D0E,},
        {0x0F12, 0x00B8,},// awbb_GridCoeff_R_2 */
        {0x0F12, 0x00B2,},// awbb_GridCoeff_B_2 */
        {0x002A, 0x0CFE,},
        {0x0F12, 0x0FAB,},// 0FAB awbb_GridConst_2_0_ */
        {0x0F12, 0x0FF5,},// 0FF5 0FF5 awbb_GridConst_2_1_ */
        {0x0F12, 0x10BB,},// 10BB 10BB awbb_GridConst_2_2_ */
        {0x0F12, 0x1117,},// 1117 1123 1153 awbb_GridConst_2_3_ */
        {0x0F12, 0x116D,},// 116D 11C5 awbb_GridConst_2_4_ */
        {0x0F12, 0x11D5,},// 122A awbb_GridConst_2_5_ */
        {0x0F12, 0x00A9,},// awbb_GridCoeff_R_1 */
        {0x0F12, 0x00C0,},// awbb_GridCoeff_B_1 */
        {0x002A, 0x0CF8,},
        {0x0F12, 0x02CC,},// awbb_GridConst_1_0_ */
        {0x0F12, 0x031E,},// awbb_GridConst_1_1_ */
        {0x0F12, 0x0359,},// awbb_GridConst_1_2_ */

        {0x002A, 0x0CB0,},
        {0x0F12, 0x0030,},// 0000 awbb_GridCorr_R_0__0_ */
        {0x0F12, 0x0040,},// 0000 awbb_GridCorr_R_0__1_ */
        {0x0F12, 0x0060,},// 0078 awbb_GridCorr_R_0__2_ */
        {0x0F12, 0x0040,},// 00AA awbb_GridCorr_R_0__3_ */
        {0x0F12, 0x0008,},// 0000 awbb_GridCorr_R_0__4_ */
        {0x0F12, 0x0008,},// 0000 awbb_GridCorr_R_0__5_ */

        {0x0F12, 0x0030,},// 0000 awbb_GridCorr_R_1__0_ */
        {0x0F12, 0x0040,},// 0096 awbb_GridCorr_R_1__1_ */
        {0x0F12, 0x0060,},// 0000 awbb_GridCorr_R_1__2_ */
        {0x0F12, 0x0040,},// 0000 awbb_GridCorr_R_1__3_ */
        {0x0F12, 0x0008,},// 0000 awbb_GridCorr_R_1__4_ */
        {0x0F12, 0x0008,},// 0000 awbb_GridCorr_R_1__5_ */

        {0x0F12, 0x0030,},// 00E6 awbb_GridCorr_R_2__0_ */
        {0x0F12, 0x0040,},// 0000 awbb_GridCorr_R_2__1_ */
        {0x0F12, 0x0060,},// 0000 awbb_GridCorr_R_2__2_ */
        {0x0F12, 0x0040,},// 0000 awbb_GridCorr_R_2__3_ */
        {0x0F12, 0x0008,},// 0000 awbb_GridCorr_R_2__4_ */
        {0x0F12, 0x0008,},// 0000 awbb_GridCorr_R_2__5_ */

        {0x0F12, 0x0018,},// 0000 awbb_GridCorr_B_0__0_ */
        {0x0F12, 0x0000,},// 0000 awbb_GridCorr_B_0__1_ */
        {0x0F12, 0x0000,},// 0064 awbb_GridCorr_B_0__2_ */
        {0x0F12, 0x0000,},// 0000 awbb_GridCorr_B_0__3_ */
        {0x0F12, 0xFF80,},// 0000 awbb_GridCorr_B_0__4_ */
        {0x0F12, 0xFEC0,},// 0000 awbb_GridCorr_B_0__5_ */

        {0x0F12, 0x0018,},// 0000 awbb_GridCorr_B_1__0_ */
        {0x0F12, 0x0000,},// 0032 awbb_GridCorr_B_1__1_ */
        {0x0F12, 0x0000,},// 0000 awbb_GridCorr_B_1__2_ */
        {0x0F12, 0x0000,},// 0000 awbb_GridCorr_B_1__3_ */
        {0x0F12, 0xFF80,},// FF38 awbb_GridCorr_B_1__4_ */
        {0x0F12, 0xFEC0,},// 0000 awbb_GridCorr_B_1__5_ */

        {0x0F12, 0x0018,},// 0000 awbb_GridCorr_B_2__0_ */
        {0x0F12, 0x0000,},// 0032 awbb_GridCorr_B_2__1_ */
        {0x0F12, 0x0000,},// 0000 awbb_GridCorr_B_2__2_ */
        {0x0F12, 0x0000,},// 0000 awbb_GridCorr_B_2__3_ */
        {0x0F12, 0xFF80,},// 0000 awbb_GridCorr_B_2__4_ */
        {0x0F12, 0xFEC0,},// 0000 awbb_GridCorr_B_2__5_ */

        {0x002A, 0x0D30,},
        {0x0F12, 0x0002,},// awbb_GridEnable */

        {0x002A, 0x3372,},
        {0x0F12, 0x0001,},// awbb_bUseOutdoorGrid */
        {0x0F12, 0x0000,},// awbb_OutdoorGridCorr_R */
        {0x0F12, 0x0000,},// awbb_OutdoorGridCorr_B */

// For Outdoor Detector */
        {0x002A, 0x0C86,},
        {0x0F12, 0x0005,},// awbb_OutdoorDetectionZone_ZInfo_m_GridSz */
        {0x002A, 0x0C70,},
        {0x0F12, 0xFF7B,},// awbb_OutdoorDetectionZone_m_BGrid_0__m_left */
        {0x0F12, 0x00CE,},// awbb_OutdoorDetectionZone_m_BGrid_0__m_right */
        {0x0F12, 0xFF23,},// awbb_OutdoorDetectionZone_m_BGrid_1__m_left */
        {0x0F12, 0x010D,},// awbb_OutdoorDetectionZone_m_BGrid_1__m_right */
        {0x0F12, 0xFEF3,},// awbb_OutdoorDetectionZone_m_BGrid_2__m_left */
        {0x0F12, 0x012C,},// awbb_OutdoorDetectionZone_m_BGrid_2__m_right */
        {0x0F12, 0xFED7,},// awbb_OutdoorDetectionZone_m_BGrid_3__m_left */
        {0x0F12, 0x014E,},// awbb_OutdoorDetectionZone_m_BGrid_3__m_right */
        {0x0F12, 0xFEBB,},// awbb_OutdoorDetectionZone_m_BGrid_4__m_left */
        {0x0F12, 0x0162,},// awbb_OutdoorDetectionZone_m_BGrid_4__m_right */
        {0x0F12, 0x1388,},// awbb_OutdoorDetectionZone_ZInfo_m_AbsGridStep */
        {0x002A, 0x0C8A,},
        {0x0F12, 0x4ACB,},// awbb_OutdoorDetectionZone_ZInfo_m_MaxNB */
        {0x002A, 0x0C88,},
        {0x0F12, 0x0A7C,},// awbb_OutdoorDetectionZone_ZInfo_m_NBoffs */

        {0x002A, 0x0CA0,},
        {0x0F12, 0x0030,}, //awbb_GnCurPntImmunity

        {0x002A, 0x0CA4,},
        {0x0F12, 0x0030,}, //awbb_GnCurPntLongJump
        {0x0F12, 0x0180,}, //awbb_GainsMaxMove
        {0x0F12, 0x0002,}, //awbb_GnMinMatchToJump

//==================================================================================
// 10.Clock Setting
//==================================================================================
// Input Clock (Mclk) 
        {0x002A, 0x012E,},
        {0x0F12, 0x5DC0,},	// REG_TC_IPRM_InClockLSBs 
        {0x0F12, 0x0000,},	// REG_TC_IPRM_InClockMSBs 
        {0x002A, 0x0146,},
        {0x0F12, 0x0000,},	// REG_TC_IPRM_UseNPviClocks 
        {0x0F12, 0x0001,},	// REG_TC_IPRM_UseNMipiClocks

// System Clock & Output clock (Pclk)
        {0x002A, 0x014C,},
        {0x0F12, 0x2AF8,},	// REG_TC_IPRM_OpClk4KHz_0 
        {0x002A, 0x0152,},
        {0x0F12, 0x55F0,},	// REG_TC_IPRM_MinOutRate4KHz_0 
        {0x002A, 0x014E,},
        {0x0F12, 0x55F0,},	// REG_TC_IPRM_MaxOutRate4KHz_0 
        {0x0F12, 0x00FA,},

        {0x002A, 0x0164,},
        {0x0F12, 0x0001,},	// REG_TC_IPRM_InitParamsUpdated 

//*************************************/
// 11.Auto Flicker Detection          */
//*************************************/
        {0x0028, 0x7000,},
        {0x002A, 0x03F4,},
        {0x0F12, 0x0001,},//REG_SF_USER_FlickerQuant */
        {0x0F12, 0x0001,},//REG_SF_USER_FlickerQuantChanged */
        {0x002A, 0x0408,},
        {0x0F12, 0x067F,},//REG_TC_DBG_AutoAlgEnBits all AA are on */

//*************************************/
// 12.AE Setting                      */
//*************************************/

        {0x002A, 0x0D40,},
        {0x0F12, 0x0038,}, //TVAR_ae_BrAve */

// For LT Calibration */
        {0x002A, 0x0D46,},
        {0x0F12, 0x000F,},// ae_StatMode */

        {0x002A, 0x0440,},
        {0x0F12, 0x3410,},// lt_uMaxExp_0_ */
        {0x002A, 0x0444,},
        {0x0F12, 0x6820,},// lt_uMaxExp_1_ */
        {0x002A, 0x0448,},
        {0x0F12, 0x8227,},// lt_uMaxExp_2_ */
        {0x002A, 0x044C,},
        {0x0F12, 0xC350,},// lt_uMaxExp_3_ */
        {0x002A, 0x0450,},
        {0x0F12, 0x3410,},// lt_uCapMaxExp_0_ */
        {0x002A, 0x0454,},
        {0x0F12, 0x6820,},// lt_uCapMaxExp_1_ */
        {0x002A, 0x0458,},
        {0x0F12, 0x8227,},// lt_uCapMaxExp_2_ */
        {0x002A, 0x045C,},
        {0x0F12, 0xC350,},// lt_uCapMaxExp_3_ */
        {0x002A, 0x0460,},
        {0x0F12, 0x01B0,},// lt_uMaxAnGain_0_ */
        {0x0F12, 0x01B0,},// lt_uMaxAnGain_1_ */
        {0x0F12, 0x0280,},// lt_uMaxAnGain_2_ */
        {0x0F12, 0x0700,},// lt_uMaxAnGain_3_ */
        {0x0F12, 0x0100,},// B0 0100 lt_uMaxDigGain */
        {0x0F12, 0x3000,},// lt_uMaxTotGain */
        {0x002A, 0x042E,},
        {0x0F12, 0x012E,},// lt_uLimitHigh */
        {0x0F12, 0x00D5,},// lt_uLimitLow */
        {0x002A, 0x0DE0,},
        {0x0F12, 0x0002,},// ae_Fade2BlackEnable F2B off, F2W on */

// For Illum Type Calibration */
// WRITE #SARR_IllumType_0_  0078 */
// WRITE #SARR_IllumType_1_  00C3 */
// WRITE #SARR_IllumType_2_  00E9 */
// WRITE #SARR_IllumType_3_  0128 */
// WRITE #SARR_IllumType_4_  016F */
// WRITE #SARR_IllumType_5_  0195 */
// WRITE #SARR_IllumType_6_  01A4 */
// WRITE #SARR_IllumTypeF_0_  0100 */
// WRITE #SARR_IllumTypeF_1_  0100 */
// WRITE #SARR_IllumTypeF_2_  0110 */
// WRITE #SARR_IllumTypeF_3_  00E5 */
// WRITE #SARR_IllumTypeF_4_  0100 */
// WRITE #SARR_IllumTypeF_5_  00ED */
// WRITE #SARR_IllumTypeF_6_  00ED */

        {0x002A, 0x0D38,},// bp_uMaxBrightnessFactor */
        {0x0F12, 0x019C,},
        {0x002A, 0x0D3E,},// bp_uMinBrightnessFactor */
        {0x0F12, 0x02A0,},

//*********************************************************************************
// 13.AE Weight (Normal)                                                           
//*********************************************************************************
        {0x002A, 0x0D4E,},
        {0x0F12, 0x0100,}, //ae_WeightTbl_16_0_  
        {0x0F12, 0x0001,}, //ae_WeightTbl_16_1_  
        {0x0F12, 0x0100,}, //ae_WeightTbl_16_2_  
        {0x0F12, 0x0001,}, //ae_WeightTbl_16_3_  
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_4_  
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_5_  
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_6_  
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_7_  
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_8_  
        {0x0F12, 0x0201,}, //ae_WeightTbl_16_9_  
        {0x0F12, 0x0202,}, //ae_WeightTbl_16_10_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_11_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_12_ 
        {0x0F12, 0x0303,}, //ae_WeightTbl_16_13_ 
        {0x0F12, 0x0303,}, //ae_WeightTbl_16_14_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_15_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_16_ 
        {0x0F12, 0x0503,}, //ae_WeightTbl_16_17_ 
        {0x0F12, 0x0305,}, //ae_WeightTbl_16_18_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_19_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_20_ 
        {0x0F12, 0x0402,}, //ae_WeightTbl_16_21_ 
        {0x0F12, 0x0204,}, //ae_WeightTbl_16_22_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_23_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_24_ 
        {0x0F12, 0x0201,}, //ae_WeightTbl_16_25_ 
        {0x0F12, 0x0102,}, //ae_WeightTbl_16_26_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_27_ 
        {0x0F12, 0x0100,}, //ae_WeightTbl_16_28_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_29_ 
        {0x0F12, 0x0101,}, //ae_WeightTbl_16_30_ 
        {0x0F12, 0x0001,}, //ae_WeightTbl_16_31_ 

//*************************************/
// 14.Flash Setting                   */
//*************************************/

//*************************************/
// 15.CCM Setting                     */
//*************************************/

        {0x002A, 0x33A4,},
        {0x0F12, 0x01D0,},//01D0// Tune_wbt_BaseCcms_0__0_  */
        {0x0F12, 0xFFA1,},//FFA1// Tune_wbt_BaseCcms_0__1_  */
        {0x0F12, 0xFFFA,},//FFFA// Tune_wbt_BaseCcms_0__2_  */
        {0x0F12, 0xFF6F,},//FF6F// Tune_wbt_BaseCcms_0__3_  */
        {0x0F12, 0x0140,},//0140// Tune_wbt_BaseCcms_0__4_  */
        {0x0F12, 0xFF49,},//FF49// Tune_wbt_BaseCcms_0__5_  */
        {0x0F12, 0xFFC1,},//FFC1// Tune_wbt_BaseCcms_0__6_  */
        {0x0F12, 0x001F,},//001F// Tune_wbt_BaseCcms_0__7_  */
        {0x0F12, 0x01BD,},//01BD// Tune_wbt_BaseCcms_0__8_  */
        {0x0F12, 0x013F,},//013F// Tune_wbt_BaseCcms_0__9_  */
        {0x0F12, 0x00E1,},//00E1// Tune_wbt_BaseCcms_0__10_ */
        {0x0F12, 0xFF43,},//FF43// Tune_wbt_BaseCcms_0__11_ */
        {0x0F12, 0x0191,},//0191// Tune_wbt_BaseCcms_0__12_ */
        {0x0F12, 0xFFC0,},//FFC0// Tune_wbt_BaseCcms_0__13_ */
        {0x0F12, 0x01B7,},//01B7// Tune_wbt_BaseCcms_0__14_ */
        {0x0F12, 0xFF30,},//FF30// Tune_wbt_BaseCcms_0__15_ */
        {0x0F12, 0x015F,},//015F// Tune_wbt_BaseCcms_0__16_ */
        {0x0F12, 0x0106,},//0106// Tune_wbt_BaseCcms_0__17_ */
        {0x0F12, 0x01D0,},//01D0// Tune_wbt_BaseCcms_1__0_  */
        {0x0F12, 0xFFA1,},//FFA1// Tune_wbt_BaseCcms_1__1_  */
        {0x0F12, 0xFFFA,},//FFFA// Tune_wbt_BaseCcms_1__2_  */
        {0x0F12, 0xFF6F,},//FF6F// Tune_wbt_BaseCcms_1__3_  */
        {0x0F12, 0x0140,},//0140// Tune_wbt_BaseCcms_1__4_  */
        {0x0F12, 0xFF49,},//FF49// Tune_wbt_BaseCcms_1__5_  */
        {0x0F12, 0xFFC1,},//FFC1// Tune_wbt_BaseCcms_1__6_  */
        {0x0F12, 0x001F,},//001F// Tune_wbt_BaseCcms_1__7_  */
        {0x0F12, 0x01BD,},//01BD// Tune_wbt_BaseCcms_1__8_  */
        {0x0F12, 0x013F,},//013F// Tune_wbt_BaseCcms_1__9_  */
        {0x0F12, 0x00E1,},//00E1// Tune_wbt_BaseCcms_1__10_ */
        {0x0F12, 0xFF43,},//FF43// Tune_wbt_BaseCcms_1__11_ */
        {0x0F12, 0x0191,},//0191// Tune_wbt_BaseCcms_1__12_ */
        {0x0F12, 0xFFC0,},//FFC0// Tune_wbt_BaseCcms_1__13_ */
        {0x0F12, 0x01B7,},//01B7// Tune_wbt_BaseCcms_1__14_ */
        {0x0F12, 0xFF30,},//FF30// Tune_wbt_BaseCcms_1__15_ */
        {0x0F12, 0x015F,},//015F// Tune_wbt_BaseCcms_1__16_ */
        {0x0F12, 0x0106,},//0106// Tune_wbt_BaseCcms_1__17_ */
        {0x0F12, 0x01C4,},//01C4// 01F3 01C2 01D0 Tune_wbt_BaseCcms_2__0_  */
        {0x0F12, 0xFFAB,},//FFAB// FFCB FF93 FFA1 Tune_wbt_BaseCcms_2__1_  */
        {0x0F12, 0xFFFC,},//FFFC// 0031 001C FFFA Tune_wbt_BaseCcms_2__2_  */
        {0x0F12, 0xFF6E,},//FF6E// FF6F Tune_wbt_BaseCcms_2__3_  */
        {0x0F12, 0x0145,},//0145// 0140 Tune_wbt_BaseCcms_2__4_  */
        {0x0F12, 0xFF4A,},//FF4A// FF49 Tune_wbt_BaseCcms_2__5_  */
        {0x0F12, 0xFFE1,},//FFE1// FFE3 FFC1 Tune_wbt_BaseCcms_2__6_  */
        {0x0F12, 0xFFF6,},//FFF6// FFF9 001F Tune_wbt_BaseCcms_2__7_  */
        {0x0F12, 0x01BD,},//01BD// 01C1 01BD Tune_wbt_BaseCcms_2__8_  */
        {0x0F12, 0x013E,},//013E// 013F Tune_wbt_BaseCcms_2__9_  */
        {0x0F12, 0x00E4,},//00E4// 00E1 Tune_wbt_BaseCcms_2__10_ */
        {0x0F12, 0xFF46,},//FF46// FF43 Tune_wbt_BaseCcms_2__11_ */
        {0x0F12, 0x0190,},//0190// 0191 Tune_wbt_BaseCcms_2__12_ */
        {0x0F12, 0xFFBC,},//FFBC// FFC0 Tune_wbt_BaseCcms_2__13_ */
        {0x0F12, 0x01B5,},//01B5// 01B7 Tune_wbt_BaseCcms_2__14_ */
        {0x0F12, 0xFF30,},//FF30// FF30 Tune_wbt_BaseCcms_2__15_ */
        {0x0F12, 0x015E,},//015E// 015F Tune_wbt_BaseCcms_2__16_ */
        {0x0F12, 0x0103,},//0103// 0106 Tune_wbt_BaseCcms_2__17_ */
        {0x0F12, 0x01C4,},//01C4// 01D0 Tune_wbt_BaseCcms_3__0_  */
        {0x0F12, 0xFFAB,},//FFAB// FFA1 Tune_wbt_BaseCcms_3__1_  */
        {0x0F12, 0xFFFC,},//FFFC// FFFA Tune_wbt_BaseCcms_3__2_  */
        {0x0F12, 0xFF6E,},//FF6E// FF6F Tune_wbt_BaseCcms_3__3_  */
        {0x0F12, 0x0145,},//0145// 0140 Tune_wbt_BaseCcms_3__4_  */
        {0x0F12, 0xFF4A,},//FF4A// FF49 Tune_wbt_BaseCcms_3__5_  */
        {0x0F12, 0xFFE1,},//FFE1// FFE3 Tune_wbt_BaseCcms_3__6_  */
        {0x0F12, 0xFFF6,},//FFF6// FFF9 Tune_wbt_BaseCcms_3__7_  */
        {0x0F12, 0x01BD,},//01BD// 01C1 Tune_wbt_BaseCcms_3__8_  */
        {0x0F12, 0x013E,},//013E// 013F Tune_wbt_BaseCcms_3__9_  */
        {0x0F12, 0x00E4,},//00E4// 00E1 Tune_wbt_BaseCcms_3__10_ */
        {0x0F12, 0xFF46,},//FF46// FF43 Tune_wbt_BaseCcms_3__11_ */
        {0x0F12, 0x0190,},//0190// 0191 Tune_wbt_BaseCcms_3__12_ */
        {0x0F12, 0xFFBC,},//FFBC// FFC0 Tune_wbt_BaseCcms_3__13_ */
        {0x0F12, 0x01B5,},//01B5// 01B7 Tune_wbt_BaseCcms_3__14_ */
        {0x0F12, 0xFF30,},//FF30// FF30 Tune_wbt_BaseCcms_3__15_ */
        {0x0F12, 0x015E,},//015E// 015F Tune_wbt_BaseCcms_3__16_ */
        {0x0F12, 0x0103,},//0103// 0106 Tune_wbt_BaseCcms_3__17_ */
        {0x0F12, 0x01C6,},//01C6// 01BF 01E9 01C7 01BF 01C7 01BF Tune_wbt_BaseCcms_4__0_  */
        {0x0F12, 0xFFC2,},//FFC2// FFBF FFE4 FFA5 FFBF FFA5 FFBF Tune_wbt_BaseCcms_4__1_  */
        {0x0F12, 0x0004,},//0004// FFFE 0031 0006 FFFE 0006 FFFE Tune_wbt_BaseCcms_4__2_  */
        {0x0F12, 0xFF6F,},//FF6F// FF6D FF6F FF6D Tune_wbt_BaseCcms_4__3_  */
        {0x0F12, 0x01C9,},//01C9// 01B4 01C9 01B4 Tune_wbt_BaseCcms_4__4_  */
        {0x0F12, 0xFF4F,},//FF4F// FF66 FF4F FF66 Tune_wbt_BaseCcms_4__5_  */
        {0x0F12, 0xFFDB,},//FFDB// FFCA FFDB FFCA Tune_wbt_BaseCcms_4__6_  */
        {0x0F12, 0xFFC0,},//FFC0// FFCE FFC0 FFCE Tune_wbt_BaseCcms_4__7_  */
        {0x0F12, 0x019D,},//019D// 017B 019D 017B Tune_wbt_BaseCcms_4__8_  */
        {0x0F12, 0x0136,},//0136// Tune_wbt_BaseCcms_4__9_  */
        {0x0F12, 0x0132,},//0132// Tune_wbt_BaseCcms_4__10_ */
        {0x0F12, 0xFF85,},//FF85// Tune_wbt_BaseCcms_4__11_ */
        {0x0F12, 0x018B,},//018B// Tune_wbt_BaseCcms_4__12_ */
        {0x0F12, 0xFF73,},//FF73// Tune_wbt_BaseCcms_4__13_ */
        {0x0F12, 0x0191,},//0191// Tune_wbt_BaseCcms_4__14_ */
        {0x0F12, 0xFF3F,},//FF3F// Tune_wbt_BaseCcms_4__15_ */
        {0x0F12, 0x015B,},//015B// Tune_wbt_BaseCcms_4__16_ */
        {0x0F12, 0x00D0,},//00D0// Tune_wbt_BaseCcms_4__17_ */
        {0x0F12, 0x01C6,},//01C6// 01BF 01E9 01C7 01BF 01C7 01BF Tune_wbt_BaseCcms_5__0_  */
        {0x0F12, 0xFFC2,},//FFC2// FFBF FFE4 FFA5 FFBF FFA5 FFBF Tune_wbt_BaseCcms_5__1_  */
        {0x0F12, 0x0004,},//0004// FFFE 0031 0006 FFFE 0006 FFFE Tune_wbt_BaseCcms_5__2_  */
        {0x0F12, 0xFF6F,},//FF6F// FF6D FF6F FF6D Tune_wbt_BaseCcms_5__3_  */
        {0x0F12, 0x01C9,},//01C9// 01B4 01C9 01B4 Tune_wbt_BaseCcms_5__4_  */
        {0x0F12, 0xFF4F,},//FF4F// FF66 FF4F FF66 Tune_wbt_BaseCcms_5__5_  */
        {0x0F12, 0xFFDB,},//FFDB// FFCA FFDB FFCA FFE7 FFCA Tune_wbt_BaseCcms_5__6_  */
        {0x0F12, 0xFFC0,},//FFC0// FFCE FFC0 FFCE FFC2 FFCE Tune_wbt_BaseCcms_5__7_  */
        {0x0F12, 0x019D,},//019D// 017B 019D 017B 018C 017B Tune_wbt_BaseCcms_5__8_  */
        {0x0F12, 0x0136,},//0136// Tune_wbt_BaseCcms_5__9_  */
        {0x0F12, 0x0132,},//0132// Tune_wbt_BaseCcms_5__10_ */
        {0x0F12, 0xFF85,},//FF85// Tune_wbt_BaseCcms_5__11_ */
        {0x0F12, 0x018B,},//018B// Tune_wbt_BaseCcms_5__12_ */
        {0x0F12, 0xFF73,},//FF73// Tune_wbt_BaseCcms_5__13_ */
        {0x0F12, 0x0191,},//0191// Tune_wbt_BaseCcms_5__14_ */
        {0x0F12, 0xFF3F,},//FF3F// Tune_wbt_BaseCcms_5__15_ */
        {0x0F12, 0x015B,},//015B// Tune_wbt_BaseCcms_5__16_ */
        {0x0F12, 0x00D0,},//00D0// Tune_wbt_BaseCcms_5__17_ */
        {0x002A, 0x3380,},
        {0x0F12, 0x01D6,}, //023C// 021B 021B 023D 01E9 01C7 01BF 01AC Tune_wbt_OutdoorCcm_0_   */
        {0x0F12, 0xFF94,}, //FFE0// FFE9 0010 0038 FFE4 FFA5 FFBF FFD7 Tune_wbt_OutdoorCcm_1_   */
        {0x0F12, 0xFFCC,}, //0052// 0050 0073 0085 0031 0006 FFFE 0019 Tune_wbt_OutdoorCcm_2_   */
        {0x0F12, 0xFF1F,}, //FF6F// FF6D Tune_wbt_OutdoorCcm_3_   */
        {0x0F12, 0x021F,}, //01C9// 01B4 Tune_wbt_OutdoorCcm_4_   */
        {0x0F12, 0xFF1F,}, //FF4F// FF66 Tune_wbt_OutdoorCcm_5_   */
        {0x0F12, 0xFFE4,}, //0000// FFE9 FFDB FFD5 FFD5 FFE7 FFCA Tune_wbt_OutdoorCcm_6_   */
        {0x0F12, 0xFFED,}, //FFA4// FFBA FFC0 FFD6 FFD6 FFC2 FFCE Tune_wbt_OutdoorCcm_7_   */
        {0x0F12, 0x01C8,}, //01A5// 01AC 019D 018D 018D 018C 017B Tune_wbt_OutdoorCcm_8_   */
        {0x0F12, 0x010F,}, //0125// 0132 Tune_wbt_OutdoorCcm_9_   */
        {0x0F12, 0x0150,}, //013B// 012E Tune_wbt_OutdoorCcm_10_  */
        {0x0F12, 0xFF16,}, //FF8D// FF8D Tune_wbt_OutdoorCcm_11_  */
        {0x0F12, 0x0210,}, //018B// Tune_wbt_OutdoorCcm_12_  */
        {0x0F12, 0xFF5D,}, //FF73// Tune_wbt_OutdoorCcm_13_  */
        {0x0F12, 0x0244,}, //0191// Tune_wbt_OutdoorCcm_14_  */
        {0x0F12, 0xFF10,}, //FF3F// Tune_wbt_OutdoorCcm_15_  */
        {0x0F12, 0x0190,}, //015B// Tune_wbt_OutdoorCcm_16_  */
        {0x0F12, 0x0145,}, //00D0// Tune_wbt_OutdoorCcm_17_  */
        {0x002A, 0x0612,},
        {0x0F12, 0x009D,},// SARR_AwbCcmCord_0_       */
        {0x0F12, 0x00D5,},// SARR_AwbCcmCord_1_       */
        {0x0F12, 0x0103,},// SARR_AwbCcmCord_2_       */
        {0x0F12, 0x0128,},// SARR_AwbCcmCord_3_       */
        {0x0F12, 0x0166,},// SARR_AwbCcmCord_4_       */
        {0x0F12, 0x0193,},// SARR_AwbCcmCord_5_       */

//*************************************/
// 17.GAMMA                           */
//*************************************/
// For Pre Post Gamma Calibration */
        {0x002A, 0x0538,},
        {0x0F12, 0x0000,},// seti_uGammaLutPreDemNoBin_0_   */
        {0x0F12, 0x001F,},// seti_uGammaLutPreDemNoBin_1_   */
        {0x0F12, 0x0035,},// seti_uGammaLutPreDemNoBin_2_   */
        {0x0F12, 0x005A,},// seti_uGammaLutPreDemNoBin_3_   */
        {0x0F12, 0x0095,},// seti_uGammaLutPreDemNoBin_4_   */
        {0x0F12, 0x00E6,},// seti_uGammaLutPreDemNoBin_5_   */
        {0x0F12, 0x0121,},// seti_uGammaLutPreDemNoBin_6_   */
        {0x0F12, 0x0139,},// seti_uGammaLutPreDemNoBin_7_   */
        {0x0F12, 0x0150,},// seti_uGammaLutPreDemNoBin_8_   */
        {0x0F12, 0x0177,},// seti_uGammaLutPreDemNoBin_9_   */
        {0x0F12, 0x019A,},// seti_uGammaLutPreDemNoBin_10_  */
        {0x0F12, 0x01BB,},// seti_uGammaLutPreDemNoBin_11_  */
        {0x0F12, 0x01DC,},// seti_uGammaLutPreDemNoBin_12_  */
        {0x0F12, 0x0219,},// seti_uGammaLutPreDemNoBin_13_  */
        {0x0F12, 0x0251,},// seti_uGammaLutPreDemNoBin_14_  */
        {0x0F12, 0x02B3,},// seti_uGammaLutPreDemNoBin_15_  */
        {0x0F12, 0x030A,},// seti_uGammaLutPreDemNoBin_16_  */
        {0x0F12, 0x035F,},// seti_uGammaLutPreDemNoBin_17_  */
        {0x0F12, 0x03B1,},// seti_uGammaLutPreDemNoBin_18_  */
        {0x0F12, 0x03FF,},// seti_uGammaLutPreDemNoBin_19_  */
        {0x0F12, 0x0000,},// seti_uGammaLutPostDemNoBin_0_  */
        {0x0F12, 0x0001,},// seti_uGammaLutPostDemNoBin_1_  */
        {0x0F12, 0x0001,},// seti_uGammaLutPostDemNoBin_2_  */
        {0x0F12, 0x0002,},// seti_uGammaLutPostDemNoBin_3_  */
        {0x0F12, 0x0004,},// seti_uGammaLutPostDemNoBin_4_  */
        {0x0F12, 0x000A,},// seti_uGammaLutPostDemNoBin_5_  */
        {0x0F12, 0x0012,},// seti_uGammaLutPostDemNoBin_6_  */
        {0x0F12, 0x0016,},// seti_uGammaLutPostDemNoBin_7_  */
        {0x0F12, 0x001A,},// seti_uGammaLutPostDemNoBin_8_  */
        {0x0F12, 0x0024,},// seti_uGammaLutPostDemNoBin_9_  */
        {0x0F12, 0x0031,},// seti_uGammaLutPostDemNoBin_10_ */
        {0x0F12, 0x003E,},// seti_uGammaLutPostDemNoBin_11_ */
        {0x0F12, 0x004E,},// seti_uGammaLutPostDemNoBin_12_ */
        {0x0F12, 0x0075,},// seti_uGammaLutPostDemNoBin_13_ */
        {0x0F12, 0x00A8,},// seti_uGammaLutPostDemNoBin_14_ */
        {0x0F12, 0x0126,},// seti_uGammaLutPostDemNoBin_15_ */
        {0x0F12, 0x01BE,},// seti_uGammaLutPostDemNoBin_16_ */
        {0x0F12, 0x0272,},// seti_uGammaLutPostDemNoBin_17_ */
        {0x0F12, 0x0334,},// seti_uGammaLutPostDemNoBin_18_ */
        {0x0F12, 0x03FF,},// seti_uGammaLutPostDemNoBin_19_ */

// For Gamma Calibration */

        {0x002A, 0x0498,},
        {0x0F12, 0x0000,},// SARR_usDualGammaLutRGBIndoor_0__0_   */
        {0x0F12, 0x0002,},// SARR_usDualGammaLutRGBIndoor_0__1_   */
        {0x0F12, 0x0007,},// SARR_usDualGammaLutRGBIndoor_0__2_   */
        {0x0F12, 0x001D,},// SARR_usDualGammaLutRGBIndoor_0__3_   */
        {0x0F12, 0x006E,},// SARR_usDualGammaLutRGBIndoor_0__4_   */
        {0x0F12, 0x00D3,},// SARR_usDualGammaLutRGBIndoor_0__5_   */
        {0x0F12, 0x0127,},// SARR_usDualGammaLutRGBIndoor_0__6_   */
        {0x0F12, 0x014C,},// SARR_usDualGammaLutRGBIndoor_0__7_   */
        {0x0F12, 0x016E,},// SARR_usDualGammaLutRGBIndoor_0__8_   */
        {0x0F12, 0x01A5,},// SARR_usDualGammaLutRGBIndoor_0__9_   */
        {0x0F12, 0x01D3,},// SARR_usDualGammaLutRGBIndoor_0__10_  */
        {0x0F12, 0x01FB,},// SARR_usDualGammaLutRGBIndoor_0__11_  */
        {0x0F12, 0x021F,},// SARR_usDualGammaLutRGBIndoor_0__12_  */
        {0x0F12, 0x0260,},// SARR_usDualGammaLutRGBIndoor_0__13_  */
        {0x0F12, 0x029A,},// SARR_usDualGammaLutRGBIndoor_0__14_  */
        {0x0F12, 0x02F7,},// SARR_usDualGammaLutRGBIndoor_0__15_  */
        {0x0F12, 0x034D,},// SARR_usDualGammaLutRGBIndoor_0__16_  */
        {0x0F12, 0x0395,},// SARR_usDualGammaLutRGBIndoor_0__17_  */
        {0x0F12, 0x03CE,},// SARR_usDualGammaLutRGBIndoor_0__18_  */
        {0x0F12, 0x03FF,},// SARR_usDualGammaLutRGBIndoor_0__19_  */
        {0x0F12, 0x0000,},// SARR_usDualGammaLutRGBOutdoor_0__0_  */
        {0x0F12, 0x0004,},// SARR_usDualGammaLutRGBOutdoor_0__1_  */
        {0x0F12, 0x000C,},// SARR_usDualGammaLutRGBOutdoor_0__2_  */
        {0x0F12, 0x0024,},// SARR_usDualGammaLutRGBOutdoor_0__3_  */
        {0x0F12, 0x006E,},// SARR_usDualGammaLutRGBOutdoor_0__4_  */
        {0x0F12, 0x00D1,},// SARR_usDualGammaLutRGBOutdoor_0__5_  */
        {0x0F12, 0x0119,},// SARR_usDualGammaLutRGBOutdoor_0__6_  */
        {0x0F12, 0x0139,},// SARR_usDualGammaLutRGBOutdoor_0__7_  */
        {0x0F12, 0x0157,},// SARR_usDualGammaLutRGBOutdoor_0__8_  */
        {0x0F12, 0x018E,},// SARR_usDualGammaLutRGBOutdoor_0__9_  */
        {0x0F12, 0x01C3,},// SARR_usDualGammaLutRGBOutdoor_0__10_ */
        {0x0F12, 0x01F3,},// SARR_usDualGammaLutRGBOutdoor_0__11_ */
        {0x0F12, 0x021F,},// SARR_usDualGammaLutRGBOutdoor_0__12_ */
        {0x0F12, 0x0269,},// SARR_usDualGammaLutRGBOutdoor_0__13_ */
        {0x0F12, 0x02A6,},// SARR_usDualGammaLutRGBOutdoor_0__14_ */
        {0x0F12, 0x02FF,},// SARR_usDualGammaLutRGBOutdoor_0__15_ */
        {0x0F12, 0x0351,},// SARR_usDualGammaLutRGBOutdoor_0__16_ */
        {0x0F12, 0x0395,},// SARR_usDualGammaLutRGBOutdoor_0__17_ */
        {0x0F12, 0x03CE,},// SARR_usDualGammaLutRGBOutdoor_0__18_ */
        {0x0F12, 0x03FF,},// SARR_usDualGammaLutRGBOutdoor_0__19_ */

//*************************************/
// 16.AFIT                            */
//*************************************/
        {0x002A, 0x3370,},
        {0x0F12, 0x0000,},// afit_bUseNormBrForAfit */

        {0x002A, 0x06D4,},
        {0x0F12, 0x0032,},// afit_uNoiseIndInDoor_0_ */
        {0x0F12, 0x0078,},// afit_uNoiseIndInDoor_1_ */
        {0x0F12, 0x00C8,},// afit_uNoiseIndInDoor_2_ */
        {0x0F12, 0x0190,},// afit_uNoiseIndInDoor_3_ */
        {0x0F12, 0x028C,},// afit_uNoiseIndInDoor_4_ */

        {0x002A, 0x0734,},
        {0x0F12, 0x0000,},// AfitBaseVals_0__0_  Brightness[0] */
        {0x0F12, 0x0000,},// AfitBaseVals_0__1_  Contrast[0] */
        {0x0F12, 0x0000,},// AfitBaseVals_0__2_  Saturation[0] */
        {0x0F12, 0x0000,},// AfitBaseVals_0__3_  Sharp_Blur[0] */
        {0x0F12, 0x0000,},// AfitBaseVals_0__4_  */
        {0x0F12, 0x0078,},// AfitBaseVals_0__5_  */
        {0x0F12, 0x012C,},// AfitBaseVals_0__6_  */
        {0x0F12, 0x03FF,},// AfitBaseVals_0__7_  */
        {0x0F12, 0x0014,},// AfitBaseVals_0__8_  */
        {0x0F12, 0x0064,},// AfitBaseVals_0__9_  */
        {0x0F12, 0x000C,},// AfitBaseVals_0__10_ */
        {0x0F12, 0x0010,},// AfitBaseVals_0__11_ */
        {0x0F12, 0x01E6,},// AfitBaseVals_0__12_ */
        {0x0F12, 0x0000,},// AfitBaseVals_0__13_ */
        {0x0F12, 0x0070,},// AfitBaseVals_0__14_ */
        {0x0F12, 0x01FF,},// AfitBaseVals_0__15_ */
        {0x0F12, 0x0144,},// AfitBaseVals_0__16_ */
        {0x0F12, 0x000F,},// AfitBaseVals_0__17_ */
        {0x0F12, 0x000A,},// AfitBaseVals_0__18_ */
        {0x0F12, 0x0073,},// AfitBaseVals_0__19_ */
        {0x0F12, 0x0087,},// AfitBaseVals_0__20_ */
        {0x0F12, 0x0014,},// AfitBaseVals_0__21_ */
        {0x0F12, 0x000A,},// AfitBaseVals_0__22_ */
        {0x0F12, 0x0023,},// AfitBaseVals_0__23_ */
        {0x0F12, 0x001E,},// AfitBaseVals_0__24_ */
        {0x0F12, 0x0014,},// AfitBaseVals_0__25_ */
        {0x0F12, 0x000A,},// AfitBaseVals_0__26_ */
        {0x0F12, 0x0023,},// AfitBaseVals_0__27_ */
        {0x0F12, 0x0046,},// AfitBaseVals_0__28_ */
        {0x0F12, 0x2B32,},// AfitBaseVals_0__29_ */
        {0x0F12, 0x0601,},// AfitBaseVals_0__30_ */
        {0x0F12, 0x0000,},// AfitBaseVals_0__31_ */
        {0x0F12, 0x0000,},// AfitBaseVals_0__32_ */
        {0x0F12, 0x0000,},// AfitBaseVals_0__33_ */
        {0x0F12, 0x00FF,},// AfitBaseVals_0__34_ */
        {0x0F12, 0x07FF,},// AfitBaseVals_0__35_ */
        {0x0F12, 0xFFFF,},// AfitBaseVals_0__36_ */
        {0x0F12, 0x0000,},// AfitBaseVals_0__37_ */
        {0x0F12, 0x050D,},// AfitBaseVals_0__38_ */
        {0x0F12, 0x1E80,},// AfitBaseVals_0__39_ */
        {0x0F12, 0x0000,},// AfitBaseVals_0__40_ */
        {0x0F12, 0x1408,},// 1408 AfitBaseVals_0__41_ iNearGrayDesat[0] */
        {0x0F12, 0x0214,},// AfitBaseVals_0__42_ */
        {0x0F12, 0xFF01,},// AfitBaseVals_0__43_ */
        {0x0F12, 0x180F,},// AfitBaseVals_0__44_ */
        {0x0F12, 0x0001,},// AfitBaseVals_0__45_ */
        {0x0F12, 0x0000,},// AfitBaseVals_0__46_ */
        {0x0F12, 0x8003,},// AfitBaseVals_0__47_ */
        {0x0F12, 0x0094,},// AfitBaseVals_0__48_ */
        {0x0F12, 0x0580,},// AfitBaseVals_0__49_ */
        {0x0F12, 0x0280,},// AfitBaseVals_0__50_ */
        {0x0F12, 0x0310,},// AfitBaseVals_0__51_ iClustThresh_H[0] iClustMulT_H[0] */
        {0x0F12, 0x3186,},// AfitBaseVals_0__52_ */
        {0x0F12, 0x707E,},// AfitBaseVals_0__53_ */
        {0x0F12, 0x0A02,},// AfitBaseVals_0__54_ */
        {0x0F12, 0x080A,},// AfitBaseVals_0__55_ */
        {0x0F12, 0x0500,},// AfitBaseVals_0__56_ */
        {0x0F12, 0x032D,},// AfitBaseVals_0__57_ */
        {0x0F12, 0x324E,},// AfitBaseVals_0__58_ */
        {0x0F12, 0x001E,},// AfitBaseVals_0__59_ */
        {0x0F12, 0x0200,},// AfitBaseVals_0__60_ */
        {0x0F12, 0x0103,},// AfitBaseVals_0__61_ */
        {0x0F12, 0x010C,},// AfitBaseVals_0__62_ */
        {0x0F12, 0x9696,},// AfitBaseVals_0__63_ */
        {0x0F12, 0x4646,},// AfitBaseVals_0__64_ */
        {0x0F12, 0x0802,},// AfitBaseVals_0__65_ */
        {0x0F12, 0x0802,},// AfitBaseVals_0__66_ */
        {0x0F12, 0x0000,},// AfitBaseVals_0__67_ */
        {0x0F12, 0x030F,},// AfitBaseVals_0__68_ */
        {0x0F12, 0x3202,},// AfitBaseVals_0__69_ */
        {0x0F12, 0x0F1E,},// AfitBaseVals_0__70_ */
        {0x0F12, 0x020F,},// AfitBaseVals_0__71_ */
        {0x0F12, 0x0103,},// AfitBaseVals_0__72_ */
        {0x0F12, 0x010C,},// AfitBaseVals_0__73_ */
        {0x0F12, 0x9696,},// AfitBaseVals_0__74_ */
        {0x0F12, 0x4646,},// AfitBaseVals_0__75_ */
        {0x0F12, 0x0802,},// AfitBaseVals_0__76_ */
        {0x0F12, 0x0802,},// AfitBaseVals_0__77_ */
        {0x0F12, 0x0000,},// AfitBaseVals_0__78_ */
        {0x0F12, 0x030F,},// AfitBaseVals_0__79_ */
        {0x0F12, 0x3202,},// AfitBaseVals_0__80_ */
        {0x0F12, 0x0F1E,},// AfitBaseVals_0__81_ */
        {0x0F12, 0x020F,},// AfitBaseVals_0__82_ */
        {0x0F12, 0x0003,},// AfitBaseVals_0__83_ */
        {0x0F12, 0x0000,},// AfitBaseVals_1__0_  Brightness[1] */
        {0x0F12, 0x0000,},// AfitBaseVals_1__1_  Contrast[1] */
        {0x0F12, 0x0000,},// AfitBaseVals_1__2_  Saturation[1] */
        {0x0F12, 0x0000,},// AfitBaseVals_1__3_  Sharp_Blur[1] */
        {0x0F12, 0x0000,},// AfitBaseVals_1__4_  */
        {0x0F12, 0x006A,},// AfitBaseVals_1__5_  */
        {0x0F12, 0x012C,},// AfitBaseVals_1__6_  */
        {0x0F12, 0x03FF,},// AfitBaseVals_1__7_  */
        {0x0F12, 0x0014,},// AfitBaseVals_1__8_  */
        {0x0F12, 0x0064,},// AfitBaseVals_1__9_  */
        {0x0F12, 0x000C,},// AfitBaseVals_1__10_ */
        {0x0F12, 0x0010,},// AfitBaseVals_1__11_ */
        {0x0F12, 0x01E6,},// AfitBaseVals_1__12_ */
        {0x0F12, 0x03FF,},// AfitBaseVals_1__13_ */
        {0x0F12, 0x0070,},// AfitBaseVals_1__14_ */
        {0x0F12, 0x007D,},// AfitBaseVals_1__15_ */
        {0x0F12, 0x0064,},// AfitBaseVals_1__16_ */
        {0x0F12, 0x0014,},// AfitBaseVals_1__17_ */
        {0x0F12, 0x000A,},// AfitBaseVals_1__18_ */
        {0x0F12, 0x0073,},// AfitBaseVals_1__19_ */
        {0x0F12, 0x0087,},// AfitBaseVals_1__20_ */
        {0x0F12, 0x0014,},// AfitBaseVals_1__21_ */
        {0x0F12, 0x000A,},// AfitBaseVals_1__22_ */
        {0x0F12, 0x0023,},// AfitBaseVals_1__23_ */
        {0x0F12, 0x001E,},// AfitBaseVals_1__24_ */
        {0x0F12, 0x0014,},// AfitBaseVals_1__25_ */
        {0x0F12, 0x000A,},// AfitBaseVals_1__26_ */
        {0x0F12, 0x0023,},// AfitBaseVals_1__27_ */
        {0x0F12, 0x001E,},// AfitBaseVals_1__28_ */
        {0x0F12, 0x2B32,},// AfitBaseVals_1__29_ */
        {0x0F12, 0x0601,},// AfitBaseVals_1__30_ */
        {0x0F12, 0x0000,},// AfitBaseVals_1__31_ */
        {0x0F12, 0x0000,},// AfitBaseVals_1__32_ */
        {0x0F12, 0x0000,},// AfitBaseVals_1__33_ */
        {0x0F12, 0x00FF,},// AfitBaseVals_1__34_ */
        {0x0F12, 0x07FF,},// AfitBaseVals_1__35_ */
        {0x0F12, 0xFFFF,},// AfitBaseVals_1__36_ */
        {0x0F12, 0x0000,},// AfitBaseVals_1__37_ */
        {0x0F12, 0x050D,},// AfitBaseVals_1__38_ */
        {0x0F12, 0x1E80,},// AfitBaseVals_1__39_ */
        {0x0F12, 0x0000,},// AfitBaseVals_1__40_ */
        {0x0F12, 0x1403,},// 1408 AfitBaseVals_1__41_ iNearGrayDesat[1] */
        {0x0F12, 0x0214,},// AfitBaseVals_1__42_ */
        {0x0F12, 0xFF01,},// AfitBaseVals_1__43_ */
        {0x0F12, 0x180F,},// AfitBaseVals_1__44_ */
        {0x0F12, 0x0002,},// AfitBaseVals_1__45_ */
        {0x0F12, 0x0000,},// AfitBaseVals_1__46_ */
        {0x0F12, 0x8003,},// AfitBaseVals_1__47_ */
        {0x0F12, 0x0080,},// AfitBaseVals_1__48_ */
        {0x0F12, 0x0080,},// AfitBaseVals_1__49_ */
        {0x0F12, 0x0180,},// AfitBaseVals_1__50_ */
        {0x0F12, 0x0310,},// AfitBaseVals_1__51_ iClustThresh_H[1] iClustMulT_H[1] */
        {0x0F12, 0x1E65,},// AfitBaseVals_1__52_ */
        {0x0F12, 0x1A24,},// AfitBaseVals_1__53_ */
        {0x0F12, 0x0A03,},// AfitBaseVals_1__54_ */
        {0x0F12, 0x080A,},// AfitBaseVals_1__55_ */
        {0x0F12, 0x0500,},// AfitBaseVals_1__56_ */
        {0x0F12, 0x032D,},// AfitBaseVals_1__57_ */
        {0x0F12, 0x324D,},// AfitBaseVals_1__58_ */
        {0x0F12, 0x001E,},// AfitBaseVals_1__59_ */
        {0x0F12, 0x0200,},// AfitBaseVals_1__60_ */
        {0x0F12, 0x0103,},// AfitBaseVals_1__61_ */
        {0x0F12, 0x010C,},// AfitBaseVals_1__62_ */
        {0x0F12, 0x9696,},// AfitBaseVals_1__63_ */
        {0x0F12, 0x2F34,},// AfitBaseVals_1__64_ */
        {0x0F12, 0x0504,},// AfitBaseVals_1__65_ */
        {0x0F12, 0x080F,},// AfitBaseVals_1__66_ */
        {0x0F12, 0x0000,},// AfitBaseVals_1__67_ */
        {0x0F12, 0x030F,},// AfitBaseVals_1__68_ */
        {0x0F12, 0x3208,},// AfitBaseVals_1__69_ */
        {0x0F12, 0x0F1E,},// AfitBaseVals_1__70_ */
        {0x0F12, 0x020F,},// AfitBaseVals_1__71_ */
        {0x0F12, 0x0103,},// AfitBaseVals_1__72_ */
        {0x0F12, 0x010C,},// AfitBaseVals_1__73_ */
        {0x0F12, 0x9696,},// AfitBaseVals_1__74_ */
        {0x0F12, 0x1414,},// AfitBaseVals_1__75_ */
        {0x0F12, 0x0504,},// AfitBaseVals_1__76_ */
        {0x0F12, 0x080F,},// AfitBaseVals_1__77_ */
        {0x0F12, 0x0000,},// AfitBaseVals_1__78_ */
        {0x0F12, 0x030F,},// AfitBaseVals_1__79_ */
        {0x0F12, 0x3208,},// AfitBaseVals_1__80_ */
        {0x0F12, 0x0F1E,},// AfitBaseVals_1__81_ */
        {0x0F12, 0x020F,},// AfitBaseVals_1__82_ */
        {0x0F12, 0x0003,},// AfitBaseVals_1__83_ */
        {0x0F12, 0x0000,},// AfitBaseVals_2__0_  Brightness[2] */
        {0x0F12, 0x0000,},// AfitBaseVals_2__1_  Contrast[2] */
        {0x0F12, 0xFFFC,},// 0000 AfitBaseVals_2__2_  Saturation[2] */
        {0x0F12, 0x0000,},// AfitBaseVals_2__3_  Sharp_Blur[2] */
        {0x0F12, 0x0000,},// AfitBaseVals_2__4_  */
        {0x0F12, 0x0064,},// AfitBaseVals_2__5_  */
        {0x0F12, 0x012C,},// AfitBaseVals_2__6_  */
        {0x0F12, 0x03FF,},// AfitBaseVals_2__7_  */
        {0x0F12, 0x0014,},// AfitBaseVals_2__8_  */
        {0x0F12, 0x0064,},// AfitBaseVals_2__9_  */
        {0x0F12, 0x000C,},// AfitBaseVals_2__10_ */
        {0x0F12, 0x0010,},// AfitBaseVals_2__11_ */
        {0x0F12, 0x01E6,},// AfitBaseVals_2__12_ */
        {0x0F12, 0x03FF,},// AfitBaseVals_2__13_ */
        {0x0F12, 0x0070,},// AfitBaseVals_2__14_ */
        {0x0F12, 0x007D,},// AfitBaseVals_2__15_ */
        {0x0F12, 0x0064,},// AfitBaseVals_2__16_ */
        {0x0F12, 0x0032,},// 0096 AfitBaseVals_2__17_ */
        {0x0F12, 0x0096,},// AfitBaseVals_2__18_ */
        {0x0F12, 0x0073,},// AfitBaseVals_2__19_ */
        {0x0F12, 0x0087,},// AfitBaseVals_2__20_ */
        {0x0F12, 0x0014,},// AfitBaseVals_2__21_ */
        {0x0F12, 0x0019,},// AfitBaseVals_2__22_ */
        {0x0F12, 0x0023,},// AfitBaseVals_2__23_ */
        {0x0F12, 0x001E,},// AfitBaseVals_2__24_ */
        {0x0F12, 0x0014,},// AfitBaseVals_2__25_ */
        {0x0F12, 0x0019,},// AfitBaseVals_2__26_ */
        {0x0F12, 0x0023,},// AfitBaseVals_2__27_ */
        {0x0F12, 0x001E,},// AfitBaseVals_2__28_ */
        {0x0F12, 0x2B32,},// AfitBaseVals_2__29_ */
        {0x0F12, 0x0601,},// AfitBaseVals_2__30_ */
        {0x0F12, 0x0000,},// AfitBaseVals_2__31_ */
        {0x0F12, 0x0000,},// AfitBaseVals_2__32_ */
        {0x0F12, 0x0000,},// AfitBaseVals_2__33_ */
        {0x0F12, 0x00FF,},// AfitBaseVals_2__34_ */
        {0x0F12, 0x07FF,},// AfitBaseVals_2__35_ */
        {0x0F12, 0xFFFF,},// AfitBaseVals_2__36_ */
        {0x0F12, 0x0000,},// AfitBaseVals_2__37_ */
        {0x0F12, 0x050D,},// AfitBaseVals_2__38_ */
        {0x0F12, 0x1E80,},// AfitBaseVals_2__39_ */
        {0x0F12, 0x0000,},// AfitBaseVals_2__40_ */
        {0x0F12, 0x0A03,},// 0A08 AfitBaseVals_2__41_ iNearGrayDesat[2] */
        {0x0F12, 0x0200,},// AfitBaseVals_2__42_ */
        {0x0F12, 0xFF01,},// AfitBaseVals_2__43_ */
        {0x0F12, 0x180F,},// AfitBaseVals_2__44_ */
        {0x0F12, 0x0002,},// AfitBaseVals_2__45_ */
        {0x0F12, 0x0000,},// AfitBaseVals_2__46_ */
        {0x0F12, 0x8003,},// AfitBaseVals_2__47_ */
        {0x0F12, 0x0080,},// AfitBaseVals_2__48_ */
        {0x0F12, 0x0080,},// AfitBaseVals_2__49_ */
        {0x0F12, 0x0180,},// AfitBaseVals_2__50_ */
        {0x0F12, 0x0210,},// AfitBaseVals_2__51_ iClustThresh_H[2] iClustMulT_H[2] */
        {0x0F12, 0x1E4B,},// AfitBaseVals_2__52_ */
        {0x0F12, 0x1A24,},// AfitBaseVals_2__53_ */
        {0x0F12, 0x0A05,},// AfitBaseVals_2__54_ */
        {0x0F12, 0x080A,},// AfitBaseVals_2__55_ */
        {0x0F12, 0x0500,},// AfitBaseVals_2__56_ */
        {0x0F12, 0x032D,},// AfitBaseVals_2__57_ */
        {0x0F12, 0x324D,},// AfitBaseVals_2__58_ */
        {0x0F12, 0x001E,},// AfitBaseVals_2__59_ */
        {0x0F12, 0x0200,},// AfitBaseVals_2__60_ */
        {0x0F12, 0x0103,},// AfitBaseVals_2__61_ */
        {0x0F12, 0x010C,},// AfitBaseVals_2__62_ */
        {0x0F12, 0x9696,},// AfitBaseVals_2__63_ */
        {0x0F12, 0x1E23,},// AfitBaseVals_2__64_ */
        {0x0F12, 0x0505,},// AfitBaseVals_2__65_ */
        {0x0F12, 0x080F,},// AfitBaseVals_2__66_ */
        {0x0F12, 0x0000,},// AfitBaseVals_2__67_ */
        {0x0F12, 0x030F,},// AfitBaseVals_2__68_ */
        {0x0F12, 0x3208,},// AfitBaseVals_2__69_ */
        {0x0F12, 0x0F1E,},// AfitBaseVals_2__70_ */
        {0x0F12, 0x020F,},// AfitBaseVals_2__71_ */
        {0x0F12, 0x0103,},// AfitBaseVals_2__72_ */
        {0x0F12, 0x010C,},// AfitBaseVals_2__73_ */
        {0x0F12, 0x9696,},// AfitBaseVals_2__74_ */
        {0x0F12, 0x1E23,},// AfitBaseVals_2__75_ */
        {0x0F12, 0x0505,},// AfitBaseVals_2__76_ */
        {0x0F12, 0x080F,},// AfitBaseVals_2__77_ */
        {0x0F12, 0x0000,},// AfitBaseVals_2__78_ */
        {0x0F12, 0x030F,},// AfitBaseVals_2__79_ */
        {0x0F12, 0x3208,},// AfitBaseVals_2__80_ */
        {0x0F12, 0x0F1E,},// AfitBaseVals_2__81_ */
        {0x0F12, 0x020F,},// AfitBaseVals_2__82_ */
        {0x0F12, 0x0003,},// AfitBaseVals_2__83_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__0_  Brightness[3] */
        {0x0F12, 0x0000,},// 0000 AfitBaseVals_3__1_  Contrast[3] */
        {0x0F12, 0xFFFA,},// AfitBaseVals_3__2_  Saturation[3] */
        {0x0F12, 0x0000,},// AfitBaseVals_3__3_  Sharp_Blur[3] */
        {0x0F12, 0x0000,},// AfitBaseVals_3__4_  */
        {0x0F12, 0x0064,},// AfitBaseVals_3__5_  */
        {0x0F12, 0x012C,},// AfitBaseVals_3__6_  */
        {0x0F12, 0x03FF,},// AfitBaseVals_3__7_  */
        {0x0F12, 0x0014,},// AfitBaseVals_3__8_  */
        {0x0F12, 0x0064,},// AfitBaseVals_3__9_  */
        {0x0F12, 0x000C,},// AfitBaseVals_3__10_ */
        {0x0F12, 0x0010,},// AfitBaseVals_3__11_ */
        {0x0F12, 0x01E6,},// AfitBaseVals_3__12_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__13_ */
        {0x0F12, 0x0070,},// AfitBaseVals_3__14_ */
        {0x0F12, 0x007D,},// AfitBaseVals_3__15_ */
        {0x0F12, 0x0064,},// AfitBaseVals_3__16_ */
        {0x0F12, 0x0032,},// 0096 AfitBaseVals_3__17_ */
        {0x0F12, 0x0096,},// AfitBaseVals_3__18_ */
        {0x0F12, 0x0073,},// AfitBaseVals_3__19_ */
        {0x0F12, 0x009F,},// AfitBaseVals_3__20_ */
        {0x0F12, 0x0028,},// AfitBaseVals_3__21_ */
        {0x0F12, 0x0028,},// AfitBaseVals_3__22_ */
        {0x0F12, 0x0023,},// AfitBaseVals_3__23_ */
        {0x0F12, 0x0037,},// AfitBaseVals_3__24_ */
        {0x0F12, 0x0028,},// AfitBaseVals_3__25_ */
        {0x0F12, 0x0028,},// AfitBaseVals_3__26_ */
        {0x0F12, 0x0023,},// AfitBaseVals_3__27_ */
        {0x0F12, 0x0037,},// AfitBaseVals_3__28_ */
        {0x0F12, 0x2B32,},// AfitBaseVals_3__29_ */
        {0x0F12, 0x0601,},// AfitBaseVals_3__30_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__31_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__32_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__33_ */
        {0x0F12, 0x00FF,},// AfitBaseVals_3__34_ */
        {0x0F12, 0x07A0,},// AfitBaseVals_3__35_ */
        {0x0F12, 0xFFFF,},// AfitBaseVals_3__36_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__37_ */
        {0x0F12, 0x050D,},// AfitBaseVals_3__38_ */
        {0x0F12, 0x1E80,},// AfitBaseVals_3__39_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__40_ */
        {0x0F12, 0x0A03,},// 0A08 AfitBaseVals_3__41_ iNearGrayDesat[3] */
        {0x0F12, 0x0200,},// AfitBaseVals_3__42_ */
        {0x0F12, 0xFF01,},// AfitBaseVals_3__43_ */
        {0x0F12, 0x180F,},// AfitBaseVals_3__44_ */
        {0x0F12, 0x0001,},// AfitBaseVals_3__45_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__46_ */
        {0x0F12, 0x8003,},// AfitBaseVals_3__47_ */
        {0x0F12, 0x0080,},// AfitBaseVals_3__48_ */
        {0x0F12, 0x0080,},// AfitBaseVals_3__49_ */
        {0x0F12, 0x0180,},// AfitBaseVals_3__50_ */
        {0x0F12, 0x0110,},// AfitBaseVals_3__51_ iClustThresh_H[3] iClustMulT_H[3] */
        {0x0F12, 0x1E32,},// AfitBaseVals_3__52_ */
        {0x0F12, 0x1A24,},// AfitBaseVals_3__53_ */
        {0x0F12, 0x0A05,},// AfitBaseVals_3__54_ */
        {0x0F12, 0x080A,},// AfitBaseVals_3__55_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__56_ */
        {0x0F12, 0x0328,},// AfitBaseVals_3__57_ */
        {0x0F12, 0x324C,},// AfitBaseVals_3__58_ */
        {0x0F12, 0x001E,},// AfitBaseVals_3__59_ */
        {0x0F12, 0x0200,},// AfitBaseVals_3__60_ */
        {0x0F12, 0x0103,},// AfitBaseVals_3__61_ */
        {0x0F12, 0x010C,},// AfitBaseVals_3__62_ */
        {0x0F12, 0x9696,},// AfitBaseVals_3__63_ */
        {0x0F12, 0x0F0F,},// AfitBaseVals_3__64_ */
        {0x0F12, 0x0307,},// AfitBaseVals_3__65_ */
        {0x0F12, 0x080F,},// AfitBaseVals_3__66_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__67_ */
        {0x0F12, 0x030F,},// AfitBaseVals_3__68_ */
        {0x0F12, 0x3208,},// AfitBaseVals_3__69_ */
        {0x0F12, 0x0F1E,},// AfitBaseVals_3__70_ */
        {0x0F12, 0x020F,},// AfitBaseVals_3__71_ */
        {0x0F12, 0x0103,},// AfitBaseVals_3__72_ */
        {0x0F12, 0x010C,},// AfitBaseVals_3__73_ */
        {0x0F12, 0x9696,},// AfitBaseVals_3__74_ */
        {0x0F12, 0x0F0F,},// AfitBaseVals_3__75_ */
        {0x0F12, 0x0307,},// AfitBaseVals_3__76_ */
        {0x0F12, 0x080F,},// AfitBaseVals_3__77_ */
        {0x0F12, 0x0000,},// AfitBaseVals_3__78_ */
        {0x0F12, 0x030F,},// AfitBaseVals_3__79_ */
        {0x0F12, 0x3208,},// AfitBaseVals_3__80_ */
        {0x0F12, 0x0F1E,},// AfitBaseVals_3__81_ */
        {0x0F12, 0x020F,},// AfitBaseVals_3__82_ */
        {0x0F12, 0x0003,},// AfitBaseVals_3__83_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__0_  Brightness[4] */
        {0x0F12, 0x0000,},// 0000 AfitBaseVals_4__1_  Contrast[4] */
        {0x0F12, 0xFFF8,},// AfitBaseVals_4__2_  Saturation[4] */
        {0x0F12, 0x0000,},// AfitBaseVals_4__3_  Sharp_Blur[4] */
        {0x0F12, 0x0000,},// AfitBaseVals_4__4_  */
        {0x0F12, 0x0028,},// AfitBaseVals_4__5_  */
        {0x0F12, 0x012C,},// AfitBaseVals_4__6_  */
        {0x0F12, 0x03FF,},// AfitBaseVals_4__7_  */
        {0x0F12, 0x0014,},// AfitBaseVals_4__8_  */
        {0x0F12, 0x0064,},// AfitBaseVals_4__9_  */
        {0x0F12, 0x000C,},// AfitBaseVals_4__10_ */
        {0x0F12, 0x0010,},// AfitBaseVals_4__11_ */
        {0x0F12, 0x01E6,},// AfitBaseVals_4__12_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__13_ */
        {0x0F12, 0x0070,},// AfitBaseVals_4__14_ */
        {0x0F12, 0x0087,},// AfitBaseVals_4__15_ */
        {0x0F12, 0x0073,},// AfitBaseVals_4__16_ */
        {0x0F12, 0x0032,},// 0096 AfitBaseVals_4__17_ */
        {0x0F12, 0x0096,},// AfitBaseVals_4__18_ */
        {0x0F12, 0x0073,},// AfitBaseVals_4__19_ */
        {0x0F12, 0x00B4,},// AfitBaseVals_4__20_ */
        {0x0F12, 0x0028,},// AfitBaseVals_4__21_ */
        {0x0F12, 0x0028,},// AfitBaseVals_4__22_ */
        {0x0F12, 0x0023,},// AfitBaseVals_4__23_ */
        {0x0F12, 0x0046,},// AfitBaseVals_4__24_ */
        {0x0F12, 0x0028,},// AfitBaseVals_4__25_ */
        {0x0F12, 0x0028,},// AfitBaseVals_4__26_ */
        {0x0F12, 0x0023,},// AfitBaseVals_4__27_ */
        {0x0F12, 0x0046,},// AfitBaseVals_4__28_ */
        {0x0F12, 0x2B23,},// AfitBaseVals_4__29_ */
        {0x0F12, 0x0601,},// AfitBaseVals_4__30_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__31_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__32_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__33_ */
        {0x0F12, 0x00FF,},// AfitBaseVals_4__34_ */
        {0x0F12, 0x0B84,},// AfitBaseVals_4__35_ */
        {0x0F12, 0xFFFF,},// AfitBaseVals_4__36_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__37_ */
        {0x0F12, 0x050D,},// AfitBaseVals_4__38_ */
        {0x0F12, 0x1E80,},// AfitBaseVals_4__39_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__40_ */
        {0x0F12, 0x0A03,},// 0A08 AfitBaseVals_4__41_ iNearGrayDesat[4] */
        {0x0F12, 0x0200,},// AfitBaseVals_4__42_ */
        {0x0F12, 0xFF01,},// AfitBaseVals_4__43_ */
        {0x0F12, 0x180F,},// AfitBaseVals_4__44_ */
        {0x0F12, 0x0001,},// AfitBaseVals_4__45_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__46_ */
        {0x0F12, 0x8003,},// AfitBaseVals_4__47_ */
        {0x0F12, 0x0080,},// AfitBaseVals_4__48_ */
        {0x0F12, 0x0080,},// AfitBaseVals_4__49_ */
        {0x0F12, 0x0180,},// AfitBaseVals_4__50_ */
        {0x0F12, 0x0110,},// AfitBaseVals_4__51_ iClustThresh_H[4] iClustMulT_H[4] */
        {0x0F12, 0x1E1E,},// AfitBaseVals_4__52_ */
        {0x0F12, 0x1419,},// AfitBaseVals_4__53_ */
        {0x0F12, 0x0A0A,},// AfitBaseVals_4__54_ */
        {0x0F12, 0x0800,},// AfitBaseVals_4__55_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__56_ */
        {0x0F12, 0x0328,},// AfitBaseVals_4__57_ */
        {0x0F12, 0x324C,},// AfitBaseVals_4__58_ */
        {0x0F12, 0x001E,},// AfitBaseVals_4__59_ */
        {0x0F12, 0x0200,},// AfitBaseVals_4__60_ */
        {0x0F12, 0x0103,},// AfitBaseVals_4__61_ */
        {0x0F12, 0x010C,},// AfitBaseVals_4__62_ */
        {0x0F12, 0x6464,},// AfitBaseVals_4__63_ */
        {0x0F12, 0x0F0F,},// AfitBaseVals_4__64_ */
        {0x0F12, 0x0307,},// AfitBaseVals_4__65_ */
        {0x0F12, 0x080F,},// AfitBaseVals_4__66_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__67_ */
        {0x0F12, 0x030F,},// AfitBaseVals_4__68_ */
        {0x0F12, 0x3208,},// AfitBaseVals_4__69_ */
        {0x0F12, 0x0F1E,},// AfitBaseVals_4__70_ */
        {0x0F12, 0x020F,},// AfitBaseVals_4__71_ */
        {0x0F12, 0x0103,},// AfitBaseVals_4__72_ */
        {0x0F12, 0x010C,},// AfitBaseVals_4__73_ */
        {0x0F12, 0x6464,},// AfitBaseVals_4__74_ */
        {0x0F12, 0x0F0F,},// AfitBaseVals_4__75_ */
        {0x0F12, 0x0307,},// AfitBaseVals_4__76_ */
        {0x0F12, 0x080F,},// AfitBaseVals_4__77_ */
        {0x0F12, 0x0000,},// AfitBaseVals_4__78_ */
        {0x0F12, 0x030F,},// AfitBaseVals_4__79_ */
        {0x0F12, 0x3208,},// AfitBaseVals_4__80_ */
        {0x0F12, 0x0F1E,},// AfitBaseVals_4__81_ */
        {0x0F12, 0x020F,},// AfitBaseVals_4__82_ */
        {0x0F12, 0x0003,},// AfitBaseVals_4__83_ */
        {0x0F12, 0x7F5E,},// ConstAfitBaseVals_0_ */
        {0x0F12, 0xFEEE,},// ConstAfitBaseVals_1_ */
        {0x0F12, 0xD9B7,},// ConstAfitBaseVals_2_ */
        {0x0F12, 0x0472,},// ConstAfitBaseVals_3_ */
        {0x0F12, 0x0001,},// ConstAfitBaseVals_4_ */

//*************************************/
// 18.JPEG Thumnail Setting           */
//*************************************/

//*************************************/
// 19.Input Size Setting              */
//*************************************/

//*********************************************************************************
// 20.Preview & Capture Configration Setting                                       
//*********************************************************************************
// Preview config[0] 640X480  15~7.5fps //
        {0x002A, 0x01BE,},
        {0x0F12, 0x0500,},	// REG_0TC_PCFG_usWidth 500:1280; 280:640
        {0x0F12, 0x03C0,},	// REG_0TC_PCFG_usHeight 3C0:960; 1E0:480 //yxq 0x03C0//0x02D0
        {0x0F12, 0x0005,},	// REG_0TC_PCFG_Format 5:YUV422; 7:RAW10  
        {0x002A, 0x01C8,},
        {0x0F12, 0x0000,},	// REG_0TC_PCFG_uClockInd 
        {0x002A, 0x01C4,},
        {0x0F12, 0x0042,},	// REG_0TC_PCFG_PVIMask 52:YUV422, 42:RAW10 
        {0x002A, 0x01D4,},
        {0x0F12, 0x0002,},	// REG_0TC_PCFG_FrRateQualityType  1b:FR(bin) 2b:Quality(no-bin) 
        {0x002A, 0x01D2,},
        {0x0F12, 0x0000,},	// REG_0TC_PCFG_usFrTimeType  0:dynamic; 1:fixed not accurate; 2:fixed accurate 
        {0x002A, 0x01D8,},
        {0x0F12, 0x03E8,},	// REG_0TC_PCFG_usMaxFrTimeMsecMult10  30fps-014D; 15fps-029A; 7.5-0535; 6.0-0682; 3.75-0A6A
        {0x002A, 0x01D6,},
        {0x0F12, 0x014D,},// REG_0TC_PCFG_usMinFrTimeMsecMult10 
        {0x002A, 0x01E8,},
        {0x0F12, 0x0003,},	// REG_0TC_PCFG_uPrevMirror 
        {0x0F12, 0x0000,},	// REG_0TC_PCFG_uCaptureMirror 

// Capture config[0] 1280x960  7.5fps 
        {0x002A, 0x02AE,},
        {0x0F12, 0x0001,},	// Capture mode AE On 
        {0x002A, 0x02B0,},
        {0x0F12, 0x0500,},	// REG_0TC_CCFG_usWidth 500:1280; 280:640
        {0x0F12, 0x03C0,},	// REG_0TC_CCFG_usHeight 3C0:960; 1E0:480 //yxq 0x03C0
        {0x0F12, 0x0005,},	// REG_0TC_CCFG_Format 5:YUV422; 7:RAW10  
        {0x002A, 0x02BA,},
        {0x0F12, 0x0000,},	// REG_0TC_CCFG_uClockInd
        {0x002A, 0x02B6,},
        {0x0F12, 0x0042,},	// REG_0TC_CCFG_PVIMask 52:YUV422; 42:RAW10 
        {0x002A, 0x02C6,},
        {0x0F12, 0x0002,},	// REG_0TC_CCFG_FrRateQualityType  1b:FR(bin) 2b:Quality(no-bin)
        {0x002A, 0x02C4,},
        {0x0F12, 0x0002,},	// REG_0TC_CCFG_usFrTimeType  0:dynamic; 1:fixed not accurate;  2:fixed accurate 
        {0x002A, 0x02CA,},
        {0x0F12, 0x014D,},	// REG_0TC_CCFG_usMaxFrTimeMsecMult10  30fps-014D; 15fps-029A; 7.5-0535; 6.0-0682; 3.75-0A6A 
        {0x002A, 0x02C8,},
        {0x0F12, 0x0000,},	// REG_0TC_CCFG_usMinFrTimeMsecMult10 

//*************************************/
// 21.Select Cofigration Display      */
//*************************************/
        {0x002A, 0x01A8,},
        {0x0F12, 0x0000,},// REG_TC_GP_ActivePreviewConfig */
        {0x002A, 0x01AA,},
        {0x0F12, 0x0001,},// REG_TC_GP_PreviewConfigChanged */
        {0x002A, 0x019E,},
        {0x0F12, 0x0001,},// REG_TC_GP_EnablePreview */
        {0x0F12, 0x0001,},// REG_TC_GP_EnablePreviewChanged */

        {0x0028, 0xD000,},
        {0x002A, 0x1000,},
        {0x0F12, 0x0001,},	// Set host interrupt 
};

static struct v4l2_subdev_info s5k8aay_subdev_info[] = {
	{
	.code   = V4L2_MBUS_FMT_YUYV8_2X8,
	.colorspace = V4L2_COLORSPACE_JPEG,
	.fmt    = 1,
	.order    = 0,
	},
	/* more can be supported, to be added later */
};

static struct msm_camera_i2c_reg_conf s5k8aay_config_change_settings[] = {

};

static void s5k8aay_stop_stream(struct msm_sensor_ctrl_t *s_ctrl) {}

static struct msm_camera_i2c_conf_array s5k8aay_init_conf[] = {
	{s5k8aay_config_start_settings,
	ARRAY_SIZE(s5k8aay_config_start_settings),
	10, MSM_CAMERA_I2C_WORD_DATA},
	{s5k8aay_recommend_settings,
	ARRAY_SIZE(s5k8aay_recommend_settings), 150, MSM_CAMERA_I2C_WORD_DATA},
};

static struct msm_camera_i2c_conf_array s5k8aay_confs[] = {
	{s5k8aay_720p_settings,
	ARRAY_SIZE(s5k8aay_720p_settings), 0, MSM_CAMERA_I2C_WORD_DATA},
};

static struct msm_sensor_output_info_t s5k8aay_dimensions[] = {
	{
		.x_output = 0x500,
		.y_output = 0x3C0,
		.line_length_pclk = 0x500,
		.frame_length_lines = 0x3C0,
		.vt_pixel_clk = 48000000,
		.op_pixel_clk = 128000000,
		.binning_factor = 1,
	},
};

static struct msm_camera_csid_vc_cfg s5k8aay_cid_cfg[] = {
	{0, CSI_YUV422_8, CSI_DECODE_8BIT},
	{1, CSI_EMBED_DATA, CSI_DECODE_8BIT},
};

static struct msm_camera_csi2_params s5k8aay_csi_params = {
	.csid_params = {
		.lane_cnt = 1,
		.lut_params = {
			.num_cid = 2,
			.vc_cfg = s5k8aay_cid_cfg,
		},
	},
	.csiphy_params = {
		.lane_cnt = 1,
		.settle_cnt = 0x14,
	},
};

static struct msm_camera_csi2_params *s5k8aay_csi_params_array[] = {
	&s5k8aay_csi_params,
	&s5k8aay_csi_params,
};

static struct msm_sensor_output_reg_addr_t s5k8aay_reg_addr = {
	.x_output = 0x01BE,
	.y_output = 0x01C0,
	.line_length_pclk = 0xC868,
	.frame_length_lines = 0xC86A,
};

static struct msm_sensor_id_info_t s5k8aay_id_info = {
	.sensor_id_reg_addr = 0x0040,
	.sensor_id = 0x08AA,
};

static const struct i2c_device_id s5k8aay_i2c_id[] = {
	{SENSOR_NAME, (kernel_ulong_t)&s5k8aay_s_ctrl},
	{ }
};

static struct i2c_driver s5k8aay_i2c_driver = {
	.id_table = s5k8aay_i2c_id,
	.probe  = msm_sensor_i2c_probe,
	.driver = {
		.name = SENSOR_NAME,
	},
};

static struct msm_camera_i2c_client s5k8aay_sensor_i2c_client = {
	.addr_type = MSM_CAMERA_I2C_WORD_ADDR,
};

static int __init msm_sensor_init_module(void)
{
	return i2c_add_driver(&s5k8aay_i2c_driver);
}

static struct v4l2_subdev_core_ops s5k8aay_subdev_core_ops = {
	.s_ctrl = msm_sensor_v4l2_s_ctrl,
	.queryctrl = msm_sensor_v4l2_query_ctrl,
	.ioctl = msm_sensor_subdev_ioctl,
	.s_power = msm_sensor_power,
};

static struct v4l2_subdev_video_ops s5k8aay_subdev_video_ops = {
	.enum_mbus_fmt = msm_sensor_v4l2_enum_fmt,
};

static struct v4l2_subdev_ops s5k8aay_subdev_ops = {
	.core = &s5k8aay_subdev_core_ops,
	.video  = &s5k8aay_subdev_video_ops,
};

static struct msm_sensor_fn_t s5k8aay_func_tbl = {
	.sensor_start_stream = msm_sensor_start_stream,
	.sensor_stop_stream = s5k8aay_stop_stream,
	.sensor_setting = msm_sensor_setting,
	.sensor_set_sensor_mode = msm_sensor_set_sensor_mode,
	.sensor_mode_init = msm_sensor_mode_init,
	.sensor_get_output_info = msm_sensor_get_output_info,
	.sensor_config = msm_sensor_config,
	.sensor_power_up = msm_sensor_power_up,
	.sensor_power_down = msm_sensor_power_down,
	.sensor_get_csi_params = msm_sensor_get_csi_params,
};

static struct msm_sensor_reg_t s5k8aay_regs = {
	.default_data_type = MSM_CAMERA_I2C_BYTE_DATA,
	.start_stream_conf = s5k8aay_config_change_settings,
	.start_stream_conf_size = ARRAY_SIZE(s5k8aay_config_change_settings),
	.init_settings = &s5k8aay_init_conf[0],
	.init_size = ARRAY_SIZE(s5k8aay_init_conf),
	.mode_settings = &s5k8aay_confs[0],
	.output_settings = &s5k8aay_dimensions[0],
	.num_conf = ARRAY_SIZE(s5k8aay_confs),
};

static struct msm_sensor_ctrl_t s5k8aay_s_ctrl = {
	.msm_sensor_reg = &s5k8aay_regs,
	.sensor_i2c_client = &s5k8aay_sensor_i2c_client,
	.sensor_i2c_addr = 0x78,
	.sensor_output_reg_addr = &s5k8aay_reg_addr,
	.sensor_id_info = &s5k8aay_id_info,
	.cam_mode = MSM_SENSOR_MODE_INVALID,
	.csi_params = &s5k8aay_csi_params_array[0],
	.msm_sensor_mutex = &s5k8aay_mut,
	.sensor_i2c_driver = &s5k8aay_i2c_driver,
	.sensor_v4l2_subdev_info = s5k8aay_subdev_info,
	.sensor_v4l2_subdev_info_size = ARRAY_SIZE(s5k8aay_subdev_info),
	.sensor_v4l2_subdev_ops = &s5k8aay_subdev_ops,
	.func_tbl = &s5k8aay_func_tbl,
};

module_init(msm_sensor_init_module);
MODULE_DESCRIPTION("Aptina 1.26MP YUV sensor driver");
MODULE_LICENSE("GPL v2");
