int astrcmp ( char* p1 , char* p2 )
{
	int flag =0 , i;

	for (i=0; p1[i] != '\0' && p2[i] != '\0'; i++)
	{
		if (p1[i] != p2[i]) 
		{
			flag = 1;

			break;
		}
	} 

	if ((p1[i] != '\0' && p2[i]== '\0') || (p1[i] == '\0' && p2[i] != '\0'))
		flag = 1;

	return (flag);
}
