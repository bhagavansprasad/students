#include <stdio.h>
//#include <signal.h>
char str_cpy(char *,char * );
//void myhandle();
int main()
{
	char str1[15]="c.manoharreddy";
	char str2[10];
//	signal(SIGABRT,myhandle);
	str_cpy(str2,str1);
	printf("%c\n",str2);
	return 0;
}
char str_cpy(char *str2,char *str1)
{
	int i;
	for(i=0;str1[i]!='\0';i++)
	{
		str2[i]=str1[i];
	}
	str2[i]='\0';
}





/*
void myhandle()
{
printf("hai");
}*/
