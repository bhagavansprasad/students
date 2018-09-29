#include <stdio.h>
int main()
{	
	int a=10,b=4;
	//x=(a=5) && (b=5);
	//y=(c=5) || (d=8);
	//printf("a:%d b:%d c:%d d:%d x:%d y:%d\n",a,b,c,d,x,y);
	//x=(a==6) && (b=9);
	//y=(c==6) || (d=10);
	//printf("a:%d b:%d c:%d d:%d x:%d y:%d\n",a,b,c,d,x,y);
	a=a++;
	a=a++ * a--;
	printf("%d",a);
	printf("%d",a++ * a++);
	//printf("%d %d",a,b);
	return 0;
}
