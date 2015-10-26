int ratoi(char *s)
  {
  int j,res=0,n;
  for(n=0;s[n]!='\0';n++)
  {
  j=s[n]-'0';
  res=res*10+j;
  }
  return res;
  }
int palin(char *str)
{
	int len,i,n;
	char str1[10];
	len=rstrlen(str);
	printf("len=%d \n",len);
	for(i=0;i<len;i++)
	{
		str1[i]=str[len-1-i];
	}
	str1[i]='\0';

	n=rstrcmp(str,str1);
printf("n==%d \n",n);
	if(n==0)
		return 0;
if(n!=0)
return 1;
//printf("ITS not a palindrome number");

}


