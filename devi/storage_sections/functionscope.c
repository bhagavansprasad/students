#include <stdio.h>
void display();
int main()
{
printf("In main\n");
goto xyz;
//printf("In main\n");
//xyz:
//display();
printf("In main\n");
return 0;
}

void display()
{
xyz:
printf("goto");
printf("In function display");
}
	
