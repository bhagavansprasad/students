int word_count(char *p)
{
	int i=0,count=0;
	for(i=0;p[i]!='\0';i++)
	{
	 	if(p[i]==' ')
		count+=1;

		if((p[i+2]=='\0')&&(p[i]!=' '))
		 count+=1;
	}
	return (count);
}
