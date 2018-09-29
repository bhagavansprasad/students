#include<stdio.h>
main()
{
	int dd=28,mm=11,yyy=2014,s=0,b,c,a,i,o3,r1,r2,r3,f,op,o2,odd;
	int arr[11]={3,0,3,2,3,2,3,3,2,3,2};
	for(i=0;i<mm-1;i++)
	{
		s=s+arr[i];
	}
	b=s+dd;
	c=b%7;
	printf("%d\n",c);
	if((yyy%100!=0)&&(yyy%4==0)||(yyy%400==0))
		c=c+1;
	r1=(yyy-1)%400;
	r2=r1%100;
	r3=r1/100;
	o3=(r3*5)%7;
	f=r2/4;
	op=f*2+(r2-f);
	o2=(op)%7;
	odd=o2+c+o3;
	printf("%d",odd);
	switch(odd)
	{
		case 0:
			printf("sunday\n");
			break;
		case 1:
			printf("monday\n");
			break;
		case 2:
			printf("tuesday\n");
			break;
		case 3:
			printf("wednesday\n");
			break;
		case 4:
			printf("thursday\n");
			break;
		case 5:
			printf("firday\n");
			break;
		case 6:
			printf("saturday\n");
			break;
		default:
			printf("worng date\n");
	}
}
