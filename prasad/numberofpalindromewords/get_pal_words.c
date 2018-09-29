#include"stdio.h"
int rstrlen(const char *s)
{
	int i;
	for(i=0;s[i]!='\0';i++);
	return i;
}
int palin(char *s1)
{
	int i,j,m;
	char s2[10];
	m=rstrlen(s1);
	for(i=0;i<m;i++)
	{
		s2[m-1-i]=s1[i];
	}
   s2[m]='\0';
printf("%s \n",s2);
	for(i=0,j=0;j<m;i++,j++)
	{ 

		if(s1[i]!=s2[j])
	{	
		return 0;
		}	
}
	return 1;
}

int get_nof_pal(char *src)
{
	int i,j,n,c=0;
	char dest[10];
	for(i=0;src[i]!='\0';i++)
	{
		while(src[i]==' ')
			i++;
		for(i,j=0;src[i]!=' '&&src[i]!='\0';j++,i++)
		{
			dest[j]=src[i];
		}
		dest[j]='\0';
		printf("%s \n",dest);
		n=palin(dest);
         printf("%d \n",n);
		if(n==1){
printf("c=%d \n",c);		
	c=c+1;
	}
}

printf("c=%d \n",c);		
	return c;
}


