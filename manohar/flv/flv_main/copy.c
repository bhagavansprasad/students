#include "define.h"
#include "tag.h"
main()
{
	int fd = -1,v_fd=-1,a_fd=-1,i=0,offset,tagtype,datasize;
	unsigned int retval,pre;
	int data,ret_vac=0;
	flv_body body;
	fd = open("sixth.flv",O_RDONLY);
	if(fd == -1)
	{
		perror("file sixth opened failed\n");
		return 0;
	}
	v_fd = creat("video.flv",O_CREAT|O_WRONLY|O_TRUNC);
	if(v_fd == -1)
	{
		perror("file video opened failed\n");
		return 0;
	}
	a_fd = creat("audio.flv",O_CREAT|O_WRONLY|O_TRUNC);
	if(a_fd == -1)
	{
		perror("file audio opened failed\n");
		return 0;
	}

	int eof=lseek(fd,0,SEEK_END);
	printf("offset=\"%d\"\n",eof);
	int off_set=lseek(fd,0,SEEK_SET);
	printf("offset=\"%d\"\n",off_set);

	header(fd,v_fd,a_fd);
	read(fd,&body.previoustag,4);
	pre=body.previoustag;
	retval=((((pre>>24)|(pre<<24)))|((((pre<<16)>>24)<<16)|(((pre>>16)<<24)>>16)));
	printf("previoustag:%d\n",retval);
	write(v_fd,&retval,4);
	write(a_fd,&retval,4);
	while(ret_vac<eof)
	{
		read(fd,&body.tagtype,1);
		printf("tagtype:%d\n",body.tagtype);
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
					 scriptdata(fd,v_fd,a_fd);
					 break;
			case  9: printf("\n<tag type=\"video\" ");
					 video(fd,v_fd);
					 break;
			case  8: printf("\n<tag type=\"audio\" ");
					 audio(fd,a_fd);   
					 break;
		}
		read(fd,&body.previoustag,4);
		pre=body.previoustag;
		retval=((((pre>>24)|(pre<<24)))|((((pre<<16)>>24)<<16)|(((pre>>16)<<24)>>16)));
		printf("previoustag:%x\n",retval);
		ret_vac=lseek(fd,0,SEEK_CUR);
		printf("current position:%d\n",ret_vac);
	}
	printf("\n");
	close(fd);
	close(v_fd);
	close(a_fd);
}

