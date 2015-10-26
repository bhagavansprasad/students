int char_count(char *p)
{
int i=0,count=1;

for(i=0;p[i]!='\0';i++);
   { 
    if(p[i]==' ')
	  count+=1;
   }
  i-=count;
return (i);
}
