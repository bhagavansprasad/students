#include<stdio.h>
#include<string.h>
int word_cunt(char *p);
char a[100] = " hello         aura    networking   in bommanahalli banglore      ";
main()
{
	int t=0;
	t = word_cunt(a);
	printf("%d\n",t);
}
int word_cunt(char *p)
{
	int i=0, count=0;

	for(i=0;p[i]!='\0'; i++)
	{
		if( (p[i]!=' ') && (p[i+1]==' ') )
		{
			count++;
		}


	}
	return(count);
}
