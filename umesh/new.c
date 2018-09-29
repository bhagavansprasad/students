#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
main()
{
	char buff[200];
	int i,n=15,fd,retval;
	int l=0;
	fd=open("a.txt",O_RDONLY);
	for(i=1;i<=n;i++)
	{
		retval=read(fd,buff,100);
	//	printf("%d \n",retval);
		buff[retval]='\0';
	//	printf("%s \n", buff);
		l=l+1;
//		printf("%s \n" ,get_word(5));
		while(retval>=14  && retval<=18 )
		{

	     printf("%s \n",buff);
	}
//	printf("%d", l);



//	printf("-->%d.%d\n", __LINE__, l);
	close(fd);
}
}
