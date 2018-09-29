#include <stdio.h>

int set_bit(int n,int pos,int val)
{
  int i, mask=0,k;
     mask = (val<<pos);
	 k = mask|n;	
	 printf("%d\n",k);
}

main()
{
  int n = 10,pos=5,val=1;
  set_bit(n,pos,val);
}
