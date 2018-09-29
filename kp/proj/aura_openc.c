#include <stdio.h>
#include "define.h"
#include <fcntl.h>
#include <string.h>
#define FILE_OPEN 1
#define FILE_READ 2
#define FILE_WRITE 3
#define FILE_SEEK 4
#define FILE_CLOSE 5

int aura_openc(char *fname, int flags)
{
	fop_data datac;

	datac.cmd = FILE_OPEN;
	strcpy(datac.udata.opn.fname, fname);
	datac.udata.opn.mode = flags;

	aura_fop_cmd_dispatcher(&datac);

	return datac.udata.opn.fd;
}

int aura_readc(int fd, char *buf, int count)
{
	fop_data datac;

	datac.cmd = FILE_READ;
	datac.udata.rdwt.fd = fd;
	aura_fop_cmd_dispatcher(&datac);
	datac.udata.rdwt.count = count;
	strncpy(buf, datac.udata.rdwt.buffer, datac.udata.rdwt.count);
	return datac.udata.rdwt.count;

}

int aura_writec(int fd, char *buf, int count)
{
	fop_data datac;

	datac.cmd = FILE_WRITE;
	datac.udata.rdwt.fd=fd;
	strncpy(buf,datac.udata.rdwt.buffer, datac.udata.rdwt.count);
	datac.udata.rdwt.count=count;
	aura_fop_cmd_dispatcher(&datac);
	return datac.udata.rdwt.count;
}

int aura_lseekc(int fd, off_t offset, int whence)
{
	fop_data datac;

	datac.cmd = FILE_SEEK;
	datac.udata.seek.fd=fd;
	datac.udata.seek.offset=offset;
	datac.udata.seek.whence=whence;
	aura_fop_cmd_dispatcher(&datac);
	return datac.udata.seek.offset;
}

int aura_closec(int fd)
{
	fop_data datac;

	datac.cmd=FILE_CLOSE;
	datac.udata.cls.fd=fd;
	aura_fop_cmd_dispatcher(&datac);
}

