#include <stdio.h>
int main()
{
	char s[20] = {"VINOTH"};
	int t = 0;
	t = get_vowel(s);
	printf("In %s string %d vowels are there\n",s,t);

}
int get_vowel(char *s)
{
	int i = 0, c = 0;
	printf("in %s the vowels are = ",s);
	for(i = 0; s[i]!='\0';i++)
	{
		if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
		{
			c++;
			printf(" %c\n",s[i]);
		}
	}
	printf("\n");
	return c;
}
