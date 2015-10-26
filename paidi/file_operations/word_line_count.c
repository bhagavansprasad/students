#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
main()
{
	int i,val,fd,nl=0,c=0;
	char buff[1000];
	fd=open("r.txt",O_RDONLY);

	while(1)
	{
		val=read(fd,buff,100);
		buff[val]='\0';

		for(i=0; buff[i]!='\0'; i++)
		{
			if(buff[i]=='\n')
			{
				nl++;

			}

		}			  
		c=c+val;
		if(val<100)
		{
			break;
		}
	} 
	printf("nl:%d \nc:%d\n",nl,c);
}	    
