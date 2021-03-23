/**
 * @File: tuya_photoresistor_switch.h 
 * @Author: huanling.zhang@tuya.com 
 * @Last Modified time: 2021-03-13 
 * @Description:photoresistor switch detection demo 
 */
#ifndef __TUYA_PHOTORESISTOR_SWITCH_H__
#define __TUYA_PHOTORESISTOR_SWITCH_H__

#include "tuya_cloud_types.h"
#include "tuya_gpio.h"

#define     SWITCH_PIN      TY_GPIOA_20

VOID switch_init(VOID);
VOID switch_task(VOID);

#endif

