#include "udp.h"
#include "uconfig.h"

char *urlptr;
udp_contex_blk udp_cb;
int i,connected=0;
int socketfd,port=0,root=0;
struct sockaddr_in mysockaddr;
int len=0,retval=0,sd1_retval=0;
char buff[1024];
char sbuff[50000];
char srvr_ip[100];
int sfd;

int parsing_port(char*buff,char*str)
{
	if((urlptr=strstr(buff,str)))
	{
		while(*urlptr!=':')
		{
			urlptr--;
		}
		while(*++urlptr!='/')
		{
			port = port*10+(*urlptr-48);
		}
		printf("port : %d\n",port);

	}
	udp_cb.port = port;
	if((urlptr=strstr(buff,"/rootDesc")))
	{
		//printf("root :%s\n",urlptr);
		while(*urlptr!=':')
		{
			urlptr--;
		}
		while(*++urlptr!='/')
		{
			root = root*10+(*urlptr-48);
		}
		printf("root :%d\n",root);
	}
	udp_cb.root = root;

}
int trivnet()
{
	int sfd;
	//char srvr_ip[100];
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	get_upnp_server_ip(srvr_ip);
	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_addr.s_addr = inet_addr(srvr_ip);
	mysockaddr.sin_port = htons(udp_cb.root);

	udp_cb.fd1=sfd;

	connected = connect(sfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr));
	if(connected == -1)
	{
		perror("--->client: connect system call failed\n");
		close(sfd);
		exit(1);
	}


	len= sprintf(buff, "%sHOST: %sUser-Agent: %s",GET,HOST,UAGENT);


	printf("-->buff len :%d\n", strlen(buff));
//	printf("-->buff :%s\n", buff);
	retval=sendto(sfd, buff, strlen(buff), 0, ((struct sockaddr *)&mysockaddr), sizeof(mysockaddr));
	printf("--->client:send retval-->:%d\n",retval);
	for(i=0;i<=5;i++)
	{
		retval=recvfrom(sfd,sbuff,sizeof(sbuff),0,((struct sockaddr *)&mysockaddr),&sd1_retval);
		if(retval < 0)
		{
			perror("--->client: sending failed\n");
			exit(1);
		}
		printf("--->client: recieve retval:%d\n",retval);
	//	printf("-->buff :%s\n", sbuff);

	}

	return 0;
}


int server()
{
	int sfd;
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	get_upnp_server_ip(srvr_ip);
	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_addr.s_addr = inet_addr(srvr_ip);
	mysockaddr.sin_port = htons(udp_cb.port);
	sd1_retval=sizeof(mysockaddr);

	//udp_cb.fd2=sfd;
	connected = connect(sfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr));
	if(connected == -1)
	{
		perror("--->client: connect system call failed\n");
		close(sfd);
		exit(1);
	}


	len= sprintf(buff, "%sHOST: %sUser-Agent: %s",GET1,HOST,UAGENT);


	retval=sendto(sfd, buff, strlen(buff), 0, ((struct sockaddr *)&mysockaddr), sizeof(mysockaddr));
	if(retval < 0)
	{
		perror("--->client: sending failed\n");
		exit(1);
	}

	printf("--->client:send retval-->:%d\n",retval);
	sleep(3);
	for(i=0;i<=5;i++)
	{
		retval=recvfrom(sfd,sbuff,sizeof(sbuff),0,((struct sockaddr *)&mysockaddr),&sd1_retval);
		if(retval < 0)
		{
			perror("--->client: sending failed\n");
			exit(1);
		}
		printf("--->client: recieve retval:%d\n",retval);
		//printf("-->buff :%s\n", sbuff);

	}
	return 0;
}


int Browse_Metadata()
{

	char metadata[1024];
	char mbuff[1024];
	int slen,len=0;
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	get_upnp_server_ip(srvr_ip);
	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_addr.s_addr = inet_addr(srvr_ip);
	mysockaddr.sin_port = htons(udp_cb.port);
	sd1_retval=sizeof(mysockaddr);

	connected = connect(sfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr));
	if(connected == -1)
	{
		perror("--->client: connect system call failed\n");
		close(sfd);
		exit(1);
	}

	slen=sprintf(mbuff,"%sHOST: %sUser-Agent: %sContent-Length: %sSOAPACTION: %scontent-type: %sconnection: %s",POST,HOST,U_AGENT,C_LEN,SOAPACTION,CONTENT_TYPE,CONNECTION);

