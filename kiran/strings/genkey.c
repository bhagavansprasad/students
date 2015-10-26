#include <stdio.h>

int main()
{
int i = 0;
	char s[100][200] = {  {"Apple"},{"apple"}, {"Ball"}, {"ball"},{"Cat"}, {"cat"},{"dog"}, {"Dog"},{"Zinc"},{"zinc"}
					   };
	int t = 0;
	for( i = 0; i < 10;i++)
	{
	t = gen_key(s[i]);
	printf(" %c === %d\n",s[i][0],t);
	}
}
int gen_key(char *s)
{
	int i = 0,j = 0, c = 0, d = 0,k = 65, l =97;
	for(i = 65;i <= 90;i++)
	{
		if(k != i)
			c++;
		if(s[0] == i)
			return c;
	}
	for(j = 97; j <= 122; j++)
	{
		if(l != j)
			d++;
		if(s[0] == j)
			return d;
	}
}
