#include<stdio.h>
#include<fcntl.h>
#include"string.h"

main()
{
	int k, p, q = 0, diff = 0, sum = 0, c, x = 0, i = 0, j = 0, value = 0;
	int fd , words,retval = 0, wretval = 0, len = 1024, count = 0;
	char buff[1024], temp[100];

	for(x = 0; x < 10 ; x++)
	{
		i = 0;
		fd = open("/proc/1972/stat", O_RDONLY, 0774);

		if( fd < 0)
			printf( "open failure\n");

		retval = read(fd , buff, len);
		retval[buff] = '\0';
		//printf("%s", buff);
		
		words = 0;
		//printf("%s\n", buff); 
		for( ; words != 13 && buff[i] != '\0'; i++) //getting 14th word
		{
			if (buff[i] == ' ')
				words++;
		}
		sum = 0;
		for(c = 14 ; c <= 17; c++)
		{
			for(k = 0 ;buff[i] != ' ' ; i++) 
			{
				temp[k] = buff[i];
				k++;
			}
			temp[k] = '\0';
			//for( ; buff[i] = ' ' && buff[i] != '\0'; i++);
			i++;
			value = atoi(temp);
			printf("%d word: %d\n", c, value);
			sum = sum + value;
		}
		printf("===>sum is %d \n\n",  sum);
		p = sum;
		diff = p - q;
		printf("--> current sum : %d  prev sum : %d --> diff is %d\n", p, q, diff);
		q = p;
		sleep(2);
	}
}
