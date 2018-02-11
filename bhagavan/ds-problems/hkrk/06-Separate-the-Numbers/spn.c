#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void separateNumbers(char* s) {
    // Complete this function
	printf ("%s\n", s);
	int i = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		
	}

	if (i == 1)
		return "NO";
}


char *strs[] = {
	"1234",
	"91011",
	"99100",
	"101103",
	"010203",
	"13",
	"1"
};

int main() {
	int len = sizeof(strs)/sizeof(char *);
	int i = 0;

	for (i = 0; i < len; i++)
        separateNumbers(strs[i]);
}
