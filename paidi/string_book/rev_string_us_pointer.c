#include <stdio.h>
#include <string.h>
/*
main()
{
	char str1[10]="paidi";
	char rev[10];
	int i= -1,j=0;

	while(str1[++i]!='\0');

	while(str1[i] >= 0)
	{
		rev[j++] = str1[--i];
		printf("%u %c\n",&str1[i],str1[i]);
	}
	rev[j]='\0';
	printf("%s\n",rev);
	return 0;
}

*/
 
main()
{
	char str[10]="paidi";
	char rev[10];
	char *p,*p1;
	p = str;
	p1 = rev;
	int i = -1;
	while(*p)
	{
		p++;
		i++;
	}
	while(i>=0)
	{
		p--;
	   *p1 = *p;
		p1++;
		--i;
	}
	*p1 = '\0';
	printf("%s\n",rev);
}


#if 0
#include <stdio.h>

int main()
{
  char ptr[10] ="paidi";
  char arr[10];
  
  int j=0,i=0,n=0;
  n = strlen(ptr);
  for(i=n; i>0 ;i--)
  {
    arr[j]= ptr[i];
	j++;
	
  }
  arr[j] = '\0';
  printf("%s\n",arr[10]);
}

#endif
