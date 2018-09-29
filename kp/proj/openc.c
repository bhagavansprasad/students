#include<stdio.h>
#include<fcntl.h>
aura_openc(char*fname,int flags)
{
	typedef struct file
	{
		int cmd;
		char fname;
		int mode;
		}sd;
	aura_opens(&struct);
	sd.cmd=1;
}
aura_readc(int fd,char buf,size_t count)
{
	typedef struct file
	{
		int cmd;
		int fd;
		char buf;
		int count;
		aura_opens(&struct);
	}sd;
	sd.cmd=2;
}
aura_writec(int fd,char buf,size_t count)
{
	typedef struct file
	{
		int cmd;
		int fd;
		char buf;
		int count;
		aura_opens(&struct);
	}sd;
	sd.cmd=3;
}
aura_lseekc(int fd,off_t offset,int whence)
{
	typedef struct file
	{
		int cmd;
		int fd;
		int offset;
		int whence;
		aura_opens(&struct);
	}sd;
	sd.cmd=4;
}
aura_close(int fd)
{
	typedef struct file
	{
		int cmd;
		int fd;
	}sd;
	sd.cmd=5;
}

