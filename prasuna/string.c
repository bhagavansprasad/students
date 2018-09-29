#include <stdio.h>
#include <string.h>
main()
{

	char buff[100]="AuRa Networks Institute";

	int i;
	int count=0;


	count=get_cap_case_count(buff);
	printf("%s, uletter:%d\n",buff,count);

}
int get_cap_case_count(char *str)
{

	int i=0;
	int count=0;

	for(i=0;str[i]!='\0';i++)
	{

		if(str[i]>='a'&&str[i]<='z')
		{
		 count++;
		}
	}
	return count;
}




