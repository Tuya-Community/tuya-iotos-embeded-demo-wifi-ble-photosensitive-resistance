/**
 * @File: tuya_app_dp_process.c 
 * @Author: huanling.zhang@tuya.com 
 * @Last Modified time: 2021-03-13 
 * @Description: photoswitch detection demo 
 */

#include "tuya_dp_process.h"
#include "tuya_iot_com_api.h"
#include "uni_log.h"
#include "tuya_cloud_wifi_defs.h"

//设备DPID
#define DPID_SWITCH_VALUE    101

UCHAR_T switch_sta = OFF;

 /***********************************************************
 *   Function:  dp_process
 *   Input:     none
 *   Output:    none
 *   Return:    none
 *   Notice:    处理 dp 数据 
 ***********************************************************/
VOID dp_process(IN CONST TY_OBJ_DP_S *root)
{
    UCHAR_T dpid;

    dpid = root->dpid;
    PR_DEBUG("dpid:%d",dpid);

    return;
}

 /***********************************************************
 *   Function:  updata_dp_all
 *   Input:     none
 *   Output:    none
 *   Return:    none
 *   Notice:    上报所有 dp 
 ***********************************************************/
VOID updata_dp_all(VOID)
{
    OPERATE_RET op_ret = OPRT_OK;
    INT_T dp_cnt = 0;
    dp_cnt = 1;

    /* 没有连接到路由器，退出 */
    GW_WIFI_NW_STAT_E wifi_state = STAT_LOW_POWER;
    get_wf_gw_nw_status(&wifi_state);
    if (wifi_state <= STAT_AP_STA_DISC || wifi_state == STAT_STA_DISC) {
        return;
    }
    
    TY_OBJ_DP_S *dp_arr = (TY_OBJ_DP_S *)Malloc(dp_cnt*SIZEOF(TY_OBJ_DP_S));
    if(NULL == dp_arr) {
        PR_ERR("malloc failed");
        return;
    }
    
    memset(dp_arr, 0, dp_cnt*SIZEOF(TY_OBJ_DP_S));
    
    dp_arr[0].dpid = DPID_SWITCH_VALUE;
    dp_arr[0].type = PROP_BOOL;
    dp_arr[0].time_stamp = 0;
    dp_arr[0].value.dp_bool = switch_sta;
    op_ret = dev_report_dp_json_async(NULL ,dp_arr,dp_cnt);
    Free(dp_arr);
    if(OPRT_OK != op_ret) {
        PR_ERR("dev_report_dp_json_async relay_config data error,err_num %d",op_ret);
    }
    PR_DEBUG("dp_query report_all_dp_data");
    
    return;
}


