#include "stdio.h"
#include "string.h"


#define MAKESTR(X) #X

enum ISO8583Datatypes
{
	eAlphaChars,
	eNumericChars,
	eSpecialChars,
	eAlphaNumericChars,
	eAlphaSpecialChars,
	eNumericSpecialChars,



}
struct Temp
{
	int value;
	char *pInfo;
};
struct Data
{
	int     value;
	char     *pDataType;
	int     DataSize;
	char     *pInfo;
};

typedef struct Temp MTIMsgVersion;
typedef struct Temp MTIMsgClass;
typedef struct Temp MTIMsgSubClass;
typedef struct Temp MTIMsgOrigin;
typedef struct Data MTIMsgData;

typedef struct _ISO8583Info
{
	MTIMsgVersion      Ver[10];
	MTIMsgClass     Class[10];
	MTIMsgSubClass    SClass[10];
	MTIMsgOrigin    Orign[6];
	MTIMsgData    Feilds[128];
}ISO8583Info;

ISO8583Info Info={
	/*MTI Description*/
	/*Version*/
	{
		{0,    "ISO 8583-1:1987 version"},
		{1,    "ISO 8583-2:1993 version"},
		{2,    "ISO 8583-3:2003 version"},
		{3,    "Reserved for ISO use"},
		{4,    "Reserved for ISO use"},
		{5,    "Reserved for ISO use"},
		{6,    "Reserved for ISO use"},
		{7,    "Reserved for ISO use"},
		{8,    "Reserved for National use"},
		{9,    "Reserved for Private use"}
	},
	/*Msg Class*/
	{
		{0,    "Not In Use"},
		{1,    "Authorization Message"},
		{2,    "Financial Messages"},
		{3,    "File Actions Message"},
		{4,    "Reversal and Chargeback Messages"},
		{5,    "Reconciliation Message"},
		{6,    "Administrative Message"},
		{7,    "Fee Collection Messages"},
		{8,    "Network Management Message"},
		{9,    "Reserved by ISO"}
	},
	/*SubClass- Function*/
	{
		{0,    "Request"},
		{1,    "Request Response"},
		{2,    "Advice"},
		{3,    "Advice Response"},
		{4,    "Notification"},
		{5,    "Notification Acknowledgement"},
		{6,    "Instruction (ISO 8583:2003 only)"},
		{7,    "Instruction Acknowledgement (ISO 8583:2003 only)"},
		{8,    "Reserved for ISO use.(Response acknowledgment) "},
		{9,    "Reserved for ISO use.(Negative acknowledgment)"}
	},
	/*Msg Origin*/
	{
		{1,    "Acquirer"},
		{2,    "Acquirer Repeat"},
		{3,    "Issuer"},
		{4,    "Issuer Repeat"},
		{5,    "Other"},
		{6,    "Other Repeat"}
	},
	/*Data Feilds Information*/
	{

		{1,    "b 64",     "Bit map (b 128 if secondary is present and b 192 if tertiary is present)"},
		{2,    "n ..19",     "Primary account number (PAN)"},
		{3,    "n 6",         "Processing code"},
		{4,     "n 12",     "Amount, transaction"},
		{5,     "n 12",     "Amount, settlement"},
		{6,     "n 12",     "Amount, cardholder billing"},
		{7,     "n 10",     "Transmission date & time"},
		{8,     "n 8",         "Amount, cardholder billing fee"},
		{9,     "n 8",         "Conversion rate, settlement"},
		{10,     "n 8",         "Conversion rate, cardholder billing"},
		{11,     "n 6",         "System trace audit number"},
		{12,     "n 6",         "Time, local transaction (hhmmss)"},
		{13,     "n 4",         "Date, local transaction (MMDD)"},
		{14,     "n 4",         "Date, expiration"},
		{15,    "n 4",        "Date, settlement"},
		{16,     "n 4",         "Date, conversion"},
		{17,     "n 4",         "Date, capture"},
		{18,     "n 4",         "Merchant type"},
		{19,     "n 3",         "Acquiring institution country code"},
		{20,     "n 3",         "PAN extended, country code"},
		{21,     "n 3",        "Forwarding institution. country code"},
		{22,     "n 3",         "Point of service entry mode"},
		{23,     "n 3",         "Application PAN sequence number"},
		{24,     "n 3",         "Function code (ISO 8583:1993)/Network International identifier (NII)"},
		{25,     "n 2",         "Point of service condition code"},
		{26,     "n 2",         "Point of service capture code"},
		{27,     "n 1",         "Authorizing identification response length"},
		{28,     "x+n 8",     "Amount, transaction fee"},
		{29,     "x+n 8",    "Amount, settlement fee"},
		{30,     "x+n 8",     "Amount, transaction processing fee"},
		{31,     "x+n 8",     "Amount, settlement processing fee"},
		{32,     "n ..11",     "Acquiring institution identification code"},
		{33,     "n ..11",     "Forwarding institution identification code"},
		{34,     "ns ..28",     "Primary account number, extended"},
		{35,     "z ..37",     "Track 2 data"},
		{36,     "n ...104",     "Track 3 data"},
		{37,     "an 12",     "Retrieval reference number"},
		{38,     "an 6",        "Authorization identification response"},
		{39,     "an 2",     "Response code"},
		{40,     "an 3",     "Service restriction code"},
		{41,     "ans 8",     "Card acceptor terminal identification"},
		{42,     "ans 15",     "Card acceptor identification code"},
		{43,     "ans 40",     "Card acceptor name/location (1-23 address 24-36 city 37-38 state 39-40 country)"},
		{44,     "an ..25",     "Additional response data"},
		{45,     "an ..76",    "Track 1 data"},
		{46,     "an ...999",     "Additional data - ISO"},
		{47,     "an ...999",     "Additional data - national"},
		{48,     "an ...999",     "Additional data - private"},
		{49,     "a or n 3",     "Currency code, transaction"},
		{50,     "a or n 3",     "Currency code, settlement"},
		{51,     "a or n 3",     "Currency code, cardholder billing"},
		{52,     "b 64",        "Personal identification number data"},
		{53,     "n 16",     "Security related control information"},
		{54,     "an ...120",     "Additional amounts"},
		{55,     "ans ...999",     "Reserved ISO"},
		{56,     "ans ...999",     "Reserved ISO"},
		{57,     "ans ...999",     "Reserved national"},
		{58,     "ans ...999",     "Reserved national"},
		{59,     "ans ...999",     "Reserved national"},
		{60,     "ans ...999",     "Reserved national"},
		{61,     "ans ...999",     "Reserved private"},
		{62,     "ans ...999",     "Reserved private"},
		{63,    "ans ...999",     "Reserved private"},
		{64,     "b 16",        "Message authentication code (MAC)"},
		{65,     "b 1",         "Bitmap, extended"},
		{66,     "n 1",         "Settlement code"},
		{67,     "n 2",         "Extended payment code"},
		{68,     "n 3",         "Receiving institution country code"},
		{69,     "n 3",         "Settlement institution country code"},
		{70,     "n 3",         "Network management information code"},
		{71,     "n 4",         "Message number"},
		{72,     "n 4",         "Message number, last"},
		{73,     "n 6",         "Date, action (YYMMDD)"},
		{74,     "n 10",     "Credits, number"},
		{75,     "n 10",     "Credits, reversal number"},
		{76,    "n 10",     "Debits, number"},
		{77,     "n 10",     "Debits, reversal number"},
		{78,    "n 10",     "Transfer number"},
		{79,    "n 10",     "Transfer, reversal number"},
		{80,    "n 10",     "Inquiries number"},
		{81,     "n 10",     "Authorizations, number"},
		{82,     "n 12",     "Credits, processing fee amount"},
		{83,     "n 12",     "Credits, transaction fee amount"},
		{84,     "n 12",     "Debits, processing fee amount"},
		{85,     "n 12",     "Debits, transaction fee amount"},
		{86,     "n 16",     "Credits, amount"},
		{87,     "n 16",     "Credits, reversal amount"},
		{88,     "n 16",     "Debits, amount"},
		{89,     "n 16",         "Debits, reversal amount"},
		{90,     "n 42",     "Original data elements"},
		{91,     "an 1",     "File update code"},
		{92,     "an 2",     "File security code"},
		{93,     "an 5",     "Response indicator"},
		{94,     "an 7",     "Service indicator"},
		{95,     "an 42",     "Replacement amounts"},
		{96,     "b 64",     "Message security code"},
		{97,     "x+n 16",     "Amount, net settlement"},
		{98,     "ans 25",     "Payee"},
		{99,     "n ..11",     "Settlement institution identification code"},
		{100,     "n ..11",     "Receiving institution identification code"},
		{101,     "ans ..17",     "File name"},
		{102,     "ans ..28",     "Account identification 1"},
		{103,     "ans ..28",     "Account identification 2"},
		{104,     "ans ...100",     "Transaction description"},
		{105,     "ans ...999",     "Reserved for ISO use"},
		{106,     "ans ...999",     "Reserved for ISO use"},
		{107,     "ans ...999",     "Reserved for ISO use"},
		{108,     "ans ...999",     "Reserved for ISO use"},
		{109,     "ans ...999",     "Reserved for ISO use"},
		{110,     "ans ...999",     "Reserved for ISO use"},
		{111,     "ans ...999",     "Reserved for ISO use"},
		{112,     "ans ...999",     "Reserved for national use"},
		{113,     "ans ...999",     "Reserved for national use"},
		{114,     "ans ...999",     "Reserved for national use"},
		{115,     "ans ...999",     "Reserved for national use"},
		{116,     "ans ...999",     "Reserved for national use"},
		{117,     "ans ...999",     "Reserved for national use"},
		{118,     "ans ...999",     "Reserved for national use"},
		{119,     "ans ...999",     "Reserved for national use"},
		{120,     "ans ...999",     "Reserved for private use"},
		{121,     "ans ...999",     "Reserved for private use"},
		{122,     "ans ...999",     "Reserved for private use"},
		{123,     "ans ...999",     "Reserved for private use"},
		{124,     "ans ...999",     "Reserved for private use"},
		{125,     "ans ...999",     "Reserved for private use"},
		{126,     "ans ...999",     "Reserved for private use"},
		{127,     "ans ...999",     "Reserved for private use"},
		{128,     "b 64",        "Message authentication code"},
	}
};

