#include <stdio.h>
main()
{
    int n=10;
	function(n);
}

function(int n)
{
  static int a=-1,b=1,sum=0;
  if(n>0)
  {
		sum=a+b;
		a=b;
		b=sum;
	printf(" %d\t",sum);
    function(n-1);
  }
}


