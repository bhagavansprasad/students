#include "stdio.h"
#include"stdlib.h"

main(int argc, char *argv[])
{
	FILE *fs,*fd;
	char ch[1024],ch1[1024];
	int i=0,j=0,flag=1;

	/*	printf("argc    :%d\r\n", argc);
		printf("argv[0] :%s\r\n", argv[0]);
		printf("argv[1] :%s\r\n", argv[1]);
		printf("argv[2] :%s\r\n", argv[2]);
	 */
	fs=fopen(argv[1], "r");

	if(fs==NULL)
	{
		printf("connot open source file");
		exit(1);
	}

	fd=fopen(argv[2], "w");
	if(fd==NULL)
	{
		printf("connot open source file");
		fclose(fs);
		exit(1);
	}

	while(1)
	{
		ch[i]=fgetc(fs);

		if(ch[i] == EOF)
			exit(1);

		else 
		{
			if( ch[i] == '/' && ch[i+1] == '*')
				flag = 0;

			if( ch[i] == '*' && ch[i+1] == '/')
			{	
				i=i+2;
				flag = 1;
			}

			if (flag == 1)
				ch1[j] = ch[i];

			j++;
		}
		fputc(ch1[j], fd);
	}

	fclose(fs);
	fclose(fd);
}
