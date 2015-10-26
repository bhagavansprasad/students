#include<stdlib.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "flv1.h"
#include <fcntl.h>

	main()
	{
		int fd,fd1,fd2;
		unsigned int t=0;
		static int i=0;
		flv_header hd;
		flv_tag tag;
		char buff[4];

		fd = file_open("sixth.flv");
		fd1 = create_file("f5.flv");


		if (fd == -1 ) 
		{
			perror("file fd not opened because : \n");
			exit(0);
		}

		if (fd1 == -1)
		{
			perror("file not opened because : \n");
			exit(0);
		}

		write_header(fd,fd1,hd);
		t = write_tag(fd,fd1,tag);

		for(; t<=3498000; )
		{
			printf("enter loop==%d\n",i++);
			t = write_tag(fd, fd1, tag);
		}
		printf("writing completed in 1.flv\n");
         
	//	lseek(fd,-46838,SEEK_CUR);
	//	read(fd,buff,3);
	//	printf("buff value=%s",buff);
   
					
	}
