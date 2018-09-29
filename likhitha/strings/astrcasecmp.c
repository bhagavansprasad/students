int astrcasecmp(char *s1,char *s2)
{
	int i,d,flag=0 ;
	for(i=0 ; s1[i]!='\0' ; i++)
	{
		if(s1[i] >= s2[i])
		{
			d=s1[i]-s2[i];
		}
		else if(s1[i] < s2[i])
		{
			d=s2[i]-s1[i];
		}

		if(d!=32 && d != 0)
		{
			flag=1;
			break;
		}
	}
	return flag;
}
