main()
{
	char *p1 = "Aura Networks";
	char *p2 = "Bangalore";
	char *pt =  NULL;

	print ("%s", p1);
	print ("%s", p2);

	pt = p1;
	p1 = p2;
	p2 = pt;

	print ("%s", p1);
	print ("%s", p2);
}
