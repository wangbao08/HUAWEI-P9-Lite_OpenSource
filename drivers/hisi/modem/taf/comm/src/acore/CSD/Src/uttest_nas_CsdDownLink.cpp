#include "gtest/gtest.h"
#include "llt_mockcpp.h"

#include "uttest_nas_CsdDownLink.h"

//�����������ã����������ùؼ���ʱ��Ҫ��ǰ׺ testing::
using namespace testing;

//˵��������������gtest+�������׺Ͳ����������ֲ�����Ϊ��
//      ������ú�gtest��ͬ�Ĺؼ��֣����ⲻ��Ҫ���鷳
//      gtest�ṩ EXPECT �� ASSERT ����,���庬����Կ���Ƭ�����׺궼��һһ��Ӧ�ģ�������EXPECTΪ��

//1���ȶԲ������� EXPECT_TRUE��EXPECT_FALSE/ASSERT_TRUE
//2���Ƚ����� EXPECT_EQ EXPECT_NE
//3���Ƚ��ַ��� EXPECT_STREQ
//4������ʧ�������Ϣ ADD_FAILUREd
//5�����óɹ���ʧ�� SUCCEED FAIL
//6���Զ����ʽ EXPECT_PRED_FORMAT3
//7�����������������TRUE EXPECT_PRED1
//8�������ͱȽ� EXPECT_FLOAT_EQ EXPECT_PRED_FORMAT2 ASSERT_PRED_FORMAT2
//9�����ͼ�� StaticAssertTypeEq
//10������3�ֲ��Լ����¼�
//11����ȡ������������ test_case_name()
//12���Ƚ��쳣 EXPECT_THROW
//13���ṹ�����ͱȽ�ASSERT_SAME_DATA ASSERT_SAME_MEMORY

#if 0

#if( FEATURE_ON == FEATURE_CSD )
/*****************************************************************************
���� : Test_CSD_DL_ProcData
�������� : Test_CSD_DL_ProcData UT������
�޸���ʷ     :
1.��   ��  : 2011-12-10
  ��   ��  : w00199382
  �޸����� : ��������
*****************************************************************************/
class Test_CSD_DL_ProcDataTask: public ::testing::Test
{
public:
    void SetUp()
	{
		UT_STUB_INIT();
        CSD_InitCtx();
    }
    void TearDown()
    {
    }
private:

};

/*******************************************************************
�����������      : Test_CSD_DL_ProcDataTask_001
������������      : CSD_DL_ProcDataTask��������û���յ�����,�ź���δ�ͷ�
Ԥ�ڽ��          : ��ӡ�ź���δ�ͷ�log
�޸���ʷ     :
1.��   ��  : 2011-12-09
  ��   ��  : w00199382
  �޸����� : �½�CASE

*******************************************************************/
TEST_F( Test_CSD_DL_ProcDataTask, Test_CSD_DL_ProcDataTask_001 )
{
    /* ������������ */

    /* �������� */
    MOCKER(VOS_SmP)
          .expects(exactly(1))
          .will(returnValue(VOS_ERR));

    MOCKER(CSD_DL_ClearData)
          .expects(never());
#if 0
    MOCKER(DICC_EnableIsr)
          .expects(never());
#endif
    /* ���Ժ������� */
    CSD_DL_ProcDataTask();

    /* ƥ��ִ�н�� */

    //������ʱ����Ҫ����������λ�ü������
    GlobalMockObject::verify();

}

