#include<stdio.h>
int main(int argc, char *argv[]) {
 float result = atoi(argv[1]);
 int i;
 for (i = 3; i < argc; i = i + 2)
 switch (*argv[i-1]) {
 case '+':
 result = result + atoi(argv[i]);
 break;
 case '-':
 result = result - atoi(argv[i]);
 break;
 case '*':
 result = result * atoi(argv[i]);
 break;
 case '/':
 result = result / atoi(argv[i]);
 break;
 default:
 printf("Wrong Input");
 }
 printf("\nResult = %f", result);
}
#if 0
#include<stdio.h>
int main(int argc, char *argv[])

{
 int firstNum = atoi(argv[1]);
 int secondNum = atoi(argv[2]);
 int sum = firstNum + secondNum;
 printf("%d + %d = %d", firstNum, secondNum, sum);
 
}
#endif
#if 0
#include <stdio.h>
void main(int argc, char * argv[]) 
{
   int i, sum = 0;
 
   if (argc != 4)
   {
      printf("You have forgot to type numbers.");
      exit(1);
    }
 
   printf("The sum is : ");
 
   for (i = 1; i < argc; i++)
      sum = sum + atoi(argv[i]);
 
   printf("%d", sum);
 
}
#endif

