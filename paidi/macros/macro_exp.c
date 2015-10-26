#include <stdio.h>
#define CUBE(x) (x*x*x)
#define BOSS(y) (y*y*y*y)
#define DON(z) (z*z*z*z*z)
main()
{
	int A=0, b =3;
	int C=0, d =3;
	int K=0, l =3;

	A = CUBE(b++);
	C = BOSS(d++);
	K = DON(l++);

	printf("macro-->= %d, a-->=%d \n",A,b);
	printf("macro-->= %d, d-->=%d \n",C,d);
	printf("macro-->= %d, l-->=%d \n",K,l);
  return 0;
}
