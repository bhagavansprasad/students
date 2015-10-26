#include<stdio.h>
int main()
{
	int i,j,k,l,m,x,y,z,z1;
<<<<<<< iso8583.c
	char str1[]="ISO15000050020000B23A800128A1801801800000000140000006500000000000020500428132710000578132710042804280428042803456174591700012340000=000000230579A1B2C3D4E5SOLABTEST TEST_3 DF MX010abcdefghij484012B456 PRO1+000013 1234PO399904ABCD";
	char buff[100];
	for(i=0;i<11;i++)
=======
	char *str="ISO0150000500200B23A800128A180180000000014000000650000000000002050042813271000057813271004280428042803456174591700012340000=000000230579A1B2C3D4E5SOLABTEST TEST-3 DF MX010abcdefghij484012B456PRO1+000013 1234P0399904ABCD";
	char dest[100];
//ISO_HEADER(str);
#if 0
char * ISO_HEADER(char *str)
{
	strncpy(str,dest,12);
	return dest;
}
#endif
	for(i=0;i<=11;i++)
>>>>>>> 1.3
	{
<<<<<<< iso8583.c
		buff[i]=str1[i]; 
=======
		/*if(str1[i])
		  printf("Header:str1[i]\n");
		  }
		  for(i=12;i<=15;i++)
		  {
		  if(i==12)
		  {
		  switch(j)
		  {
		  case 0:printf("ISO 8583-1987\n");
		  case 1:printf("ISO 8583-1993\n");
		  case 2:printf("ISO 8583-2003\n");
		  case 3:printf("")*/
		dest[i]=*str;
		str++;
	}
	dest[i]='\0';
	printf("header       :%s\n",dest);
	for(i=0;i<=3;i++)
	{
		dest[i]=*str;
		str++;
	}
	dest[i]='\0';
	printf("MTI        :%s\n",dest);
	for(i=0;i<=15;i++)
	{
		dest[i]=*str;
		str++;
>>>>>>> 1.3
	}
<<<<<<< iso8583.c
	buff[i]='\0';
	printf("header:%s\n",buff);
	for(i=11;i<15;i++)
=======
	dest[i]='\0';
	printf("primary bit map   :%s\n",dest);
	for(i=0;i<=15;i++)
>>>>>>> 1.3
	{
<<<<<<< iso8583.c
		buff[i]=str1[i];
		printf("%c\n",buff[i]);
	//buff[i]='\0';
	//printf("MTI:%s\n",buff);
	//if(i==11)
	//{
		switch(str[11]=0)
		switch(0==str[11])
		{
			case 0:printf("ISO 8583-1987\n");
				   break;
			case 1:printf("ISO 8583-1993\n");
				   break;
			case 2:printf("ISO 8583-2003\n");
				   break;
			case 3:printf("ISO reserved bits\n");
				   break;
			case 4:printf("ISO reserved bits\n");
				   break; 
			case 5:printf("ISO reserved bits\n");
				   break;
			case 6:printf("ISO reserved bits\n");
				   break;  
			case 7:printf("ISO reserved bits\n");
				   break;
			case 8:printf("reserved for national\n");
				   break;
			default:printf("reserved for national\n");
					break;
		}
	//}
	//if(i==12)
	//{
		switch(str[12]=2)
		{
			case 1:printf("authorisation message");
				   break;
			case 2:printf("financial");
				   break;
			case 3:printf("file actions");
				   break;
			case 4:printf("reversal&charge back");
				   break;
			case 5:printf("reconcillation");
				   break;
			case 6:printf("administrative");
				   break;
			case 7:printf("free collection");
				   break;
			case 8:printf("nw management");
				   break;
			default:printf("reserved for ISO");
					break;
		}
	//}
	//if(i==13)
	{
		switch(l=0)
		{
			case 0:printf("request");
				   break;
			case 1:printf("request response");
				   break;
			case 2:printf("advice");
				   break;
			case 3:printf("advice response");
				   break;
			case 4:printf("notification");
				   break;
			case 5:printf("notification acknowledgement");
				   break;
			case 6:printf("inst");
				   break;
			case 7:printf("inst ack");
				   break;
			default:printf("reserve");
					break;
		}
	}
	if(i==14)
	{
		switch(m=0)
		{
			case 0:printf("acquirer");
				   break;
			case 1:printf("acquirer repeat");
				   break;
			case 2:printf("issuer");
				   break;
			case 3:printf("issuer repeat");
				   break;
			case 4:printf("other");
				   break;
			case 5:printf("other repeat");
				   break;
			default:printf("reserved");
					break;
		}
	}	
for(i=15;i<=32;i++)
{
	atoi(str1[i]);
	for(z=0;z<=3;z++)
	{
		x=str1[i]%2;
		printf("%d",x);
		x=str1[i]/2;
	}
}
if(str1[15]==1)
{
	printf("there exist secondary bit map");
	for(i=32;i<=48;i++)
	{
		for(z1=0;z1<=3;z1++)
		{
			y=str1[i]%2;
			printf("%d",y);
			y=str1[i]/2;
		}
	}
}
else
{
	printf("there is no exist secondary bit map");
}
}
=======
		dest[i]=*str;
		str++;
	}
	dest[i]='\0';
	printf("secondary bit map        :%s\n",dest);
	prc_code(dest,str+44);
	printf("processing code is  :%s\n",dest);
}	
char *proc_code(char *d,char *s)
{
		strncpy(d,s,6);
		return d;
} 
/*char * ISO_HEADER(char *str)
{
	strncpy(str,dest,12);
	return dest;
}*/

>>>>>>> 1.3
