 #define CUBE(x) (x*x*x)
main()
 {
   int a,b=3;
   a=CUBE(b++);
   printf("\n %d %d",a,b); 
 }
