#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
char *name (char * , char *);
char *t;
char *st;
char *et;
char  p[100];
char *q;	
char buff[1000];
char *i=0;
int a;
char *name(char *,char *);
main()
{
	int fd = open("tstr.txt",O_RDONLY);
	int retval = read(fd,buff,1000);
//	printf("%d",retval);
	buff[retval] = '\0';
<<<<<<< a.c
	t = strstr(buff,"dc:title");
	st =  t + strlen("dc:title");
	 a = name (t , st);
	//et=strstr(buff,"st");
	printf("%s \n", et);
=======
	t = strstr(buff,"dc:title");
	st =  t + strlen("dc:title");
//	printf(" t  == \n%s \n s---->\n%s ",t ,st);
	char *ptr=name (t ,st);
	//et=strstr(buff,"st");
//	printf("%s \n", et);
>>>>>>> 1.3
	close(fd);
}
char *name(char *t,char *st)
{
	
	while(*t!=*st)
	{
<<<<<<< a.c
		*p[i]=t[i];;
		i++;
		t++;
=======
			//printf("st is %c\n",*st);
		//	printf("t is %c\n",*t);
		p[i]=*t;
		t++;
		//st++;
		i++;
>>>>>>> 1.3
	}
	i[p]='\0';
	printf("\n %s\t ",p);
	printf("\n");

}


