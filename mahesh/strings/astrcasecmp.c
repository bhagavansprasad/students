char lowr (char );

int astrcasecmp (char *p1,char *p2)
{
	int i , rv;

	char p3 , p4;

	for (i=0; p1[i] != '\0' && p2[i] != '\0'; i++)
	{
		p3 = lowr(p1[i]);

		p4 = lowr(p2[i]);

		if(p3 != p4)
		{
			rv = 1;
			break;
		}
	}

	if ((p1[i] != '\0' && p2[i] == '\0') || (p1[i] == '\0' && p2[i] != '\0'))
		rv = 1;

	return(rv);

}
char lowr ( char l)
{

	if (l >= 65 && l <= 90)
		l = l+32;

	return(l);
}
