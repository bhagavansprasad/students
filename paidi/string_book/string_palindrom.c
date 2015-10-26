#include<stdio.h>

int main()
{
	char str[100]="pap";
	int i=0,j=-1,flag=0;

	while(str[++j] != '\0');
	j--;

	while(i<j)
		if(str[i++] != str[j--])
		{
			flag=1;
			break;
		}

	if(flag == 0)
		printf("The string is a palindrome\n");
	else
		printf("The string is not a palindrome\n");

	return 0;
}
