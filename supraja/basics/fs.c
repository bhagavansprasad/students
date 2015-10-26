#include<stdio.h>
main()
{
	int t;
	char name[]="aura networks banglore";
	t=get_as_count(name);
	printf("value of t is : %d",t);
}
int get_as_count(char *ptr)
{
	int ac=0,i;
	for(i=0;ptr[i]!='\0';i++)
	{
		if(ptr[i]=='a')
			ac=ac+1;
			}
		return (ac);
}	
