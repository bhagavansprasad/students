#include "stdio.h"
#include "fcntl.h"
#include "fop.h"

int main()
{
	char buff[100];
	int t,t1,rval,len = 10;

	t  =  aopen("t.txt",O_RDONLY, 0);
	t1 =  aopen("t7.txt",O_RDWR|O_CREAT, 0777);
	
	while( 1 )
	{
		rval=aread(t,buff,len);

		buff[rval]='\0';
	
		printf("%s",buff);
		
		awrite(t1,buff,rval);
		
		if(rval < len)
		  break;
	}
	aclose(t);
	aclose(t1);
	
	return 0;
}
