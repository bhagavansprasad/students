#if 0
#include <stdio.h>
#include<stdlib.h>
#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int max)
int strindex(char source[], char searchfor[]);
char pattern[] = "ould";
/* pattern to search for */
/* find all lines matching pattern */

int main()
{
	char line[MAXLINE];
	int found = 0;
	while (getline(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	return found;
}
/* getline: get line into s, return length */
int getline(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
	int i, j, k;
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}
#endif

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLENGTH 100

int main(int argc, char **argv)
{
	char line[100];
	int l_no = 0;

	if(argc == 1)
	{
		printf("File is not specified\n");
		exit(0);
	}

	if(argc < 2)
	{
		printf("Word not specified\n");
		exit(0);
	}

	FILE *fptr = fopen(argv[1],"r");

	while(fgets(line,MAXLENGTH,fptr) != 0)
	{
		l_no++;
		if(strstr(line,argv[2]))
			printf("%d : %s\n",l_no,line);
	}
	return 0;
}
