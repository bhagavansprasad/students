int get_word_count(const char *s)
{
	int i=0,wc;

	if(s[i]==' ')
		wc=0;
	else
		wc=1;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]==' ' && s[i+1]!=' '&& s[i+1]!='\0')
			wc++;
	}
	return wc;
}

