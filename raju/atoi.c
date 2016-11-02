#include<stdio.h>
int aatoi(char a)
main()
{
char d='34';
int r=0;
r=aatoi(d);
printf("%d\n",r);
}
int aatoi(char a)
{
	//char a='2';
	int i=0,A=48,k;
	for(i=0;A<=57;i++,A++)
	{
		if(a==A)
		{
		//	k=i;
	//	printf("i:%d\n",i);
			return i;

		//	a=i;
	   //	break;
		}
	}
/*	printf("a:%d\n",a);
	printf("k:%d\n",k);
	printf("ac:%c\n",a);*/		


}
