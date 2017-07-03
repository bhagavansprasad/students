#include<stdio.h>
#include<string.h>

union book{
	int pages;
	float price;
	char bookname[8];
};

int main()
{
//	union book a1={200 , 31.5 , "abc" };
	union book a1;
	a1.pages = 100;
	a1.price = 21.5;
	strcpy(a1.bookname, "xyz");

	printf("%d\n",a1.pages);
	printf("%f\n",a1.price);
	printf("%s\n",a1.bookname);
	printf("--> size of union: %d\n", sizeof(a1));
}

