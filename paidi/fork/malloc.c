#include <stdio.h>
#include <string.h>
main()
{
 char *p=malloc(100);
 printf("%u\n",p);
strcpy(p,"paidiKUMWQravi");
printf("string ---->== %s\n",p);
free(p);
//free(p+6);

printf("charecter ----> %s\n",(p+6));
printf("charecter ----> %c\n",*(p+6));
printf("charecter ----> %c\n",*(p+7));
printf("charecter ----> %c\n",*(p+8));
printf("charecter ----> %c\n",*(p+9));
printf("charecter ----> %c\n",*(p+10));
printf("charecter ----> %c\n",*(p-4));
}



