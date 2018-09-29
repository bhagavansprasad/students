#include<stdio.h>
void main()
{
	long array[][3]={7l,14l,21l,28l,35l,42l};

	long int (*ptr )[2][1]=&array;
	long int (*ptr0)[2][1]=&array;
	long int (*ptr1)[2][1]=&array;
	long int (*ptr2)[2][1]=&array;
	long int (*ptr3)[2][1]=&array;
	long int (*ptr5)[2][1]=&array;

	printf("%ld\n", 0[0[0[ptr]]]);
	printf("%ld\n", 0[1[0[ptr]]]);
	printf("%ld\n", 0[2[0[ptr]]]);
	printf("%ld\n", 0[3[0[ptr]]]);
	printf("%ld\n", 0[4[0[ptr]]]);
	printf("%ld\n", 0[5[0[ptr]]]);

	}
