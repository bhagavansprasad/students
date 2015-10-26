#include <stdio.h>
main()
{
	int i ;
	int wc = 0 ;
	//	char cc,pc;
	//char R[100] = "Number   of characters    in an Array is a string";
    char R[100] = " Run Raja Run";
	//char R[100] = " Run ";
	//char R[100] = " R ";
    //char R[100] = " ";
	for (i = 0 ; R[i] != '\0' ; i++)

	{
		if ( R[i] == ' ' && R[i-1] != ' ' && R[i+1] != '\0' )
			wc += 1;
		if ( R[i] != ' ' && R[i+1] == '\0' )
		    wc += 1;
	}
            
         printf ("%d \n", wc);
}
