#include <stdlib.h>
#include<time.h>
#include<stdio.h>
#define MAX 70000


void selection_sort(int *,int);
//void print_oftersort(int *,int );
void bubble_sort(int *,int);
void quick_sort(int*,int,int);
int GetRand(int min,int max);
int arr[MAX];

main ()
{

	int i,r,q,n,x;
	n=sizeof(arr)/sizeof(arr[0]);
//	printf("random variabuls-->=\n");
	for (i = 0; i <MAX; i++)
	{
		r=GetRand(0,MAX-1);   
		arr[i]=r;
	//	printf("%4d\t",arr[i]);
	//	printf("%d\t",arr[i]);
	}
	//printf("\n");

//	printf("bubble_sort order-->=\n");
//	printf("\n");
	bubble_sort(arr,n);
//	print_oftersort(arr,n);
//	printf("\n");

//	printf("selection_sort order-->=");
//	printf("\n");
	selection_sort(arr,n);
//	print_oftersort(arr,n);
//	printf("\n");

//	printf("quick_sort order------>=");
//	printf("\n");   
	quick_sort(arr,0,n-1);
//	print_oftersort(arr,n); 
//	printf("\n");
}
/*void print_oftersort(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}*/

void bubble_sort(int *a,int p)
{
	time_t t1,t2;
	(void) time(&t1);
	int i,j,temp;
	for(i=0;i<p;i++)
	{
		for(j=0;j<p-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	
	(void) time(&t2);
	printf("\n bubble time1---->=%d\n",(int) (t2-t1));
}
void selection_sort(int *b,int p)
{
	time_t t1,t2;
	(void) time(&t1);
	int i,temp,j;
	for(i=0;i<p;i++)
	{
		for(j=i+1;j<p;j++)
		{
			if(b[i]>b[j])
			{
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
	}
	(void) time(&t2);
	printf("\n selection sort time-->=%d\n",(int) (t2-t1));
}

void quick_sort(int *x,int first,int last)
{
	time_t t1,t2;
	(void) time(&t1);
	int pivot,j,temp,i,n;
        if(first<last)
        {
            pivot=first;
            i=first;
            j=last;
            while(i<j)
            {
                while(x[i]<=x[pivot] && i<last)
                    i++;
                while(x[j]>x[pivot])
                    j--;
                if(i<j)
                {
                    temp=x[i];
                    x[i]=x[j];
                    x[j]=temp;
                }
            }
            temp=x[pivot];
            x[pivot]=x[j];
            x[j]=temp;
            quick_sort(x,first,j-1);
            quick_sort(x,j+1,last);
        }
        (void) time(&t2);
		printf("\nquick sort time-->=%d\n ",(int) (t2-t1));
}


int GetRand(int min,int max)
{
    static int b=0;
    int a;
    if(b==0)
    {
      b=1;
    }
    a=(rand()%(max-min+1)+min);
    return (a);
}

