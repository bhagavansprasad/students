#include <stdio.h>
#include <string.h>
main()
{
char *p,str[100]="      main()";
strcpy(str,str+strspn(str,"\t"));
puts(str);
}
