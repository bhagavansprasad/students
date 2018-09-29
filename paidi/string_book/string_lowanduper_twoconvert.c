main()
{
	char b[30]="pAiDI KUmaR";
	int i;
	for(i=0; i<10; i++)
	{
		if(b[i]>=65 && b[i]<=91)
		{
			b[i]+=32;
		}
		else

			if(b[i]>=97 && b[i]<=122)
			{
				b[i]-=32;
			}
	}
	printf("%s\n",b);

}
