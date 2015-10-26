#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
char temp[50];
int my_function (char* ,char*,char*,char* ,char* );

int my_function (char *buf,char *string,char *a,char *b,char *tem)
{
	int i=0;
	char *ptr;
	ptr=strstr(buf,string);
	for(;*ptr++!= *a;);
	for(;*ptr!=*b;ptr++)
	{
		tem[i++]=*ptr;
	}
	tem[i]='\0';
	printf("%s %s\n",string,tem);
}

main()
{
	int i=0, retval = 0;
	char buff[10000];
	int fd;
	char *sp = NULL;
	char *ep = NULL;

	fd = open("1.txt",O_RDONLY);
	if(fd == -1)
	{
		printf("file is not open\n");
		exit(1);
	}

	retval = read(fd, buff, 10000);
	buff[retval] = '\0';
	sp = buff;
	printf("buff-->=\n%s\n", buff);
	//	printf("string size--->= %d\n", retval);
	
	my_function (buff,"iq from=","\'","\'",temp);
	my_function (buff,"to=","\'","\'",temp);
	my_function (buff,"id=","\'","\'",temp);
	my_function (buff,"type=","\'","\'",temp);
	my_function (buff,"xmlns=","\'","\'",temp);
	printf("\n");

	for (i = 0; i < 5; i++)
	{
		sp = strstr(sp, "<subscription ");
		ep = strstr(sp, "/><subscription");
		printf("sp --> %s\n", sp);
		//printf("ep --> %s\n", ep);
		my_function (sp,"jid=","\'","\'",temp);
		my_function (sp,"subid=","\'","\'",temp);
		my_function (sp,"subscription=","\'","\'",temp);
		my_function (sp,"node=","\'","\'",temp);
		printf("\n");
		sp = ep;
	}
	my_function (buff,"message from=","\'","\'",temp);
	my_function (buff,"to=","\'","\'",temp);
	my_function (buff,"type=","\'","\'",temp);
	my_function (buff,"id=","\'","\'",temp);
	my_function (buff,"xmlns=","\'","\'",temp);
	printf("\n");


}

