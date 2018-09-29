#include <stdio.h>
char strings[10][100] =  {
	"The arguments dest and src point to the",
    " Run Raja Run",
	"Run ",
	" R ",
    " ",
    "",
	" as long as the team works "
};

int get_words_count(char *ptr)
{
	int i, wc=0;

	printf("-->In function ptr :%s\n", ptr);

	for (i = 0; ptr[i] != '\0'; i++)
	{
		if ( ptr[i] != ' ' && ptr[i+1] == ' ' )
			wc += 1;

		if ( ptr[i] != ' ' && ptr[i+1] == '\0' )
			wc += 1;
	}

	printf("-->In function wc :%d\n", wc);

	return wc;
}

main()
{
	int i;
	int word_count = 0 ;

	for (i = 0; i < 7; i++)
	{
		printf("-->%s\n", strings[i]);

		word_count = get_words_count(strings[i]);

		printf("-->In main wc :%d\n\n", word_count);
	}
}


#if 0
	for (j = 0; j < 7; j++)
	{
		printf("-->%s\n", strings[j]);

		r = strings[i];

		for (i = 0; r[i] != '\0'; i++)
		{
			if ( r[i] != ' ' && r[i+1] == ' ' )
				wc += 1;

			if ( r[i] != ' ' && r[i+1] == '\0' )
				wc += 1;
		}
		printf ("%d \n", wc);
	}

	for (i = 0; R[i] != '\0'; i++)
	{
		if ( R[i] != ' ' && R[i+1] == ' ' )
			wc += 1;

		if ( R[i] != ' ' && R[i+1] == '\0' )
			wc += 1;
	}
#endif



