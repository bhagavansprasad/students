#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char buff[100];
char *str1="ISO0150000500200B23A800128A180180000000014000000650000000000002050042813271000057813271004280428042803456174591700012340000=000000230579A1B2C3D4E5SOLABTEST TEST-3 DF MX010abcdefghij484012B456PRO1+000013 1234P0399904ABCD";
int conv(char c)
{
	int num;
	if(isdigit(c)) 
		num = c -'0';
	else if(c>='a' && c<='f')
		num = 10 + c - 'a';
	else if(c>='A' && c<='F')
		num = 10 + c - 'A';
	return num;
}
char * sbitmap2(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i] = '\0';
	printf("secondary bit map is          : %5s\n",buff);
	return str;
}
char * proccode(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i] = '\0';
	printf("processing code is            : %5s\n",buff);
	return str;
}
char * amount(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i] = '\0';
	printf("amount transaction is         : %5s\n",buff);
	return str;  
}
char * date(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i] = '\0';
	printf("transmission time/date is	:%s\n",buff);
	return str;
}
char * trace(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i] = '\0';
	printf("system trace audit number is  :%s\n",buff);
	return str;
}
char * time(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i] = '\0';
	printf("time is                       :%s\n",buff);
	return str;
}
char *dateissued(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i] = '\0';
	printf("date issued is                :%s\n",buff);
	return str;
}
char * limitdate(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i] = '\0';
	printf("limit date is                 :%s\n",buff);
	return str;
}
char* expdate(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i] = '\0';
	printf("expiration date  is           :%s\n",buff);
	return str;
}
char * idcode(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i] = '\0';
	printf("identification code is 	:%s\n",buff);
	return str;
}
char * t2data(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i] = '\0';
	printf("track 2 data is               :%s\n",buff);
	return str;
}
char * ref(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i] = '\0';
	printf("reference number is           :%s\n",buff);
	return str;
}
char * termid(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i] = '\0';
	printf("term id is                   :%s\n",buff);
	return str;
}
char  * rxlocation(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i] = '\0';
	printf("card acceptor name/location  :%s\n",buff);
	return str;
}
char * privatedata(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i] = '\0';
	printf("private data  is             :%s\n",buff);
	return str;
}
char * currency(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i] = '\0';
	printf("currency is                  :%s\n",buff);
	return str;
}
char * res1(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i] = '\0';
	printf("reserved 1 is                :%s\n",buff);
	return str;
}
char * res2(char *str,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i] = '\0';
	printf("reserved2 is                 :%s\n",buff);
	return str;
}
void dataelements(char *p)
{
	int c=0,i=0,j=0;
	char * str;
	str=str1;
	//for(i=0;i<=15;i++)
	{	
		int n=conv(*p);
		p++;
		for(j=3;j>=0;j++)
		{
			int k=n&(1<<j);
			if(k!=0)
			{
				c++;
				switch(c)
				{
					case 1 :
						printf("secondary bit map is present in transaction message\n");
						str=str+32;
						str=sbitmap2(str,16);
						break;
					case 3 :
						str = proccode(str,6);
						break;
					case 4 : 
						str = amount(str,12);
						break;
					case 7 : 
						str = date(str,10);
						break;
					case 11 : 
						str = trace(str,6);
						break;
					case 12 : 
						str = time(str,6);
						break;
					case 13 : 
						str = dateissued(str,4);
						break;
					case 15 : 
						str = limitdate(str,4);
						break;
					case 17 :
						str = expdate(str,4);
						break;
					case 32 : 
						str = idcode(str+2,3);
						break;
					case 35 : 
						str = t2data(str+2,17);
						break;
					case 37 : 
						str = ref(str,12);
						break;
					case 41 : 
						str = termid(str,10);
						break;
					case 43 :
						str = rxlocation(str,22);
						break;
					case 48 : 
						str = privatedata(str+3,10);
						break;
					case 49 : 
						str = currency(str,3);
						break;
					case 60 : 
						str = res1(str+3,12);
						break;
					case 61 : 
						str = res2(str+3,6);
						break;
					case 100 : 
						//str = rxidcode(str+2,3);
						break;
					case 102:	
						//str = 
						//break;
					default :
						//	printf("default case \n");
						break;

				}
			}
		}
	}
}

char * isoheader(char *str)
{
	int i=0;
	for(i=0;i<12;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i]='\0';
	//	printf("iso header          : %s\n",buff);
	return buff;

}
char * mti(char * str)
{
	int i;
	for(i=0;i<4;i++)
	{
		buff[i]=*str;
		str++;
	}
	buff[i]='\0';	
	return buff;
}
char * pbitmap(char *str)
{
	int i;
	for(i=0;i<16;i++)
	{
		buff[i]=*str;
		buff[i+1]=' ';
		str++;
	}
	buff[i]='\0';
	return buff;
}
int main()
{
	char *p;
	int i ;
	p=isoheader(str1);
	printf("iso header                    : %s\n",p);
	p=mti(str1+12);
	printf("message type indicator        : %s\n",p);
	p=pbitmap(str1+16);
	printf("primary bit map               : %s\n",p);
	dataelements(p);
}
