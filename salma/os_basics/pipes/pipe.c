#include<stdio.h>
#define LEN 20
main()
{
	int i=0,j=0,pid;
	char buff[LEN];
	int p[2];
	char *msg1[]={"hai","how r u","bye"};
	char *msg2[]={"hello","am fine","bye"};
	pipe(p);
	pid=fork();
	if(pid>0)
	{
		while(1)
		{
			write(p[1],msg1[i],LEN);
			sleep(2);
			read(p[0],buff,LEN);
			printf(" parent :%s\n",buff);
			if(strcmp(buff,"bye")==0)
				break;
		    i++;
		}
	}
	else
	{
		while(1)
		{
			read(p[0],buff,LEN);
			printf(" child :%s\n",buff);
			write(p[1],msg2[j],LEN);
			sleep(2);
			if(strcmp(buff,"bye")==0)
     			break;
			j++;
		}
		
	}

}

