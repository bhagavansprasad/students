char atoupper (char ch)
{
	if (ch >= 'a'&& ch <= 'z')
		ch -= 'a' - 'A';
	
	return ch;
}
