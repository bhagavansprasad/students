#include<stdio.h>
#include<fcntl.h>
main()
{
	char buf[100]="aura net";
		int len=0;
	len=astrlen(buf);
		printf("%d",len);
}
int astrlen( char *pb)
{
	int i=0;
	for(i=0;pb[i]!='\0';i++);
		return(i);
}

