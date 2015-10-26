#include"sys/types.h"
#include"sys/stat.h"
#include"fcntl.h"
#include"stdio.h"
#include "stdlib.h"
void main()
{
	int fd;
	int retval=0;
	char buffer[1024];
	int nw=0;
	int sl=0;
	int cl=0;
	int nint=0;
	int nln=0;
	int nch=0;
	int i=0;

	fd=open("t.txt",O_RDONLY);

	while(1)
	{
		printf("\n");
		retval=read(fd,buffer,200);

		buffer[retval]='\0';

		printf("read:%d no:of bytes from file \n",retval);

		for(i = 0 ;buffer[i]!='\0';i++)
		{
			if((buffer[i]>=65)&&(buffer[i]<=91))
				cl++;
			else if((buffer[i]>=97)&&(buffer[i]<=123))
				sl++;
			else if((buffer[i]>='0')&&(buffer[i]<='9'))
				nint++;

			else if(buffer[i]==' ')
				{
					while(i<1024)
						{
							if(buffer[i]==' ')
							i++;
							else break;
						}
					nw++;
				}

			else if(buffer[i]=='\n')
			{
				nln++;
				nw++;
			}
		}

		nch = nch + retval;  
		if (retval<1024)
			break;
	
	}

	printf("cl :%d, sl :%d, int :%d, words:%d, lines :%d,noc: %d\n",cl,sl,nint,nw,nln,nch);
}

