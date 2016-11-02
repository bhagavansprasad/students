#include <stdio.h>
#include "defs.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int get_giffs_bypid(int pid)
{
	int fd, giffs = 0;

	fd = get_fd_by_pid(pid);

	OVDC_DEBUG("-->fd:%d\n", fd);

	giffs = read_nthto_mwords_sum(fd);
	close(fd);

	return giffs;
}

