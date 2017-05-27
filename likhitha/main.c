#include<stdio.h>
main()
{
	char arr[] = "1921 (a.out) R 1544 1921 1544 34817 1921 4210688 73 0 0 0 1298 4790 0 0 20 0 1 0 771766 2080768 130 4294967295 134512640 134514140 3220278560 3220276824 3078356300 0 0 0 0 0 0 0 17 0 0 0 0 0 0 134520584 134520868 164876288 3220283838 3220283844 3220283844 3220287476 0";
	int sum , a,b,c,d,e,f,g,h,i,j,k,l,m,n,o;
	char s1[20];
	char s2[10];

	sscanf(arr, "%d %s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&a, s1, s2, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &o);
	printf("value13 : %d \n ",k);
	printf("value14 : %d \n ",l);
	printf("value15 : %d \n ",m);
	printf("value16 : %d \n ",n);
	printf("value17 : %d \n ",o);

	sum=k+l+m+n+o;
	printf("sum: %d\n",sum);
}
