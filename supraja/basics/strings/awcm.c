#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int get_word_count(char *ptr);

int main()
{
	char buff[100];
	int fd, rval, t, wc = 1, i = 1;

	fd = open("t.txt", O_RDONLY);
	if (fd < 0)
	{
		printf ("-->Error in opening file\n");
		exit(1);
	}

	while(1)
	{
		rval = read(fd, buff, 20);
		buff[rval] = '\0';


		t = get_word_count(buff);

/*
		printf("-->loop count  :%d\n", i++);
		printf("-->retval :%d\n", rval);
		printf("-->buff   :%s\n", buff);
		printf("-->words  :%d\n", t);
 */

		wc = wc + t;

		if(rval < 20)
			break;
	}
	printf("-->Total number of words are : %d\n", wc);

	close(fd);

	return 0;
}

int get_word_count(char *ptr)
{
	int i, w = 0;

	for(i = 0; ptr[i] != '\0'; i++)
	{
		if(ptr[i] == ' ')
			w++;
	}
	return (w);
}
