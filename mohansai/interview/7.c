#include <stdio.h>

int main()
{
    FILE *vp;
    char s[100];

    vp=fopen("outfile","r");
    if (!vp)
        return 1;
    while (fgets(s,100,vp)!=NULL)
        printf("%s",s);
    fclose(vp);
    return 0;
}


