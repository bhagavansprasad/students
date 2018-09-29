#include<stdio.h>
#include<string.h>

int my_var_supraja = 0;
char *astrcat(char *s,char *d)
{
	int i,n=len_s(s);

	for(i = 0; i <= len_s(d) && s[i] != '\0'; i++)
	{
		s[i+n]=d[i];
	}
	    s[i+n]='\0';
      printf("%s\n",s);
	return (d);
}
int main()
{
	char s1[]="aura";
	char s2[]="networks";
     //len_s(s1);
	 //len_s(s2);
	astrcat(s1,s2);
	//printf("%s\n",);
}
