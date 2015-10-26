#include <stdio.h>
void astrcpy(char s[], char d[]);
void pstrcpy(char *s, char*d);
main()
{
	char s[] = "sai prasad";
	char d[15];
	printf("print the strings before copy%s\t %s\n", s,d);
	printf("print the size of the strings %d\t %d\n", sizeof (s),sizeof (d));
	astrcpy(s,d);
	printf("print the size of the strings after astrcpy \n%d\t %d\n", sizeof (s),sizeof (d));
	printf("print after string copy is %s\t %s\n", s,d);
	pstrcpy(s,d);
	printf("print the size of the strings after pstrcpy\n  %d\t %d\n", sizeof (s),sizeof (d));
	printf("print after string copy is %s\t %s\n", s,d);

}

void astrcpy(char s[], char d[])
{
	int i;
	printf("print the size of the strings in astrcpy :\n%d\t %d\n", sizeof (s),sizeof (d));
	for (i = 0; d[i] = s[i]; i++);

}
void pstrcpy(char *s, char*d)
{
	printf("print the size of the strings in pstrcpy\n  %d\t %d\n", sizeof (s),sizeof (d));
	while(*d = *s)
	{
		d++;
		s++;
	}
}


