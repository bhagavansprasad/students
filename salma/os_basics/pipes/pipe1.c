#include<stdio.h>
#define LENSIZE 20
main()
{
	char *msg1[]={"hai","how r u","bye"};
	char *msg2[]={"hello","am fine","bye"};
	int p[2],pid,i=0,j=0;
	char buff[LENSIZE];
	pipe(p);
	pid=fork();
	if(pid>0)
	{
		while(1)
		{
			write(p[1],msg1[i],LENSIZE);
			sleep(2);
			read(p[0],buff,LENSIZE);
			printf("parent :%s\n",buff);
			if(strcmp(buff,"bye")==0)
			  break;
			i++;
		}
	}
		else
		{
			while(1)
			{
				read(p[0],buff,LENSIZE);
				printf("child :%s\n",buff);
				write(p[1],msg2[j],LENSIZE);
				sleep(2);
				if(strcmp(buff,"bye")==0)
					break;
				j++;
			}
		}
	}

