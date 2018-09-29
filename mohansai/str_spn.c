#include"stdio.h"
#include"string.h"
int astrspn(char *name1,char *name2);

main()
{

	int i;
	char name1[]="mohansai";
	char name2[]="mohansai";

	i=astrspn(name1,name2);

	printf("%d\n",i);
}
int astrspn(char *name1,char *name2)

{
int i,j;
int count = 0;
for(i = 0 ; name1[i] != '\0' ; i++)
{
	for(j = 0 ; name2[j] != '\0' ; j++)
	{
		if(name1[i]==name2[j])
		{
			count++;
			break;
		}
	}	
	
	if(name1[i]!=name2[j])
		{	
			return (count);
		}

		
}
return(count);
}
