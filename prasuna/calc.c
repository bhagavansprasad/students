#include "stdio.h"

main()
{
	char str[100] = "add 10 20";
	int result = 0;

	result = caliculator(str);

	printf("result :%d\n", result);
}

int caliculator(char *str)
{ 
	int sum=0;
    static int i;
	char cmd[100];
	char firstarg[100];
	char secondarg[100];
	
	for(i=0;str[i]!= ' ';i++)
	{
	sprintf(cmd,"%c",(char)str[i]);
	printf("%s",cmd);
    }
	printf("\n\n");
//	printf("i:%d\n",i);
    
   for(i=4;str[i]!=' ';i++)
   {
   sprintf(firstarg,"%c",(int)str[i]);
   printf("%s",firstarg);
   }
   printf("\n\n");

   for(i=7;str[i]!='\0';i++)
   {
   sprintf(secondarg,"%c",(int)str[i]);
   printf("%s",secondarg);
   }
   printf("\n");

   if(strcmp(cmd,"add") == 0)
   {
//   	sum = firstarg + secondarg;
	sum = (atoi(firstarg))+ (atoi(secondarg));
	}
	return sum;
}

