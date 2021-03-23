/**
 * @File: tuya_dp_process.h 
 * @Author: huanling.zhang@tuya.com 
 * @Last Modified time: 2021-03-13 
 * @Description: photoresistor switch detection demo 
 */

#ifndef __TUYA_DP_PROCESS_H_
#define __TUYA_DP_PROCESS_H_

#include "tuya_cloud_com_defs.h"
#include "tuya_cloud_types.h"

#define     ON      1
#define     OFF     0

VOID updata_dp_all(VOID);
VOID dp_process(IN CONST TY_OBJ_DP_S *root);


#endif

