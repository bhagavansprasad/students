#include<stdio.h>
//#include<conio.h>

void main()
{
	char a[20]="aura";
	char b[20]="paidi";
	int i,j,k=0;
	for(i=0,j=0;a[i]!=NULL||b[j]!=NULL;i++,j++)
	{
		if(a[i]!=b[j])
			k++;
	}
	if(k==0)
		printf("string equals\n");
	else
		printf("not equal\n");
}


