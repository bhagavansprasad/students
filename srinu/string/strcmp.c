#include <stdio.h>
#include<fcntl.h> 
int main()
{
	int t;

	char str1[100]="k sRAVANI";

	char str2[100]="hai sravani";

	t= compare_strings(str1, str2);

	if (t== 0)

		printf("Entered two strings are equal.\n");

	else

		printf("Entered two strings are not equal.\n");
}
int compare_strings(char a[], char b[])
{

	int i=0;

	for(i=0;a[i]!='\0';i++)

	{
		if(a[i]>='a' && a[i]<='z')

			a[i]=a[i]-32;
		if(b[i]>='a' && b[i]<='z')

			b[i]=b[i]-32;

		if(a[i]==b[i])

			return 0;
	}
	return 1;
}
