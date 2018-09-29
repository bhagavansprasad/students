#include<stdio.h>
/* main()
{
int i;
for(i=1;i++;i<100)
 printf("hi paidi\t");
}
// out put--->= infinite
*/
/*main()
{
 int i;
for(i=0;i++;i<100)
printf("hai paidi\t");

}
//output--->= 0 times no output
*/

/*
main()
{
char c;
scanf("%s\n",c);
}
// output-->= runtime error
*/

/*
main()
{
int k=5;
if(++k<5 && k++/5 || ++k<8)
printf("%d\n",k);
}
// output--->= 7 
*/
/*
main()
{
 int i=10;
i++;
printf("1st valu-->= %d\n ",i);
++i;
printf("2st valu-->= %d\n ",i);

}
*/

/*
main()
{
	int *ptr1,*ptr2;
	ptr1=(*int)malloc(sizeof(int));
	ptr2=fun(20,10,ptr1);
	printf("% %d\n",*ptr1,*ptr2);
}

int fun(int a,int b,int *c)
{
	int x=a+b; *c=a-b;
	return(&x);
}
*/
// out put-->=error

main()
{
	int i=10,j;
	if((j=~i)<i)
		//printf("TRUE\n");
		printf("FALSE\n");
	else
		//printf("FALSE\n");
		printf("TRUE\n");
}
// output-->= FALSE
