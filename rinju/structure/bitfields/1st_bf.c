#include<stdio.h>
#include<string.h>
struct a
{
	int height;
	int width;
}a1;
struct b 
{
	int height:3;
	int width:1;
}b1;

main()
{
    b1.height=4;
	b1.width=1;
	printf(" height=%d\n",b1.height);
	printf(" width=%d\n",b1.width);
	printf("memory occupied=%d\n",sizeof(a1));
	printf("memory occupied=%d\n",sizeof(b1));
}
