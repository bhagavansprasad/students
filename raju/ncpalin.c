#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int get_pal(char d[]);

int get_words(char s[],char *p);

int count=0;

main()
{
	char s[100],p[100]=" ";
	int r,l=10,i,j;
	int fd=open("a.txt",0,O_RDONLY);
	do
	{
		r=read(fd,s,l);
		s[r]='\0';
		printf("string:%s\n",s);

		get_words(s,p);
		

		if(s[r-1]!=' ' && s[r-1]!='\n')
		{
			for(i=r-1;s[i]!=' ' && s[i]!='\n';i--);
				
				if(s[i]==' ' || s[i]=='\n')
				{
				
					for(j=0;i<r-1;i++,j++)
					{
						p[j]=s[i+1];
					}																/*	p=&s1[i+1];
																						printf("main p:%s\n",p);
																						break;*/
				    p[j]='\0';
				}	
			
		}	
				
	}while(r==l); 

	printf("No. of Palindromes:%d\n", count);


}
int get_words(char *s,char *p)
{
	char buff[100];
	int i=0,j=0,pal;

	printf("get words p:%s\n",p);

	if(s[i]!=' ' && p[i]!=' ')
	{
		printf("if p i:%d\n",i);
		for(j=0;p[j]!='\0' && p[j]!='\n';j++)
		{
			buff[j]=p[j];
		}

		for(i=0;s[i]!=' ' && s[i]!='\0';i++,j++)
		{
			if((s[i]>=48 && s[i]<=57)||(s[i]>=65 && s[i]<=90) || (s[i]>=97 &&
						s[i]<=122))
			{
				buff[j]=s[i];	
			}
		/*	else 
				break;*/
	
		}

		buff[j]='\0';

		printf("p buff:%s\n",buff);

		pal=get_pal(buff);

		if(pal==1)
		{
			count++;
			printf("p count:%d\n",count);
		}
	}

	for(   ;s[i]!='\0';i++)
	{
		for(;s[i]==' ';i++);
		
		for(j=0;s[i]!=' ' && s[i]!='\0';i++,j++)
		{
			if((s[i]>=48 && s[i]<=57)||(s[i]>=65 && s[i]<=90) || (s[i]>=97 &&
						s[i]<=122))
			{
				buff[j]=s[i];	
			}
		/*	else 
				break;*/
		}
		
		buff[j]='\0';

		printf("main buff:%s\n",buff);


		pal=get_pal(buff);

		if(pal==1)
		{
			count++;
			printf("main count:%d\n",count);

		}	
		if(s[i]=='\0' || s[i]=='\n')
			break;
		
	}
}	


int get_pal(char *d)
{
	int i,j;

	printf("d:%s\n",d);
	printf("strlen:%d\n",strlen(d));
	printf("sizeof:%d\n",sizeof(d));

	for(i=0;d[i]!='\0'  && d[i]!='\t' && d[i]!='\r' && d[i]!='\n';i++)
	{
		printf("d[%d]:%c\t",i,d[i]);
	}
	printf("\n");
	
	j=i-1;


	for(i=0/*,j=strlen(d)-1*/;tolower(d[i])==tolower(d[j]) ;i++,j--)
	{
		
		if(i>=j)
		{
			printf("palindrome\n");
			return 1;
		}
	}	

	if(i<j)
	{
		printf("Not a Palindrome\n");	
		return 0;
	}	
}		
