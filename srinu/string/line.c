#include<stdio.h>
#include<fcntl.h>
int main()
{
	int line=0;
	char buff[100]="Aura\n Networks\n Banglore\n"; 
	line=get_line_count(buff);
	printf("%d\n",line);
}
int get_line_count(char *pb)
{
	int i,line=0;
	for(i=0;pb[i]!='\0';i++)
	{
		if(pb[i]=='\n')
			line++;
	}
	return line;
}
