#include <stdio.h>
#include <string.h>
#include "BasicFunc.h"
#include "common.h"
#include "mem_fun.h"
#define HICICOMV500

int cicom_v500_trans_config(UINT32 src_addr, UINT32 des_addr, UINT32 num_8);
void cicom_v500_trans_en();
int cicom_v500_trans_check(UINT32 src_addr, UINT32 des_addr, UINT32 num_8);
#ifdef HICICOMV500
#define CICOM_BaseAddr                CICOM_BASEADDR

#define	asicCICOMCICOM_STATE_RESET	 CICOM_BaseAddr+0x00000000
#define	asicCICOMPRIOR_SELECT	 	 CICOM_BaseAddr+0x00000004
#define	asicCICOMLLI_PARAM_ADDR_UL	 CICOM_BaseAddr+0x00000008
#define	asicCICOMGLOBAL_CFG_UL		 CICOM_BaseAddr+0x0000000c
#define	asicCICOMCHL_FST_ADDR_UL	 CICOM_BaseAddr+0x00000010
#define	asicCICOMCHL_LST_ADDR_UL	 CICOM_BaseAddr+0x00000014
#define	asicCICOMINT_EN_UL	 	 CICOM_BaseAddr+0x00000018
#define	asicCICOMINT_RAW_UL		 CICOM_BaseAddr+0x0000001c
#define	asicCICOMINT_CLR_UL		 CICOM_BaseAddr+0x00000020
#define	asicCICOMINT_MSK_UL		 CICOM_BaseAddr+0x00000024
#define	asicCICOMEN_UL			 CICOM_BaseAddr+0x00000028
#define	asicCICOMCK_ADDR_UL		 CICOM_BaseAddr+0x0000002c
#define	asicCICOMCK_31_0_UL		 CICOM_BaseAddr+0x00000030
#define	asicCICOMCK_63_32_UL		 CICOM_BaseAddr+0x00000034
#define	asicCICOMCK_95_64_UL		 CICOM_BaseAddr+0x00000038
#define	asicCICOMCK_127_96_UL		 CICOM_BaseAddr+0x0000003c
#define	asicCICOMCC_UL			 CICOM_BaseAddr+0x00000040
#define	asicCICOMSRC_PDU_TOTAL_LEN_UL	 CICOM_BaseAddr+0x00000044
#define	asicCICOMCUSTOM_CFG_UL		 CICOM_BaseAddr+0x00000048
#define	asicCICOMSRC_PDU_SEG_ADDR_UL	 CICOM_BaseAddr+0x0000004c
#define	asicCICOMSRC_PDU_SEG_LEN_UL	 CICOM_BaseAddr+0x00000050
#define	asicCICOMLLI_SRC_PDU_SEG_ADDR_UL CICOM_BaseAddr+0x00000054
#define	asicCICOMDST_TTF_SEG_ADDR_UL	 CICOM_BaseAddr+0x00000058
#define	asicCICOMDST_TTF_SEG_LEN_UL	 CICOM_BaseAddr+0x0000005c
#define	asicCICOMLLI_DST_TTF_SEG_ADDR_UL CICOM_BaseAddr+0x00000060
#define	asicCICOMDST_MBX_SEG_ADDR_UL	 CICOM_BaseAddr+0x00000064
#define	asicCICOMDST_MBX_SEG_LEN_UL	 CICOM_BaseAddr+0x00000068
#define	asicCICOMLLI_DST_MBX_SEG_ADDR_UL CICOM_BaseAddr+0x0000006c
#define	asicCICOMERROR_ADDR_UL		 CICOM_BaseAddr+0x00000070
#define	asicCICOMSRC_SEG_RD_ADDR_UL	 CICOM_BaseAddr+0x00000074
#define	asicCICOMSRC_SEG_LEAVE_LEN_UL	 CICOM_BaseAddr+0x00000078
#define	asicCICOMTTF_SEG_WR_ADDR_UL	 CICOM_BaseAddr+0x0000007c
#define	asicCICOMTTF_SEG_LEAVE_LEN_UL	 CICOM_BaseAddr+0x00000080
#define	asicCICOMMBX_SEG_WR_ADDR_UL	 CICOM_BaseAddr+0x00000084
#define	asicCICOMMBX_SEG_LEAVE_LEN_UL	 CICOM_BaseAddr+0x00000088
#define	asicCICOMLLI_PARAM_ADDR_DL	 CICOM_BaseAddr+0x00000108
#define	asicCICOMGLOBAL_CFG_DL		 CICOM_BaseAddr+0x0000010c
#define	asicCICOMINT_EN_DL		 CICOM_BaseAddr+0x00000118
#define	asicCICOMINT_RAW_DL		 CICOM_BaseAddr+0x0000011c
#define	asicCICOMINT_CLR_DL		 CICOM_BaseAddr+0x00000120
#define	asicCICOMINT_MSK_DL		 CICOM_BaseAddr+0x00000124
#define	asicCICOMEN_DL			 CICOM_BaseAddr+0x00000128
#define	asicCICOMCK_ADDR_DL		 CICOM_BaseAddr+0x0000012c
#define	asicCICOMCK_31_0_DL		 CICOM_BaseAddr+0x00000130
#define	asicCICOMCK_63_32_DL		 CICOM_BaseAddr+0x00000134
#define	asicCICOMCK_95_64_DL		 CICOM_BaseAddr+0x00000138
#define	asicCICOMCK_127_96_DL		 CICOM_BaseAddr+0x0000013c
#define	asicCICOMCC_DL			 CICOM_BaseAddr+0x00000140
#define	asicCICOMSRC_PDU_TOTAL_LEN_DL	 CICOM_BaseAddr+0x00000144
#define	asicCICOMCUSTOM_CFG_DL		 CICOM_BaseAddr+0x00000148
#define	asicCICOMSRC_PDU_SEG_ADDR_DL	 CICOM_BaseAddr+0x0000014c
#define	asicCICOMSRC_PDU_SEG_LEN_DL	 CICOM_BaseAddr+0x00000150
#define	asicCICOMLLI_SRC_PDU_SEG_ADDR_DL CICOM_BaseAddr+0x00000154
#define	asicCICOMDST_TTF_SEG_ADDR_DL	 CICOM_BaseAddr+0x00000158
#define	asicCICOMDST_TTF_SEG_LEN_DL	 CICOM_BaseAddr+0x0000015c
#define	asicCICOMLLI_DST_TTF_SEG_ADDR_DL CICOM_BaseAddr+0x00000160
#define	asicCICOMERROR_ADDR_DL		 CICOM_BaseAddr+0x00000170
#define	asicCICOMSRC_SEG_RD_ADDR_DL	 CICOM_BaseAddr+0x00000174
#define	asicCICOMSRC_SEG_LEAVE_LEN_DL	 CICOM_BaseAddr+0x00000178
#define	asicCICOMTTF_SEG_WR_ADDR_DL	 CICOM_BaseAddr+0x0000017c
#define	asicCICOMTTF_SEG_LEAVE_LEN_DL	 CICOM_BaseAddr+0x00000180
#endif/* !defined HICICOMV500 */

