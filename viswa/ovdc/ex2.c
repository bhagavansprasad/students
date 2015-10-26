#include <stdio.h>
#include <fcntl.h>


main()
{
	int fd ,len = 300 ,j, i ,ret =0, wordcount = 0;
	char buff[300];
	int var1,var2;
	int sum[5];
	char strstored[50];
	int k =0 , sub;

	fd = open("/proc/1444/stat",O_RDONLY);
	for(j = 0 ; j< 5; j++)
	{
		while(1)
		{
			ret = read(fd  , buff ,len);
			buff[ret] = '\0';
			printf("%s\n",buff);


			for(i = 0 ; buff[i] != '\0'; i++)
			{
				if((buff[i+1] != ' ')&&(buff[i] == ' '|| buff[i] == '\n' || buff[i] == '\0'))
					wordcount = wordcount + 1;

				if((wordcount  == 14)||(wordcount == 15))
				{
					strstored[k] = buff[i];
					k++;
				}

			}

			sscanf(strstored ,"%d%d",&var1 , &var2);
			sum[i] = var1 + var2;
			printf("\n sum :->%d\n",sum);
			if(ret < len)
				break;
		}
		lseek(fd ,0l,0);
		printf("\n");
	}
	sub = sum[1] - sum[0];
	printf("cpu time consumption is---->%d\n",sub);
}
