#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;
    char * myfifo = "/home/bhagavan/students/rajini/OS/pipes/tmp/myfifo";
	char buff[1024] = "Hi how are u";
    /* create the FIFO (named pipe) */
    mkfifo(myfifo, 0666);

    /* write "Hi" to the FIFO */
    fd = open(myfifo, O_WRONLY);
    write(fd, buff, sizeof(buff));
    close(fd);

    /* remove the FIFO */
   // unlink(myfifo);

    return 0;
}
