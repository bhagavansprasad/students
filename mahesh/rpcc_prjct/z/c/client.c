#include <stdio.h>
#include <fcntl.h>
#include "afop_defs.h"
//#include "structrep.h"
#include "errno.h"
int tcp_client_init();
extern int erro,err,errw,errc;
int errno;
//int client_read_req(struct server *s );
int main()//int argc, char* argv[])
{
	int fdr,fdw,retval,wral,length=10,fdc,fdc2;
	char buff[512];
//	struct server s;
	tcp_client_init();
	printf("---------->>>> Open file <<<<----------\n");
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	fdr = a_open("t.txt",O_RDONLY,0644);
	if(fdr<0)
	{
	//	client_read_req(&s); 	
		errno=erro;
		printf("errno:%d\n",errno);
		perror("error is:");
	}
	printf("-->fdr :%d\n", fdr);

	printf("---------->>>> creation of file <<<<----------\n");
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	fdw = a_open("c.txt",O_CREAT|O_RDWR,0644);
	if(fdw<0)
	{
	//	client_read_req(&s); 
		errno=erro;
		printf("errno:%d\n",errno);
		perror("error is:");
	}

	printf("-->fdw :%d\n", fdw);

	while(1)
	{
		
		printf("----------->>>> Reading a file <<<<-----------\n");
		printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);		
		retval = a_read(fdr, buff, length);
		if(retval<0)
	{
		//client_read_req(&s); 
			errno=err;
		printf("errno:%d\n",errno);
		perror("error is:");
	}

		buff[retval]='\0';
	//retval = a_read(fdr, buff, length);
		printf("-->retval :%d\n", retval);
	    printf("-->buff :%s\n", buff);
		printf("--------------->>>> Writing a file <<<<---------------\n");
		printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);	
		wral = a_write(fdw, buff, retval);
		if(wral<0)
	{
		//client_read_req(&s); 
			errno=errw;
		printf("errno:%d\n",errno);
		perror("error is:");
	}

		printf("-->wral :%d\n", wral);
	//	lseek(fdr,-11l,2);	
	//	retval = a_read(fdr, buff, length);
	//	buff[retval]='\0';
	//	printf("-->retval :%d\n", retval);
	//    printf("-->buff :%s\n", buff);
	//	printf("----------->>>> Writing a file <<<<-----------\n");
	//	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);	
	//	wral = a_write(fdw, buff, retval);

		if(retval < length) 	
		break;
	}
	
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	fdc=a_close(fdr);
	if(fdc<0)
	{
		//client_read_req(&s);
			errno=errc;
		printf("errno:%d\n",errno);
		perror("error is:");
	}


	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	fdc2=a_close(fdw);
	if(fdc2<0)
	{
		//client_read_req(&s);
			errno=errc;
		printf("errno:%d\n",errno);
		perror("error is:");
	}

}
