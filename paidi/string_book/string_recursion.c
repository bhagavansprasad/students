#include<stdio.h>
#define MAX 100
char* getReverse(char[]);

int main()
{
    char str[MAX]="paidikumar";
	char*rev;

    rev = getReverse(str);

    printf("Reversed string is: %s\n",rev);
    return 0;
}

char* getReverse(char str[])
{
    static int i=0;
    static char rev[MAX];

    if(*str)
	{
         getReverse(str+1);
         rev[i++] = *str;
    }
    return rev;
}
