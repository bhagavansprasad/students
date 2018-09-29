int word_count(char *p)
{ 
	int i=0,count=0;
	for(i =0; p[i] != '\0'; i++)
	{ 
		if ((p[i]!=' ')&&(p[i+1]=='\0')||(p[i]!=' ')&&(p[i+1]==' '))
		{ 
			count++;
		}

		
	}
	return(count);
}
