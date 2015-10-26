#include <stdio.h>
#include <fcntl.h>
main()
{
	int tl = 0;
	int len;
	char buff[100];

	int fd = open ("prasad.txt", O_RDONLY);

	for ( ; len = read (fd,buff,5); )
	{
		tl = len;
                buff[len]= '\0';
		printf("%s", buff);
        //     {
        //        printf("\n %d", len);
        //     }
	}

	printf("return value is : \n %d \n", tl);
}
