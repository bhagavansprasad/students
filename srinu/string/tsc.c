#include<stdio.h>
#include<fcntl.h>
int main()
{
	int len=0,line=0,wc=0,twc=0,tlen=0,tline=0,f,fd=0,size=10;
	char buff[100];
	fd=open("k.c",0,O_RDONLY);
	while(1)
	{
		f=read(fd,buff,size);
		buff[f]='\0';
		printf("%s",buff);
		len=astrlen(buff);
		tlen=tlen+len;
		printf("%d\n",tlen);
		wc=get_word_count(buff);
		twc=twc+wc;
		line=get_line_count(buff);
		tline=tline+line;
		if(f<size)
			break;
	}
	printf("%d",tlen);
	printf("%d",tline);
	printf("%d",twc);
}
int astrlen(char *pb)
{
	int i;
	for(i=0;pb [i]!='\0';i++);
	return i;
}
int get_line_count(char *pb)
{
	int i,line=0;
	for(i=0;pb[i]!='\0';i++)
	{
		if(pb[i]=='\n')
			line++;
	}
	return line;
}
/*int get_word_count(char *pb)
  {
  int i,j=0;
  for(i=0;pb[i]!='\0';i++)
  {
  if(pb[i]==' ')
  j++;
  }
  return j;
  }
  int get_word_count(char *pb)
  {
  int i,wc=0;
  for(i=0;pb[i]==' ';i++);
  for(;pb[i]!='\0';i++)
  {
  if(pb[i-1]==' ')
  {
  if(pb[i+1]!='\0 ')
  {
  wc++;
  }
  }
  }
  if((pb[i]==' '||pb[i]==' '||pb[i]=='\n')&&pb[i-1]==' '&&pb[i+1]!='\0 ')
  wc++;
  return wc;
  }
  int get_word_count(char *pb)
  {
  int i,wc=0;
  for(i=0;pb[i]==' ';i++);
  for(;pb[i]!='\0';i++)
  {
  if(pb[i]==' ')
  {
  if(pb[i-1]!=' ')
  {
  wc++;
  }
  }
  }
  if(pb[i]=='\0'&&pb[i-1]!=' ')
  wc++;
  return wc;
  }
  int get_word_count(char *pb)
  {
  int i,wc=0;
  for (i=0; pb[i]!='\0'; i++)   
  {
  if(pb[i]==' ')    
  {
  wc++;
  }
  }
  return wc;
  }
  int getN(char *);
  int main(){
  char str[999];
  printf("Enter Sentence: "); gets(str);
  printf("there are %d words", getN(str));
  }
  int get_word_count(char *pb)
  {

  int i = 0, len, c= 0,buff;
  len =astrlen(buff);
  if(pb[i] >= 'A' && pb[i] <= 'z')
  c++;
for (i = 1; i<len; i++)
if((pb[i]==' ' || pb[i]=='\t' || pb [i]=='\n')&& pb[i+1] >= 'A' && pb[i+1] <= 'z')
c++;
return c;
}*/
int get_word_count(char *pb)
{
	int i,wc=0;
	for(i=0;pb[i]!='\0';i++)
	{
		if(pb[i]==' '&&pb[i+1]!=' ')
			wc++;
	}
	if(wc>1)
		return wc;
}
