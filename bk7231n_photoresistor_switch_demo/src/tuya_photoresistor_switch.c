/**
 * @File: tuya_photoswitch.c 
 * @Author: hunaling.zhang@tuya.com 
 * @Last Modified time: 2021-03-13 
 * @Description:photoswitch detection demo 
 */

#include "tuya_dp_process.h"
#include "tuya_photoresistor_switch.h"
#include "tuya_iot_com_api.h"
#include "uni_log.h"

#include "FreeRTOS.h"
#include "task.h"
#include "uni_thread.h"

extern UCHAR_T switch_sta;

VOID switch_init(VOID)
{
    tuya_gpio_inout_set(SWITCH_PIN, TRUE);
    tuya_hal_thread_create(NULL, "check_switch_status", 512 * 4, TRD_PRIO_2, switch_task);
}

VOID switch_task(VOID)
{   
    while(1) { 
        
        if (FALSE == tuya_gpio_read(SWITCH_PIN)) {
            switch_sta = OFF;
            PR_NOTICE("OFF");
        } else {
            switch_sta = ON;
            PR_NOTICE("ON");
        }
        
        updata_dp_all();
        tuya_hal_system_sleep(1000);

    }
}

