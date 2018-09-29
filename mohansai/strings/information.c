	
	
	#include <strings.h>

	int strcasecmp(const char *s1, const char *s2);
	int strncasecmp(const char *s1, const char *s2, size_t n);
       
	char *strcat(char *dest, const char *src);
	char *strncat(char *dest, const char *src, size_t n);
       
        int strcmp(const char *s1, const char *s2);
	int strncmp(const char *s1, const char *s2, size_t n);
	
	size_t strlen(const char *s);
	char *strstr(const char *haystack, const char *needle);
	
	char *strncpy(char *dest, const char *src, size_t n);
	char *strcpy(char *dest, const char *src);

		       



	char *index(const char *s, int c);
	char *rindex(const char *s, int c);
	int strcoll(const char *s1, const char *s2);
	char *strfry(char *string);
	char *strpbrk(const char *s, const char *accept);
	size_t strxfrm(char *dest, const char *src, size_t n);


strtok
char *strtok(char *s, const char *delim);
size_t strspn(const char *s, const char *accept);
char *strrchr(const char *s, int c);
char *strchr(const char *s, int c);
size_t strcspn(const char *s, const char *reject);




http://en.wikibooks.org/wiki/C_Programming/Strings



================================================================================
    char *strdup(const char *s); 

strdup - return duplicate copy of string


char *my_strdup(const char *s) 
{
    char *p = malloc(strlen(s) + 1);
    if(p) 
    {
	 strcpy(p, s); 
    }
    return p;
}
   1. It tries to allocate enough memory to hold the old string (plus a null character to mark the end of the string).
   2. If the allocation failed, it sets errno to ENOMEM and returns NULL immediately (setting of errno to
	 ENOMEM is something malloc does so we don't need to explicitly do it in our strdup).
   3. Otherwise the allocation worked so we copy the old string to the new string and return the new address 
	(which the caller is responsible for freeing).

================================================================================

char *strsep(char **stringp, const char *delim);

#include <string.h>
#include <stdio.h>
int main()
{
    char *one=(char *)malloc(12);
    char *res;
    char **two=&one;
    strcpy(one,"Hello,World");
    res=strsep(two,",");
    if(strcmp(res,"hello"))
    printf("%s\n",res);      
    return 0;
}

#include <stdio.h>
#include <string.h>
int main()
{
  char *x, *y;
  int i = 0;
  x =(char *) malloc((size_t)128);
  strcpy(x,"This is a test;Testing 1, 2, 3;Done");
  printf ("x=%x\ni=%d: %s\n", &x, i, x);
  while (y = strsep(&x, ";")) {
    printf("y=\"%s\"\n", y);
    printf("x=%x\ni=%d: %s\n", &x, ++i, x);
  }
  return 0;
}


================================================================================



#include <stdio.h>
#include <string.h>

void main(void)
 {
   char buffer[64] = "Jamsa's 1001 C/C++ Tips";
   char target[64];

   int length;

   length = strxfrm(target, buffer, sizeof(buffer));

   printf("Length %d Target %s Buffer %s\n", length,
     target, buffer);
 }

 ...

















