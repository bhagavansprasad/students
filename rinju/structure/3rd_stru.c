#include<stdio.h>
#include<string.h>
	struct books
	{
		char title[20];
		char author[24];
		int id;
	};		
void printbook(struct books*);
main()
{
	
	struct books book1={"hindi","rinju",23};
	struct books book2;
	strcpy(book2.title,"odiya");
	strcpy(book2.author,"bapi");
	book2.id=14;
	printf("%d",sizeof(struct books));
	printf("%d",sizeof(book1));
	printbook(&book1);
	printbook(&book2);
}
void printbook(struct books *book)
{
printf("%s %s %d ",book->title,book->author,book->id);
}
