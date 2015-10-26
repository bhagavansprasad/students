char str[]="@ #  a  c  d  .  >  ";
int argument(char *s , char deli)
{
 int i,t,k;
 char name[30];
 for(i=0;s[i]!='\0';i++)
 {
  if(s[i]==deli)
    continue;
	else
	{
	t=s[i]-48;

	printf("%d\t ",t);
	}
  }
}
int main(void)
{
 argument(str,' ');
}
