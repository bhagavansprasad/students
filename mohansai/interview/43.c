char* myFunction (char *ptr)
{
   ptr += 3;
   return (ptr);
}
int main()
{
   char *x, *y;
   x = "HELLO";
   y = myFunction (x);
   printf ("y = %s \n", y);
   return 0;
}
