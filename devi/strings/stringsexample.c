//- What is the ouput of below statements?
//  incase of address of both the strings are 500 and 700 
#include <stdio.h>
main()
{
  char name[100] = "Aura Networks";
  char *ptr = "Aura Networks";

 // * What is the difference between 'name' and 'ptr'
 // * What are the values in 'name' and 'ptr'
 //* What is the ouput
  printf("size of name[100]=%d\n",sizeof(name));
  printf("size of ptr=%d\n",sizeof(ptr));
  printf("addr of ptr=%p\n", ptr);

//*  * Which of below statements valid/Invalid and Why?
//	name[3] = 'A';
//	ptr[3] = 'A';
//	printf("name[3]=%c\n",name[3]);
//	printf("ptr[3]=%c\n",*ptr[3]);
//  * What is the storage section of 'name'
  //* What is the storage section of 'ptr'
//  * What is the storage section of string "Aura Networks"

//- What is the output of below statements?
  char name1[] = "Aura Networks";
  char name2[] = "Embedded Training";

  char *ptr1 = "Aura Networks";
  char *ptr2 = "Embedded Training";
  char *temp;

  //* Which of below statements valid/Invalid, Why and what is the output?
  temp = ptr1;
  ptr1 = ptr2;
  ptr2 = temp;

	printf("ptr1=%s :\n", ptr1);
	printf("ptr2=%s :\n", ptr2);
	printf("temp=%s :\n",temp);

  temp = name1;
//  name1 = name2;
 // name2 = temp;

  printf("name1=%s :\n", name1);
  printf("name2=%s :\n", name2);
  printf("temp=%s :\n", temp);

//- What is the output of below statements, incase
//  of base of address of array is 500?

//						Value	Type
	char cc;
	cc=*("Aura Networks"+6);
	printf("cc=%c:\n",cc);
	printf("new exp=%c\n","Aura Networks"[6]);
  printf("new exp2=%c\n",5["Aura Networks"]);
  printf("new exxxp3=%s\n","Aura Networks");

//- What is the difference between
//  pointer to an array?
//  array of pointers?*/
}
