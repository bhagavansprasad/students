#include<stdio.h>
#include<fcntl.h>

main()
{
	int i,fd = 0, retval = 0, n = 15;
	char buff[100] = "";
	int wcount,lcount,len, tot_wcount = 0;

	fd = open("t.txt", O_RDONLY, 0);

	while(1)
	{
		retval = read(fd, buff, n);
		buff[retval] = '\0';

		//printf("retval :%d, buff :%s\n", retval, buff);
		printf("%s :", buff);

		wcount = get_wcount(buff);
		printf("wcount :%d\n", wcount);
		tot_wcount=tot_wcount+wcount;

		if(retval<n)
			break;
	}

	printf("tot_wcount :%d\n", tot_wcount);

	printf("\n");

	close(fd);
}
