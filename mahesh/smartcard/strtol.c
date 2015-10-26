
#include<stdio.h>
#include<stdlib.h>

int main ()
{
	char buffer[] = "B 2 3 A 8 0 0 1 2 8 A 1 8 0 1 8";
	char * ptr_end;
	long int li1, li2, li3, li4,li5,li6,li7,li8,li9,li10,li11,li12,li13,li14,li15,li16;

	li1 = strtol (buffer,&ptr_end,16);
	li2 = strtol (ptr_end,&ptr_end,16);
	li3 = strtol (ptr_end,&ptr_end,16);
	li4 = strtol (ptr_end,&ptr_end,16);
	li5 = strtol (ptr_end,&ptr_end,16);
	li6 = strtol (ptr_end,&ptr_end,16);
	li7 = strtol (ptr_end,&ptr_end,16);
	li8 = strtol (ptr_end,&ptr_end,16);
	li9 = strtol (ptr_end,&ptr_end,16);
	li10 = strtol (ptr_end,&ptr_end,16);
	li11 = strtol (ptr_end,&ptr_end,16);
	li12 = strtol (ptr_end,&ptr_end,16);
	li13 = strtol (ptr_end,&ptr_end,16);
	li14 = strtol (ptr_end,&ptr_end,16);
	li15 = strtol (ptr_end,&ptr_end,16);
	li16 = strtol (ptr_end,NULL,0);

	printf ("In decimals: %ld, %ld, %ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld\n", li1, li2, li3,
	li4,li5, li6, li7, li8, li9, li10, li11, li12,li13, li14, li15, li16);

	return 0;
}

