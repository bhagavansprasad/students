/*STRUCTURE FLV HEADER*/

typedef struct 
{
	unsigned char signature[4];
	unsigned char version;
	unsigned char flag;
	unsigned int byte_off_set;
}flv_header;




#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#pragma packoff(1)
main()
{
	int fd,val=0;
	char version=0,flag;
	flv_header header;
	fd=open("sixthsense.flv",O_RDONLY);
	if(fd==-1)
	{
		perror("\nfile is not opened\n");
		exit(0);
	}
	read_flv_header(fd, &header);   /*calling function flv_header*/

}




int read_flv_header(int fd, flv_header *phead)
{ 
       int val=0;
        
	val = read(fd, phead->signature, 3);
	  phead->signature[4]='\0';

	if((strncmp(phead->signature, "FLV", 3) != 0))
	{
		printf("Invalid Signature :%s\n", phead->signature);
		exit(1);
	}

	printf("Got Signature :%s\n", phead->signature);

	val=read(fd, &phead->version, 1);
		if(phead->version == 1)
		{
			printf("VERSION :%d\n",phead->version);
		}
		else
		{
			printf("VERSION NUMBER IS NOT MATCHED%d\n",phead->version);
		}

		val=read(fd,&phead->flag,1);
		printf("FLAG =%d\n",phead->flag);
		if(phead->flag==5)
		{   
			//printf("FLAG =%d\n",phead->flag);
			position(5,0,2);
		}	 
		else
		{
			printf("FLAG IS NOT 5\n",phead->flag);
		}

		val=read(fd,&phead->byte_off_set,4);
		printf("%d\n",val);
		unsigned char *c;
		c=&phead->byte_off_set;
		int i;
		c=c+3;
		//printf("byte offset=%d\n",*c);
		//for(i=0;i<4;i++)
		//{
		//printf("BYTE_OFF_SET =%d\n",c[i]);
		//c[0]=c[0]+c[3];
		//c[3]=c[0]-c[3];
		//c[0]=c[0]-c[3];
		//c[1]=c[1]+c[2];
		//c[2]=c[1]-c[2];
		//c[1]=c[1]-c[2];
		       
		//}
		//printf("  c[0]=%d c[1]=%d c[2]=%d c[3]=%d \n",c[0],c[1],c[2],c[3]);
		printf("BYTE OFFSET=%d\n",*c);


}

position(int n,int pos1,int pos3)
{

	int mask,k,bit;
	mask=1<<(pos1);
	bit=n&mask;
	if(bit==0)
	{
		printf("PRESENT FILE HAVE NO VIDEO\n");
	}
	else
	{
		printf("VIDEO TAG IS PRESENT\n");
	}
	mask=1<<(pos3);
	k=n&mask;
	if(bit==0)
	{
		printf("PRESENT FILE HAVE NO AUDIO\n");
	}
	else
	{
		printf("AUDIO TAG IS PRESENT\n");
	}

}