/*******************************************************************
�����������      : Test_CSD_DL_ProcDataTask_002
������������      : CSD_DL_ProcDataTask��CSD_GetCallState��Ϊ AT_CSD_CALL_STATE_ON��������û�н�ͨ�绰
Ԥ�ڽ��          : ���DICC�����������ݣ�ʹ���жϣ���ӡ�쳣 ���������ݱ��ͷ�
�޸���ʷ     :
1.��   ��  : 2011-12-09
  ��   ��  : w00199382
  �޸����� : �½�CASE

*******************************************************************/
TEST_F( Test_CSD_DL_ProcDataTask, Test_CSD_DL_ProcDataTask_002 )
{
    /* ������������ */

    /* �������� */
    MOCKER(VOS_SmP)
          .expects(exactly(1))
          .will(returnValue(VOS_OK));

    MOCKER(DICC_GetChannelNodeCnt)
          .expects(exactly(1))
          .will(returnValue(3));

    MOCKER(DICC_RemoveChannelData)
          .will(returnValue(DICC_OK));

    MOCKER(IMM_RbRemoteFreeMem)
          .expects(exactly(3));
#if 0
    MOCKER(DICC_EnableIsr)
          .expects(exactly(1));
#endif

    /* ���Ժ������� */
    CSD_DL_ProcDataTask();

    /* ƥ��ִ�н�� */

    //������ʱ����Ҫ����������λ�ü������
    GlobalMockObject::verify();


}
/*******************************************************************
�����������      : Test_CSD_DL_ClearData_001
������������      : CSD_DL_ProcDataTask��CSD_GetCallState��Ϊ AT_CSD_CALL_STATE_ON��������û�н�ͨ�绰
                    ��DICC���Ƴ�����ʧ��
Ԥ�ڽ��          : ��ӡ�쳣����������δ�ͷ�
�޸���ʷ     :
1.��   ��  : 2011-12-09
  ��   ��  : w00199382
  �޸����� : �½�CASE

*******************************************************************/
TEST_F( Test_CSD_DL_ProcDataTask, Test_CSD_DL_ClearData_001 )
{
    /* ������������ */

    /* �������� */
    MOCKER(VOS_SmP)
          .expects(exactly(1))
          .will(returnValue(VOS_OK));

    MOCKER(DICC_GetChannelNodeCnt)
          .expects(exactly(1))
          .will(returnValue(3));

    MOCKER(DICC_RemoveChannelData)
          .will(returnValue(DICC_ERR_TRIG_ISR_FAIL));

    MOCKER(IMM_RbRemoteFreeMem)
          .expects(never());
#if 0
    MOCKER(DICC_EnableIsr)
          .expects(exactly(1));
#endif

    /* ���Ժ������� */
    CSD_DL_ProcDataTask();

    /* ƥ��ִ�н�� */

    //������ʱ����Ҫ����������λ�ü������
    GlobalMockObject::verify();


}
/*******************************************************************
�����������      : Test_CSD_DL_ClearData_002
������������      : CSD_DL_ProcDataTask��CSD_GetCallState��Ϊ AT_CSD_CALL_STATE_ON��������û�н�ͨ�绰
                    ���DICC�з�����������,��ȡ�ڵ���Ŀ�Ƿ�
Ԥ�ڽ��          : ���������ֱ�ӷ���
�޸���ʷ     :
1.��   ��  : 2011-12-09
  ��   ��  : w00199382
  �޸����� : �½�CASE

*******************************************************************/
TEST_F( Test_CSD_DL_ProcDataTask, Test_CSD_DL_ClearData_002 )
{
    /* ������������ */

    /* �������� */
    MOCKER(VOS_SmP)
          .expects(exactly(1))
          .will(returnValue(VOS_OK));

    MOCKER(DICC_GetChannelNodeCnt)
          .expects(exactly(1))
          .will(returnValue(DICC_INVALID_VALUE));

    MOCKER(DICC_RemoveChannelData)
          .expects(never());

    MOCKER(IMM_RbRemoteFreeMem)
          .expects(never());
#if 0
    MOCKER(DICC_EnableIsr)
          .expects(exactly(1));
#endif
    /* ���Ժ������� */
    CSD_DL_ProcDataTask();

    /* ƥ��ִ�н�� */

    //������ʱ����Ҫ����������λ�ü������
    GlobalMockObject::verify();


}

