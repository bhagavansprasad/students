#include "stdio.h"
#include "string.h"
#include "fcntl.h"
#include "stdlib.h"
#define MAX 256 
#define MAX1 837 
#define MAX2 2161 

struct timevalues
{
char totstr[MAX];
int hour;
int min;
int secs;
int milsecs;
int sumoftimes;
}t1[MAX1],t2[MAX2];

int parsestring(char *buff, int mac, int p)
{
	char *str1;
	int sum;
	if(mac == MAX1)       
	{
		strcpy(t1[p].totstr, buff); 
		str1 = strtok(buff, ":. ");
		t1[p].hour = atoi(str1);
		str1 = strtok(NULL, ":. ");
		t1[p].min = atoi(str1);
		str1 = strtok(NULL, ":. ");
		t1[p].secs = atoi(str1);
		str1 = strtok(NULL, ":. ");
		t1[p].milsecs = atoi(str1);       
		sum =  t1[p].hour+t1[p].min+t1[p].secs+t1[p].milsecs;
		t1[p].sumoftimes = sum;
		printf("totstr:%s\r\n",t1[p].totstr);	
		printf("hour:%d min:%d secs:%d milsecs:%d sumoftimes:%d\r\n",t1[p].hour,t1[p].min,t1[p].secs,t1[p].milsecs,t1[p].sumoftimes);	
	}
	else
	{	
		strcpy(t2[p].totstr,buff); 
		str1 = strtok(buff, ":. ");
		t2[p].hour = atoi(str1);
		str1 = strtok(NULL, ":. ");
		t2[p].min = atoi(str1);
		str1 = strtok(NULL, ":. ");
		t2[p].secs = atoi(str1);
		str1 = strtok(NULL, ":. ");
		t2[p].milsecs = atoi(str1);       
		sum =  t2[p].hour+t2[p].min+t2[p].secs+t2[p].milsecs;
		t2[p].sumoftimes = sum;
		printf("totstr:%s\r\n",t2[p].totstr);	
		printf("hour:%d min:%d secs:%d milsecs:%d sumoftimes:%d\r\n",t2[p].hour,t2[p].min,t2[p].secs,t2[p].milsecs,t2[p].sumoftimes);	
	}

	return 0;

}

int compaireandwrite()
{
int i;
FILE *fp3;
fp3 = fopen("f3.c", "a");
for(i=0; i<MAX1; i++)
{
if(t1[i].sumoftimes >= t2[i].sumoftimes)
{
fwrite(t2[i].totstr, 1, 48, fp3);
fwrite(t1[i].totstr, 1, 48, fp3);
}
else
{
fwrite(t1[i].totstr, 1, 48, fp3);
fwrite(t2[i].totstr, 1, 48, fp3);
}
}

fclose(fp3);
return 0;
}

int main()
{
	static int i=0,j=0;
	char buff1[MAX],buff2[MAX];
	FILE  *fp1,*fp2;
	fp1 = fopen("f1.c", "r");
	fp2 = fopen("f2.c", "r");
	while(fgets(buff1, MAX, fp1) != NULL)
	{

		parsestring(buff1, MAX1, i); 
		i++;
	}
	while(fgets(buff2, MAX, fp2) != NULL)
	{
		parsestring(buff2, MAX2, j); 
		j++;
	}
printf("calling compaireandwrite function\r\n");
compaireandwrite();
fclose(fp1);
fclose(fp2);
}
