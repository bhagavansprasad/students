#include "stdio.h"

#define MAX 5

struct students
{
	char name[10];
	char address[20];
	int  age;
	int  class;
};

void selection_sort(struct students *b);
int main()
{
	int i;
	struct students b[5] ={ 
				{ "mohan", "10-13-507",5,5 },
				{"saketh","10-13-506",30,5},
	 			{"ram",   "10-13-505",20,5},
				{"vachna","10-13-504",15,5},
				{"deeru", "10-13-503",10,5},
			      }	;
	
	/*for( i = 0 ; i < MAX ; i++ )
	{
		printf("name:-  %s\t",b[i].name);
		printf("adderss:- %s\t",b[i].address);
		printf("age:-   %d\t",b[i].age);
		printf("class:- %d\t", b[i].class);
		printf("\n\r");
	}*/
	
	selection_sort(b);
}

void selection_sort(struct students *b)
{
	int i,j,temp;	

	for( i = 0 ; i < MAX ; i++)
	{
		for( j = 0 ; j < MAX-1	; j++)
		{
			if(b[i].age < b[j].age)
			{		
		         b[i] =  b[j];			
			
				 //temp     =  b[i].age;
				// b[i].age =  b[j].age;			
				 //b[j].age =  temp;
			}
		}
	}	

			

	for( i = 0 ; i < MAX ; i++ )
	{
		printf("name:-  %s\t",b[i].name);
		printf("adderss:- %s\t",b[i].address);
		printf("age:-   %d\t",b[i].age);
		printf("class:- %d\t", b[i].class);
		printf("\n\r");
	}
}

