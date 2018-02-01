#include <stdio.h>
#include <stdlib.h>

#define size 3

main()
{
	int n = size, temp = 0, a = 1, num = 0, i = 0, j = n/2, k = 0, number = 0, arr[size][size]={0};
	char str[10];
	temp = n*(n * n + 1)/2;
	printf("%d\n", temp);

	printf("\n\t\t\t\t WELCOME TO TIC-TAC-TOE\n");
	printf("\t\t\t\t<======================>\n");
	printf("press \"enter\" to start the game : ");

	scanf("%s", str);
	a = strcmp(str, "enter");
	printf("\n");
	if(a == 0)
	{
		for(k = 1 ; k <= n * n; k++)
		{
			arr[i][j] = k;
			i--;
			j++;

			if(k % n == 0) 
			{
				i = i + 2;
				j--;
			}

			else
			{
				if(j == n)
					j = j - n;
				else if(i < 0)
					i = i + n;
			}
		}

		for(i = 0;i < n; i++)
		{
			for(j = 0;j < n; j++)
			{
				printf("%10d",arr[i][j]);
			}
			printf("\n\n");
		}
	}
	else
	{
		printf("\nSorry, you have entered incorrect input,\n");
		printf("if you are interested to start the game press \"start\" or press \"Cancel\" to exit from the game\n\n");
		
		scanf("%s", str);
		a = strcmp(str, "CANCEL");

		if ( a == 0)
			exit (0);
		else
			main();
	}

	for( i = 1; i < n * n; i++)
	{
		if( i % 2 != 0)
		{
			static int total = 0;
			printf("Enter User1 : ");
			scanf("%d", &number);
			num = number;
			if( num < 1 || num > 9)
			{
				printf("Sorry Buddy, You have selected the number that is not part of our Game\n\n");
				exit(0);
			}

			total = total + number;
	//		printf("User1 Total : %d\n", total);

			if( total == temp)
			{
				printf("Congratulations User1, You have win the Game\n");
				printf("Thanks for playing\n\n");
				exit(0);
			}
		}
		else
		{
			static int total = 0;
			printf("Enter User2 : ");
			scanf("%d", &number);
			num = number;

			if( num < 1 || num > n * n)
			{
				printf("Sorry Buddy, You have selected the number that is not part of our Game\n\n");
				exit(0);
			}

			total = total + number;
//			printf("User2 Total : %d\n", total);

			if( total == temp)
			{
				printf("Congratulations User2, You have win the Game\n");
				printf("Thanks for playing\n\n");
				exit(0);
			}
		}
	}
	printf("\nThis Game has no result or Tie\n");
	printf("Lets start a new game if you interested\n\n");

	return 0;
}
