#include<stdio.h>
int main()
{
	f1(1,2);
	//return f1;
}
int f1(int c,int d)
{
	c++;
	c--;
	d++;
	d--;
	printf("---->c:%d\n",c);
	printf("---->d:%d\n",d);

	int x=3,y=4;
	f2(x,y);
	return f1;
}
int f2(int x,int y)
{
printf("------>x:%d\n",x);
printf("-------->y:%d\n",y);
	int e=5,f=6;
	e++;
	e--;
	f++;
	f--;
	char buff[8]={1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,1,0,0,2,0,0,2,9,3,8,2,9,9,7,4,4,3,2,2,3,1,3,2,4,4,4,4,3,3,2,42,2,,432,2,43,4.2,222,42,424,4,7,9,8,9,3,73,0,9,5};
	printf("%d\n",buff[0]);
	printf("%d\n",buff[1]);
	printf("%d\n",buff[2]);
	printf("%d\n",buff[3]);
	printf("%d\n",buff[4]);
	printf("%d\n",buff[5]);
	printf("%d\n",buff[6]);
	printf("%d\n",buff[7]);
	printf("%d\n",buff[8]);
	printf("%d\n",buff[9]);
	printf("---->e:%d\n",e);
	printf("---->f:%d\n",f);
	return f2;
}
