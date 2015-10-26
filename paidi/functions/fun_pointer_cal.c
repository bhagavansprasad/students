#include<stdio.h> 
int add_func (int a, int b)
{
  return a+b;
}

int sub_func (int a, int b)
{
  return a-b;
}

int mul_func (int a, int b)
{
  return a*b;
}

int div_func (int a, int b)
{
  return a/b;
}


int main(void)
{
    int retval = 0;
    int(*fptr)(int,int); // Function pointer 

    fptr = add_func;
    retval = fptr(2,3);
	printf("add-->= %d\n",retval);

    fptr = sub_func;  
    retval = sub_func(20,10);
	printf("sub-->= %d\n",retval);

    fptr = &mul_func; 
    retval = fptr(3,4);
	printf("mul-->= %d\n",retval);

    fptr = &div_func;  
    retval = fptr(10,4);
	printf("div-->= %d\n",retval);

   }
