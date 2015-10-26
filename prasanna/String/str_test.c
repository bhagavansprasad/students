
#include"str_header.h"
main()
{
	int choice;
	char str[30];
	//="Prasanna Kumar S Yadravi";
	char str1[30]; 
		//= "prasanna kumar"
		char *str2 = "prasanna Kumar",str3[14];
	char src[5]="kumar",dest[15]="prasanna ";
	printf("Enter the first string \n");
	scanf("%s",str);
	printf("Enter second string\n");
	scanf("%s",str1);
	printf("Enter choice \n");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:printf("%d\n",astrcompare(str,str1));
		       if((astrcompare(str,str1)) == 0)
			       printf("same\n");
		       else
			       printf("Not same\n");
		       break;
		case 2: printf("copied string: %s\n",astrcopy(str,str3));	
			break;

		case 3: if(astrncompare(str1,str2,4) == 0)
				printf("same\n");
			else
				printf("not same\n");
			break;

		case 4:printf(" %s \n",astrcat(str1,str2)); 
		       break;

		case 5:printf(" %s\n",astrncat(dest,src,2));
		       break;
		case 6:printf("string length:%d\n",astrlen(str));
		       break;
		case 7:printf(" %s \n",astrrev(str)); 
		       break;
		case 8:printf("No of uppercase letters in a string :%d\n",get_upper_case_count(str));
		       break;
		case 9:printf("No of lowercase letters in a string: %d\n",get_lower_case_count(str));
		       break;
		case 10:printf("Sting in uppercase:  %s\n",a_to_upper(str));
			break;
		case 11:printf("String in lower case: %s\n",a_to_lower(str));
			break;
		case 12:printf("  %s\n",a_strchar(str,'s'));
			break;
		default:printf("Enter choice between 1 to 12\n");
			break;
	}
}

