/******************************************************************************

                 版权所有 (C), 2001-2012, 华为技术有限公司

 ******************************************************************************
  文 件 名   : bbp_baseaddr_interface.h
  版 本 号   : 初稿
  作    者   : 林庆恩
  生成日期   : 2015-05-14 16:50:26
  最近修改   :
  功能描述   : BBP基地址接口头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2015年05月14日
    作    者   : 林庆恩
    修改内容   :

******************************************************************************/

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/

#ifndef __BBP_BASEADDR_INTERFACE_H__
#define __BBP_BASEADDR_INTERFACE_H__


#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif



/*****************************************************************************
  2 宏定义
*****************************************************************************/
/* FPGA平台BBP基地址定义 */
#define SOC_BBP_ABB_CFG_FPGA_BASE_ADDR          (0x5D9CE000)
#define SOC_BBP_ET_FPGA_BASE_ADDR               (0x5D90F000)


/* SFT平台BBP基地址定义 */
#define SOC_BBP_ABB_CFG_SFT_BASE_ADDR           (0xE19CE000)
#define SOC_BBP_ET_SFT_BASE_ADDR                (0xE1F88000)

/* ASIC平台BBP基地址定义 */
#define SOC_BBP_ABB_CFG_ASIC_BASE_ADDR          (0xE1F8E000)
#define SOC_BBP_ET_ASIC_BASE_ADDR               (0xE1F88000)

/*****************************************************************************
  3 枚举定义
*****************************************************************************/



/*****************************************************************************
  4 消息头定义
*****************************************************************************/


/*****************************************************************************
  5 消息定义
*****************************************************************************/



/*****************************************************************************
  6 STRUCT定义
*****************************************************************************/



/*****************************************************************************
  7 UNION定义
*****************************************************************************/





/*****************************************************************************
  8 OTHERS定义
*****************************************************************************/



/*****************************************************************************
  9 全局变量声明
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of bbp_baseaddr_interface.h */

