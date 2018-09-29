#include<stdio.h>
main()
{
int a, b;
<<<<<<< funct1.c
printf("---->address of a in main() is = %u\n",&a );
printf("---->address of b in main() is = %u\n",&b );
printf("\n");
=======
printf(" a in main() is = %u\n",&a );
printf(" b in main() is = %u\n",&b );
printf("\n");
>>>>>>> 1.2

fun1(a,b);
}

void fun1 (int c, int d)
{
<<<<<<< funct1.c
int l,m, new;

printf("---->address of c in fun1() is = %u\n",&c );
printf("---->address of d in fun1() is = %u\n",&d );
printf("---->address of l in fun1() is = %u\n",&l );
printf("---->address of m in fun1() is = %u\n",&m );
printf("---->address of new in fun1() is = %u\n",&new);
printf("\n");
=======
int l,m;
int new;
printf(" c in fun1() is = %u\n",&c );
printf("d in fun1() is = %u\n",&d );
printf(" l in fun1() is = %u\n",&l );
printf(" m in fun1() is = %u\n",&m );
printf(" new in fun1() is = %u\n",&new );
printf("\n");
>>>>>>> 1.2
fun2(l,m);
}

void fun2(int e, int f)
{
int k,n;

<<<<<<< funct1.c
printf("---->address of e in fun2() is = %u\n",&e );
printf("---->address of f in fun2() is = %u\n",&f );
printf("---->address of k in fun2() is = %u\n",&k );
printf("---->address of n in fun2() is = %u\n",&n );
printf("\n");
=======
printf(" e in fun2() is = %u\n",&e );
printf(" f in fun2() is = %u\n",&f );
printf(" k in fun2() is = %u\n",&k );
printf(" n in fun2() is = %u\n",&n );
printf("\n");
>>>>>>> 1.2
fun3(k, n);
}
void fun3(int g, int h)
{
int o,p;
<<<<<<< funct1.c
printf("---->address of g in fun3() is = %u\n",&g );
printf("---->address of h in fun3() is = %u\n",&h );
printf("---->address of o in fun3() is = %u\n",&o );
printf("---->address of p in fun3() is = %u\n",&p );
printf("\n");
=======
printf(" g in fun3() is = %u\n",&g );
printf(" h in fun3() is = %u\n",&h );
printf("o in fun3() is = %u\n",&o );
printf("p in fun3() is = %u\n",&p );
printf("\n");
>>>>>>> 1.2

}
