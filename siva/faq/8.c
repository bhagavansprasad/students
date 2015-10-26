#define STYLE1 char
main()
{
	typedef char STYLE2;
	STYLE1 x;
	STYLE2 y;
	x=255;y=255;
	printf("%d  %d\n", x,y);
}

