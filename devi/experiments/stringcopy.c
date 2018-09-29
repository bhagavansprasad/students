#include <stdio.h>
#include <string.h>
int main()
{
	char str[]="Nagpur";
	str[0]='K';
	printf("%s\n",str);
	//str[7]="Kanpur";
	strcpy(str,"Kanpur");
	printf("%s\n",str+1);
	return 0;

	/*o/p:

	Kagpur
	agpur
	stack smashing detected
	*/

}
