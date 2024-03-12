// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2017-2020, The Linux Foundation. All rights reserved.
 * Copyright (c) 2020, Oplus. All rights reserved.
 */

#include "cam_sensor_dev.h"
#include "cam_req_mgr_dev.h"
#include "cam_sensor_soc.h"
#include "cam_sensor_core.h"
#include "oplus_cam_sensor_dev.h"
#include "oplus_cam_sensor_core.h"

struct cam_sensor_i2c_reg_setting_array {
	struct cam_sensor_i2c_reg_array reg_setting[4600];
	unsigned short size;
	enum camera_sensor_i2c_type addr_type;
	enum camera_sensor_i2c_type data_type;
	unsigned short delay;
};

struct cam_sensor_settings {
    struct cam_sensor_i2c_reg_setting_array imx766_setting;
    struct cam_sensor_i2c_reg_setting_array imx686_setting_part1;
    struct cam_sensor_i2c_reg_setting_array imx686_setting_part2;
    struct cam_sensor_i2c_reg_setting_array imx586_setting0;
    struct cam_sensor_i2c_reg_setting_array imx586_setting1;
    struct cam_sensor_i2c_reg_setting_array streamoff;
    struct cam_sensor_i2c_reg_setting_array s5k3m5_setting;
    struct cam_sensor_i2c_reg_setting_array gc5035_setting;
    struct cam_sensor_i2c_reg_setting_array imx689_setting;
    struct cam_sensor_i2c_reg_setting_array imx616_setting;
};

struct cam_sensor_settings sensor_settings = {
#include "CAM_SENSOR_SETTINGS.h"
};

/* Add for AT camera test */
long oplus_cam_sensor_subdev_ioctl(struct v4l2_subdev *sd,
	unsigned int cmd, void *arg, unsigned int *is_ftm_current_test)
{
	int rc = 0;
	struct cam_sensor_ctrl_t *s_ctrl =
		v4l2_get_subdevdata(sd);

    struct cam_sensor_i2c_reg_setting sensor_setting;
	switch (cmd) {

	case VIDIOC_CAM_SENSOR_STATR:
		rc = cam_sensor_start(s_ctrl);
		break;
	case VIDIOC_CAM_SENSOR_STOP:
		rc = cam_sensor_stop(s_ctrl);
		break;
	default:
		CAM_ERR(CAM_SENSOR, "Invalid ioctl cmd: %d", cmd);
		break;
	}
	return rc;
}

