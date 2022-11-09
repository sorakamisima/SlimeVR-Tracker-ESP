/*
    SlimeVR Code is placed under the MIT license
    Copyright (c) 2021 Eiren Rain

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/
#include <map>
#ifndef BMI160_DEFINES_H
#define BMI160_DEFINES_H

// BMI160 gyro/accel axis remapping
#define BMI160_REMAP_AXIS_X(x, y, z) (sensorId == 0 ? x : x)
#define BMI160_REMAP_AXIS_Y(x, y, z) (sensorId == 0 ? y : y)
#define BMI160_REMAP_AXIS_Z(x, y, z) (sensorId == 0 ? z : z)
// Additional magnetometer remapping (if present and enabled in <debug.h>)
#define BMI160_MAG_REMAP_AXIS_X(x, y, z) (sensorId == 0 ? x : x)
#define BMI160_MAG_REMAP_AXIS_Y(x, y, z) (sensorId == 0 ? y : y)
#define BMI160_MAG_REMAP_AXIS_Z(x, y, z) (sensorId == 0 ? z : z)

// BMI160 magnetometer type, applies to both main and aux trackers, mixed types are not supported currently
// If only 1 out of 2 trackers has a mag, tracker without a mag should still function normally
// NOT USED if USE_6_AXIS == true
// Pick one:
#define BMI160_MAG_TYPE BMI160_MAG_TYPE_HMC
// #define BMI160_MAG_TYPE BMI160_MAG_TYPE_QMC

// Use VQF instead of mahony sensor fusion
#define BMI160_USE_VQF true

// Use temperature calibration
#define BMI160_USE_TEMPCAL true

// Calibration method options:
// Rotation - rotate the device in hand
// 6 point - put the device in 6 unique orientations
// #define BMI160_ACCEL_CALIBRATION_METHOD ACCEL_CALIBRATION_METHOD_ROTATION
#define BMI160_ACCEL_CALIBRATION_METHOD ACCEL_CALIBRATION_METHOD_6POINT

// Send temperature to the server as 1XXXYY,
// where XXX is calibration progress from 0 to 60, and YY is temperature
#define BMI160_TEMPCAL_DEBUG false

// Print debug info every second
#define BMI160_DEBUG false

// Use sensitivity calibration
#define BMI160_USE_SENSCAL true

// Sensitivity calibration
// TODO: docs
#define SENSORID_PRIMARY 0
#define SENSORID_AUX 1
struct SensitivityOffsetXYZ { uint8_t sensorId; double spins; double x; double y; double z; };
const std::map<String, SensitivityOffsetXYZ> sensitivityOffsets = {
    // example values
    { "A4:E5:7C:B6:00:01", { SENSORID_PRIMARY, .spins = 10, .x = 2.63, .y = 37.82, .z = 31.11 } },
    { "A4:E5:7C:B6:00:02", { SENSORID_PRIMARY, .spins = 10, .x = -2.38, .y = -26.8, .z = -42.78 } },
    { "A4:E5:7C:B6:00:03", { SENSORID_PRIMARY, .spins = 10, .x = 11, .y =  2.2, .z =  -1 } },
    { "A4:E5:7C:B6:00:04", { SENSORID_PRIMARY, .spins = 10, .x = -7, .y = -53.7, .z = -57 } },
    { "A4:E5:7C:B6:00:05", { SENSORID_PRIMARY, .spins = 10, .x = -10.63, .y = -8.25, .z = -18.6 } },
};

#endif