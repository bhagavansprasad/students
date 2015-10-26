main(int argc,char *argv[])
{
	printf((argc>1 ? "%c":"%c",*++argv));
	printf("%d\n",argc);
	
}
