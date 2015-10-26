#include<stdio.h>
char  *toggle(char *t);

main()
{
	char s1[100]="Aura Networks";
	char *s2;
	int i;
	printf("B S1:%s\n",s1);
	printf("B S2:%s\n",s2);
	
    s2=toggle(s1);
	
	printf("A S1:%s\n",s1);
	printf("A S2:%s\n",s2);
}
/* toggle(char *d,char *t)
{
	int i;
	for(i=0;t[i]!='\0';i++)
	{
	  if(t[i]>='A' && t[i]<='Z')
	  {
	    d[i]=t[i]+32;
	  }
	  if(t[i]>='a' && t[i]<='z')
	  {
	    d[i]=t[i]-32;
	  }
	  if(t[i]>=32  && t[i]<=64)
	  {
	    d[i]=t[i];
	  }	

  }          */
char *toggle(char t[])
{
	int i;
	char k[100];
	for(i=0;t[i]!='\0';i++)
	{
	  if(t[i]>='A' && t[i]<='Z')
	  {
	    k[i]=t[i]+32;
	  }
	  if(t[i]>='a' && t[i]<='z')
	  {
	    k[i]=t[i]-32;
	  }
	  if(t[i]>=32  && t[i]<=64)
	  {
	    k[i]=t[i];
	  }	

  }
  return k;


}
/*
toggle(char d[],char t[])
{
	int i;
	for(i=0;t[i]!='\0';i++)
	{
	  if(t[i]>='A' && t[i]<='Z')
	  {
	    d[i]=t[i]+32;
	  }
	  if(t[i]>='a' && t[i]<='z')
	  {
	    d[i]=t[i]-32;
	  }
	  if(t[i]>=32  && t[i]<=64)
	  {
	    d[i]=t[i];
	  }	

  }
}*/
