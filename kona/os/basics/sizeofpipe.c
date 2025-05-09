#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(void)
{
    int tube[2];
    char c = 'c';
    int i;

    fprintf(stdout, "Tube Creation\n");
    fprintf(stdout, "Theoretical max size: %d\n", PIPE_BUF);
    if( pipe(tube) != 0)
    {
        perror("pipe");
        _exit(1);
    }
    fprintf(stdout, "Writing in pipe\n");
    for(i=0;; i++)
    {
        fprintf(stdout, "%d bytes written\n", i+1);
        if( write(tube[1], &c, 1) != 1)
        {
            perror("Write");
            _exit(1);
        }
    }
    return 0;
}
