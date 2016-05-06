/******************************************************************************

                  版权所有 (C), 2001-2012, 华为技术有限公司

 ******************************************************************************
  文 件 名   : TafMmaNetworkNameTbl.h
  版 本 号   : 初稿
  作    者   : w00176964
  生成日期   : 2013年5月17日
  最近修改   :
  功能描述   : TafMmaNetworkNameTbl.c 的头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2013年5月17日
    作    者   : W00176964
    修改内容   : 创建文件

******************************************************************************/
#ifndef _TAF_MMA_NETWORK_NAME_TBL_H_
#define _TAF_MMA_NETWORK_NAME_TBL_H_

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "vos.h"
#include "Ps.h"
#include "MmaAppLocal.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/


/*****************************************************************************
  3 枚举定义
*****************************************************************************/


/*****************************************************************************
  4 全局变量声明
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/


/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/
TAF_PH_OPERATOR_NAME_TBL_STRU *TAF_MMA_GetNetworkNameTblAddr(VOS_VOID);
VOS_UINT16 TAF_MMA_GetNetWorkNameTblSize(VOS_VOID);


#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of TafMmaNetworkNameTbl.h */