/*******************************************************************
�����������      :  Test_CSD_DL_SendData_001
������������      :  CSD_DL_ProcDataTask��CSD_DL_SendData ulDICCNodeCntΪ��
Ԥ�ڽ��          :  ��ӡ���淢�������������ݱ����
�޸���ʷ     :
1.��   ��  : 2011-12-09
  ��   ��  : w00199382
  �޸����� : �½�CASE

*******************************************************************/
TEST_F( Test_CSD_DL_ProcDataTask, Test_CSD_DL_SendData_001 )
{
    /* ������������ */

    /* �������� */
    MOCKER(VOS_SmP)
          .expects(exactly(1))
          .will(returnValue(VOS_OK));

    MOCKER(DICC_GetChannelNodeCnt)
          .expects(exactly(1))
          .will(returnValue(0));

    MOCKER(DICC_RemoveChannelData)
          .expects(never());

    MOCKER(IMM_RbRemoteFreeMem)
          .expects(never());
#if 0
    MOCKER(DICC_EnableIsr)
          .expects(exactly(1));
#endif
    CSD_SetCallState(AT_CSD_CALL_STATE_ON);

    /* ���Ժ������� */
    CSD_DL_ProcDataTask();

    /* ƥ��ִ�н�� */

    //������ʱ����Ҫ����������λ�ü������
    GlobalMockObject::verify();



}
/*******************************************************************
�����������      :  Test_CSD_DL_SendData_002
������������      :  CSD_DL_ProcDataTask��CSD_DL_SendData,
                     ��ȡDICCͨ���ڵ���Ŀ�Ƿ�
Ԥ�ڽ��          :  ��ӡ�ڵ���Ŀ�쳣��Ϣ����ֹ���̣���������δ�ı�
�޸���ʷ     :
1.��   ��  : 2011-12-09
  ��   ��  : w00199382
  �޸����� : �½�CASE

*******************************************************************/
TEST_F( Test_CSD_DL_ProcDataTask, Test_CSD_DL_SendData_002 )
{
    /* ������������ */

    /* �������� */
    MOCKER(VOS_SmP)
          .expects(exactly(1))
          .will(returnValue(VOS_OK));

    MOCKER(DICC_GetChannelNodeCnt)
          .expects(exactly(1))
          .will(returnValue(DICC_INVALID_VALUE));

    MOCKER(DICC_RemoveChannelData)
          .expects(never());

    MOCKER(IMM_RbRemoteFreeMem)
          .expects(never());
#if 0
    MOCKER(DICC_EnableIsr)
          .expects(exactly(1));
#endif
    CSD_SetCallState(AT_CSD_CALL_STATE_ON);

    /* ���Ժ������� */
    CSD_DL_ProcDataTask();

    /* ƥ��ִ�н�� */

    //������ʱ����Ҫ����������λ�ü������
    GlobalMockObject::verify();


}

/*******************************************************************
�����������      :  Test_CSD_DL_SendData_003
������������      :  CSD_DL_ProcDataTask��CSD_DL_SendData,
                     ulRsltΪVOS_ERR���������DICC���Ƴ�����ʧ��
Ԥ�ڽ��          :  ��ӡ�����Ƴ��쳣��Ϣ����ֹ���̣�
�޸���ʷ     :
1.��   ��  : 2011-12-09
  ��   ��  : w00199382
  �޸����� : �½�CASE

*******************************************************************/
TEST_F( Test_CSD_DL_ProcDataTask, Test_CSD_DL_SendData_003 )
{
    /* ������������ */

    /* �������� */
    MOCKER(VOS_SmP)
          .expects(exactly(1))
          .will(returnValue(VOS_OK));

    MOCKER(DICC_GetChannelNodeCnt)
          .expects(exactly(1))
          .will(returnValue(3));

    MOCKER(DICC_RemoveChannelData)
          .will(returnValue(DICC_ERR_TRIG_ISR_FAIL));

    MOCKER(IMM_ZcStaticAlloc_Debug)
          .expects(never());

    MOCKER(AT_SendCsdZcDataToModem)
          .expects(never());

    MOCKER(IMM_RbRemoteFreeMem)
          .expects(never());

#if 0
    MOCKER(DICC_EnableIsr)
          .expects(exactly(1));
#endif
    CSD_SetCallState(AT_CSD_CALL_STATE_ON);

    /* ���Ժ������� */
    CSD_DL_ProcDataTask();

    /* ƥ��ִ�н�� */

    //������ʱ����Ҫ����������λ�ü������
    GlobalMockObject::verify();


}

/*******************************************************************
�����������      :  Test_CSD_DL_SendData_004
������������      :  CSD_DL_ProcDataTask��CSD_DL_SendData,
                     C�˴��͹���������ָ��Ϊ��
Ԥ�ڽ��          :  ��ӡ����ָ��Ϊ���쳣��Ϣ����ֹ����
�޸���ʷ     :
1.��   ��  : 2011-12-09
  ��   ��  : w00199382
  �޸����� : �½�CASE

*******************************************************************/
TEST_F( Test_CSD_DL_ProcDataTask, Test_CSD_DL_SendData_004 )
{
    CST_CSD_DATA_IND_STRU               stDLData;

    /* ������������ */
    PS_MEM_SET(&stDLData, 0x00, sizeof(CST_CSD_DATA_IND_STRU));

    stDLData.pGarbage                   = VOS_NULL_PTR;
    /* �������� */
    MOCKER(VOS_SmP)
          .expects(exactly(1))
          .will(returnValue(VOS_OK));

    MOCKER(DICC_GetChannelNodeCnt)
          .expects(exactly(1))
          .will(returnValue(3));

    MOCKER(DICC_RemoveChannelData)
          .with(eq(ACPU_PID_CSD),
                eq(DICC_CHAN_ID_2),
                outBoundP((VOS_VOID *)&stDLData, sizeof(CST_CSD_DATA_IND_STRU)))
           .will(returnValue(DICC_OK));

    MOCKER(IMM_ZcStaticAlloc_Debug)
          .expects(never());

    MOCKER(AT_SendCsdZcDataToModem)
          .expects(never());

    MOCKER(IMM_RbRemoteFreeMem)
          .expects(never());

#if 0
    MOCKER(DICC_EnableIsr)
          .expects(exactly(1));
#endif
    CSD_SetCallState(AT_CSD_CALL_STATE_ON);

    /* ���Ժ������� */
    CSD_DL_ProcDataTask();

    /* ƥ��ִ�н�� */

    //������ʱ����Ҫ����������λ�ü������
    GlobalMockObject::verify();

}

