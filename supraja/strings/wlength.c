#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
//wlength.c
//=======
int main()
{
	char buff[100];
	int fd , rval ,s=0,l,wc=0,t=0,t1=0,l1;
	fd=open("t.txt1",O_RDONLY);
	if( fd < 0)
	{
		printf("there exist error in opening file");
		exit(1);
	}
	while(1)
	{
		rval = read(fd , buff , 20);
		buff[rval] = '\0';
		printf("%s" , buff);
		l=get_lines_count(buff);
		t=get_words_count(buff);
		s = s + rval;
		wc=wc+t;
		t1=t1+l;
		if(rval<10)
			break;
	}
	printf("the number of bytes in the opend file is %d \n",s);
	printf("the number of lines in the opend file is %d \n",t1);
	printf("the number of words in the opend file is %d \n",wc);
	close(fd);
	return (0);
}	
//>>>>>>> 1.4
int get_lines_count(char *ptr)
{
	int i,l1 = 0;

	for(i=0;ptr[i]!='\0';i++)
	{
		if(ptr[i] == '\n')
			l1++;
	}
	return (l1);
}  

int get_words_count(char *ptr)
{
	int j,w;

	for(j = 0; ptr[j] != '\0'; j++)
	{
	if(ptr[j+1]==' '&& ptr[j] == ' '||ptr[j]=='\n' )
			w = w + 1;
	}
	return (w);
} 

#if 0
int get_words_count(char *ptr)
{
	int j,w=0;
<<<<<<< wlength.c
	for(j = 0; ptr[j] != '\0'; j++)
=======
	for(j=1;ptr[j-1]!='\0';j++)
>>>>>>> 1.4
	{
<<<<<<< wlength.c
		if(ptr[j+1] == ' ')
		{
			if(ptr[j]!=' ')
				w=w+1;
		}

		if(ptr[j] == '\n')
			w = w + 1;
=======
		if(ptr[j]==' ')
		{
		 if(ptr[j-1]!=' ')
			w=w+1;
		}
		if(ptr[j]=='\n')
		    w=w+1;
>>>>>>> 1.4
	}
	return (w);
} 
#endif


int main()
{
	char filename[100] = "t4.txt";
	char buff[100];
	int fd, retval, totalbytes = 0, lc = 0,wc = 0;

	fd = open(filename, O_RDONLY);
	if( fd < 0)
	{
		printf("there exist error in opening file");
		exit(1);
	}

	while(1)
	{
		retval = read(fd , buff , 10);
		buff[retval] = '\0';

		totalbytes = totalbytes + retval;

		lc += get_lines_count(buff);
		wc += get_words_count(buff);


		if(retval<10)
			break;
	}

	printf (" lines : %d\n words : %d\n bytes : %d\n file name : %s\n", lc, wc,
	totalbytes, filename);

#if 0
	printf("the number of bytes in the opend file is %d \n", s);
	printf("the number of lines in the opend file is %d \n", lc);
	printf("the number of words in the opend file is %d \n", wc);
#endif

	close(fd);
	return (0);
}	


