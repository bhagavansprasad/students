#include<stdio.h>
main()
{
	char str[50]="hema svist kadapa";
	str_to_upper(str);
}
int str_to_upper(char *p)
{
 int i;
 for(i=0;p[i]!='\0';i++)
 {
 	
		if(p[i]>=97&&p[i]<=123)
		{
			p[i]=p[i]-32;
			printf("upper string:%c\n",p[i]);
		}
}
return 0;
}
