
int gen_key(char *s)
{
	int i = 0,j = 0, c = 0, d = 0,k = 65, l =97;

	if (s[0] >= 'a' && s[0] <= 'z')
		return s[0]-'a';
	else if (s[0] >= 'A' && s[0] <= 'Z')
		return s[0]-'A';
	else
		return 0;

#if 0

	for(i = 65;i <= 90;i++)
	{
		if(k != i)
			c++;

		if(s[0] == i)
			return c;
	}
	for(j = 97; j <= 122; j++)
	{
		if(l != j)
			d++;
		if(s[0] == j)
			return d;
	}
#endif
}
