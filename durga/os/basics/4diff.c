#include<stdio.h>
#include<fcntl.h>

main()
{

	int r,f,i, l = 10, val1, val2, x,y=0, dif;
	char buf[100];
	int fd[4];
	fd[0] = open("/proc/4850/stat", O_RDONLY);
	fd[1] = open("/proc/4878/stat", O_RDONLY);
	fd[2] = open("/proc/4886/stat", O_RDONLY);
	fd[3] = open("/proc/4913/stat", O_RDONLY);
	for (f  = 0; f<4; f++)
	{
		for(i = 0; i<3; i++)
		{
			while(1)
			{
				r = read( fd[f], buf, l);
				buf[r] = '\0';
				printf("%s",buf);
				if(r < l)
					break;
			}

			lseek(fd[f], 59l,0);
			r = read(fd[f], buf, 11);
			buf[r] = '\0';
			printf("%s",buf);
			sscanf( buf, "%d %d", &val1, &val2);
			//printf(" %d\t%d", val1,val2);
			int v3 = val1+val2;
			x = v3;
			dif = x - y;

			y = x;
			if(i>=1)
				printf("differnce is %d", dif); 

			lseek(fd[f], 0l, 0);
			printf("\n");
			sleep(2);
		}
		close(fd[0]);
	}
}

