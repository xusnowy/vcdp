
#ifndef _WIN_TEMPLET_DEFINE_H
#define _WIN_TEMPLET_DEFINE_H

typedef enum
{
	TM_TYPE_NONE	= -1,		// δ����
	TM_TYPE_4X3		= 0,		//  4 : 3��
	TM_TYPE_16X9					// 16 ��9��
}TM_TYPE;

typedef enum
{
	TM_SUBTYPE_0_NONE		= -1,
	TM_SUBTYPE_1_1X1		= 0,
	TM_SUBTYPE_2_1X2_SPACE,
	TM_SUBTYPE_2_1X2_FULL,
	TM_SUBTYPE_4_2X2,
	TM_SUBTYPE_4_L1_R3,
	TM_SUBTYPE_6_LT1_RD5,
	TM_SUBTYPE_8_LT1_RD7,
	TM_SUBTYPE_9_3X3,
	TM_SUBTYPE_10_T2_B2X4,
	TM_SUBTYPE_13_IN1_RD12,
	TM_SUBTYPE_16_4X4,
	TM_SUBTYPE_2_PIC_IN_PIC,

	TM_SUBTYPE_4_B1_T3,
	TM_SUBTYPE_5_L1_R4,
	TM_SUBTYPE_5_B1_T4,
	TM_SUBTYPE_6_T2_B4,
	TM_SUBTYPE_7_L2X2_R3,
	TM_SUBTYPE_10_LT1_RD9,
	TM_SUBTYPE_25_5X5,
	TM_SUBTYPE_36_6X6,

	TVWALL_TYPE_TEST		= 100,
}TM_SUBTYPE;

#define TM_MAX_WIN_COUNT	36

#endif