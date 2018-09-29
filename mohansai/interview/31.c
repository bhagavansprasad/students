#include "stdio.h"
int main()
{
	enum numbers{ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN };
	int count;
	for(count=0; count<7; count=count+4)
	{
		prientf("%s,", numbers(count));
	}
	return 0;
}


