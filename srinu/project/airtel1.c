#include <stdio.h>
#include <fcntl.h>
#include <string.h>
main()
{
	char c1[100] = "src", c2[100] = "you are left with only";
	char s[10000], s1[100] = "", b[100], b1[100] = "";
	int fd1=0,fd2=0;

	system("wget http://www.airtel.in/smartbyte-s/page.html");
	fd1=open("page.html",0,O_RDONLY);

	do
	{
		read(fd1, s, 5);
		if(s==c1)
		{
			do
			{
				read(fd1, s, 10000);
				strcat(s1, s);
				if(s[0] == '"')
				{
					break;
				}
			}while(1);
		}	
		else
		{
			lseek(fd1,-4,SEEK_CUR);
		}  

	}while(1);
	system("wget s1");
	fd2=open("index.html",0,O_RDONLY);
	do
	{
		read(fd2,b,22);
		if(b==c2)
		{
			do
			{
				read(fd2,b,1);
				if(b=='<')
				{
					do
					{
						read(fd2,b,1);
						if(b=='/')
						{
							break;
						}
					}while(b!='>');
				}	
				else
				{
					strcat(b1,b);
				}
			}while(1);
		}
		else
		{
			lseek(fd2,-21,SEEK_CUR);
		}	

	}while(1);

	strcat(b1,c2);
	printf("%s\n",b1);
}	









