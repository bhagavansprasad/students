#include <stdio.h>
#include <string.h>
main()
{
	char arr[]="132710";
	char str[5],time[20];
	int a[3];
	int i =0,j=0;
	for(i=0;i<3;i++,j+=2)
	{
		strncpy(str,arr+j,2);
		str[2]='\0';
		a[i]=atoi(str);
	}
	sprintf(time,"%d:%d:%d",a[0],a[1],a[2]);
	printf("%s\n",time);
}
