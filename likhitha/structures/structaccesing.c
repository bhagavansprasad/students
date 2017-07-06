#include<stdio.h>
#include<string.h>

struct book{
	int pages;
	float price;
	char bookname[9];
	char a;
	char d;
	char c;
	char b;
};

int main()
{
	struct book a1={100 , 21.5 , "abc" };
/*	a1.pages = 100;
	a1.price = 21.5;
	strcpy(a1.bookname, "abc");
	a1.a = 'z';
	a1.d = 'z';
	a1.c = 'z';
a1.b = 'z';
*/
	printf("%d\n",a1.pages);
	printf("%f\n",a1.price);
	printf("%s\n",a1.bookname);
	printf("--> size of structre : %d\n", sizeof(a1));
}

