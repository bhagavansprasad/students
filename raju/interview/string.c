#include<stdio.h>
#include<string.h>

main()
{
//	int b = 10;
	char a[]="123";
//	int x = 5;
	char b[]="456789";


	printf("a:%u, %d\n", a, sizeof(a));
//	printf("x:%u    \n", &x);
//	printf("x:%u    \n", &b);
	printf("b:%u, %d\n", b, sizeof(b));

	strcpy(a,b);

	printf("a:%s\n",a);
//	printf("x:%u    \n", &x);
	printf("b:%s\n",b);


}	
