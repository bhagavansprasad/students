//#include<stdio.h>
//main()
//{
//char *p;
//char *p=(char)malloc(100);
//printf("%s",p);
//}
#include<stdio.h>

int main()
{
    static char *s[] = {"black", "white", "pink", "violet"};
    char **ptr[] = {s+3, s+2, s+1, s}, ***p;
//	printf("%s%s%s%s",**ptr);
    p = ptr;
//	printf ("%d",p);
    ++p;
    printf("%s", **p+1);
    return 0;
}