//	printf("build string %s",metadata);

	len +=sprintf(metadata,"%s",mbuff);
	len +=sprintf(metadata+len,"%s","<?xml version=\"1.0\" encoding=\"utf-8\"?>");
	len +=sprintf(metadata+len,"%s","<s:Envelope s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\" xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\">");
	len +=sprintf(metadata+len,"%s","<s:Body><ns0:Browse xmlns:ns0=\"urn:schemas-upnp-org:service:ContentDirectory:1\">");
	len +=sprintf(metadata+len,"%s","<ObjectID>0</ObjectID><BrowseFlag>BrowseMetadata</BrowseFlag>");

	len +=sprintf(metadata+len,"%s","<Filter>*</Filter><StartingIndex>0</StartingIndex><RequestedCount>0</RequestedCount><SortCriteria /></ns0:Browse></s:Body></s:Envelope>");
	printf("build string %s",metadata);

	retval=sendto(sfd, metadata, strlen(metadata), 0, ((struct sockaddr *)&mysockaddr), sizeof(mysockaddr));
	if(retval < 0)
	{
		perror("--->client: sending failed\n");
		exit(1);
	}

	printf("--->client:send retval-->:%d\n",retval);
	for(i=0;i<=1;i++)
	{
	retval=recvfrom(sfd,sbuff,sizeof(sbuff),0,((struct sockaddr *)&mysockaddr),&sd1_retval);
	if(retval < 0)
	{
		perror("--->client: sending failed\n");
		exit(1);
	}
	printf("--->client: recieve retval:%d\n",retval);
//	printf("-->buff :%s\n", sbuff);
  }
	return 0;

}


int Browse_Direct_Children()
{
	char D_children[1024];
	char child_buff[1024];
	int slen,len=0;
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	get_upnp_server_ip(srvr_ip);
	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_addr.s_addr = inet_addr(srvr_ip);
	mysockaddr.sin_port = htons(udp_cb.port);
	sd1_retval=sizeof(mysockaddr);

	connected = connect(sfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr));
	if(connected == -1)
	{
		perror("--->client: connect system call failed\n");
		close(sfd);
		exit(1);
	}

	slen=sprintf(child_buff,"%sHOST: %sUser-Agent: %sContent-Length: %sSOAPACTION: %scontent-type: %sconnection: %s",POST,HOST,U_AGENT,C_LEN1,SOAPACTION,CONTENT_TYPE,CONNECTION);

	//printf("build string %s",metadata);

	len +=sprintf(D_children,"%s",child_buff);
	len +=sprintf(D_children+len,"%s","<?xml version=\"1.0\" encoding=\"utf-8\"?>");
	len +=sprintf(D_children+len,"%s","<s:Envelope s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\" xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\">");
	len +=sprintf(D_children+len,"%s","<s:Body><ns0:Browse xmlns:ns0=\"urn:schemas-upnp-org:service:ContentDirectory:1\">");
	len +=sprintf(D_children+len,"%s","<ObjectID>0</ObjectID><BrowseFlag>BrowseDirectChildren</BrowseFlag>");

	len +=sprintf(D_children+len,"%s","<Filter>*</Filter><StartingIndex>0</StartingIndex><RequestedCount>0</RequestedCount><SortCriteria /></ns0:Browse></s:Body></s:Envelope>");
	printf("build string %s",D_children);

	retval=sendto(sfd, D_children, strlen(D_children), 0, ((struct sockaddr *)&mysockaddr), sizeof(mysockaddr));
	if(retval < 0)
	{
		perror("--->client: sending failed\n");
		exit(1);
	}

	printf("--->client:send retval-->:%d\n",retval);
	for(i=0;i<=1;i++)
	{
	retval=recvfrom(sfd,sbuff,sizeof(sbuff),0,((struct sockaddr *)&mysockaddr),&sd1_retval);
	if(retval < 0)
	{
		perror("--->client: sending failed\n");
		exit(1);
	}
	printf("--->client: recieve retval:%d\n",retval);
	printf("-->buff :%s\n", sbuff);
  }
	return 0;

}

