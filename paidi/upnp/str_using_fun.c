#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>

int parse_tag_num(char *a, char *str, char val1, char val2)
{
	int i=0; char *ptr; 
	ptr=strstr(a,str);
	for(;*ptr++!=val1;);
	for(;*ptr!=val2;ptr++)
	{
		i=i*10+(*ptr-48);
	}
	switch ( i )
	{
		case 218: printf("item id=%d\n",i);
				  i=0; break;
		case 216: printf("parent id=%d\n",i);
				  i=0; break;
		case 1: printf("restricted=%d\n",i);
				i=0; break;
		case 769757678: printf("size=%d\n",i);
						i=0; break;
		case 607: printf("bitrate=%d\n",i);
				  i=0; break;
		case 44100: printf("sampleFrequency=%d\n",i);
					i=0; break;
		default: return(0); break;
	}
}

int parse_tag_num1(char *a, char *str, char valu1, char valu2)
{
	int i=0; char *ptr; 
	ptr=strstr(a,str);
	for(;*ptr++!=valu1;);
	for(;*ptr!=valu2;ptr++)
	{
		i=i*10+(*ptr-48);
	}
	printf("duration=%d\n",i);
	i=0;
}

int parse_tag_string(char *a, char *buf, char *str, char value1, char value2)
{
	int i=0; 
	char *ptr; 
	ptr=strstr(a,str);
	for(;*ptr++!=value1;);
	for(;*ptr!=value2;ptr++)
	{
		buf[i++]=*ptr;
	}
	buf[i]='\0';
	//	if(buf !="lifeisbeautiful.mp4")
	if(buf !="object.item.videoItem")
	{    
		printf("title=%s\n",buf);
		i=0;
	}
	else
	{   
		printf("enter\n");
		printf("class=%s\n",buf);
		i=0;
	}
}

int parse_tag_strng(char *a, char *buf, char *str, char val1, char val2)
{
	int i=0; 
	char *ptr; 
	ptr=strstr(a,str);
	for(;*ptr++!=val1;);
	for(;*ptr!=val2;ptr++)
	{
		buf[i++]=*ptr;
	}
	buf[i]='\0';
	printf("protocolInfo =%s\n",buf);
	i=0;
}

int parse_tag_num2(char *a, char *str, char valu1, char valu2)
{
	int i=0; char *ptr; 
	ptr=strstr(a,str);
	for(;*ptr++!=valu1;);
	for(;*ptr!=valu2;ptr++)
	{
		i=i*10+(*ptr-48);
	}
	printf("nrAudioChannels=%d\n",i);
	i=0;
}

int parse_tag_num5(char *a, char *str, char valu1, char valu2)
{
	int i=0;
	char *ptr; 
	ptr=strstr(a,str);
	for(;*ptr++!=valu1;);
	for(;*ptr!=valu2;ptr++)
	{
		i=i*10+(*ptr-48);
	}
	printf("resolution=%d\n",i);
	i=0;
}

int parse_tag_strng1(char *a, char *buf, char *str, char val1, char *val2)
{
	int i=0; char *ptr; 
	ptr=strstr(a,str);
	for(;*ptr++!=val1;);
	for(;*ptr!= *val2;ptr++)
	{
		buf[i++]=*ptr;
	}
	buf[i]='\0';
	printf("http =%s\n",buf);
	i=0;
}

main()
{
	int fd,val,i=0;
	char buff[400];
	char buff1[500];
	char *ptr;
	fd=open("txt.c",O_RDONLY|0666); 
	if(fd==-1)
	{
		printf("file1 is not open\n");
		exit(1);
	}
	val=read(fd,buff,sizeof(buff));
	buff[val]='\0';
	if(val==-1)
	{
		printf("file2 is not open\n");
		exit(1);
	}
	for(i=0;i<=1;i++)
	{
		parse_tag_num(buff, "id=", '"', '"');
		parse_tag_num(buff, "parentID=", '"', '"');
		parse_tag_num(buff, "restricted=", '"', '"');
		parse_tag_string(buff,buff1, "title", '>', '<');
		parse_tag_string(buff,buff1, "class", '>', '<');
		parse_tag_strng(buff,buff1, "protocolInfo=", '"', '"');
		parse_tag_num(buff, "size=", '"', '"');
		parse_tag_num1(buff, "duration=", '"', '"');
		parse_tag_num(buff, "bitrate=", '"', '"');
		parse_tag_num5(buff, "resolution=", '"', '"');
		parse_tag_num(buff, "sampleFrequency=", '"', '"');
		parse_tag_num2(buff, "nrAudioChannels=", '"', '"');
		parse_tag_strng1(buff,buff1, "http:", '/', "</res>");
	}

}
