#include<stdio.h>
main()
{
#if 0
	float a1,b1,a2,b2,a3,b3;
	a1=2;
	b1=6.8;
	a2=4.2;
	b2=3.57;
	a3=9.82;
	b3=85.673;
	printf("%3.1f,%4.2f\n",a1,b1);
	printf("%5.1f,%6.2f\n",a2,b2);
	printf("%7.1f,%8.2f\n",a3,b3);
	printf("%10s\n","India");
	printf("%4s\n","India");
	printf("%.2s\n","India");
	printf("%5.2s\n","India");
#endif
float a=123.1265;
printf("%f\t",a);
printf("%.2f\t",a);
printf("%.3f\t",a);
}
