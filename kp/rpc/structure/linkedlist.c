#include<stdio.h>
struct link
{
	int a;
	struct link *l;
};

int append(struct link **q, int n)
{
	struct link *t, *r;

	if(*q == NULL)
	{
		t=malloc(sizeof(struct link));
		//printf("-->t :%p\n", t);
		t->a=n;
		printf("t-> a- :%d\n",t->a);
		t->l=NULL;
		*q = t;
	}
	else
	{
		t = *q;

		while(t->l!=NULL)
			t=t->l;

		r=malloc(sizeof(struct link));
		r->a=n;
		printf("r-> a- :%d\n",r->a);
		r->l=NULL;
		t->l=r;
	}
}

main()
{
	struct link *p = NULL; 

	append(&p,1);
	append(&p,2);
	append(&p,3);

}


