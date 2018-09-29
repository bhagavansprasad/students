void print(int p, int q) 
{ 
  if (p > q)
  {
    printf("%d\n", p--);
    print(p,q);
  }
  else if (p < q)
  {
    printf("%d\n", p++);  
    print(p,q);    
  }
  else
  {
    printf("%d, %d\n", p, q);
    return;
  }
} 
int main() 
{ 
  print(1, 3);  
  return 0; 
}


