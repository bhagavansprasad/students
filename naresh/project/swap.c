#include<stdio.h>
void swapv(short int *sh1,short int *sh2);
void swap(char *pc1,char *pc2);
void swapq(char *pch1,char *pch2);

main()
{
	int a=0x12131415;
	short *sh1=(short int *)&a;
	short int *sh2;
	sh2=sh1+1;

	printf("%x",*sh1);
	printf("%x\n",*sh2);

	swapv(sh2,sh1);
	printf("%x",*sh1);
	printf("%x\n",*sh2);

	char *pc1=(char *)sh1;
	char *pc2;
	pc2=pc1+1;
	printf("pc1 :%x\n",*pc1);
	printf("pc2 :%x\n",*pc2);

	swap(pc1,pc2);
	printf("pc1 :%x\n",*pc1);
	printf("pc2 :%x\n",*pc2);


	char *pch1=(char *)sh2;
	char *pch2;
	pch2=pch1+1;
	printf("pch1 :%x\n",*pch1);
	printf("pch2 :%x\n",*pch2);

	swapq(pch1,pch2);
	printf("pch1 :%x\n",*pch1);
	printf("pch2 :%x\n",*pch2);

		return 0;
}
void swapv (short int *sh1,short int *sh2)
{
	short int t;

	t=*sh1;
	*sh1=*sh2;
	*sh2=t;

}

void swap (char *pc1,char *pc2)
{
	int s;
	s=*pc1;
	*pc1=*pc2;
	*pc2=s;
}

void swapq (char *pch1,char *pch2)
	{
		int r;
		r=*pch1;
		*pch1=*pch2;
		*pch2=r;
	}

