#include<stdio.h>

union student
{
    int roll;
    char name[100];
    float marks;
};

int main()
{
  union student *ptr = 0;
  ptr++;
  printf("Size of the union student:  %d\n",ptr);
}
