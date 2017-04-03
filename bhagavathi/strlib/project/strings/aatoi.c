int aatoi(char *a)
{
	int i,val=0;
	for(i=0 ; a[i] != '\0'  ; i++)
	{
		if(a[i] >='0' && a[i] <= '9')
			val=(val*10)+(a[i]-'0');
		else
			return val;
	}
	return val;
}


