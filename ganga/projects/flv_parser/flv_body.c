#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"
#include "stdbool.h"
#include "defs.h"

int read_flv_tags(int fd)
{
	static temp = 0;
	int a = 0, c = 0, i = 0, n = 0, wval = 0, wretval = 0, retval = 0, mask = 0x1F; 
	char buff[100000]=" ";
	char b[10]=" ";
	char bu[10]=" ";
	char buf[10]=" ";
	char bufff[10]=" ";
	char buffe[10]=" ";

	char *p;
	char *dp;
	char *tp; 
	char *sp = (char *)&tdata.stream_id;
	extern fd5, fd6, fd7, fd8;
	char buff1[200] = " ";

	retval = read(fd, buff1, 4);

	if(retval < 4)
		return 1;

	else
	{
		p = (char *)&tdata.previoustag;
		for (i = 3 ; i >= 0; i--)
		{
			*p = buff1[i];
			p++;

		}
		tdata.previoustag = tdata.data_size;
		printf("previous %d\n",tdata.previoustag);

		retval = read(fd, b, 1);

		a = b[0];
		n = ((a >> 6) & 3);
		tdata.reserved = n;

		tdata.filter = ((a >> 5) & 1);

		c = a & mask;
		tdata.tag_type = c;
		retval = read(fd, bu, 3);

		tdata.data_size = 0;
		dp = (char *)&tdata.data_size;

		for(i = 2; i >= 0; i--)
		{
			*dp = bu[i];		
			dp++;
		}

		retval = read(fd, buf, 3);

		tdata.timestamp = 0; 
		tp= (char *)&tdata.timestamp;
		for(i = 2; i >= 0; i--)
		{
			*tp = buf[i];
			tp++;
		}

		retval = read(fd, bufff, 1);

		tdata.timestamp_extended = bufff[0];

		retval = read(fd, buffe, 3);

		for(i = 2; i >= 0; i--)
		{
			*sp = buffe[i];
			sp++;
		}

		if(tdata.tag_type == 18)
		{
			wretval=write(fd6, buff1, 4);
			wretval=write(fd6, b, 1);
			wretval=write(fd6, bu, 3);
			wretval=write(fd6, buf, 3);
			wretval=write(fd6, bufff, 1);
			wretval=write(fd6, buffe, 3);

			read(fd, buff, tdata.data_size);
			wretval=write(fd6, buff, tdata.data_size);

			wretval=write(fd7, buff1, 4);
			wretval=write(fd7, b, 1);
			wretval=write(fd7, bu, 3);
			wretval=write(fd7, buf, 3);
			wretval=write(fd7, bufff, 1);
			wretval=write(fd7, buffe, 3);
			wretval=write(fd7, buff, tdata.data_size);

			write(fd5, buff1, 4);
			write(fd5, b, 1);
			write(fd5, bu, 3);
			write(fd5, buf, 3);
			write(fd5, bufff, 1);
			write(fd5, buffe, 3);
			wretval=write(fd5, buff, tdata.data_size);

			lseek(fd, -tdata.data_size, SEEK_CUR);

			wretval = write(fd8, buff1, 4);

			wretval = write(fd8, b, 1);
			wretval = write(fd8, bu, 3);
			wretval = write(fd8, buf, 3);
			wretval = write(fd8, bufff, 1);
			wretval = write(fd8, buffe, 3);
	
			wretval = write(fd8, buff, tdata.data_size);
			lseek(fd, -tdata.data_size, SEEK_CUR);
		}
		
		else if(tdata.tag_type == 9)
		{
			retval=read(fd, buff, tdata.data_size);
			int	r = ((buff[0] >> 4) & 0xF);
			
			if(r == 1)
			{
				wretval = write(fd6, buff1, 4);

				wretval = write(fd6, b, 1);
				wretval = write(fd6, bu, 3);
				wretval = write(fd6, buf, 3);
				wretval = write(fd6, bufff, 1);
				wretval = write(fd6, buffe, 3);

				wretval = write(fd6, buff, tdata.data_size);
			}
			
			else if(r == 2)
			{
				wretval = write(fd7, buff1, 4);
				wretval = write(fd7, b, 1);
				wretval = write(fd7, bu, 3);
				wretval = write(fd7, buf, 3);
				wretval = write(fd7, bufff, 1);
				wretval	= write(fd7, buffe, 3);

				wretval= write(fd7, buff, tdata.data_size);
			}

			write(fd5, buff1, 4);
			write(fd5, b, 1);
			write(fd5, bu, 3);
			write(fd5, buf, 3);
			write(fd5, bufff, 1);
			write(fd5, buffe, 3);
			write(fd5, buff, tdata.data_size);

			lseek(fd, -tdata.data_size, SEEK_CUR);
		}
		
		else if(tdata.tag_type == 8)
		{ 
		 	wretval = write(fd8, buff1, 4);

			wretval = write(fd8, b, 1);
			wretval = write(fd8, bu, 3);
			wretval = write(fd8, buf, 3);
			wretval = write(fd8, bufff, 1);
			wretval = write(fd8, buffe, 3);
	
			read(fd, buff, tdata.data_size);
			wretval = write(fd8, buff, tdata.data_size);

			lseek(fd, -tdata.data_size, SEEK_CUR);
		}
	}
	
	return tdata.tag_type;
}
