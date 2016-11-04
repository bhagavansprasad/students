#include<stdio.h>

main()
{
	
	int a=1,b=12,c,n=0,mask=10;
	
	c=a & b;

	printf("c and:%d\n",c);

	c=a|b;

	printf("c or:%d\n",c);

	c=a^b;

	printf("c xor:%d\n",c);
	
	c=a<<-1;


	printf("c left1:%d\n",c);

	c=a<<2;


	printf("c left2:%d\n",c);
	
	c=a>>1;
	
	printf("c right1:%d\n",c);

	c=a>>2;
	
	printf("c right2:%d\n",c);

	c=!n;


	printf("c not:%d\n",c);

	
}
