#include"stdio.h"
#include"stdlib.h"
#define SIZE 5
int a[SIZE];
int insert_element(int m,int n)
{
 int i;
 if(m<SIZE)
 {
 a[m]=n;
return;
}
else printf("THE ARRAY SIZE EXCEEDED");
exit(1);
}
main()
{
  int i;
  insert_element(0,10);
  insert_element(1,20);
  insert_element(2,30);
  insert_element(3,40);
  insert_element(4,50);

  insert_element(3,90);

  insert_element(5,90);
printf("THE ELEMENTS AFTER INSERTION");
  for(i=0;i<SIZE;i++)
  {
    printf(" %d \n",a[i]);
  }
}

