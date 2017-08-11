#include<stdio.h>
main(int argc,char *argv[])
{
	int arr[500],i,j,sum=0,n;
	FILE *fp;
	fp=fopen(argv[1],"r");
	if(fp==NULL)
		printf("can't open");
	n=read(fp,arr,500);
	for(i=0;i<=500;i++)
		printf("%d",arr[i]);
	for(j=13;j<=17;j++)
	{
		sum=arr[j];
	}
	printf("sum=%d",sum);
}
