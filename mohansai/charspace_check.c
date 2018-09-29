#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int con (int *s);
int astrcmp( char *name1 , char *name2 );
int get_results(char *ptr);

int add(int *num);

char astrupper(char *a);

char strings[][100] = 
{
	"add 8 3",
	"add 7 5",
	" add      5       10",
	" add      5a       10",
	"            add      578       10",
	"            add      578       20             ",
};

main()
{
	int i;
	int count = 0;
	int retval = 0;
	//printf("hi");

	for(count = 0; count < sizeof(strings)/100; count++)
	{
		retval = get_results(strings[count]);

		printf("%d-->%s -->%d\r\n", count+1, strings[count], retval);
	}
}


int get_results(char *ptr)
{
	int i , t=0 , j=0 , k=0 , l ,m , con=0 , n , s ;

	char a[10];

	int num[10];

	char b[]= "ADD";

	for(i = 0 ; ptr[i] == ' '; i++ ); /*skips initial spaces*/

	for(; (a[j]=ptr[i]) != ' '; i++, j++); /*copies operation command*/

	a[j] = '\0';

	astrupper(a);	/* converting	case to upper	*/		

	//printf("%s\r\n", a);

	for ( s =  i ; ptr[i] != '\0' ; i++ )
	{
		for( ; ptr[i] == ' ' && ptr[i] !='\0' ; i++ );

		t = 0;
		for( ; ptr[i] != ' ' && ptr[i] !='\0' ; i++ )
		{
			if (ptr[i] >= '0' && ptr[i] <='9')
			{
				
				t  = t * 10 +(ptr[i]-'0');

				//	printf("%d",t);
			}
			else
			{
				if (ptr[i] >= 'a' && ptr[i] <='z' || ptr[i] >= 'A' && ptr[i] <='Z'  )   
				{
					return -1;
				}
			}
		}
		num[k++]=t;
	}

	/* this  function is a colling  function  of string compiration */


	n=astrcmp(a,b);  
	if(n==0)
	{
		l=add(num);
		return(l);
	}
}
//************* This part is function part *****************************");


/* this function is to add to array integers */

int add (int *num)	
{
	int m;

	m =num[0]+num[1];
	//printf("%d",m);
	return(m);
}

/* this function is to convert the string from lower case to upper case */

char astrupper(char *name)       
{
	int i;

	for( i = 0 ; name[i] != '\0' ; i++ )
	{
		if(name[i] >= 'a' && name[i] <= 'z')
		{
			name[i]=name[i]-32;
		}

	}
}


/* this function is to compare the string  */


int astrcmp( char *name1 , char *name2 )
{
	int j;

	for( j = 0 ; name1[j] != '\0' && name2[j] != '\0' ; j++ )
	{

		if( name1[j] != name2[j] )

		{

			return ( name1[j] - name2[j]);
		}

	}	
	return ( name1[j] - name2[j]);

}



