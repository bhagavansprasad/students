void swapping(char *x, char *y)
{
	char *pt =  NULL;

	print ("%s", x);
	print ("%s", y);

	pt = x;
	x = y;
	y = pt;

	print ("%s", x);
	print ("%s", y);
}

main()
{
	char arr1[20] = "Aura Networks";
	char arr2[20] = "Bangalore";

	print ("%s", arr1);
	print ("%s", arr2);

	swap(arr1, arr2);

	print ("%s", arr1);
	print ("%s", arr2);
}
