#include<stdio.h>
#include<string.h>

int main()
{
    char *str1 = "India";
    char *str2 = "BIX";
    char *str3;
    str3 = strcat(str1, str2);
    printf("%s %s\n", str3, str1);
    return 0;
}
