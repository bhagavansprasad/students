#include<stdio.h>
#include<fcntl.h>
main()
{
	int read_retval,write_retval,fd,fd1,l;
	char buf[100];
	fd=aura_openc("a.txt",O_RDONLY);
	fd1=aura_openc("b.txt",O_WRONLY);
	read_retval=aura_readc(fd,buf,10);
	buf[read_retval]='\0';
	write_retval=aura_writec(fd1,buf,read_retval);
	l=aura_lseekc(fd,-20,SEEK_END);
	l=aura_lseekc(fd,l,SEEK_SET);
	read_retval=aura_readc(fd,buf,20);
	buf[read_retval]='\0';
	write_retval=aura_writec(fd1,buf,read_retval);
	aura_closec(fd);
}

