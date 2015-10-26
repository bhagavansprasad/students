#include"stdio.h"
int awccount(char strs);
main()
{
	char strs[20][40]={"abc","vbnm","k","dg","vk","rv","prince"};
	int exp_val[20]={3,4,1,2,2,2,6};
	int wc=0,n=7,i=0,j=0;
	for(j=0;j<n;j++)
	{
		wc=awccount(strs[i][j]);
		if(wc!=exp_val[j])
			printf("error:%d and %d are not same",wc,exp_val[j]);
		else
			printf("success:%d and %d are same",wc,exp_val[j]);
	}
}
int awccount(char strs)
{
	int i=0,wc=0,j=0;
	for(j=0;strs[i][j]!='\0';j++)
		wc=wc+1;
	return wc;
}

