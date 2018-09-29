#include <stdio.h>

int values[5][3] = {
    {1, 2, 100},
    {2, 5, 100},
    {3, 4, 100}
};

int main() 
{
    int N,K,p,q,sum,i,j,max=0,x=0;

    N = 5;
    K = 3;

    long int arr[] ={0, 0, 0, 0, 0};

    for(i=0; i < K;i++)
    {
        p = values[i][0];
        q = values[i][1];
        sum = values[i][2];

        arr[p]= arr[p] + sum;
        if((q+1) <= N) 
            arr[q+1]-=sum;
    }

    for(i = 1; i <= N; i++)
    {
        x = x + arr[i];
        if(max < x) 
            max = x;
    }

    printf ("max :%d\n", max);
    return 0;
}

