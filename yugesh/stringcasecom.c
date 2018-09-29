#include<stdio.h>
int astrcasecamp(char* p1,char* p2);
char toupper(char p1);

main()
{
	int rv;
	char s1[12]="yugesh naidu";
	char s2[12]="yugEyH NaiDu";
	rv=astrcasecamp(s1,s2);
	if(rv==0)
		printf("same%d",rv);
	else
		printf("notsame%d",rv);
}
int astrcasecamp(char* p1,char* p2)
{
	int flag=0,i;
	char r1,r2;
	for(i=0;p1[i]!='\0'&&p2[i]!='\0';i++)
	//for(i=0;i<=4;i++)
	{
		r1=toupper(p1[i]);
		r2=toupper(p2[i]);
		if(r1!=r2)
		{
			flag =1;
			break;
		}
	}
		return(flag);

}
	char toupper(char p1)
	{
		if(p1>97&&122>p1)
		p1=p1-32;
		return(p1);
	}


