#include "stdio.h"
int main()
{
	int rearrange (int n, int *x)
	{
		int i, temp, num;
	    for (num = 0; num < n-1; num++)
    	{
			for (i = num + 1; i < n; i++)
    	    {
				if (*(x + num) < *(x + i))
           		{
           	 		** missing code **
           		}
                return 0;
     	}
	}
	}

A..   temp = *(x + num);  *(x + num) = *( x + i); *(x + i) = temp;

B. temp = &(x + num); &(x + num) = *(x + i); *(x + i) = temp;

C.  temp = &(x + num); &(x + num) = &( x + i);  &(x + i) = temp;

D.   temp = *(x + num); &(x + num) = &(x + i); *(x + i) = temp;
