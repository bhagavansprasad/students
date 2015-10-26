#include <stdio.h>
static int i;
static int i = 25;
static int i;
//i = 20;// we cant write assignment stmt globally
/*initialization is diff from assignment
initialization: assigning a value to a var at the time of declaration
assignment: assigning a value not at the time of declaration*/
//static int i = 20; Again initialization leads to error:redefinition of i
int main()
{
int j=0;
i = 20;		//assignment stmt by placing this stmt o/p:20
			//static int i; if u give this stmt o/p:0 bcoz ststic default val is 0
printf("%d\n", i);//otherwise it prints 25
for(j=0;j<4;j++)
{
static int a = 10; //initialization is done only once
printf("%d \t", a); //o/p 10 11 12 13
a++;
}
return 0;
}

