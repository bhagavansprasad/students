#include<stdio.h>
#include<string.h>
int get_wordcount(char *a);
int i=0, wordcount=0, w, count= 0;
char a[50]= "hello aura networks";
main()
{ 
	w=get_wordcount(a);

	printf( "%d\n",w);
}
int get_wordcount(char *a)
{
	for(i=0;a[i]!='\0';i++)
	{
		if (a[i]==' ' ||a[i]=='\n')
		{ 
			while(a[i]==' ');
			{ 
				i++;
			}

			count++;
		}
	}
	wordcount++;
	return (count);
}


