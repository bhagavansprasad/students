#include<stdio.h>
#include<string.h>


char str1[10][100] ={
	"aura networks",
	"aura networks",
	"Bangalor",
	"Karnataka",
	"I am in AP",
	"Works in cisco",
	"Works in cisc",
	"Works in cisco"
};

char str2[10][100] ={
	"aura networks",
	"aura networks Bangalore",
	"Bangalore",
	"Karataka",
	"i am in AP",
	"Works in Cisco",
	"Works in cisc"
	"Works incisc"
};

main()
{
	int i, retval;

	for (i = 0; i < 8; i++)
	{
		printf("%d. %s--%s--", i+1, str1[i], str2[i]);

		retval = astrcmp(str1[i], str2[i]);

		if(retval == 0)
			printf("SAME:%d\n", retval);
		else
			printf("NOT same:%d\n", retval);
	}
}
