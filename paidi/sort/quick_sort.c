#include<stdio.h>
void quick_sort(int [14],int,int);
main()
//void quick_sort(int *,int,int);
{
    int x[14]={10,10,10,2,34,23,56,45,78,43,2,11,22,10};
    int i,size=14;
    quick_sort(x,0,size-1);
    for(i=0;i<size;i++)   
        printf("%d\n",x[i]);
        return 0;
}
void quick_sort(int x[14],int first,int last)
{
        int pivot,j,temp,i;
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
}
