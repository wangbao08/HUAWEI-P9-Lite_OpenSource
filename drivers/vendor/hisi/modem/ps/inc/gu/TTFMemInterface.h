/******************************************************************************

                  版权所有 (C), 2001-2011, 华为技术有限公司

 ******************************************************************************
  文 件 名   : TTFMemInterface.h
  版 本 号   : 初稿
  作    者   : y00171741
  生成日期   : 2011年12月15日
  最近修改   :
  功能描述   : TTFMemInterface.h 的头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2011年12月15日
    作    者   : y00171741
    修改内容   : 创建文件

******************************************************************************/

#ifndef __TTFMEMINTERFACE_H__
#define __TTFMEMINTERFACE_H__


/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "v_typdef.h"
#include "product_config.h"
#include "TtfDrvInterface.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/
/* 转定义原有的上行RLC SDU池的数据都从上行DATA池中取 */
#define  TTF_MEM_POOL_ID_UL_RLC_SDU    TTF_MEM_POOL_ID_UL_DATA

/* 转定义原有的上行RLC PDU池的数据都从上行DATA池中取 */
#define  TTF_MEM_POOL_ID_UL_RLC_PDU    TTF_MEM_POOL_ID_UL_DATA

/* 转定义原有的下行DL池的数据都从下行PDU池中取 */
#define  TTF_MEM_POOL_ID_DL            TTF_MEM_POOL_ID_DL_PDU


/*****************************************************************************
  3 枚举定义
*****************************************************************************/
/*****************************************************************************
 结构名    : TTF_MEM_POOL_ID_ENUM_UINT32
 协议表格  :
 ASN.1描述 :
*****************************************************************************/
enum TTF_MEM_POOL_ID_ENUM
{
    TTF_MEM_POOL_ID_DL_SHARE  = 0,    /* C-CPU 下行跨核共享内存池，目前只能由CDS和CST模块使用 */
    TTF_MEM_POOL_ID_DL_PDU,           /* C-CPU 下行PDU内存池 */
    TTF_MEM_POOL_ID_UL_DATA,          /* C-CPU 上行数据内存池 */
    TTF_MEM_POOL_ID_EXT,              /* A-CPU 跨核内存池 */
    TTF_MEM_POOL_ID_UL_IP_DATA,       /* C-CPU 上行 IP包数据内存池*/

    TTF_MEM_POOL_ID_BUTT
};
typedef VOS_UINT32 TTF_MEM_POOL_ID_ENUM_UINT32;


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
extern TTF_MEM_ST *TTF_MemBlkAlloc_Debug(VOS_UINT16 usFileID, VOS_UINT16 usLineNum, VOS_UINT32 ulPid, VOS_UINT32 ulPoolId, VOS_UINT16 usLen);

extern VOS_VOID TTF_MemFree_Debug(VOS_UINT16 usFileID, VOS_UINT16 usLineNum, VOS_UINT32 ulPid, TTF_MEM_ST **ppMem);

extern TTF_MEM_ST * TTF_DataTransformTtfMem_Debug(VOS_UINT16 usFileID, VOS_UINT16 usLineNum,VOS_UINT8* pucData,VOS_UINT16 usLen, VOS_VOID*  pstIMMZc);


