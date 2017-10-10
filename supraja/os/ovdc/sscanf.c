#include <stdio.h>
int main()
{
	char arr[50]="india 20 15";
	int var3,var1,var2;
	char a[10];
	sscanf(arr,"%s %d %d",a,&var1,&var2);
	printf("%d \n %d\n",var1,var2);
	var3=var1+var2;
	printf("%d\n",var3);
}
