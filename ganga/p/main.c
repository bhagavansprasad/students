#include "structure.h"

struct node *h[26] = {NULL};

char s[20][30] = {
	{"Apple"}, {"aura net"},
	{"Ball"},{"baby"},
	{"Cat"},{"cool"},
	{"Dog"},{"doll"},
	{"Zoo"},{"zinc"},
	{"Ant"},{"struture"},
	{"cot"},{"union"},
	{"linked list"},{"pointers"},
	{"arrays"},{"basics"}
};


int main()
{
	int i = 0, n = 20;

	for(i = 0; i < n; i++)
	{
		addnode(s[i]);
		dump_list();

		sleep(1);
	}

	return 0;
}
