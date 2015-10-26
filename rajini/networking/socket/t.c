main()
{
	char b1[100] = "Hi";
	char b2[100] = "How are you";
	char b3[100];

	sprintf(b3, "%s %s", b1, b2);

	printf("-->b3 :%s\n", b3);
}
