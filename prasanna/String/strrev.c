//#include<stdio.h>

#include <stdio.h>
#include <string.h>

void my_strrev(char* begin){
    char temp;
    char* end;
    end = begin + strlen(begin)-1;

    while(end>begin){
        temp = *end;
        *end = *begin;
        *begin = temp;
        end--;
        begin++;
    } 
}

main(){
    char string[20] = "DELLL INDIA";

	printf("Before reverse :%s\n",string);
    my_strrev(string);

    printf(" After reverse  :%s\n", string);
}

/*#include<string.h>
char *Reverse(char *,char *);
int main()
{
	char str[100],temp[100];
	printf("Enter a string to reverse: ");
	gets(str); 
	printf("%s\n",Reverse(str,temp));
	printf("Reversed string: "); 
	puts(str); 
	strcpy(temp,str);
	printf("%s\n",temp);

	return 0; 
}
char *Reverse(char *str,char *temp)
{
	int i,j,len=0; 
	for(i=0;str[i]!='\0';i++)	
		len++; 
	for(i=len-1,j=0; i+1!=0; --i,++j) 
	{ 
		temp[j]=str[i];
	}
	temp[j]='\0'; 
	return temp; 
}


#include<stdio.h>

int main(int argc,char *argv[])
{
	int n,res=0,t;
	n=atoi(argv[1]);
	while(n)
	{
		
		t=n%10;
		n=n/10;
		res=res*10+t;
	
	}
               
	printf("\n%d",res);
	return 0;
i}

*/