/*******************************************************************
�����������      :  Test_CSD_DL_SendData_005
������������      :  CSD_DL_SendData��IMM_ZcLargeMemAlloc���������ڴ�ʧ��VOS_NULL_PTR
Ԥ�ڽ��          :  ��ӡ�ڴ�����ʧ���쳣���ͷ�C������
�޸���ʷ     :
1.��   ��  : 2011-12-09
  ��   ��  : w00199382
  �޸����� : �½�CASE

*******************************************************************/
TEST_F( Test_CSD_DL_ProcDataTask, Test_CSD_DL_SendData_005 )
{
    CST_CSD_DATA_IND_STRU               stDLData;

    /* ������������ */
    PS_MEM_SET(&stDLData, 0x00, sizeof(CST_CSD_DATA_IND_STRU));

    stDLData.pGarbage                   = (VOS_VOID *)PS_MEM_ALLOC(ACPU_PID_CSD,
                                                                   4);
    /* �������� */
    MOCKER(VOS_SmP)
          .expects(exactly(1))
          .will(returnValue(VOS_OK));

    MOCKER(DICC_GetChannelNodeCnt)
          .expects(exactly(1))
          .will(returnValue(3));

    MOCKER(DICC_RemoveChannelData)
          .with(eq(ACPU_PID_CSD),
                eq(DICC_CHAN_ID_2),
                outBoundP((VOS_VOID *)&stDLData, sizeof(CST_CSD_DATA_IND_STRU)))
           .will(returnValue(DICC_OK));

    MOCKER(IMM_ZcStaticAlloc_Debug)
          .expects(exactly(1))
          .will(returnValue(VOS_NULL_PTR));

    MOCKER(IMM_RbRemoteFreeMem)
          .expects(exactly(1))
          .with(mirror(stDLData.pGarbage, 4));

    MOCKER(AT_SendCsdZcDataToModem)
          .expects(never());
#if 0
    MOCKER(DICC_EnableIsr)
          .expects(exactly(1));
#endif
    CSD_SetCallState(AT_CSD_CALL_STATE_ON);

    /* ���Ժ������� */
    CSD_DL_ProcDataTask();

    /* ƥ��ִ�н�� */

    //������ʱ����Ҫ����������λ�ü������
    GlobalMockObject::verify();


}

/*******************************************************************
�����������      :  Test_CSD_DL_SendData_006
������������      :  CSD_DL_SendData��AT_UsbModemWriteDataд�����ڴ�ʧ��
Ԥ�ڽ��          :  �ͷ�A���ڴ��C�������ڴ�
�޸���ʷ     :
1.��   ��  : 2011-12-09
  ��   ��  : w00199382
  �޸����� : �½�CASE

*******************************************************************/
TEST_F( Test_CSD_DL_ProcDataTask, Test_CSD_DL_SendData_006 )
{
    CST_CSD_DATA_IND_STRU               stDLData;

    /* ������������ */
    PS_MEM_SET(&stDLData, 0x00, sizeof(CST_CSD_DATA_IND_STRU));

    stDLData.pGarbage                   = PS_MEM_ALLOC(ACPU_PID_CSD, 4);
    stDLData.pucData                    = (VOS_UINT8 *)PS_MEM_ALLOC(ACPU_PID_CSD, 4);
    stDLData.usLen                      = 4;

    /* �������� */
    MOCKER(VOS_SmP)
          .expects(exactly(1))
          .will(returnValue(VOS_OK));

    MOCKER(DICC_GetChannelNodeCnt)
          .expects(exactly(1))
          .will(returnValue(3));

    MOCKER(DICC_RemoveChannelData)
          .with(eq(ACPU_PID_CSD),
                eq(DICC_CHAN_ID_2),
                outBoundP((VOS_VOID *)&stDLData, sizeof(CST_CSD_DATA_IND_STRU)))
           .will(returnValue(DICC_OK));

    MOCKER(IMM_ZcStaticAlloc_Debug)
          .expects(exactly(1))
          .will(returnValue(&stDLData.pucData));

    MOCKER(V_MemCpy)
          .expects(exactly(1));

    MOCKER(AT_SendCsdZcDataToModem)
          .expects(exactly(1))
          .will(returnValue(VOS_ERR));

    MOCKER(IMM_RbRemoteFreeMem)
          .expects(exactly(1))
          .with(mirror(stDLData.pGarbage, 4));

#if 0
    MOCKER(DICC_EnableIsr)
          .expects(exactly(1));
#endif
    CSD_SetCallState(AT_CSD_CALL_STATE_ON);

    /* ���Ժ������� */
    CSD_DL_ProcDataTask();

    /* ƥ��ִ�н�� */

    //������ʱ����Ҫ����������λ�ü������
    GlobalMockObject::verify();


}

