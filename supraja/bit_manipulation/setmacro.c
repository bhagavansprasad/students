
#include<stdio.h>
#define setbit(n,pos)  printf("%d",(n|(1<<(pos-1))));
//void setbit(int , int);

	int main()
	{
		unsigned int a=10;
		int c,b=3;
		setbit(a,b);
		return 0;
	}
