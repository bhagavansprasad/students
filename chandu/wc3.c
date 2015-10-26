#include<stdio.h>
#include<string.h>

int word_count(char *p);
int line_count(char *p);  

	char strings[10][100]={ 
		{"    hello"},
		{"aura networks"},
		{"    bommanahalli  bang street"},
		{"banglore"},
		{"    banglore   abcd 1234  a  "}
	};

	main()
	{ 
		int wcount = 0, linecount=0;
		int i = 0;

		for(i = 0; i < 5; i++)
		{
			wcount = word_count(strings[i]);
			linecount=line_count(strings[i]);
			printf("string :%s, wcount :%d\n", strings[i], wcount);
			printf("string :%s,linecount :%d\n", strings[i], linecount);
		}
	}


