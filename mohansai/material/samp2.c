/* Q3. How make above statment correct?
 
 - Answer below questions
  
  typedef struct mydata
  {
	  int age;
	  char name[10];
  }my_data;

  my_data d1 = {10, "Aura Net"}, d2, *p;
  p = &d1;

Q1. Draw the memory map d1, d2 and p?
Q2. What is the size of p and d1?
Q3. how to print values of d1 using p?
Q4. Assign d2's address to p.  Then using p, change the members of d2.



*/

#include "stdio.h"
#include "string.h"
typedef struct mydata
  {
	  int age;
	  char name[10];
 }my_data;
 
main()
{
  my_data d1 = {10, "Aura Net"}, d2, *p;
  p = &d1;
	
	printf("%s \n\r",d1.name);	
	printf("sizeof %d\n\r",sizeof(p));/* size of p Q1*/
	printf("sizeof %d\n\r",sizeof(d1));/* size of d1 Q1*/
//	printf("sizeof %d\n\r",sizeof(int));

	p=&d1;
	printf("age=> %d \n\rname=> %s\n\r",p->age,p->name);/* Q2*/
	
	d2=d1;
	printf("the value in the d2 is now is %d\n\r",d2.age);
	
	p=&d2;
	p->age=30;
	printf("the value in the d2 is now is %d\n\r",p->age);

	
	printf("the value in the d1 is now is %s\n\r",d1.name);/* it is possible to	write the date d1.name[2] = 'R';*/
	d1.name[2] = 'R';										/*because it points	to the  array but not to pointer*/
	printf("the value in the d1 is now is %s\n\r",d1.name);

}

