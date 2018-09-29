/*#include<stdio.h>
#include<string.h>
int main()
{
	int b=0,c=0,d=0,i;
	char s[100]={"AAABBBaaa"};
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='A')
		{
			b++;
		}
		else if(s[i]=='B')
		{
			c++;
		}
		else if(s[i]='a')
		{
			d++;
		}
	}
	printf("%d\n",b);
	printf("%d\n",c);
	printf("%d\n",d);
}*/
#include<stdio.h>
#include <malloc.h>
#include <string.h>

int iitoa(int i);

main()
{
	char *s="AAAAAAAABBBBAAAACCCRRRRPPZZZZZ";
	char buff[100] ;
	// output A8B4A4C3R4
	int i=0,j,k= 0,c1;
	char d;

	while(s[i] != '\0')
	{
		for(buff[k] = s[i],c1 = 1 ,j = i+1 ;s[i] == s[j] && s[i] != '\0';j++)
		{
			c1++;
		}
		
		d=iitoa(c1);

		//printf("d:%d\t dc:%c\n",d,d);

	    //printf("%c\n",buff[k+1]);

		buff[k+1] = d;
		k += 2;
		i=j;

	}
		buff[strlen(buff)] ='\0';
	/*	for(i = 0;buff[i] !='\0';i++)*/
			printf("S:%s\n",buff);
}

int iitoa(int i)
{

	char c;

	int A;

	int count=0;

	c=i;


	//printf("%c\t %d\n",c,c);
	
	c=65;

	//printf("c:%c\n",c);

	for(A=48;A<=57;count++,A++)
	{
		
		if(count==i)
		{	
		
		//printf("A:%d\t Ac:%c\n",A,A);
		return A;
		}	
			

	}

}	
