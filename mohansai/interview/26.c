 #include <stdio.h>
int main()
{ 
	  FILE *fp;
      unsigned char ch; 
      fp = fopen("test.txt","r");
      while((ch=fgetc(fp)) != NULL)
      printf("%c", ch); fclose(fp); 
}


