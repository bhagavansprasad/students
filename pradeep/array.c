#include<stdio.h>
main()
{
int arr[5]={10,20,30,40,50};
int p=0,q=0,r=0;
p=&arr+1;
q=arr;
r=p-q;
printf("%u\n",arr[0]);
printf("%u\n",arr[1]);
printf("%u\n",*(arr+1));
printf("%u\n",*(1+arr));
printf("%u\n",1[arr]);
printf("%u\n",arr[2]);
printf("%u\n",arr[3]);
printf("%u\n",arr[4]);

printf("%u\n",&arr[0]);
printf("%u\n",&arr[1]);
printf("%u\n",&arr[2]);
printf("%u\n",&arr[3]);
printf("%u\n",&arr[4]);

printf("%u\n",&arr+1);

printf("%u\n",r);
}
