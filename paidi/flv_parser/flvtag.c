#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define swap_uint32(x) (((((x) & 0x000000FFU) << 24) | \
(((x) & 0x0000FF00U) << 8)  | \
     (((x) & 0x00FF0000U) >> 8 ) | \
(((x) & 0xFF000000U) >>24)))
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

  struct flv_header
{
	char name[4];
	char version;
	char flag;
	int offset;
} ;
struct flv_header f1;
void position (char);

main()
{
	int fd,i;
	fd=open("sixthsense.flv",O_RDONLY);

        read(fd,&f1.name,3);
	printf("name              :%s\n",f1.name);

	read(fd,&f1.version,1);
	printf("version           :%d\n",f1.version);

	read(fd,&f1.flag,1);
	printf("flag              :%d\n",f1.flag);

	read(fd,&f1.offset,4);
	
        i=swap_uint32(f1.offset); 
	printf("offset            :%x\n",i);

	position(f1.flag);
	close(fd);
   } 

void position (char k)
{
	int v=0;
	v=k&(1<<2);
	if(v == 0)
	{
		printf("file is havng     : no audio\n");
	}
	else
	{
		printf("file is havng     : audio wil rock\n");
	}
	v=k&(1<<0);
		if(v==0)
		{
			printf("file is havng     :no vedio\n");
		}
		else
		{
			printf("file is havng     : vedio will play\n");
		}
}



