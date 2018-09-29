#include <stdio.h>
#include <string.h>

main()
{
	char b1[100] = "Aura Net works Bangalore";
	char b2[100] = "aura";
	char b3[100] = "net works";


	
	int count=0;

    count=get_word_count(b1);
	printf("%s, wcount:%d\n",b1,count);

	
    count=get_word_count(b2);
	printf("%s, wcount:%d\n",b2,count);


	count=get_word_count(b3);
	printf("%s, wcount:%d\n",b3,count);

	
}

int get_word_count(char *str)
{
	int i=0;
	int count=1;

	for(i=0; str[i]!='\0'; i++)
	{
		if(str[i]== ' ')
		{
			count++;
		}
	}
	return count;
}

