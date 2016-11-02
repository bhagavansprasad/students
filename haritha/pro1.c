#include <stdio.h>
int main(int argc,char *argv[])
{
	int i=1,k=1,a=1,b=1,c=1,j,res = 0;

	for(j=0;j<argc;j++)
	{
		printf("-->%s\n", argv[j]);
	}
	switch(atoi(argv[0]))
	{
		if(strcmp(argv[1],"add")==0)

		case 0:

			res = (atoi(argv[i+1]))+(atoi(argv[i+2])); 
			printf("sum-->%d\n",res);
			//break;



		case 1:
			if (strcmp(argv[1],"sub")==0)
				res=(atoi(argv[k+1])-atoi(argv[k+2]));
			printf("sub--->%d\n",res);
			
		case 2:
			if (strcmp(argv[1],"mul")==0)
				res=(atoi(argv[a+1])*atoi(argv[a+2]));
			printf("mul--->%d\n",res);
		case 3:
			if (strcmp(argv[1],"div")==0)
				res=(atoi(argv[b+1])/atoi(argv[b+2]));
			printf("div--->%d\n",res);
			
		case 4:
			if (strcmp(argv[1],"mod")==0)
				res=(atoi(argv[c+1])%atoi(argv[c+2]));
			printf("mod--->%d\n",res);
			
	}

}

