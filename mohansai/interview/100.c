#include <stdio.h>
int x(char *chr)
{
    chr=(char *) malloc(10*sizeof(char));
    *chr="welcome";
}
int main(int argc, char *argv[])
{
    char *chr="C programming";
    x(chr);
    printf("%s\n",chr);
    return 0;
}
