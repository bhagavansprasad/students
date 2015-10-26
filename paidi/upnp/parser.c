main()
{
	int i=0,n=0;
	char buff[]="<root><paidi><major>1</major><minor>0</minor></specVersion><device><deviceType>urn:schemas-upnp-org:device:MediaServer:1</deviceType></root>";
	char *ptr;
        char temp[100];
	ptr=buff;
	ptr=strstr(buff,"major");
	while (*ptr++!='>');
	while (*ptr!='<')
	{
		i = n*10+(*ptr-48);
		ptr++;
	}
	printf("%d\n",i);
	i=0;
	ptr=strstr(buff,"deviceType");
	while(*ptr++!='>');
	while(*ptr!='<')
	{
		temp[i++]=*ptr;
                ptr++;
	}
	temp[i]='\0';
	printf("%s\n",temp);

}
