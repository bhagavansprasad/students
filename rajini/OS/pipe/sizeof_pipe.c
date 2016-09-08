#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main(void)
{
    int tube[2];
    char c = 'c';
    int i;
    if( pipe(tube) != 0)
    {
        perror("pipe");
        exit(1);
    }
	printf("writing in pipe\n");
    for(i=0;; i++)
    {
		printf("%d bytes written\n",i+1);
        if( write(tube[1], &c, 1) != 1)
        {
			printf("write system call failed\n");
            perror("Write");
            exit(1);
        }
    }
    return 0;
}
