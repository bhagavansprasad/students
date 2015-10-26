#include<stdio.h>
#include<fcntl.h>

main()
{

	int r,fd,i, l = 10, val1, val2, x,y=0, dif;
	char buf[100];
	fd = open("/proc/3785/stat", O_RDONLY);
	for(i = 0; i<5; i++)
	{
	   while(1)
	   {
	   r = read( fd, buf, l);
	   buf[r] = '\0';
	   printf("%s",buf);
	   if(r < l)
	   break;
	   }

	   lseek(fd, 59l,0);
	   r = read(fd, buf, 11);
	   buf[r] = '\0';
	   printf("%s",buf);
	   sscanf( buf, "%d %d", &val1, &val2);
	   int v3 = val1+val2;
	   x = v3;
	   dif = x - y;

	   y = x;
	   if(i>=1)
	   printf("differnce is %d", dif); 

	  lseek(fd, 0l, 0);
	  printf("\n");
	  sleep(2);
	}
	close(fd);
}

