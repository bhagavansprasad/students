#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
//int get_word(char [],int, char);

int pid[5] = {2536, 2725, 2848,1935 , 2841};
main()
{
	char buff[200],s[100];
	int i,n=4,fd,retval,line=0,j,word=0;
//	fd=open("a.txt",O_RDONLY)
	char buff[2000];
	int i;
	int fd,retval,line=0,j=0;
	int k=0;
	char b[100];
	int c;
	int curent;
	int old=0;
	int new;
	int n=12; 
	int sum=0;
	int a=0;
	int x;
	int d=0;

	//fd=open("a.txt", O_RDONLY);

	//	fd=open("/proc/3273/stat", O_RDONLY);
	while(1)
	{ 

<<<<<<< acat.c
	//	fd=open("/proc/4477/stat", O_RDONLY);
//	fd=open("a.txt", O_RDONLY);
	retval=read(fd, buff, 2000);
	buff[retval]='\0';
	//	printf("read retval :%d\n", retval);
	printf("buff :%s\n", buff);
//	get_word(buff[i],n, b[k]);
	//	for(i = 0; buff[i] != '\0'; i++)
//	int get_word(char buff[i],int n , char b[k])
//	{
		for(j=0;j<=12;j++)
>>>>>>> 1.2
=======
		x=0;
		for(d=0;d<4;d++)
>>>>>>> 1.3
		{
			sprintf(fname,"proc/%d/stat",pid[d]);

			fd=open("fname",O_RDONLY);
			i=0;
			retval = read(fd, buff, 1000);
			buff[retval]='\0';
			//printf("buff :%s\n", buff);
			for(j=0;j<=12;j++)
			{
				for( ;buff[i]!=' ';i++);
				i++;
			}
			sum=0; 
			for(c=0;c<=3;c++)
			{
				for(k=0  ;buff[i]!=' ';i++) 
				{
					b[k]=(buff[i]);
					k++;
				}
				b[k]='\0';
				i++;
				//printf("%s\n",b);
				a=atoi(b);
				sum=sum+a;
			}

			new=sum;
			//printf("%d\n",new);
			curent=new-old;
			//printf("%d\n",old);
			printf("%d\n",curent);
			old=new;
			//printf("%d\n",sum);
			//printf("-->Val :%d\n", atoi(b));
			//	lseek(fd, 0, SEEK_SET);
			a++;
			x++;
			d++;
		}
		sleep(1);
	}
	close(fd);



}
