#include"stdio.h"
#define ARRAY_SIZE 5
int a[ARRAY_SIZE];
int count=0;
int insert(int val)
{
  int i,j;
  if(count<ARRAY_SIZE)
  {
    if(count==0)
    {
      a[count]=val;
      count++;
      return;
    }
    for(i=0;i<count;i++)
    {
      if(val<a[i])
      {
	for(j=count;j!=i;j--)
	{
	  a[j]=a[j-1];
	}
	a[j]=val;
	count++;
	return;
      }
    }
    a[count]=val;
    count++;
    return;
  }
  else printf("THE ARRAY SIZE IS EXCEEDED");
}
main()
{

  int i;
  insert(64);
  insert(47);
  insert(9);
  insert(10);
  insert(1);
  for(i=0;i<ARRAY_SIZE;i++)
    printf(" %d \n",a[i]);

}