int Browse_Data()
{
  char Bdata[1024];
	char child_buff[1024];
	int slen,len=0;
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	get_upnp_server_ip(srvr_ip);
	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_addr.s_addr = inet_addr(srvr_ip);
	mysockaddr.sin_port = htons(udp_cb.port);
	sd1_retval=sizeof(mysockaddr);

	connected = connect(sfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr));
	if(connected == -1)
	{
		perror("--->client: connect system call failed\n");
		close(sfd);
		exit(1);
	}

	slen=sprintf(child_buff,"%sHOST: %sUser-Agent: %sContent-Length: %sSOAPACTION: %scontent-type: %sconnection: %s",POST,HOST,U_AGENT,C_LEN2,SOAPACTION,CONTENT_TYPE,CONNECTION);

	//printf("build string %s",metadata);

	len +=sprintf(Bdata,"%s",child_buff);
	len +=sprintf(Bdata+len,"%s","<?xml version=\"1.0\" encoding=\"utf-8\"?>");
	len +=sprintf(Bdata+len,"%s","<s:Envelope s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\" xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\">");
	len +=sprintf(Bdata+len,"%s","<s:Body><ns0:Browse xmlns:ns0=\"urn:schemas-upnp-org:service:ContentDirectory:1\">");
	len +=sprintf(Bdata+len,"%s","<ObjectID>172</ObjectID><BrowseFlag>BrowseDirectChildren</BrowseFlag>");

	len +=sprintf(Bdata+len,"%s","<Filter>*</Filter><StartingIndex>0</StartingIndex><RequestedCount>0</RequestedCount><SortCriteria /></ns0:Browse></s:Body></s:Envelope>");
	printf("build string %s",Bdata);

	retval=sendto(sfd, Bdata, strlen(Bdata), 0, ((struct sockaddr *)&mysockaddr), sizeof(mysockaddr));
	if(retval < 0)
	{
		perror("--->client: sending failed\n");
		exit(1);
	}

	printf("--->client:send retval-->:%d\n",retval);
	for(i=0;i<=1;i++)
	{
	retval=recvfrom(sfd,sbuff,sizeof(sbuff),0,((struct sockaddr *)&mysockaddr),&sd1_retval);
	if(retval < 0)
	{
		perror("--->client: sending failed\n");
		exit(1);
	}
	printf("--->client: recieve retval:%d\n",retval);
	printf("-->buff :%s\n", sbuff);
  }
	return 0;

}


int Browse_Data1()
{
  char Bdata[1024];
	char child_buff[1024];
	int slen,len=0;
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	get_upnp_server_ip(srvr_ip);
	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_addr.s_addr = inet_addr(srvr_ip);
	mysockaddr.sin_port = htons(udp_cb.port);
	sd1_retval=sizeof(mysockaddr);

	connected = connect(sfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr));
	if(connected == -1)
	{
		perror("--->client: connect system call failed\n");
		close(sfd);
		exit(1);
	}

	slen=sprintf(child_buff,"%sHOST: %sUser-Agent: %sContent-Length: %sSOAPACTION: %scontent-type: %sconnection: %s",POST,HOST,U_AGENT,C_LEN2,SOAPACTION,CONTENT_TYPE,CONNECTION);

	//printf("build string %s",metadata);

	len +=sprintf(Bdata,"%s",child_buff);
	len +=sprintf(Bdata+len,"%s","<?xml version=\"1.0\" encoding=\"utf-8\"?>");
	len +=sprintf(Bdata+len,"%s","<s:Envelope s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\" xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\">");
	len +=sprintf(Bdata+len,"%s","<s:Body><ns0:Browse xmlns:ns0=\"urn:schemas-upnp-org:service:ContentDirectory:1\">");
	len +=sprintf(Bdata+len,"%s","<ObjectID>173</ObjectID><BrowseFlag>BrowseDirectChildren</BrowseFlag>");

	len +=sprintf(Bdata+len,"%s","<Filter>*</Filter><StartingIndex>0</StartingIndex><RequestedCount>0</RequestedCount><SortCriteria /></ns0:Browse></s:Body></s:Envelope>");
	printf("build string %s",Bdata);

	retval=sendto(sfd, Bdata, strlen(Bdata), 0, ((struct sockaddr *)&mysockaddr), sizeof(mysockaddr));
	if(retval < 0)
	{
		perror("--->client: sending failed\n");
		exit(1);
	}

	printf("--->client:send retval-->:%d\n",retval);
	for(i=0;i<=1;i++)
	{
	retval=recvfrom(sfd,sbuff,sizeof(sbuff),0,((struct sockaddr *)&mysockaddr),&sd1_retval);
	if(retval < 0)
	{
		perror("--->client: sending failed\n");
		exit(1);
	}
	printf("--->client: recieve retval:%d\n",retval);
	printf("-->buff :%s\n", sbuff);
  }
	return 0;

}

