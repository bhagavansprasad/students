#include <stdio.h>
int main()
{
struct student
{
char name[100];
int roll;
int marks;
};
struct student s={"sreenivasula reddy",12704,78};
      printf("\nDisplaying Information\n");
    printf("Name: %s\n",s.name);
    printf("Roll: %d\n",s.roll);
    printf("Marks: %d\n",s.marks);
}
