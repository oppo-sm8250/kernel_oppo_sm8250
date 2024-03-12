
/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2017-2019, The Linux Foundation. All rights reserved.
 * Copyright (c) 2020, Oplus. All rights reserved.
 */
#ifndef _OPLUS_CAM_OIS_DEV_H_
#define _OPLUS_CAM_OIS_DEV_H_

#include <linux/i2c.h>
#include <linux/gpio.h>
#include <media/v4l2-event.h>
#include <media/v4l2-subdev.h>
#include <media/v4l2-ioctl.h>
#include <media/cam_sensor.h>
#include <cam_sensor_i2c.h>
#include <cam_sensor_spi.h>
#include <cam_sensor_io.h>
#include <cam_cci_dev.h>
#include <cam_req_mgr_util.h>
#include <cam_req_mgr_interface.h>
#include <cam_mem_mgr.h>
#include <cam_subdev.h>
#include "cam_soc_util.h"
#include "cam_context.h"

#ifndef OPLUS_FEATURE_CAMERA_COMMON
#define OPLUS_FEATURE_CAMERA_COMMON
#endif

#ifdef OPLUS_FEATURE_CAMERA_COMMON

#define OIS_HALL_MAX_NUMBER 100

struct hall_info
{
    uint32_t timeStampSec;  //us
    uint32_t timeStampUsec;
    uint32_t mHalldata;
};

typedef struct OISHall2Eis
{
    struct hall_info datainfo[OIS_HALL_MAX_NUMBER];
} OISHALL2EIS;

#define GET_HALL_DATA_VERSION_DEFUALT         0
#define GET_HALL_DATA_VERSION_V2              1
#define GET_HALL_DATA_VERSION_V3              2

struct cam_ois_hall_data_in_ois_aligned {
	uint16_t hall_data_cnt;
	uint32_t hall_data;
};

struct cam_ois_hall_data_in_driver {
	uint32_t high_dword;
	uint32_t low_dword;
	uint32_t hall_data;
};

#define SAMPLE_COUNT_IN_DRIVER        100
#define SAMPLE_COUNT_IN_OIS           34
#define SAMPLE_SIZE_IN_OIS            6
#define SAMPLE_SIZE_IN_OIS_ALIGNED    (sizeof(struct cam_ois_hall_data_in_ois_aligned))
#define SAMPLE_SIZE_IN_DRIVER         (sizeof(struct cam_ois_hall_data_in_driver))

#define OIS_HALL_SAMPLE_COUNT         100
#define SAMPLE_COUNT_IN_OIS_FIFO      7
#define OIS_HALL_SAMPLE_BYTE          12

#define CLOCK_TICKCOUNT_MS       	  19200
#define OIS_MAGIC_NUMBER              0x7777
#define OIS_MAX_COUNTER               36
#endif

void init_ois_hall_data(struct cam_ois_ctrl_t *o_ctrl);

void oplus_cam_ois_fw_init(struct cam_ois_ctrl_t *o_ctrl);

int oplus_cam_ois_deinit(struct cam_ois_ctrl_t *o_ctrl);
#endif
