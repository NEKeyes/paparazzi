/*
 * Copyright (C) 2014 Freek van Tienen <freek.v.tienen@gmail.com>
 * Copyright (C) 2017 Gautier Hattenberger <gautier.hattenberger@enac.fr>
 *
 * This file is part of paparazzi.
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

/**
 * @file subsystems/imu/imu_disco.h
 * Interface for the Disco magnetometer, accelerometer and gyroscope
 */


#ifndef IMU_DISCO_H
#define IMU_DISCO_H

#include "generated/airframe.h"
#include "subsystems/imu.h"

#include "peripherals/ak8963.h"
#include "peripherals/mpu60x0_i2c.h"

/** default gyro sensitivy and neutral from the datasheet
 * MPU with 1000 deg/s has 32.8 LSB/(deg/s)
 * sens = 1/32.8 * pi/180 * 2^INT32_RATE_FRAC
 * sens = 1/32.8 * pi/180 * 4096 = 2.17953
 */
#if !defined IMU_GYRO_P_SENS & !defined IMU_GYRO_Q_SENS & !defined IMU_GYRO_R_SENS
// FIXME
#define IMU_GYRO_P_SENS 2.17953
#define IMU_GYRO_P_SENS_NUM 18271
#define IMU_GYRO_P_SENS_DEN 8383
#define IMU_GYRO_Q_SENS 2.17953
#define IMU_GYRO_Q_SENS_NUM 18271
#define IMU_GYRO_Q_SENS_DEN 8383
#define IMU_GYRO_R_SENS 2.17953
#define IMU_GYRO_R_SENS_NUM 18271
#define IMU_GYRO_R_SENS_DEN 8383
#endif

/** default accel sensitivy from the datasheet
 * MPU with 8g has 4096 LSB/g
 * sens = 9.81 [m/s^2] / 4096 [LSB/g] * 2^INT32_ACCEL_FRAC = 2.4525
 */
#if !defined IMU_ACCEL_X_SENS & !defined IMU_ACCEL_Y_SENS & !defined IMU_ACCEL_Z_SENS
// FIXME
#define IMU_ACCEL_X_SENS 2.4525
#define IMU_ACCEL_X_SENS_NUM 981
#define IMU_ACCEL_X_SENS_DEN 400
#define IMU_ACCEL_Y_SENS 2.4525
#define IMU_ACCEL_Y_SENS_NUM 981
#define IMU_ACCEL_Y_SENS_DEN 400
#define IMU_ACCEL_Z_SENS 2.4525
#define IMU_ACCEL_Z_SENS_NUM 981
#define IMU_ACCEL_Z_SENS_DEN 400
#endif

/** Everything that is in the disco IMU */
struct ImuDisco {
  struct Mpu60x0_I2c mpu;         ///< The MPU gyro/accel device
  struct Ak8963 ak;               ///< The AK8963 mag
};

extern struct ImuDisco imu_disco;

extern void imu_disco_init(void);
extern void imu_disco_periodic(void);
extern void imu_disco_event(void);

#endif /* IMU_DISCO_H */

