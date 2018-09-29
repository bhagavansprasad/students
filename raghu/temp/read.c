#include <fcntl.h>
#include <stdio.h>
main()
{
	char buff[100];
	int i,fd,s,l=0,len=100;
	int t1=0,t2=0,t3=0;
	fd=open("t.txt",O_RDONLY);
	while(1)
	{
		s=read(fd,buff,len);
		buff[s]='\0';
		printf("%s",buff);
		t1+=get_wc(buff);
		t2+=get_line_count(buff);
		t3+=get_char_count(buff);
		if(s<len)
			break;

	}
	printf("\n");
	printf("no of lines:%d \nno of words :%d \nno of charectors :%d \n",t2,t1,t3);
	close(fd);
}
