#include<stdio.h>
#define MAX 5
int queue[MAX];
 int size= -1;
void push(int x)
{
 if(size == MAX)
  printf("queue over flow\n");
 else
 {
    size++;
    queue[size] = x;
     printf("|%d|\n",queue[size]);
  }
}

main()
{
 push(10);
 push(20);
 push(30);
 push(40);
 push(50);
 push(60);
 push(70);
 push(80);
 push(90);
}

