#include <stdio.h>
#include <string.h>

int main()
{
	char *str="ISO0150000500200B23A800128A180180000000014000000650000000000002050042813271000057813271004280428042803456174591700012340000=000000230579A1B2C3D4E5SOLABTEST TEST-3 DF MX010abcdefghij484012B456PRO1+000013 1234P0399904ABCD";
	char buff[100]; 
	int i=0,m;
	for(i=0;i<12;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i]='\0';
	printf("iso header : %s\n",buff);
	for(i=0;i<4;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i]='\0';
	printf("message type indicator : %s\n",buff);
//	mti(buff);
	for(i=0;i<16;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i]='\0';
	printf("primary bit map : %s\n",buff);
	
/*	int n = atoi('B');
	for(i=0;i<4;i++)
	{
		m=n%2;
		m=n/2;
		printf("%d\n",m);
	}*/

	for(i=0;i<16;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i]='\0';
	printf("secondary bit map : %s\n",buff);
	
	for(i=0;i<6;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i]='\0';
	printf("processing time : %s\n",buff);

	for(i=0;i<12;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i]='\0';
	printf("Amount : %s\n",buff);

	for(i=0;i<10;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i]='\0';
	printf("Date&Time(mmddhhmmss) : %s\n",buff);

	for(i=0;i<6;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i]='\0';
	printf("AUDIT NUMBER : %s\n",buff);

	for(i=0;i<6;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i]='\0';
	printf("TIME (hhmmss) : %s\n",buff);

	for(i=0;i<4;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i]='\0';
	printf("DATE(mmdd): %s\n",buff);

	for(i=0;i<4;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i]='\0';
	printf("DATE SETTLEMENT(mmdd): %s\n",buff);

	for(i=0;i<4;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i]='\0';
	printf("Expiration date (mmdd): %s\n",buff);

	for(i=0;i<5;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i]='\0';
	printf("acqiring institution identification code : %s\n",buff);










}

