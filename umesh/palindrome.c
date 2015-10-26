#include<stdio.h>
main()
{
	char s[100]="mom and dad  madam are so great abcdcba     a   ";
	int i,j,b;
	int k;
	int count=0;

	for(i = 0; s[i] != '\0'; i++)
	{
		for(j = i; s[j] !=' '; j++);
		printf("%c",s[j]);

		j = j - 1;

		for(k = 0; k <= j-i && s[j] !=' '; k++)
		{
			if(s[i] == s[j])
			{
				i++;
				j--;
			}
			else
			{
				b=1;
				break;
			}
		}
		if(s[j]!=' ')
		{
			if(b == 1) 
			{
				continue;
			}
			else
			{
				count++;
			}
		}
	}
	printf("-->%d\n",count);
}
