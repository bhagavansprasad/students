#include<stdio.h>
#include<string.h>
char string[100]="madam is non mom 1234321";
int string_polindrome(char *str)
{
  int i,len;
  len=strlen(str);
  for(i=0;i<len/2;i++)
  {
    if(*(str+i)!=*(str+len-i-1))
	      return 0;
  }
  return 1;
}
void main()
{
  //char string[100]="madam is non mom";
  int i,j,k,count=0;
  char p[10]=" ";
  for(i=0;*(string+i)!='\0';i++)
  {
    for(j=i,k=0;string[j]!=' ';j++,k++)
	{
	  p[k]=string[j];
	  if(string[j]=='\0')
	     break;
    }
	p[k+1]='\0';
	i=j;
	if(string_polindrome(p))
	{
	   count=count+1;
	}  
	
  }	
  printf("Number of palindromes in a given string:%d\n",count);
}  


