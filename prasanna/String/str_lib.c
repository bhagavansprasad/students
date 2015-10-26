#include"str_header.h"

/*function which returns the string length */
int astrlen(char *str)
{
	int i=0;
	while(*str++ !='\0')
		i++;
	return i;
}
/*Function which compares two string and returns integer value */
int astrcompare(char *str1,char *str2)
{
	int i;
	if(astrlen(str1) != astrlen(str2))
		return (astrlen(str1) - astrlen(str2));
	for(i=0;str1[i] == str2[i];i++)
		if(str1[i] == '\0')
			return 0;
	return str1[i] - str2[i];
}
/*Function which copies string source to destnation and returns copied string*/
char *astrcopy(char *sourc,char *destn)
{
	int i=0;
	while((destn[i] = sourc[i]) !='\0')
		i++;
	destn[i] ='\0';
	return destn; 
	
}
/*Function strncopy  */
 
char *astrncpy(char *dest, const char *src, int n)
{
	int  i;
	for (i = 0; i < n && src[i] != '\0'; i++)
               dest[i] = src[i];
//         for ( ; i < n; i++)
                dest[i] = '\0';

               return dest;
           }


/*Function which compare the two strings upto given range and returns the integer value */
int astrncompare(char *str1,char *str2,int value)
{
	int i;
	for(i=0;i<value;i++)
	{
		if(*(str1+i) != *(str2+i))
			return (*(str1+i) - *(str2+i));
	}
	return 0;
}
/*Function concatenate the two string and retuns the cocatenate string*/
char *astrcat(char *str1,char *str2)
{
	int i=0,j=0;
	while(str1[i] != '\0')
		i++;
	while((str1[i++] = str2[j++]) !='\0');
		str1[i+j] ='\0';
	return str1;
}
/*Function concatenate the two string upto given range and retuns the concatenate string */
char *astrncat(char *dest, const char *src, int n)
{
	//int dest_len = astrlen(dest);
      int j=0,i=0;
      while(dest[i] != '\0')
      	i++;
      for (j = 0 ; j < n && src[j] != '\0' ; j++)
	      dest[i + j] = src[j];
      dest[i + j] = '\0';
      return dest;
}

/*Function to revese the string */
char * astrrev (char *s)
{
        int temp = 0;
        int i,j;
        for (i = 0 ; s[i]!= '\0' ; i++);
        i--;

        for(j = 0 ; j < i ; j++ , i--)
        {
                temp = s[j];
                s[j] = s[i];
                s[i] = temp;
        }
		
        return s;
}

/*Function to return the uppercase letters  count in given string*/

int get_upper_case_count(char *p)
{
	int i,count = 0;
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i] >='A' && p[i] <='Z')
			count++;
	}
	return count;
}

/*Function to return the uppercase letters  count in given string*/
int get_lower_case_count(char *s)
{
	int i,count=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>='a' && s[i]<='z')
			count++;
	}
	return count;
}

/*Function to covert lowercase into upper case*/
char *a_to_upper(char *s)
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i] >='a' && s[i] <= 'z')
			s[i] = s[i] + 'A' - 'a';
	}
	return s;
}

/*Function to convert upper case in to lower case */
char *a_to_lower(char *s)
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i] >='A' && s[i] <='Z')
			s[i] = s[i] + 'a' -'A';
	}
	return s;
} 

/*Function to retun pointer to given character */
char *a_strchar(char *str,char ch)
{
	int i;
	for(i=0;str[i] !='\0';i++)
	{
		if(str[i] == ch)
			return str+i;
	}
	return 0;
}
	
	
		
