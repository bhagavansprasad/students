#include <stdio.h>
#include <fcntl.h>
	
	int i,j,rfd;
	int fd1,fd2,fd3,fd4;
	int k,l;
	int sub;
	
	int wc;
	int sum[5];
	int var1,var2;
	
	char str[20];
	char buff[500];

main()
{
	for(j=0;j<5;j++)
	{
		k=0;
		wc = 1;
		rfd = read(fd,buff,400);
		buff[rfd]='\0';
		//printf("%s\n",buff);

		for(i=0;buff[i]!='\0';i++)
		{
			if(buff[i+1]!=' ' &&(buff[i]==' '||buff[i]=='\n'||buff[i]=='\0'))
				wc = wc+1;

			if(wc==14||wc==15)
			{
				str[k]=buff[i+1];
				k++;
			}
		}
		
		str[k]='\0';
		sscanf(str,"%d %d",&var1,&var2);
		
		sum[j] = var1+var2;
		printf("sum[%d]-->%d\n",j,sum[j]);
		
		lseek(fd,0l,0);
		
		printf("\n");
		
		sleep(2);
	}

	sub = sum[2]-sum[1];
	
	printf("the sub valu is %d\n",sub);

	return sub;
}

