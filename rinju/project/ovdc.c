#include<stdio.h>
#include<fcntl.h>
main(int argc,char *argv[])
{
	char arr[500];
	char arr1[500];
	int i,j,sum=0,n;
	int fd, count = 1, v13, v17, val13, val14, val15, val16, val17;

	for( j = 0; j < 10; j++)
	{
		fd=open("/proc/1402/stat", O_RDONLY,0744);
		//fd=open("temp.txt", O_RDONLY,0744);
		if(fd < 0)
			printf("can't open");
		n=read(fd,arr,500);
		//printf("arr is %s\n", arr);

		for( i = 0; arr[i] != '\0'; i++)
		{
			if( arr[i] == ' ')
			{
				count = count + 1;
				if( count == 12)
				{
					//printf("index of 13th word %d\n", i+1);
					v13 = i + 1;
					//printf("word of 13th word %c  ", arr[i+1]);
				}
				if( count == 17)
				{
					//printf("index of 17th word %d\n", i -1);
					v17 = i ;
					//printf("word of 17th word %c  ", arr[i]);
				}

			}
		}
		n=lseek(fd,v13, SEEK_SET);
		n=read(fd,arr1, v17 - v13);
		arr1[n] = '\0';
		printf("arr1 is %s\n", arr1);
		sscanf(arr1, "%d %d %d %d %d\n", &val13, &val14, &val15, &val16, &val17);
		//printf("%d %d %d %d %d\n", val13, val14, val15, val16, val17);
		sum = val13 + val14 + val15 + val16 + val17;
		printf("sum is %d\n", sum);
		sleep(2);
	}
}
