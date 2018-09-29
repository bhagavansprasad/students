#include<stdio.h>
#include<fcntl.h>
main()
{
	int fd=0,t,s=0;
	char buff[100];
	fd=open("t.txt",0,O_RDONLY);
	while(1)
	{
		t=read(fd,buff,10);
		buff[t]='\0';
		printf("%s",buff);

		s+=get_word_count(buff);
			
		if(t!=10)
		break;
	
    }
	s=s-1;
	printf("%d\n",s);
	
	close(fd);
}