DumpMTIFeild(int pos, int value)
{
	switch(pos)
	{
		case 0:
			printf("version  = %s \n",Info.Ver[value].pInfo);
			break;
		case 1:
			printf("Class      = %s \n",Info.Class[value].pInfo);
			break;
		case 2:
			printf("Function = %s \n",Info.SClass[value].pInfo);
			break;
		case 3:   
			printf("Origin      = %s \n",Info.Orign[value].pInfo);
			break;
		default:
			break;
	}
}
void DumpBitFeildInfo(int FeildNum)
{
	printf("%d \t of datatype %s \t info: %s\t \n",Info.Feilds[FeildNum].value,Info.Feilds[FeildNum].pDataType,Info.Feilds[FeildNum].pInfo);
}
void DumpDataFeild(int Feild,char **pData)
{
	switch(Feild)
	{
		case 2:
			printf("Primary Account Number");
			break;
		case 3:
			{
				char PCode[6+1];
				memset(PCode,0,sizeof(PCode));
				strncpy(PCode,*pData,6);
				*pData += 6;
				printf("Processing Code %u",atoi(PCode));
			}
			break;
		case 4:
			{
				char TAmount[12+1];
				memset(TAmount,0,sizeof(TAmount));
				strncpy(TAmount,*pData,12);
				*pData += 12;
				printf("Transaction Amount = %u",atoi(TAmount));
			}
			break;
		default:
			break;
	}
}    
