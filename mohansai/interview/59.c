main()
{
  int a,b;
  a=sumdig(123); 
  b=sumdig(123);
  printf("%d %d",a,b);
}
sumdig(int n)
  {
  static int s=0;
  int d;
  if(n!=0)
   {
   d=n%10;
   n=(n-d)/10;
   s=s+d;
   sumdig(n);
   }
else return(s);
  }
