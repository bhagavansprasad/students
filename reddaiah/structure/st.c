#include"stdio.h"
#include"string.h"
struct books
{
	char title[50];
	char author[30];
	char subject[25];
	int rollno;
};
int main()
{
	struct books book1;
	strcpy(book1.title,"cprograming");
	strcpy(book1.author,"ali nuice");
	strcpy(book1.subject,"cbasics");
	book1.rollno=254361;
	printf("book1 title:%s\n",book1.title);
	printf("book1 author:%s\n",book1.author);
	printf("book1 subject:%s\n",book1.subject);
printf("books book1.id:%d\n",book1.rollno);
return 0;
}
