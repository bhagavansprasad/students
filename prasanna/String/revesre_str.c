 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>

 void reve(char *s)
{
    
  char *end ; 
for(end = s + (strlen(s) - 1); end > s ; --end, ++s)
    {
        (*s) ^= (*end);
        (*end) ^= (*s);
        (*s) ^= (*end);
    }
 }

int main(void)
{
    char *c = malloc(sizeof(char *) * 250);
    scanf("%s", c);
    reve(c);
    printf("\nReverse String %s\n", c);
}
