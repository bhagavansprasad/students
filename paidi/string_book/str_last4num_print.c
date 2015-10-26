#include <stdio.h>
#include <string.h>

int main(void)
{
   char text[] = "This is a string";
   char *ptr;
   int len = strlen(text);
   ptr = &text[len-6];
    printf("%s\n",ptr);
   //printf("%s\n",(&text[len - 6]));
   return 0;
}

