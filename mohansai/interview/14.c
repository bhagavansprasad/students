struct st
{
   short int a : 4;
   short int b : 6;
   short int c : 1;
};
int main()
{
  struct st s1;
  printf("%ld", sizeof(s1));
  return 0;
}