#if 0
int Browse_Directories()
{
    char Bdata[1024];
	char child_buff[1024];
	int slen,len=0;
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	get_upnp_server_ip(srvr_ip);
	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_addr.s_addr = inet_addr(srvr_ip);
	mysockaddr.sin_port = htons(udp_cb.port);
	sd1_retval=sizeof(mysockaddr);

	connected = connect(sfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr));
	if(connected == -1)
	{
		perror("--->client: connect system call failed\n");
		close(sfd);
		exit(1);
	}

	slen=sprintf(child_buff,"%sHOST: %sUser-Agent: %sContent-Length: %sSOAPACTION: %scontent-type: %sconnection: %s",POST,HOST,U_AGENT,C_LEN2,SOAPACTION,CONTENT_TYPE,CONNECTION);

	//printf("build string %s",metadata);

	len +=sprintf(Bdata,"%s",child_buff);
	len +=sprintf(Bdata+len,"%s","<?xml version=\"1.0\" encoding=\"utf-8\"?>");
	len +=sprintf(Bdata+len,"%s","<s:Envelope s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\" xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\">");
	len +=sprintf(Bdata+len,"%s","<s:Body><ns0:Browse xmlns:ns0=\"urn:schemas-upnp-org:service:ContentDirectory:1\">");
	len +=sprintf(Bdata+len,"%s","<ObjectID>175</ObjectID><BrowseFlag>BrowseDirectChildren</BrowseFlag>");

	len +=sprintf(Bdata+len,"%s","<Filter>*</Filter><StartingIndex>0</StartingIndex><RequestedCount>0</RequestedCount><SortCriteria /></ns0:Browse></s:Body></s:Envelope>");
	printf("build string %s",Bdata);

	retval=sendto(sfd, Bdata, strlen(Bdata), 0, ((struct sockaddr *)&mysockaddr), sizeof(mysockaddr));
	if(retval < 0)
	{
		perror("--->client: sending failed\n");
		exit(1);
	}

	printf("--->client:send retval-->:%d\n",retval);
	for(i=0;i<=1;i++)
	{
	retval=recvfrom(sfd,sbuff,sizeof(sbuff),0,((struct sockaddr *)&mysockaddr),&sd1_retval);
	if(retval < 0)
	{
		perror("--->client: sending failed\n");
		exit(1);
	}
	printf("--->client: recieve retval:%d\n",retval);
	printf("-->buff :%s\n", sbuff);
  }
	return 0;

}

int Browse_Directory_data()
{
 char Bdata[1024];
	char child_buff[1024];
	int slen,len=0;
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	get_upnp_server_ip(srvr_ip);
	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_addr.s_addr = inet_addr(srvr_ip);
	mysockaddr.sin_port = htons(udp_cb.port);
	sd1_retval=sizeof(mysockaddr);

	connected = connect(sfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr));
	if(connected == -1)
	{
		perror("--->client: connect system call failed\n");
		close(sfd);
		exit(1);
	}

	slen=sprintf(child_buff,"%sHOST: %sUser-Agent: %sContent-Length: %sSOAPACTION: %scontent-type: %sconnection: %s",POST,HOST,U_AGENT,C_LEN2,SOAPACTION,CONTENT_TYPE,CONNECTION);

	//printf("build string %s",metadata);

	len +=sprintf(Bdata,"%s",child_buff);
	len +=sprintf(Bdata+len,"%s","<?xml version=\"1.0\" encoding=\"utf-8\"?>");
	len +=sprintf(Bdata+len,"%s","<s:Envelope s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\" xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\">");
	len +=sprintf(Bdata+len,"%s","<s:Body><ns0:Browse xmlns:ns0=\"urn:schemas-upnp-org:service:ContentDirectory:1\">");
	len +=sprintf(Bdata+len,"%s","<ObjectID>176</ObjectID><BrowseFlag>BrowseDirectChildren</BrowseFlag>");

	len +=sprintf(Bdata+len,"%s","<Filter>*</Filter><StartingIndex>0</StartingIndex><RequestedCount>0</RequestedCount><SortCriteria /></ns0:Browse></s:Body></s:Envelope>");
	printf("build string %s",Bdata);

	retval=sendto(sfd, Bdata, strlen(Bdata), 0, ((struct sockaddr *)&mysockaddr), sizeof(mysockaddr));
	if(retval < 0)
	{
		perror("--->client: sending failed\n");
		exit(1);
	}

	printf("--->client:send retval-->:%d\n",retval);
	for(i=0;i<=1;i++)
	{
	retval=recvfrom(sfd,sbuff,sizeof(sbuff),0,((struct sockaddr *)&mysockaddr),&sd1_retval);
	if(retval < 0)
	{
		perror("--->client: sending failed\n");
		exit(1);
	}
	printf("--->client: recieve retval:%d\n",retval);
	printf("-->buff :%s\n", sbuff);
  }
	return 0;


}
#endif
