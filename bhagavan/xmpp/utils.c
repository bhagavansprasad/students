#include "string.h"
#include "stdio.h"
#include "xmppc.h"
#include "utils.h"
#include "config.h"

int parse_realm(char *tbuff, char *prealm)
{
	int j=0;
	char  *ptr = NULL;

	ptr = strstr(tbuff, "realm");
	for( ; *ptr !=  '\"' ; ptr++);
	while((*(++ptr)) != '\"' )
	{
		prealm[j] = *ptr;
		j++;
	}
	prealm[j] = '\0';

	return 0;
}

int parse_nonce(char *tbuff, char *pnonce)
{
	int j=0;
	char  *ptr = strstr(tbuff, "nonce");
	
	for( ; *ptr !=  '\"' ; ptr++);

	while((*(++ptr)) != '\"' )
	{
		pnonce[j] = *ptr;
		j++;
	}
	pnonce[j] = '\0';

	return j;
}

int parse_qop(char *tbuff, char *pqop)
{
	int j=0;
	char  *ptr = strstr(tbuff, "qop");
	
	for( ; *ptr !=  '\"' ; ptr++);


	while((*(++ptr)) != '\"' )
	{
		pqop[j] = *ptr;
		j++;
	}
	pqop[j] = '\0';

	return 0;
}

int parse_charset(char *tbuff, char *pchar_set)
{
	int j=0;
	char  *ptr = strstr(tbuff,"charset");
	
	for( ; *ptr !=  '=' ; ptr++);

	while((*(++ptr)) != ',' )
	{
		pchar_set[j] = *ptr;
		j++;
	}
	pchar_set[j] = '\0';

	return 0;
}

int parse_challange(char *tbuff, int len, char *pchallange, int *pchallenge_len)
{
	int i, j;

	*pchallenge_len = 0;

	for (i = 0; tbuff[i] != '\0' && tbuff[i] != '>'; i++);

	for (j = 0, i++; (pchallange[j] = tbuff[i]) != '='; j++, i++);

	//Need to consider even '='
	j++;

	pchallange[j] = '\0';

	*pchallenge_len = j;

	return 0;
}

int xmpp_write_to_server(char *buff, int len)
{
	int fd = 0;
	int retval  = 0;
	
	//XMPP_DEBUG("-->C2S sending buffer_len :%d, buffer :%s\n", len, buff);
	fd = get_sock_fd();

	retval = write(fd, buff, len);
	if(retval<0)
	{
		perror("Error in write");
		printf("error in writing data to server retval :%d", retval);
		exit(0);
	}

	//XMPP_DEBUG("-->C2S success sending data retval :%d\n", retval);
	return retval;
}

int xmpp_read_from_server(char *buff, int len)
{
	int fd = 0;
	int retval  = 0;
	
	//XMPP_DEBUG("-->S2C reading from server\n");
	fd = get_sock_fd();

	retval = read(fd, buff, len);
	if(retval<0)
	{
		printf("error in reading response from server retval :%d", retval);
		exit(0);
	}

	buff[retval] = '\0';

	//XMPP_DEBUG("-->S2C success reading data from server retval :%d, data :%s\n", retval, buff);

	return retval;
}


