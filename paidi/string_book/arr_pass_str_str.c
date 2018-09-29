#include <string.h>
#include <stdio.h>

char* my_str_str(char*p1,char*p2)
{
	int i=0,j=0,k;
	for(i=0;p1[i]!='\0';i++)
	{
		if(p1[i] == p2[0])
		{
			k=i;
			for(j=0;p2[j]!='\0';j++,k++)
			{
				if(p1[k]!=p2[j])
					break;
			}
		}
		if(p2[j] == '\0')
		{   
			return &p1[i];
		}
	}
	return NULL;
}

int main()
{
	char*retstr;
	char str1[]="paidi kumar";
	char str2[]="kumar";

	retstr = my_str_str(str1,str2);
	if(retstr!=NULL)
		printf("find sub_string     :%s\n",retstr);
	else
		printf("No sub_string       :%s\n",retstr);

}

