#include <stdio.h>
char string[]="hellow";
int main()
{
//	char buff[7];
	//char *cp2,*cp1;
	int fds[2];
//	cp1=string;
//	cp2=buff;
//	while(*cp1)
//		*cp2++=*cp1++;
	pipe(fds);
	//for(;;)
	//{
	//	write(fds[1],buff,6);
	//	read(fds[0],buff,6);
//		printf("%s\n",buff);
printf("%d\n",fds);
	//}
} 
