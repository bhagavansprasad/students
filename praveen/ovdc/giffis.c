#include <stdio.h>
#include <fcntl.h>
main()
{
	int i,j,fd,rfd;
	int k;
	int wc;
	int sub;
	int var1,var2;
	char buff[500];
	char sum[5];
	char str[20];
	fd = open("/proc/3165/stat",O_RDONLY,0);
	for(j = 0;j<5;j++)
	{
		k = 0;
		wc = 1;
		rfd = read(fd,buff,400);
		buff[rfd] = '\0';
		printf("%s\n",buff);

		for(i = 0;buff[i]!='\0';i++)
		{
			if(buff[i+1]!=' ' &&(buff[i] == '\n'||buff[i] == '\0'))
				wc = wc+1;

			if(wc==14||wc==15)
			{
				str[k] =buff[i+1];
				k++;
			}
		}
		str[k] = '\0';
		sscnaf(str,"%d %d",&var1,&var2);
		sum[j] =var1+var2;
		printf("sum[%d]-->%d\n",j,sum[j]);
		lseek(fd,0l,0);
		printf("\n");
		sleep(2);
	}
	sub = sum[3]-sum[2];
	printf("the sub valu is %d\n",sub);
}

