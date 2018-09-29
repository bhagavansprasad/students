<<<<<<< array_using_concat.c
/*
#include<stdio.h>
int main()
=======
#include <stdio.h>
#include <string.h>
main()
>>>>>>> 1.2
{
	char str1[10]="paidi";
	char str2[10]="kumar";
	int n=0,i;
	n = strlen(str1);
	//for(i=0;str1[n+i]=str2[i];i++)
	for(i=0;str1[n+i]=str2[i];i++);
	printf("concurent-->= %s\n",str1);
}

/*#include<stdio.h>
  int main()
  {

  char str1[100]="paidi";
  char str2[100]="kumar";
  int i=0,j=0;

  while(str1[i]!='\0')
  {
  i++;
  }
  while(str2[j]!='\0')
  {
  str1[i] = str2[j];   
  i++;
  j++;
  }
  str1[i] = '\0';

  printf("string cat---->=%s\n",str1);
  }

<<<<<<< array_using_concat.c
*/
=======

 */

>>>>>>> 1.2

/*
#include<stdio.h>

void stringConcat(char[],char[]);
int main(){

char str1[100]="paidi";
char str2[100]="kumar";
int compare;
stringConcat(str1,str2);
printf("String after concatenation: %s",str1);
return 0;
}

void stringConcat(char str1[],char str2[]){
int i=0,j=0;


while(str1[i]!='\0'){
i++;
}

while(str2[j]!='\0'){
str1[i] = str2[j];   
i++;
j++;
}

str1[i] = '\0';
}
<<<<<<< array_using_concat.c
*/

#include<stdio.h>
#include<string.h>
main()
{
  char str[10]="paidi";
  char str1[12]="kumar";
  int i=0,n=0;
  n=strlen(str);
  for(i=0;str[n+i]=str1[i];i++);
  printf("%s\n",str);
}
=======
 */
>>>>>>> 1.2
