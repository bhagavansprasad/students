#include<stdio.h>
#include<string.h>

int main()
{
	char str1[500] = "prasanna", str2[100]="Kumar";
	int i, j;
	//printf("Please enter first string: ");
	//gets(str); 
	// fgets is a better option over gets to read multiword string .
	//fgets(str1, 500, stdin);
	// Following can be added for extra precaution for '\n' character
	// if(str1[length(str1)-1] == '\n') str1[strlen(str1)-1]=NULL;

//	printf("Please enter second string: ");
	// gets(str2); 
	//fgets(str2, 100, stdin); 
	// if(str2[length(str2)-1] == '\n') str2[strlen(str2)-1]=NULL;

	for(i=0;str1[i]!=NULL;i++);
	for(j=0;str2[j]!=NULL;j++)
	{
		str1[i++]=str2[j];
	}
	str1[j]=NULL;

	printf("Concatenated string is: %s",str1,str2);

	return 0;
}
