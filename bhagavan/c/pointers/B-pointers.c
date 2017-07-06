void swapping(char *x, char *y)
{
	char pt[100];

	print ("%s", x);
	print ("%s", y);

	strcpy(pt, x);
	strcpy(x, y);
	strcpy(y, pt);

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
