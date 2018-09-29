#include<stdio.h>

int astrlen (char * p)
{
	int i , l = 0;

	for (i=0; p[i] != '\0'; i++);
	//	{
	//l++;
	//	}

	return(i);
}
