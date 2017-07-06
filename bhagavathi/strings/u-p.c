#include <stdio.h>
#include <string.h>
void user(char *ur,int pw);
int main()
{
char username[]="ravi andhra";	
int pass=9741;
user(username,pass);
return 0;

}
void user(char *ur,int pw)
{
printf("%s\n",ur);
printf("%d\n",pw);
}


