int a_strupr(char ch)
{
	if(ch>='a' && ch<='z')
		return ch-=('a'-'z');
	return ch;
}
