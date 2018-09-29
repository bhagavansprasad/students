#include<stdio.h>
#include<string.h>
#include<stdlib.h>

main()
{
    char buff[ ]="how are you";
    int i,w=0;
    for(i=0 ;buff[i]!='\0'; i++)
    {
        if(buff[i]==' ')
        {
            for( ;buff[i]==' '; i++);
        }
        if(buff[i]!=' ')
        {w++;

            for( ;buff[i]!=' ';i++);
        }
        
    }
    printf("%d\n",w);
}

