#include"stdio.h"
#include"string.h"
int astrcspn(char *name1,char *name2);

main()
{

	int i;
	char name1[]="mohansai";
	char name2[]="mOhANSAI";
	
	i=astrcspn(name1,name2);
	
	printf("%d\n",i);
}

int astrcspn(char *name1,char *name2)

{
int j,k;
int count = 0;
for(j = 0 ; name1[j] != '\0' ; j++)
{
	for(k = 0 ; name2[k] != '\0' ; k++)
	{
		if(name1[j]!=name2[k])
		{
			
			continue;
		}		
		
	if(name1[j]==name2[k])
		{
			return(j);
			
		}
	}
	
	}	
return(j);

}
