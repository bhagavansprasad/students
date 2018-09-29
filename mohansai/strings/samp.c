#include "stdio.h"

void convert(char *s);
void atoupper(char s);

void main()
{
        char name[] = "MOHANSAI";

        convert(name);

        printf("name--> %s\r\n", name);
}

void convert(char *s)
{
        int i;

        for( i = 0 ; s[i]!='\0' ; i++)
        {
                atoupper(s[i]);

                printf("convert--> %c\r\n",s[i]);
        }
}

void atoupper(char s)
{
        if( s >= 'A' && s <= 'Z' )
        {
                s=s+32;
        }
        printf("chracter--> %c\r\n",s);
}

