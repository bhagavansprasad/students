#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
main()
{
	int fop=0,fop1=0,rret=0,len=10;
	char buff[100];

	fop  = open("t1.txt",O_RDONLY,0);
	printf("fop_m=%d\n",fop);

	fop1 = open("t2.txt",O_CREAT|O_WRONLY,0777);
	printf("fop_m=%d\n",fop1);

		rret = read(fop,buff,len);
		buff[rret] = '\0';
		write(fop1,buff"\n",rret);
		printf("%s\n",buff);
			
		lseek(fop,-10l,2);
		rret = read(fop,buff,len);
		buff[rret] = '\0';
		write(fop1,"\n"buff,rret);
		printf("%s\n",buff);
		
	close(fop);
	close(fop1);
}
