int isprime( int m)
{
 	int c=0,i;
	for( i=2;i<m;i++)
	{
		if( m%i==0)
		{
			c=c++;
			break;
		}
	}
	return(c);
}
