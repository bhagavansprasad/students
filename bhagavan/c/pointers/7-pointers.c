void swapping(char *x, char *y)
{
	char *p1;
	char *p2;
	char *pt =  NULL;

	p1 = x;
	p2 = y;

	print ("%s", x);
	print ("%s", y);
	print ("%s", p1);
	print ("%s", p2);

	pt = p1;
	p1 = p2;
	p2 = pt;

	print ("%s", x);
	print ("%s", y);
	print ("%s", p1);
	print ("%s", p2);
}

main()
{
	char arr1[20] = "Aura Networks";
	char arr2[20] = "Bangalore";
	char *p1;
	char *p2;

	p1 = arr1;
	p2 = arr2;

	print ("%s", arr1);
	print ("%s", arr2);
	print ("%s", p1);
	print ("%s", p2);

	swap(p1, p2);

	print ("%s", arr1);
	print ("%s", arr2);
	print ("%s", p1);
	print ("%s", p2);
}
