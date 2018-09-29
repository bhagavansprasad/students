#include <stdio.h>
#include <string.h>

char my_function(char str1[],char str2[])
{
	int i,j=0,k=0;
	while(str1[k] != '\0' && str2[j] != '\0')
	{
		i=k;
		j=0;
		while(str1[i] != '\0' && str2[j] != '\0')
		{
			if(str1[i] != str2[j])
			{
				break;
			}
			i++;
			j++;
		}
		k=k+1;
	}
	if(str1[i] == str2[j])
		printf("find substring \n");
	else
		printf("not find substring \n");

}

int main()
{
	char str1[]="paidikumar";
	char str2[]="kumar";
	my_function(str1,str2);
}


