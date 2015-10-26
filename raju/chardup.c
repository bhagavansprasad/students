#include<stdio.h>
#include<string.h>
main()
{
	char s[100]="Ananth";
	int i=0,j=0,n;
	n=strlen(s);

	for(i=0;i<n;i++)
	{
		                                                //	if(s[i]!='\0'){
		printf("for i:%d\t j:%d\n",i,j);
		for(j=i+1;j<n;j++)
		{

			printf("for2 i:%d\t j:%d\n",i,j);
			if(s[i]==s[j] || s[i]-s[j]==32 || s[j]-s[i]==32)
			{
				printf("if i:%d\t j:%d\n",i,j);
				s[j]='\0';
			}

		}
		                                              //	}
	}
	for(i=0;i<n;i++)
	{
		printf("s:%c\n",s[i]);
	}	
}	

