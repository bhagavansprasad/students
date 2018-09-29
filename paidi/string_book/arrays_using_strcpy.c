 #include<stdio.h>

int main()
{
    char str1[12]="paidi kumar";
	char str2[12]="aura";
    int i=0;
    while(str1[i]!='\0')
	{
         str2[i] = str1[i];
         i++;
    }
    str2[i]='\0';
    printf("copy string---->=%s\n",str2); 
}
