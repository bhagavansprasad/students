#include <stdio.h>
#include <string.h>
main()
{
	char arr[20]="0428132710";
	char date[30], arr2[10];
	int a[5];
	char* month[]={"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
	int i ,j=0;

	for(i=0;i<5;i++,j+=2)
	{
		strncpy(arr2,arr+j,2);
		arr2[2]='\0';
		a[i]=atoi(arr2);
	}
	sprintf(date,"%s %d %d:%d:%d",month[a[0]-1],a[1],a[2],a[3],a[4]);
	printf("%s\n",date);
}
