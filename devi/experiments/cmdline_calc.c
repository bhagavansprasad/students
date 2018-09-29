#include <stdio.h>
int main(int argc,char *argv[])
{
	int i=1,j,res = 0,key;
	for(j=0;j<argc;j++)
	{
		printf("-->%s\n", argv[j]);
	}
	switch(atoi(argv[1]))
		{
			if(strcmp(argv[1],"ADD")==0)
			{
			key = 0;
			}
			case 0:

							printf("entered in case\n");
							res = (atoi(argv[i+1]))+(atoi(argv[i+2])); 
							printf("sum-->%d\n",res);
							break;
		}
}

