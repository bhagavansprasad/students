#include<stdio.h>
#include<string.h>

int main()
{

	char temp[100];
	char src[100]="hello";
	char dest[100];
	char s[]="0123456789";
	int i,len;

	memset(temp,'\0',sizeof(temp));
	printf("temp data after setting to NULL char\n");
	for(i=0;i<100;i++)
		printf("%c ",temp[i]);
	printf("\n");

	memset(temp,56,sizeof(temp)-1);
	printf("temp data after setting to 8(ascii value of 56)\n");
	len = strlen(temp);
	temp[len]='\0';
	for(i=0;i<len;i++)
		printf("%d ",temp[i]);//printing integer values

	printf("\n");
	printf("temp:%s\n",temp);// printing acsii values

	memcpy(dest,src,sizeof(src));
	printf("Data in dest after memcpy %s\n",dest);

	memmove(dest," He llo world",5);
	printf("Data in dest after memmove %s\n",dest);

	return 0;
}


/*memset()
Syntax:

#include <string.h>
void *memset( void *str, int ch, size_t n );


Description:
The function memset() copies ch into the first 'n' characters of str, and returns str. memset() is useful for intializing a section of memory to some value. For example:

memset(array, '\0', sizeof(array) );

it is a very efficient way to set all values of array to NULL.

memcpy()
Syntax:

#include <string.h>
void *memcpy( void *dest, const void *src, size_t n );


Description:
The function memcpy() copies 'n' characters from the array 'src' to the array 'dest'. memcpy() returns 'dest'. The behavior of memcpy() is undefined if 'src' and 'dest' overlap.
memmove()
Syntax:

#include <string.h>

void *memmove( void *dest, const void *src, size_t n );

Description:
The memmove() function is similer to |memcpy() function, except that it works even if 'src' and 'dest' memory areas overlap.
*/
