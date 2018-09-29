#include <stdio.h>
int flag =0;
void print(char s1[],char s2[])
{
	flag ++;
	int i=0,j=0,f=0;
	for(i=0;s1[i];i++)
	{
		for(j=0;s2[j];j++)
		{
			if(s1[i]==s2[j])
			{
				f=1;
				break;
			}
		}
		if(f!=1)
			printf("%c\t",s1[i]);
		f=0;
	}
	if(flag < 2)
		print(s2,s1);
}
main()
{
	char s1[10]="maheswar";
	char s2[10]="prasad";
	print(s1,s2);
}
