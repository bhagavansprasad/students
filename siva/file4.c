#include<stdio.h>
#include <string.h>
#include <fcntl.h>
#include<stdlib.h>
main(int argc, char *argv[])		
{
   
   char name[]="shiva";
   char name1[]="SHIVA";
   int i;
	
	if(argc <= 1)
	{
		printf("need arguements\n");
	}
	
	printf("argv[1]--> %d \n",argv[1]);	
	
	if(atoi(argv[1]) == 2 )
	{
		
			uppercase(name);
}
	uppercase(char *name)
		for(i=0;name[i]!='\0';i++)
		{
			if(name[i]>=97 && name[i]<=122)
			{
				name[i]-=32;
			}
		}
		   printf("%s\n",name);
	}
	if(atoi(argv[1]) == -1)
	{
		//printf("lower case \n");

		lowercase(name1);
}
lowercase(char *name)

		for(i=0;name1[i]!='\0';i++)
		{
			if(name1[i]>=65 && name1[i]<=91)
			{
				name1[i]+=32;
			}
		}
		printf("%s\n",name1);
	}
}
