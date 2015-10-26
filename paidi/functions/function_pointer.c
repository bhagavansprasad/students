#include<stdio.h> 
int my_func (int a, int b)
{
    printf("\n a = %d, b = %d\n",a,b);
} 

int main(void)
{
    int(*fptr)(int,int); // Function pointer 
    fptr = &my_func; // Assign address to function pointer 
    my_func(2,3);
    fptr(7,6); 
}
