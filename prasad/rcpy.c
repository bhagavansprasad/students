#include"stdio.h"
#include"stdlib.h"
main(int argc,char *argv[])
{
	char ch;
	FILE *fs,*fd;
	if(argc!=3)
	{
	printf("insufficient arguments ");
	exit(1);
	}
	fs=fopen(argv[1],"r");
	if(fs==NULL)
	{
	printf("FILE doesn't exist");
	exit(1);
	}
	fd=fopen(argv[2],"w");
	while(1)
	{
		if((ch=getc(fs))!=EOF)
		{
			putc(ch,fd);
		
		}
		else 
		break;
	}
	fclose(fs);
	fclose(fd);
}
