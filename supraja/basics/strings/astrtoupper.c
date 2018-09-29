astrtoupper(char *ptr)
{
	int i;
	for(i=0;ptr[i]!='\0';i++)
	{
		if(ptr[i]>=97&&ptr[i]<=128)
		{
			ptr[i]=ptr[i]-32;
		}
		return (ptr[i]);
	}
}
