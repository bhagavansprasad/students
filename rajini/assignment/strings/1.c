#include <stdio.h>
main()
{
	char name[100] = "rajini kanth",c;
	int i=0, count = 0;	
	printf("%s:\n", name );
	printf("enter a character to find  frequency :");
	scanf("%c", &c);
	
	for(i=0;name[i]!='\0';i++)
	{
		if(c==name[i])
			count++;
	}
	
	printf("frequency of  %c = %d\n", c, count);
	return 0;
}


/*#include <stdio.h>
int main(){
   char c[1000],ch;
   int i,count=0;
   printf("Enter a string: ");
   gets(c);
   printf("Enter a character to find frequency: ");
   scanf("%c",&ch);
   for(i=0;c[i]!='\0';i++)
   {
       if(ch==c[i])
           count++;
   }
   printf("Frequency of %c = %d", ch, count);
   return 0;
}
*/


/*#include <stdio.h>
main()
{
 char c;
 printf("enrter a character ");
 scanf("%c \n",&c);
// printf("ASCII value for the cahracter%d",c);
printf("ASCII value of %c = %d",c,c);
}*/
