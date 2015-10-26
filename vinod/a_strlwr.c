char a_strlwr(char ch)
{
	if(ch>='A' && ch<='Z')
		return ch+=32;
	return ch;
}
