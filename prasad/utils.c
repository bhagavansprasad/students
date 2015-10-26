#include"stdio.h"

int rstrlen(const char *s)
{
	int i;
	for(i=0;s[i]!='\0';i++);
	return i;
}


int rstrcmp(const char *s1,const char *s2)
{
	int i;
	for(i=0;s1[i]!='\0';i++)
	{
		if(*s1==*s2)
			s1++,s2++;
		
		else 
			return *s1-*s2;
	}
	return *s1-*s2;
}


int rstrncmp(const char *s1,const char *s2,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(*s1==*s2)
			s1++,s2++;
		else 
			return *s1-*s2;
	}
	return *s1-*s2;
}


char *rstrcpy(char *dest ,const char *src)
{
  int i,l;
  l=rstrlen(src);
  for(i=0;i<=l;i++)
    dest[i]=src[i];
  return dest;
}


char *rstrncpy(char *dest ,const char *src,int n)
{
  int i,l;
  for(i=0;i<n;i++)
    dest[i]=src[i];
dest[n]='\0';
  return dest;
}


char *rstrcat(char *dest,const char *src)
{
  int l,l1,i;
  l=rstrlen(dest);
  l1=rstrlen(src);
  for(i=0;i<=l1;i++)
    dest[l+i]=src[i];
  return dest;
}


char *rstrncat(char *dest,const char *src,int n)
{
  int l,l1,i;
  l=rstrlen(dest);
  for(i=0;i<n;i++)
    dest[l+i]=src[i];
  dest[l+n]='\0';
  return dest;
}


char *rstrlwtoup(char *p)
{
  int i;
  char upr[20];
  for(i=0;p[i]!='\0';i++)
  {
    if(p[i]>='a'||p[i]<='z')
    {
      upr[i]=p[i]-32;
  }
  }
  upr[i]='\0';

  return upr;
}


