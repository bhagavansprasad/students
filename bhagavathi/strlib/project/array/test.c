#include <stdio.h>
int noe=0;
int arr[50];
int max=50;

int ordered_insert (int value)
{
	int i,j;

	if (noe == 0)
	{
		arr[i] = value;
		noe++;
		return 0;
	}
	for(i=0; i < noe; i++)
	{
	 if(arr[i] > value)
		{
		for(j=noe ; j > 0; j--)
			arr[noe]=arr[noe -1];
		}
		else
		{
		for(j=noe ; j > 0; j--)
			arr[noe+1]=arr[noe];
		}
		arr[i]=value;
		noe++;
	}
}


main()
{
	int y=0,i = 0;

	ordered_insert(9);
	
	if(y==0)
	{
        printf("%3d", arr[0]);
    printf("\n");
	}
	else
    {
	for(i=0; i <= noe; i++)
        printf("%3d", arr[i]);
     printf("\n");
	 }

}

