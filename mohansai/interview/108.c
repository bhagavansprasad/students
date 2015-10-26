#include<stdio.h>
int main()
{
    char *str = "cat";
    while(*++str != NULL)
    {      
        switch(*str)
        {
             case 'c': printf("%c",*++str);
             break;
             case 'a':printf("%c",*++str);
             break;
             case 't': printf("%c",*++str);
        }
    } 
    return 0;
}
