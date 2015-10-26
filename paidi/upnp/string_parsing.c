#include <stdio.h>
#include <string.h>
main()
{
	int i=0;
	char temp[50];
	char *ptr;
	char buff[]="<tag1><paidi></tag1><tag2><aura></tag2><tag3><networks></tag3><size><100000></size>";
	ptr=buff;

	ptr=strstr(buff,"tag2");
	for(;*ptr++!='<';);
	for(;*ptr!='>';ptr++)
	{
		temp[i++]=*ptr;
	}
	temp[i]='\0';
	printf("string---->=%s\n",temp);

	i=0;
	ptr=strstr(buff,"size");
	for(;*ptr++!='<';);
	for(;*ptr!='>';ptr++)
	{
		i=i*10+(*ptr-48);
	}
	printf("valu----->=%d\n",i);
}
