#include<stdio.h>
int i,t;
main()
{
	char a[50]="  B haritha btech ece kadapa   ";
	t=get_word_count(a);
	printf("%d",t);
}
int get_word_count(char*p)
{
	int w=0,i;
	for(i=0;p[i]!='\0';i++)
	{
		while(p[i]==' ')
			i++;
		
			if(p[i]!=' ' && p[i]!='\0')
				w++;
		
		while(p[i]!=' ' && p[i]!='\0')
			i++;


		//printf("%d\n",w);

	}
	return w;

}
