#include <stdio.h>
#include <string.h>

#define ISO8583_HEADER_SIZE    12    /* bytes yet to discuss how to form this*/

#define ISO8583_MTI_OFFSET    ISO8583_HEADER_SIZE
#define ISO8583_MTI_SIZE    4       
#define ISO8583_PBITMAP_OFFSET    (ISO8583_MTI_OFFSET + ISO8583_MTI_SIZE)
#define ISO8583_BITMAPBUFF_SIZE    16
#define ISO8583_BITMAP_SIZE    8     /*64 bits of bitmap */
#define ISO8583_SBITMAP_OFFSET    (ISO8583_PBITMAP_OFFSET + ISO8583_BITMAPBUFF_SIZE)

char ISOMsg[] = "ISO0150000500200B23A800128A180180000000014000000650000000000002050042813271000057813271004280428042803456174591700012340000=000000230579A1B2C3D4E5 SOLABTEST TEST-3 DF MX010abcdefghij484012B456PRO1+000013 1234P0399904ABCD";

char FeildsPresent[128+1] = {0};

void ISO8583_Header(char *pISOMsg)
{
	char Header[ISO8583_HEADER_SIZE+1];

	memset(Header,0, sizeof(Header)+1);

	strncpy(Header,pISOMsg, ISO8583_HEADER_SIZE);

	printf("\n ISO Header = %s \n",Header);   
}

void ParseMTI(char* pMTI)
{
	DumpMTIFeild(0,pMTI[0]-'0');
	DumpMTIFeild(1,pMTI[1]-'0');
	DumpMTIFeild(2,pMTI[2]-'0');
	DumpMTIFeild(3,pMTI[3]-'0');
}

void ISO8583_MTI(char *pMTI)
{
	char MTI[ISO8583_MTI_SIZE + 1];

	memset(MTI,0, sizeof(MTI) + 1);

	strncpy(MTI,pMTI,ISO8583_MTI_SIZE);

	printf("MTI = %s \n",MTI);

	ParseMTI(MTI);
}

unsigned char GetHexValue(char *p)
{
	unsigned char value = 0;
	unsigned char nibble = 0;
	int i = 0;
	for(; i < 2 ; i++)
	{
		if((p[i] >= 'A') && (p[i] <= 'F'))
		{
			switch(p[i])
			{
				case 'A': nibble = 0XA; break;   
				case 'B': nibble = 0XB; break;
				case 'C': nibble = 0XC; break;
				case 'D': nibble = 0XD; break;
				case 'E': nibble = 0XE; break;
				case 'F': nibble = 0XF; break;
			}
		}
		else
			nibble = p[i] - '0';

		if(i == 0)
			value = nibble << 4;
		else
			value |= nibble;
	}
	return value;
}
void DumpBitFeilds(unsigned char *pBitMap)
{
	int Byte = 0, Bit = 7;
	static int count = 1;
	for(; Byte < 8; Byte++)
	{
		//printf("%02u %02X -->",pBitMap[Byte],pBitMap[Byte]);
		for(; Bit >= 0 ; Bit--)
		{
			if(pBitMap[Byte] & (unsigned char)(1 << Bit))
			{
				FeildsPresent[count] = 1;
				DumpBitFeildInfo(count);
			}
			count++;           
		}
		Bit = 7;
	}
	printf("feilds are present\n");
}
void ParseBitMap(char *pBitMapBuff)
{
	unsigned char BitMap[ISO8583_BITMAP_SIZE+1];
	int i = 0;

	memset(BitMap, 0 , sizeof(BitMap) +  1);
	for(; i < 8 ; i++)
	{
		BitMap[i] = GetHexValue(&pBitMapBuff[i*2]);
		//    printf("\n varun--> parse = %0X\n", BitMap[i]);
	}
	DumpBitFeilds(BitMap);
}

void ISO8583_BitMap(char *pBitMap)
{
	char BitMapBuff[ISO8583_BITMAPBUFF_SIZE + 1];

	memset(BitMapBuff, 0 , sizeof(BitMapBuff));

	strncpy(BitMapBuff, pBitMap, ISO8583_BITMAPBUFF_SIZE);

	printf("\n BitmapBuff = %s \n", BitMapBuff);

	ParseBitMap(BitMapBuff);
}
void ParseBitFeildsData(char *pISOData)
{
	int i = 2,max_feilds = FeildsPresent[0]?128:64;
	for(; FeildsPresent[i] != 0XFF ; i++)
	{
		if(FeildsPresent[i] == 1)
		{   
			DumpDataFeild(i,&pISOData);
		}
	}
}
void main()
{
	int SecondaryBitMapoffset = 0;
	char *pISOData = NULL;
	ISO8583_Header(ISOMsg);
	ISO8583_MTI(ISOMsg + ISO8583_MTI_OFFSET);

	memset(FeildsPresent,0XFF,sizeof(FeildsPresent));
	ISO8583_BitMap(ISOMsg + ISO8583_PBITMAP_OFFSET);
	pISOData =  ISOMsg + ISO8583_PBITMAP_OFFSET + ISO8583_BITMAPBUFF_SIZE;
	if(FeildsPresent[1] == 1)
	{
		ISO8583_BitMap(ISOMsg + ISO8583_SBITMAP_OFFSET);
		pISOData =  ISOMsg + ISO8583_SBITMAP_OFFSET + ISO8583_BITMAPBUFF_SIZE;
	}
	ParseBitFeildsData(pISOData);
}
