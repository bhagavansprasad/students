#include "stdio.h"
int main()
{
  FILE* fp = NULL;
  unsigned char c;
  fp = fopen("test.txt","rb");
  while((c = getc(fp)))
  putchar(c);
  fclose(fp);
  return 0;
}


