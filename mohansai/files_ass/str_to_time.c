#include "stdio.h"
typedef struct my_time_t
{
//	int year;
//	int month;
//	int day;
	int hours;
	int minutes;
	int seconds;
	int mil_sec;
}my_time;
int i;
char test_string[]= "16:13:31.23228600 L1R1TS31SC0 ECHO          MSG";

int get_time_from_string(my_time *ptime, char *src_str)
{
	int count=0,j=0;
	char temp[10];
	for( i = 0 ; src_str[i] != '\0' && src_str[i] != '\n' ; i++ )
	{
		if(src_str[i]!=':'  && src_str[i]!=' ' && src_str[i]!='.' )
		{
			temp[j]=src_str[i];
			count++;
			j++;
		}
		else
		{
			temp[j+1]='\0';
			if( i > 0 && i < 3 )
			{
				ptime->hours=atoi(temp);
				j=0;
			}
			else if( i > 3 && i < 6 )
			{
				ptime->minutes=atoi(temp);
				j=0;
			}
			else if( i > 6 && i < 9 )
			{
				ptime->seconds=atoi(temp);
				j=0;
			}
		
			else if( i > 9 && i<19 )
			{
				ptime->mil_sec=atoi(temp);
				j=0;
			}
		}		
	}
}

int main()
{
	my_time time_vals;

	get_time_from_string(&time_vals, test_string);

	
	printf("hours-->%3d\t minutes-->%3d\t seconds-->%3d\t mil_sec-->%8d\t\r\n", time_vals.hours, time_vals.minutes, time_vals.seconds, time_vals.mil_sec);
	
//	printf("%5d%3d%3d%3d%3d%3d%8d\r\n",time_vals.year, time_vals.month,	time_vals.day, time_vals.hours, time_vals.minutes, time_vals.seconds,time_vals.mil_sec);
}
