int india(float x, float y) 
{
   if (y == 0)
     return x;
  else
     return india(x - 1, x + y);
}

int main() 
{
   printf("%d", india(10, 0));
   return 0;
}


