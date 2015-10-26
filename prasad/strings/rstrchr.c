#include"stdio.h"
#include"string.h"
char *rstrchr(const char *s,int c)
{
	while(*s!='\0')
	{
		if(*s==c)
			return s;
			s++;
	}
	return s;
}
int main()
{
	char str[]="ramprasad";
	char *ch;
	ch=rstrchr(str,'d');
	if(ch!=NULL)
	{
		printf("\n %c \n",*ch);
		return 0;
	}
	if(ch==NULL)
		printf("There is no such a charecter in a given string");
}

