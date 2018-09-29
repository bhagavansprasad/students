main()
{
	int i,count=0;
	char *p1="abcdefghij",*p2="alcmenfoip";
	printf("STRLEN : %d\n",strlen(p1));
	for(i=0;i<=strlen(p1);i++)
	{
		if(*p1++ == *p2++)
		{
			count+=5;
			printf("P1 : %c\n",*p1++ );
			printf("P1 : %c\n",*p2++ );
			printf(" TRUE : %d\n",count);
		}
		else
		{
			count-=3;
			printf("P1 : %c\n",*p1++ );
			printf("P1 : %c\n",*p2++ );
			printf("FALSE : %d\n",count);
		}

	}
	printf("END :%d\n",count);
}