/*****************************************************************************
 函 数 名  : TTF_MemBlkAlloc
 功能描述  : TTF MEM 内存申请
 输入参数  : ulPid - 调用此函数的模块的Pid
             ulPoolId - 申请内存块所在的内存池ID
             ulLen - 申请的字节数
 输出参数  : 无
 返 回 值  : TTF_MEM_ST* -- 指向分配好的块的指针
             或VOS_NULL_PTR表示失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
#define TTF_MemBlkAlloc(ulPid, ulPoolId, usLen) \
    TTF_MemBlkAlloc_Debug(THIS_FILE_ID, __LINE__, ulPid, ulPoolId, usLen)


/*****************************************************************************
 函 数 名  : TTF_MemFree
 功能描述  : TTF MEM内存释放
 输入参数  : ulPid - 调用此函数的模块的Pid
             ulLen - 申请的字节数
 输出参数  : 无
 返 回 值  : TTF_MEM_ST* -- 指向分配好的块的指针
             或VOS_NULL_PTR表示失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
#define TTF_MemFree(ulPid, pMem) \
    TTF_MemFree_Debug(THIS_FILE_ID, __LINE__, ulPid, &(pMem))


/*****************************************************************************
 函 数 名  : TTF_RemoteFreeImmZc
 功能描述  : 释放远端IMM_ZC。
 输入参数  : pucAddr - 指向C核的TTF_MEM的指针
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :
 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
extern VOS_VOID TTF_ExtMemFree( void **pstExtMem );

#define TTF_RemoteFreeImmMem(pucAddr)  TTF_ExtMemFree((&pucAddr))


/*****************************************************************************
 函 数 名  : TTF_DataTranformTtfMem
 功能描述  : 申请TTF_MEM_ST控制头并把A核共享内存挂接到TTF_MEM_ST上
 输入参数  : pucData - 数据块首地址
             ulLen - 数据块长度(byte)
             pstIMMMem - 保存A核的地址，A核指向IMM_MEM_STRU的地址
 输出参数  : 无
 返 回 值  : 无
 调用函数  : 成功：返回指向TTF_MEM_ST的指针
             失败：返回NULL；
 被调函数  :
 其它      : 本接口申请不到TTF_MEM_ST头节点，本接口回收A核共享内存。
 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
#define TTF_DataTransformTtfMem(pucData, usLen, pstIMM)\
    TTF_DataTransformTtfMem_Debug(THIS_FILE_ID, __LINE__, pucData, usLen, pstIMM)


/*****************************************************************************
 函 数 名  : TTF_GetDlIpFreeMemCnt
 功能描述  : C-CPU上查询C-CPU中下行IP包数据所在内存池中最大档空闲内存的数目
 输入参数  : 无
 输出参数  : 无
 返 回 值  : C-CPU 下行IP包数据所在内存池中最大档空闲内存的数目。
 说明      : 对于V3R3版本，查询的是TTF_MEM_POOL_ID_DL_SHARE，C-CPU下行跨核共享内存池中最大档空闲内存的数目；
             对于V9R1/V7R2版本，查询的是TTF_MEM_POOL_ID_DL_PDU，C-CPU下行PDU内存池中最大档空闲内存的数目。
 调用函数  :
 被调函数  :
 修改历史      :
  1.日    期   : 2013年1月9日
    作    者   : h00163499
    修改内容   : 新生成函数

*****************************************************************************/
extern VOS_UINT32 TTF_GetDlIpFreeMemCnt (VOS_VOID);


/*****************************************************************************
 函 数 名  : TTF_GetUlIpFreeMemCnt
 功能描述  : C-CPU上查询C-CPU中上行IP包数据所在内存池中最大档空闲内存的数目。
 输入参数  : 无
 输出参数  : 无
 返 回 值  : C-CPU 上行IP包数据所在内存池中最大档空闲内存的数目。
 说明      : 对于V3R3版本，查询的是A-CPU跨核共享内存池中最大档空闲内存的数目；
             对于V9R1/V7R2版本，查询的是TTF_MEM_POOL_ID_UL_IP_DATA，上行IP包数据内存池中最大档空闲内存的数目。
 调用函数  :
 被调函数  :
 修改历史      :
  1.日    期   : 2013年1月9日
    作    者   : h00163499
    修改内容   : 新生成函数

*****************************************************************************/
extern VOS_UINT32 TTF_GetUlIpFreeMemCnt (VOS_VOID);


/*****************************************************************************
 函 数 名  : TTF_MemCcpuCheckPoolLeak
 功能描述  : 检查C核内存池泄露情况外部接口
 输入参数  : VOS_VOID
 输出参数  : 无
 返 回 值  : VOS_VOID
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月12日
    作    者   : s00164817
    修改内容   : 新生成函数

*****************************************************************************/
extern VOS_VOID TTF_MemCcpuCheckPoolLeak( VOS_VOID );



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

#endif /* end of TTFMemInterface.h */

