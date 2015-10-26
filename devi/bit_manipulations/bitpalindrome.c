#include <stdio.h>
#include <stdbool.h>
bool isPalindrome(int n)
{
	int i,j,c,d=0;
	for(i=0,j=7;j>i;j--,i++)
	{
		c = (n&(1<<i));
		if(c==0)
		c=0;
		else
		c=1;

		d = (n&(1<<j));
		if(d==0)
		d=0;
		else
		d=1;

		if(c!=d)
		break;
	}
	if(j<i)
	return 1;
	else
	return 0;
}
main()
{
	int a = 195,w;
	w = isPalindrome(a);
	if(w)
	printf("True");
	else
	printf("false");

}
