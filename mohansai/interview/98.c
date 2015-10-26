#include<stdio.h>

int i = 0;

int main()

{

static i=3;

printf("%d ",i--);

return i>0 ? main():0;

return 0;

}
