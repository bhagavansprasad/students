#include <stdio.h>
#include <fcntl.h>

main()
{
	int fd1,fd2,fd3,rd1,rd2,rd3;
	int ret;
	char *cm1 = "Hi";
	char *cm2 = "Hello";
	char *cm3 = "Hey";
	
	char buffs1[30];
	char buffs2[30];
	char buffs3[30];
	
	fd1 = open("raghu1",O_RDWR);
	fd2 = open("raghu2",O_RDWR);
	fd3 = open("raghu3",O_RDWR);
	
	rd1 = open("richie1",O_RDWR);
	printf("the open value is %d\n",rd1);
	rd2 = open("richie2",O_RDWR);
	rd3 = open("richie3",O_RDWR);
	
	read(fd1,buffs1,30);
	printf("From the 1st client %s\n",buffs1);
	
	read(fd2,buffs2,30);
	printf("From the 2nd client %s\n",buffs2);
	
	read(fd3,buffs3,30);
	printf("From the 3rd client %s\n",buffs3);

	write(rd1,cm1,30);
	printf("the data send to the client %s\n",cm1);

	write(rd2,cm2,30);
	printf("the data send to the client %s\n",cm2);

	write(rd3,cm3,30);
	printf("the data send to the client %s\n",cm3);
}
