#include "define.h"
#include "tags.h"
main()
{
	int fd = -1,v_fd=-1,a_fd=-1,i=0,retval,offset,tagtype,datasize;
	int pre,data;
	flv_body body;
	fd = open("sixth.flv",O_RDONLY);
	if(fd == -1)
	{
		perror("file opened failed\n");
		return 0;
	}
	v_fd = creat("video.flv",O_CREAT|O_WRONLY|O_TRUNC);
	if(v_fd == -1)
	{
		perror("file opened failed\n");
		return 0;
	}
	a_fd = creat("audio.flv",O_CREAT|O_WRONLY|O_TRUNC);
	if(a_fd == -1)
	{
		perror("file opened failed\n");
		return 0;
	}
	header(fd,v_fd,a_fd);
	//	retval=lseek(fd,0,SEEK_END);
	//	printf("offset=\"%d\"\n",retval);
	//	int off_set=lseek(fd,0,SEEK_SET);
	//	printf("offset=\"%d\"\n",offset);
	read(fd,&body.previoustag,4);
	pre=body.previoustag;
	retval=((((pre>>24)|(pre<<24)))|((((pre<<16)>>24)<<16)|(((pre>>16)<<24)>>16)));
	write(v_fd,&retval,4);
	write(a_fd,&retval,4);
	while(i<=10)
	{
		read(fd,&body.tagtype,1);
		switch(body.tagtype)
		{
			case 18: write(v_fd,&body.tagtype,1);
					 write(a_fd,&body.tagtype,1);
					 break;
			case 9: write(v_fd,&body.tagtype,1);
					break;
			case 8: write(a_fd,&body.tagtype,1);
					break;
		}
		switch(body.tagtype)
		{
			case 18: printf("\n<tag type=\"script data\" ");
					 datasize = scriptdata(fd,v_fd,a_fd);
					 break;
			case  9: printf("\n<tag type=\"video\" ");
					 datasize = video(fd,v_fd);
					 break;
			case  8: printf("\n<tag type=\"audio\" ");
					 datasize = audio(fd,a_fd);   
					 break;
		}
		int previoustag=(datasize+11);
		pre=previoustag;
		retval=((((pre>>24)|(pre<<24)))|((((pre<<16)>>24)<<16)|(((pre>>16)<<24)>>16)));

		switch(body.tagtype)
		{
			case 18: write(v_fd,&retval,4);
					 write(a_fd,&retval,4);
					 break;
			case 9: write(v_fd,&retval,4);
					break;
			case 8: write(a_fd,&retval,4);
					break;
		}
		read(fd,&body.previoustag,4);
		i++;
	}
	printf("\n");
	close(fd);
	close(v_fd);
	close(a_fd);
}

