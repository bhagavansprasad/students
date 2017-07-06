#include <stdio.h>
#include<fcntl.h>
#include"string.h"
int pid[1]={1402};
main()
{
    int fd ,id, words = 0, retval=0 , x, i = 0, j = 0, value = 0, sum = 0 , p=0, q=0, diff=0,len=1024;
    char buff[1024];
    char temp[100] = "";
    for(id=0 ; id<5 ;id++)
    {
        for( x = 0; x < 10; x++)
        {
            i = 0;
            fd = open("/proc/1402/stat", O_RDONLY, 0774);

            if( fd < 0)
                printf( "open failure\n");

            retval = read(fd , buff, len);
            retval[buff] = '\0';
            printf("%s", buff);
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
        }
    }
}

