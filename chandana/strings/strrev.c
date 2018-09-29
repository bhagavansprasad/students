#include <string.h>
int main() 
{
	char str[10]="chandana";
	char rev[10];
	char *p1,*p2;
	p1 = str;
	p2 = rev;
	int i=-1;

	while(*p1)
	{
		p1++;
		i++;
	}
	
	while(i>=0)
	{
		p1--;
		*p2 = *p1;
		p2++;
		--i;
	}
	*p2='\0';
	printf("========== %s\n",rev);
}
