#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
main()
{
	int fd, i=0, ln=10, r, w=0, fd1, c;
	char buf[100], arr[100]; 
	fd = open("prasad.txt", O_RDWR);
	fd1 = open("b.txt", O_RDWR|O_CREAT, 0777);
	printf("%d\n",fd);
	printf("%d\n", fd1);

	while(1)
	{
		r = read( fd, buf,ln);
		buf[r]='\0';
        //  c = aconverter(buf);
    	for( i = 0; buf[i] != '\0'; i++)
		{
			if( buf[i] >= 65 && buf[i] <= 90)
				buf[i]= buf[i]+32;

			//arr[r]='\0';
		}
		printf("%s\n",buf);
		w = write( fd1,buf,r);
		if(w<0)
		{
			perror("not writng due to:");
			printf("%d",errno);

		}
		if(r<ln)
			break;

	}
	//		printf("%s",buf);
	close(fd);
	printf("%d\n",fd);

	close(fd1);
	printf("%d\n",fd1);
}

/* function for case convater

int aconverter( char *buf)
{
  int i;
   for( i = 0; buf[i] != '\0'; i++)
   {

      if(buf[i] >= 65&&buf[i] <= 90)
	  {
	   buf[i] = buf[i]+32;
	   }
	  }
   return(i);
   }*/
