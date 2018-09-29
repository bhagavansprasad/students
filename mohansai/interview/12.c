void func(int *str)
{
  printf("%s",str);
}
int main()
{
  char str[]="hello world";
  func(str+1);
  return 0;
}


