#include<stdio.h>

int main()
{
	
//	int char_count(char *);
//	int word_count(char *);
//	int line_count(char *);

	
	
	
	int i,j,k;
    char arr[100]="I am learning C";

	i=char_count(arr);
	j=word_count(arr);
	k=line_count(arr);

	printf("\nCharacter count is %d \n",i);
	printf("worrd count is %d \n",j);
	printf("line count is %d \n",k);

	return 0;
}
