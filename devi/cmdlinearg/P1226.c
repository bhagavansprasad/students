#include <stdio.h>
int main(int argc,char *argv[])
{
	int i,j=0 ,len;
	char str[100];
	char *p;
	printf("argc=%d", argc);
	for(i=0;i<argc;i++)
	{
		printf("argv[%d]=%s\n",i,argv[i]);
		printf("addr of argv[%d] is %p\n",i,&argv[i]);
//		p=&argv[i];
//		printf("after init in ptr p the addr is %p\n",);
	}
	/*	if(i>0)
		{
			while(*p!='\0')
			{
				str[j]=*p;
				j++;
			}
		}
	}
	str[j++]='\0';
	printf("the string is %s\n",str);*/
	return 0;
}
