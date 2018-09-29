#include "stdio.h"
int main()
{ 
      unsigned char ch; FILE* fp;
      fp = fopen("myfile.txt","r");
      while((ch=getc(fp)) != EOF)
      printf("%c", ch); fclose(fp); 
}


