#include<stdio.h>
int main()
{
	char name[]="hai hellow how are you";
	int t;
	t=get_word(name);
	printf("num of word is :%d \n",t);
}
int get_word(char *ptr)
{
	int w=1,i;
	for(i=0;ptr[i]!='\0';i++)
	{
		if(ptr[i]==' ')
			w=w+1;
	}
	return (w);
}