/*******************************************************************
�����������      :  Test_CSD_DL_ProcDataTask_007
������������      :  �������ݳɹ�
Ԥ�ڽ��          :  �������ݳɹ�ʹ��DICC�ж�
�޸���ʷ     :
1.��   ��  : 2011-12-09
  ��   ��  : w00199382
  �޸����� : �½�CASE

*******************************************************************/
TEST_F( Test_CSD_DL_ProcDataTask, Test_CSD_DL_ProcDataTask_007 )
{
    CST_CSD_DATA_IND_STRU               stDLData;

    /* ������������ */
    PS_MEM_SET(&stDLData, 0x00, sizeof(CST_CSD_DATA_IND_STRU));

    stDLData.pGarbage                   = PS_MEM_ALLOC(ACPU_PID_CSD, 4);
    stDLData.pucData                    = (VOS_UINT8 *)PS_MEM_ALLOC(ACPU_PID_CSD, 4);
    stDLData.usLen                      = 4;

    /* �������� */
    MOCKER(VOS_SmP)
          .expects(exactly(1))
          .will(returnValue(VOS_OK));

    MOCKER(DICC_GetChannelNodeCnt)
          .expects(exactly(2))
          .will(returnObjectList(3,0));

    MOCKER(DICC_RemoveChannelData)
          .with(eq(ACPU_PID_CSD),
                eq(DICC_CHAN_ID_2),
                outBoundP((VOS_VOID *)&stDLData, sizeof(CST_CSD_DATA_IND_STRU)))
           .will(returnValue(DICC_OK));

    MOCKER(IMM_ZcStaticAlloc_Debug)
          .expects(exactly(1))
          .will(returnValue(&stDLData.pucData));

    MOCKER(V_MemCpy)
          .expects(exactly(1));

    MOCKER(AT_SendCsdZcDataToModem)
          .expects(exactly(1))
          .will(returnValue(VOS_OK));

    MOCKER(IMM_RbRemoteFreeMem)
          .expects(exactly(1))
          .with(mirror(stDLData.pGarbage, 4));

#if 0
    MOCKER(DICC_EnableIsr)
          .expects(exactly(1));
#endif
    CSD_SetCallState(AT_CSD_CALL_STATE_ON);

    /* ���Ժ������� */
    CSD_DL_ProcDataTask();

    /* ƥ��ִ�н�� */

    //������ʱ����Ҫ����������λ�ü������
    GlobalMockObject::verify();


}

/*******************************************************************
�����������      : Test_CSD_DL_ProcIsr_001
������������      : �����ж���Ӧ����
Ԥ�ڽ��          : �ͷ��ź������ر��ж�
�޸���ʷ     :
1.��   ��  : 2011-12-09
  ��   ��  : w00199382
  �޸����� : �½�CASE

*******************************************************************/
TEST_F( Test_CSD_DL_ProcDataTask, Test_CSD_DL_ProcIsr_001 )
{
    /* ������������ */

    /* �������� */
    MOCKER(VOS_SmV)
          .with(eq(CSD_GetDownLinkDataSem()));
#if 0
    MOCKER(DICC_DisableIsr)
          .expects(exactly(1));
#endif
    /* ���Ժ������� */
    CSD_DL_ProcIsr();

    /* ƥ��ִ�н�� */

    //������ʱ����Ҫ����������λ�ü������
    GlobalMockObject::verify();

}

#endif

#endif