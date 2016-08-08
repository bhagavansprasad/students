#include <stdio.h>
#include "defs.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int read_nthto_mwords_sum(int fd)
{   
	char src_buff[1024],dst_buff[1024];
	int dst = 0;
	int n,m=4,sum=0;
	int rval = read(fd, src_buff, 1000);

	src_buff[rval] = '\0';

	for(n = 13; n < n+m; n++, m--)
	{
		get_nth_word(src_buff,dst_buff,n);
		OVDC_DEBUG("-->n       :%d\n", n);
		OVDC_DEBUG("-->buffer  :%s\n", dst_buff);

		dst = atoi(dst_buff);

		sum = sum + dst;
	}
	OVDC_DEBUG("----->sum=%d\n",sum);
	return sum;

}

