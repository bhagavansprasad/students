#include<stdio.h>
main()
{
 
 	char s2[50]="HEMA AURA NETWORKS";

	str_to_lower(s2);

}
int str_to_lower(char *ch)
{

	int i;
	for(i=0;ch[i]!='\0';i++)
	{
		ch[i]=ch[i]+32;
		printf("lower:%c\n",ch[i]);
	}
	return 0;
}
