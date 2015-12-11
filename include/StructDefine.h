#pragma once

// MCU�ṹ
typedef struct _MMS_MCU
{
	std::string		mcuid;
	std::string		mcutype;
	unsigned long	connections;
	std::string		bandwidth;
	unsigned long	activity;

	std::string		ipaddr;
	unsigned short	ipport;
	std::string		iptype;
	std::string		ipname;

	_MMS_MCU()
	{
		mcuid="";
		mcutype="";
		connections=0;
		activity=0;

		ipaddr="";
		ipport=0;
		iptype="";
		ipname="";
	};
}MMS_MCU,*PMMS_MCU;

// ������Ϣ�ṹ
typedef struct tagORG_ITEM
{
	std::string orgid;			// ����ID
	std::string orgname;		// ��������
	int			membernumber;   // ����������
}ORG_ITEM,*PORG_ITEM;

//�����豸����Ϣ
typedef struct tagGroupInfo
{
	std::string groupid;
	std::string groupname;
	std::string devid;
	std::string parentid;
}GROUPINFO,*PGROUPINFO;

//ͨ����Ϣ
typedef struct _CHANNELINFO
{
	std::string channelid;
	std::string channelname;
	std::string devid;
	std::string devinfo;
	std::string nodeid;
	std::string groupid;
	std::string mcuid;
	std::string mcuaddr;
	unsigned short mcuport;
	std::string nataddr;
	std::string localaddr;
	unsigned short localport;
	std::string termtype;
	unsigned long videocid;
	unsigned long audiocid;
	unsigned short status;
	unsigned char controlflag;
	_CHANNELINFO()
	{
		mcuport=0;
		localport=0;
		videocid=0;
		audiocid=0;
		status=0;
		controlflag=0;
	}
}CHANNELINFO,*PCHANNELINFO;

typedef std::map<unsigned long,GROUPINFO*>		MapMonGroupItem;
typedef std::map<std::string,CHANNELINFO*>		MapMonChannelItem;

// �������Ϣ�ṹ
typedef struct tagREG_ITEM
{
	unsigned long rid;
	std::string name;
	std::string type;
	int level;
	//std::string upgradeid;
	unsigned long pid;
	std::string desc;
}REG_ITEM,*PREG_ITEM;

//-----------------------------------------------
// ��ػ���Ϣ�ṹ
typedef struct tagMAC_ITEM
{
	unsigned long pid;
	unsigned long rid;
	std::string devid;
	std::string name;
	int			chnum;
	int			status;
}MAC_ITEM,*PMAC_ITEM;

//-------------------------------------------

// ��ʱ������ṹ
typedef struct _MMS_ROOM_TEMP
{
	std::string		domain;						//������������
	std::string		roomid;						//������ID
	std::string		roomname;					//����������
	std::string		groupid;					//��ID
	std::string		groupname;					//������
	unsigned short	roomtype;					//����������MMS_ROOM_TYPE����
	std::string		roomcode;					//������CODE
	std::string		password;					//����������
	std::string		limitcode;					//����������λ: ������ʱ����������Ч
	std::string		desc;						//����������
	std::string		adminid;					//�����ҹ���Ա�ʺ�,������ʱ��������adminidΪ�����ߣ����ڸ߼���������adminidΪ����������.
	int				membersum;					//�������е�������
	int				onlinesum;					//�������еĵ�ǰ��������
	std::string		schedule;					//none=���¼����żƻ���appointed=ָ�����ڻ���(��ʱ����)��weekly=ÿ�����ᣬmonthly=ÿ�����ᣬdialy=ÿ�ջ��飬manual=�ֹ�����
	std::string		startdate;					//���鿪ʼ����
	std::string		enddate;					//�����������
	std::string		starttime;					//���鿪ʼʱ��
	std::string		endtime;					//�������ʱ��
	std::string		dayflag;					//���ڱ�־
	int				defaultgroup;				//Ĭ����
	_MMS_ROOM_TEMP()
	{
		roomtype=0;
		membersum=1;
		onlinesum=0;
		defaultgroup=0;
	};
}MMS_ROOM_TEMP,*PMMS_ROOM_TEMP;

typedef std::list<PMMS_ROOM_TEMP> MMS_ROOM_TEMP_LST;