int func(int * a, int * b)
{
  if(*a > *b)
    printf("%d", *a);
  else
    printf("%d", *b);
}
int main()
{  
  int a = 10, b = 8;
  func(a, b);
  return 0;
}


