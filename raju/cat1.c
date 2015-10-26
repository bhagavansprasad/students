#include<stdio.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	char s[100][100],p=' ';
	int i,j,t=0,l=10,sl,tsl,wc=0,twc,nl=0,tnl,fd;
	for(j=1;j<argc;j++)
	{
	  
	 fd=open(argv[j],0,O_RDONLY);
      twc=0;
	  tnl=0;
	  tsl=0;
	for(i=0; ;i++)
	{
	   t=read(fd,s[i], l);
	   s[i][t]='\0';
	   printf("%s\n",s[i]);
	   wc=get_word_count(s[i],p);
	   printf("wc:%d\n",wc);
	   p=s[i][t-1];
	   twc=twc+wc;
	   sl = astrlen(s[i]);		//write astrlen since strlen is a built in fn.
	   printf("no.c:%d\n",sl);
	   tsl = tsl + sl;
	   nl=get_number_of_lines(s[i]);
	   printf("no.l:%d\n",nl);
	   tnl=tnl+nl;
		if(t<l)
		{
		  break;
		}  
     }

	//printf("no. of characters=%d\n",tsl);
	//printf("no. of words=%d\n",twc);
	//printf("no. of lines=%d\n",tnl);
   
	printf("%3d  %d %d t.txt\n", tnl, twc, tsl);
	
  }
	close(fd);
}


int astrlen(char sp[])
{
	int i;
	for(i=0;sp[i]!='\0';i++);
	return i;
}


int get_number_of_lines(char  sp[])
{
	int i,x=0;
	for(i=0;sp[i]!='\0';i++)
	{
		if(sp[i]=='\n')
		{
			x++;
		}
	}
	return x;
}
/*int get_word_count(char *sp)
{
	int i,x=0;
	for(i=0;sp[i]==' ';i++);

	for(;sp[i]!='\0';i++)
	{
		if(sp[i]==' ')
		{
			if(sp[i-1]!=' ')
			{
				x++;
			}
		} 
    }
	for(i=0;sp[i]!='\0' ;i++)
	{
		if(sp[i]=='\n')
		{
			x++;
		}  
}		
		if(sp[i]=='\0' && sp[i-1]=='\n') 
		{
		if(sp[i-2]==' ')
		{
		  x--;
		}  
		}
		
		if(sp[i]=='\0' && sp[i-1]!=' ')
		
		{
		  x++;
		}  
		return x;
	

		  


		if(sp[i-1]==' ' || sp[0]==' ')
		{

		if(sp[i-1]==' ' && sp[0]==' ')
		{
		return x-1;
		}  

		if(sp[i-1]==' ')
		{
		return x;
		} 

		if(sp[0]==' ')
		{ 
		return x;
		}  		

		}  
		else
		{
		return x+1;
		} 
	

}   */














