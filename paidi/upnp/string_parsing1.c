<item 
id="218"
parentID="216"
restricted="1">
<dc:title>lifeisbeautiful.mp4</dc:title>

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>

//int parse_tag(char *s, char *d, char *tn, char sc, char ec)
int parse_tag(char *s, char *d, char *tn, char sc, char ec)
{
        val=read(fd,buff,80);
    	buff[val]='\0';
    	sum=sum+val;
   
}
main()
{
	//char ntag[100];
//	char pidtag[100];

	int i=0,fd=0;
	char temp[500];
	char *ptr;
  
  //ptr=buff;

    fd=open("txt.t",O_RDONLY); 
	if(fd==-1)
	{
		printf("file is not open\n");
		exit(1);
	}
       
  buff=fd;
    
	parse_tag(buff, idtag, "id=", '"', '"');
//	printf("item id :%s\n", idtag);

//	parse_tag(buff, pidtag, "parentID=", '"', '"');

//	parse_tag(buff, pidtag, "dc:title", '>', '<');

	
