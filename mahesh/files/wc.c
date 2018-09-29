#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

int get_wordcount(char *a);
int get_linecount(char *a);


main()
{
	char buff[512];
	int retval=0,count=0,len=10,lcount=0;
	 //for(i=1;i<argc;i++)
	 //{
	 //	int count=0;
	    int fd = open("a.txt",O_RDONLY);
	
		while(1)
		{
			retval = read(fd,buff,len);
			//count += get_wordcount(buff);
			buff[retval] = '\0';
				count += get_wordcount(buff);
				lcount+=get_linecount(buff);

			printf("%s", buff);

			if(retval <len)
			 break;
				
		}
		close(fd);
		printf("Word count:%d\n", count);
			printf("line count:%d\n", lcount);

	//}
	
}

int get_wordcount(char *a)
{
	int i=0, count=0;
	for(i=0 ; a[i]!='\0' ; i++)
	{
		if((a[i] ==' '|| a[i] == '\0'|| a[i] =='\n')&&a[i+1]!=' ')
		 {		
		 count++;
		 }
	}
	return count;
}
int get_linecount(char *a)
{
	int i=0, count=0;
	for(i=0 ; a[i]!='\0' ; i++)
	{
		if(a[i] =='\n')
		 {		
		 count++;
		 }
	}
	return count;
}



