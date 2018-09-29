#ifndef __LIST_H_
#define __LIST_H_

#include<stdlib.h>


struct data
{
	int    val;
	void   *pMaddress;
	struct data *next;
};



int append_node(int n,void *p);
void delete_node(void *p);
void display_node();

#endif /* __LIST_H_ */

