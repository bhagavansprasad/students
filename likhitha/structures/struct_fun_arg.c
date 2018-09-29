#include <stdio.h>
#include<string.h>

struct book{
	int pages;
	float price;
	char bookname[9];
};


void funct(struct book a);


int main()
{
	struct book a1={100 , 21 , "abc" };
	struct book a2;
	a2.pages = 200;
	a2.price = 31.7;
	strcpy(a2.bookname, "xyz");

	funct(a1);
	funct(a2);
}
void funct(struct book a)
{
	printf("%d\n",a.pages);
	printf("%f\n",a.price);
	printf("%s\n",a.bookname);
	printf("--> size of structre : %d\n", sizeof(a));

}

