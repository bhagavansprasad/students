#include <stdio.h>
main()
{
	struct book
	{
		int pages;
		float price;
		char name[100];
	};

	struct book a1 = { 31 , 51.5 , "book1"};
	struct book b1 = { 31 , 51.5 , "book1"};
	printf("%d %f %s \n",a1.pages ,a1.price , a1.name);
	printf("%d %f %s \n",b1.pages ,b1.price , b1.name);
}


