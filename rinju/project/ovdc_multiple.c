#include <stdio.h>
#include <fcntl.h>
#include "string.h"
int get_giff(int);
main()
{   
 int giffs, i,temp;
 int pid[5]={19934,10132};   
 while(1)
 {
	for(i=0;i<2;i++)
	{
	   int arr[10][2] ;
	   printf(" %d ",pid[i]);
	   giffs=get_giff(pid[i]);
	   printf(" %d ",giffs);
	   temp=giffs;

	}
}	
}	
	
	int get_giff(int pid)
	{
	int fd ,id, words = 0, retval=0 , x, i = 0, j = 0, value = 0, sum = 0 , p=0, q=0, diff=0,len=1024;
    char buff[1024];
    char temp[100] = "";
    char temp1[1000] = "";
	for(x=0;x<10;x++)
	{
	sprintf(temp1,"/proc/%d/stat",pid);
	fd=open(temp1,O_RDONLY);


            if( fd < 0)
                printf( "open failure\n");

            retval = read(fd , buff, len);
            retval[buff] = '\0';
            //printf("%s", buff);
            words = 0;
            //printf("%s\n", pbuff);
            for( ; words != 13 && buff[i] != '\0'; i++) //getting 14th word
            {
                if (buff[i] == ' ')
                    words++;
            }
            //printf("i     :%d\n", i);
            //printf("words :%d\n", words);
            //printf("%s\n", &pbuff[i]);

            sum = 0;
            for(words = 0 ; words < 4; words++)
            {
                for( ; buff[i] != ' '; i++, j++)
                    temp[j] = buff[i];
                temp[j] = '\0';
                i++;
                value =(int) atoi(temp); //converting ascii to integer
                printf("value :%d\n", value);
                sum = sum + value;
                //    i++;   
                j = 0;

            }
            printf("sum=%d\n",sum);
            p=sum;
            diff=p-q;
            printf("diff=%d\n\n",diff);
            q=p;
            sleep(2);
			return diff;
			close(fd);
			}
        }

