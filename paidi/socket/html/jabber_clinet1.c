#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"unistd.h"

int main(void)
{

        int socketfd;
        int connected;
        struct sockaddr_in myclientaddr;
        char cbuff[1024]="<?xml version='1.0' ?>";
        char buff[1024]="<stream:stream to='auranetworks.in' xmlns='jabber:client' xmlns:stream='http: ";
        char sbuff[1024];
        int retval=0,retval1;
        socketfd = socket(AF_INET, SOCK_STREAM, 0);
        if(socketfd == -1)
        {
                perror("--->client: Failed to create a socket \n");
                exit(1);
        }

        myclientaddr.sin_family = AF_INET;
        myclientaddr.sin_addr.s_addr = inet_addr("192.168.1.30");
        myclientaddr.sin_port = htons(5222);

        printf("--->client: Connecting to the server\n");
        connected = connect(socketfd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));
        if(connected == -1)
        {
                perror("--->client: connect system call failed\n");
                close(socketfd);
                exit(1);
        }
       while(1)
    {
        sleep(2);
                retval=write(socketfd,cbuff,strlen(cbuff));
                retval1=write(socketfd,buff,strlen(buff));
                printf("--->client: write retval:%d\n",retval);
                printf("--->client: write retval:%d\n",retval1);
                if(retval < 0)
                {
                        break;
                }

                retval=read(socketfd, sbuff, sizeof(sbuff));
                printf("--->client: read retval:%d\n",retval);
                if(retval < 0)
                {
                        break;
                }
         sbuff[retval]='\0';
                printf("--->client: string read from server:%s\n",sbuff);

        }
        close(socketfd);

        return 0;

}
                                                                 
