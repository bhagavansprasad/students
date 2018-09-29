#include<stdio.h>

main()
{

	int i, j, w =0;
	int ch;
	char choice = 'y';
	do{
		
	
//		printf("Enter the number \n");
//		scanf("%d",&ch);

		if(ch == 1)
		{
			printf("\n     for 1   \n");
			for(i=0;i<5;i++)
			{
				for(j=0;j<5;j++)
				{
					if(i <=3 && j == 0)
						printf("%c ",' ');
					else if(i == 1 && j ==1)
						printf("%c ",'#');
					else if(i == 4 || j==2 )
						printf("%c ",'#');
					else 
						printf("%c ",' ');
					//w++;
				}                               	
				printf("\n");                   
			}
		}
		else if(ch ==2){

			printf("\n     for 2   \n");

			for(i=0;i<5;i++,w++)

			{
				for(j=0;j<5;j++)
				{
					if(j==0)
						printf("%c ",' ');
					else if(i == 0)
						printf("%c ",'#');
					else if( i == 1 && j == 4)
						printf("%c ",'#');
					else if(i == 2 )
						printf("%c ",'#');
					else if(i == 3 && j == 1)
						printf("%c ",'#');
					else if(i == 4)
						printf("%c ",'#');
					else 
						printf("%c ",' ');
					//w++;
				}                               	
				printf("\n");                   
			}
		}
		else if(ch ==3){
			printf("\n     for 3   \n");

			for(i=0;i<5;i++,w++)

			{
				for(j=0;j<5;j++)
				{
					if(j==0)
						printf("%c ",' ');
					else if(i == 0 )
						printf("%c ",'#');
					else if(j == 4)
						printf("%c ",'#');
					else if(i == 2 )
						printf("%c ",'#');
					else if(i == 4)
						printf("%c ",'#');
					else 
						printf("%c ",' ');
					//w++;
				}                               	
				printf("\n");                   
			}
		}
		else if(ch == 4){

			printf("\n     for 4   \n");

			for(i=0;i<5;i++,w++)

			{
				for(j=0;j<5;j++)
				{
					if(j==0)
						printf("%c ",' ');
					else if(i <= 2 && j == 1)
						printf("%c ",'#');
					else if(i == 2)
						printf("%c ",'#');
					else if(j == 4 )
						printf("%c ",'#');
					else 
						printf("%c ",' ');
					//w++;
				}                               	
				printf("\n");                   
			}
		}
		else if(ch == 5){
			printf("\n     for 5   \n");

			for(i=0;i<5;i++,w++)

			{
				for(j=0;j<5;j++)
				{
					if(j==0)
						printf("%c ",' ');
					else if(i == 0 )
						printf("%c ",'#');
					else if(i <=1 && j == 1)
						printf("%c ",'#');
					else if(i == 2 )
						printf("%c ",'#');
					else if(i == 3 && j == 4)
						printf("%c ",'#');
					else if(i == 4)
						printf("%c ",'#');
					else
						printf("%c ",' ');
					//w++;
				}                               	
				printf("\n");                   
			}
		}
		else if(ch == 6){
			printf("\n     for 6   \n");

			for(i=0;i<5;i++,w++)
			{
				for(j=0;j<5;j++)
				{
					if(j==0)
						printf("%c ",' ');
					else if(i == 0 || j== 1)
						printf("%c ",'#');
					else if(i == 2 )
						printf("%c ",'#');
					else if(i == 3 && j == 4)
						printf("%c ",'#');
					else if(i == 4)
						printf("%c ",'#');
					else
						printf("%c ",' ');
				}                               	
				printf("\n");
			}	
		}

		else if(ch ==7 ){
			printf("\n     for 7   \n");

			for(i=0;i<5;i++,w++)

			{
				for(j=0;j<5;j++)
				{
					if(j==0)
						printf("%c ",' ');
					else if(i == 0)
						printf("%c ",'#');
					else if(i == 1 && j == 1)
						printf("%c ",'#');
					else if(j == 4 )
						printf("%c ",'#');
					else 
						printf("%c ",' ');
				}                               	
				printf("\n");                   
			}
		}
		else if(ch == 8){
			printf("\n     for 8   \n");

			for(i=0;i<5;i++,w++)

			{
				for(j=0;j<5;j++)
				{
					if(j==0)
						printf("%c ",' ');
					else if(i == 0 || i == 2 || i == 4 || j == 1 || j == 4)
						printf("%c ",'#');
					else 
						printf("%c ",' ');
				}                               	
				printf("\n");                   
			}
		}
		else if(ch == 9){
			printf("\n     for 9   \n");

			for(i=0;i<5;i++,w++)

			{
				for(j=0;j<5;j++)
				{
					if(j==0)
						printf("%c ",' ');
					else if(i == 0 || i == 2 || i == 4 || j == 4)
						printf("%c ",'#');
					else if(i == 1 && j == 1)
						printf("%c ",'#');
					else 
						printf("%c ",' ');
				}                               	
				printf("\n");                   
			}
		}
		else if(ch == 0){

			printf("\n     for 0   \n");

			for(i=0;i<5;i++,w++)

			{
				for(j=0;j<5;j++)
				{
					if(j==0)
						printf("%c ",' ');
					else if(i == 0 || i == 4 || j == 1 || j == 4)
						printf("%c ",'#');

					else 
						printf("%c ",' ');
				}                               	
				printf("\n");                   
			}
		}
		
	//	printf("Do you want continue press yes for Y no for any letter\n");
	//	scanf("%c",&choice);
		printf("Enter number\n");
		scanf("%d",&ch);
		}while(choice == 'y');
}
