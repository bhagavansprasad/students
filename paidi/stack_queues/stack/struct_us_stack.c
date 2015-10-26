/*
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define size 5
struct stack 
{
   int s[size];
   int top;
} st;

int stfull() 
{
   if (st.top >= size - 1)
      return 1;
   else
      return 0;
}

void push(int item) 
{
   st.top++;
   st.s[st.top] = item;
}

int stempty() 
{
   if (st.top == -1)
      return 1;
   else
      return 0;
}

int pop()
{
   int item;
   item = st.s[st.top];
   st.top--;
   return (item);
}

void display() 
{
   int i;
   if (stempty())
      printf("\nStack Is Empty!");
   else
   {
      for (i = st.top; i >= 0; i--)
         printf("\n%d", st.s[i]);
   }
}

int main() 
{
   int item, choice;
   char ans;
   st.top = -1;

   printf("\n\tImplementation Of Stack");
   do {
      printf("\nMain Menu");
      printf("\n1.Push \n2.Pop \n3.Display \n4.exit");
      printf("\nEnter Your Choice");
      scanf("%d", &choice);
      switch (choice)
	  {
      case 1:
         printf("\nEnter The item to be pushed");
         scanf("%d", &item);
         if (stfull())
            printf("\nStack is Full!");
         else
            push(item);
         break;
      case 2:
         if (stempty())
            printf("\nEmpty stack!Underflow !!");
         else
		 {
            item = pop();
            printf("\nThe popped element is %d", item);
         }
         break;
      case 3:
         display();
         break;
      case 4:
         exit(0);
      }
      printf("\nDo You want To Continue?");
      ans = getche();
   } while (ans == 'Y' || ans == 'y');

return 0;
}

*/

#include<stdio.h>
#define MAX 3                                    
struct name
{
	int top;
	int stack[MAX];
};
struct name s;

void push(int p1)
{
	printf("top-->%d\n",s.top);
	if(MAX == s.top)                 
	{
		printf("stack overflow\n");
	}
	else
	{
		s.top++;                               
		printf("top suss-->%d\n",s.top);
		s.stack[s.top] = p1;                       
		printf("%d succ. pushed\n",p1);
	}

}
int pop(void)
{
	int y;
	printf("\npop strt--> %d\n",s.top);
	s.top--;
		if(s.stack[s.top] == 0)                                   
	{
		printf("\nstack ia empty\n");
		s.top = 0;
		return 0;
	}
	return s.stack[s.top];
	printf("------> %d\n",s.top);
}
int stempty() 
{
	if (s.top == -1)
		return 1;
	else
		return 0;
}

void display() 
{
	int i;
	if (stempty())
		printf("\nStack Is Empty!");
	else
	{
		for (i = s.top; i >= 1; i--)
			printf("\n---|%d|",s.stack[i]);
	}
}


void main()
{
	int retval = 0;
	push(10);
	push(20);
	push(30);
	push(40);
	//push(50);
	//push(60);
	//push(70);
	display();
	retval = pop();
	printf("\npop_val1 %d",retval);
	display();

	retval = pop();
	printf("\npop_val2 %d",retval);
	display();

	retval = pop();
	printf("\npop_val3 %d",retval);
	display();

	retval = pop();
	printf("\npop_val4 %d",retval);
	display();

	retval = pop();
	printf("\npop_val5 %d",retval);
	display();
}

