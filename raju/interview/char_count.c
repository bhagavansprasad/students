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

	//	printf("d:%d\t dc:%c\n",d,d);

	//	printf("%c\n",buff[k+1]);

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
char_count.c
	c=i;


//	printf("%c\t %d\n",c,c);
	
	c=65;

//	printf("c:%c\n",c);

	for(A=48;A<=57;count++,A++)
	{
		
		if(count==i)
		{	
		
	//	printf("A:%d\t Ac:%c\n",A,A);
		return A;
		}	
			

	}

}	
