#include <stdio.h>
#include <stdlib.h>

main()
{
	int r,c,k,l,m,count=0;;
	printf(" Enter Rows and Cols for 2D array: ");
	scanf("%d %d",&r,&c);
	
   int **arr=malloc(r*sizeof(int ));

	for(k=0;k<r;k++)
	 arr[k]=malloc(c*sizeof(int ));

	

	for(l=0;l<r;l++)
	   for(m=0;m<c;m++)
	      arr[l][m]=count++;


	for(l=0;l<r;l++)
	   {
	     for(m=0;m<c;m++)
		    printf("  %d  ", arr[l][m]);

			printf("\n");
        }

	free(arr);
	printf("%d\n", arr[1][2] );


}
