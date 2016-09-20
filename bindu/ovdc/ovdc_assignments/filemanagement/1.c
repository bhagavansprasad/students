
#include<stdio.h>

int main()
{
	FILE *fp;
	int count = 0,word = 0,n = 216;
	char s;
	

	fp = fopen("myown.txt","w");
	int i;
	for(i = 0;i <= 0Xff;i++)
	{
		fprintf(fp,"%c ",i);
	}
	fclose(fp);

	fp = fopen("myown.txt","r");
	int c = 0;
	
	while(c != EOF)
	{
		c = fgetc(fp);
		count++;
		if(c == ' ')
		{
			if(n == word)
			{
				
			}
			word++;
		}
	}
	word = word + 1;
	printf("number of bytes : %d\n",count);
	//printf("number of words : %d\n",count/2);
	printf("number of words : %d\n",word);


	fseek(fp,n,SEEK_SET);
	s = fgetc(fp);

	printf("%c\n",s);
	fclose(fp);
	return 0;
}
