#include <stdio.h>
int main()
{
    int array[50]={15,100,30,40,50}, size=5, i, largest;

    for (i = 0; i < size; i++)
    largest = array[0];

    for (i = 1; i < size; i++)
    {
        if (largest < array[i])

            largest = array[i];
    }
    printf("\n largest element in array--= %d\n", largest);
    return 0;

}
