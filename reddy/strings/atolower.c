#include<stdio.h>
main()
{
   char atolower(char ex);
	char st [ ] = "A boy CAN DO EVERY THING FOr gIRL";
	char ch ;
        int i;
        for ( i = 0; st[i]; i++)
	  printf("%c ",atolower(st[i]));
}
char atolower(char ex)
{
	int diff = 'a' - 'A';
	if (ex >= 'A' && ex <= 'Z')
	{
		ex += diff;
	}
	return ex;  
}
