#include <stdio.h>
#include <fcntl.h>
#include <string.h>

main(int argc, char *argv[])
{
	int read_retval, write_retval, rfd, wfd, pos;
	char buf[100];
	char rfname[10];
	char wfname[10];
 /* printf("%s\n",argv[1]);
	strcpy(wfname, argv[1]);
	strcpy(rfname, argv[2]);

	printf("-->rfname :%s\n", rfname);
	printf("-->wfname :%s\n", wfname);
*/
	rfd = aura_openc("2.txt", O_RDONLY);
	wfd = aura_openc("1.txt", O_WRONLY);

	read_retval = aura_readc(rfd, buf, 10);
	buf[read_retval]='\0';
	write_retval = aura_writec(wfd, buf, read_retval);

	pos = aura_lseekc(rfd, -20, SEEK_END);
	pos = aura_lseekc(rfd, pos, SEEK_SET);

	read_retval = aura_readc(rfd, buf, 20);
	buf[read_retval]='\0';

	write_retval = aura_writec(wfd, buf, read_retval);

	aura_closec(rfd);
	aura_closec(wfd);
}


