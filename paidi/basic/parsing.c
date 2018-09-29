#include <stdio.h>
#include <string.h>
char buff[500];
int i;
char iso_header(char *ptr,int a)
{
	int i=0,m;
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("iso header                     : %s\n",buff);
}

char message_type(char *ptr,int a)
{
	int i;
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("message type indicator         : %s\n",buff);
}

char primary_bitmap(char *ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("primary bit map                : %s\n",buff);
}

char secondary_bit_map(char *ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("secondary bit map              : %s\n",buff);
}

char processing_time(char *ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("processing time                : %s\n",buff);
}
char amount(char *ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("amount                         : %s\n",buff);
}

char date(char *ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("date                           : %s\n",buff);
}

char trace(char *ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("trace                          : %s\n",buff);
}
char time(char *ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("time                           : %s\n",buff);
}
char date_issue(char*ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("date_issue                     : %s\n",buff);
}
char limit_date(char*ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("limit_date                     : %s\n",buff);
}

char expiration_date(char* ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("expiration_date                : %s\n",buff);
}
char acquiring_institution_identi(char* ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("acquiring_institution_identi   : %s\n",buff);
}

char track_2_date(char* ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("track_2_date                   : %s\n",buff);
}
char reference_num (char* ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("reference_num                  : %s\n",buff);
}
char card_accepter(char* ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("card_accepter                  : %s\n",buff);
}
char card_accepter_name(char* ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("card_accepter_name             : %s\n",buff);
}
char additional_data (char* ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("additional_data                : %s\n",buff);
}
char currency_code_transaction (char* ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("currency_code_transaction      : %s\n",buff);
}
char reserved_for_private_us (char* ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("reserved_for_private_us        : %s\n",buff);
}
char reserved_for_private_us1 (char* ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("reserved_for_private_us1       : %s\n",buff);
}

char receiving_institution_identif (char* ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("receiving_institution_identif  : %s\n",buff);
}
char Account_identification_1 (char* ptr,int a)
{
	for(i=0;i<a;i++)
		buff[i]=*ptr++;
	buff[i]='\0';
	printf("Account_identification_1       : %s\n",buff);
}

int parse_card_acceptor_name(char *src, char *dest)
{
	return len;
}

int translate_card_acceptor_name(char *src, char *dest)
{
	return len;
}

main()
{

char dest[100];
char hr_str[100];
....


parse_currency_data(str+offset, dest)
translate_currency_data(dest, hr_str)
....


}
int parse_currency_data(char *src, char *dest)
{
	return len;
}

int translate_currency_data(char *src, char *dest)
{
	return len;
}


int main()
{
	char str[]="ISO0150000500200B23A800128A180180000000014000000650000000000002050042813271000057813271004280428042803456174591700012340000=000000230579A1B2C3D4E5SOLABTEST TEST-3 DF MX010abcdefghij484012B456PRO1+000013 1234P0399904ABCD";

	
	iso_header(str,12);

	char *ptr ;
	ptr = strstr(str,"02");
	message_type(ptr,4);

	ptr = strstr(str,"B2");
	primary_bitmap(ptr,16);

	ptr = strstr(str,"018");
	for( ;*ptr++!='8'; );
	secondary_bit_map(ptr,16);

	ptr = strstr(str,"65");
	processing_time(ptr,6);

	ptr = strstr(str,"650000");
	for(i=0;i<6;i++,ptr++);
	amount(ptr,12);

	ptr = strstr(str,"042");
	date(ptr,10);

	ptr = strstr(str,"710");
	for(i=0;i<3;i++,ptr++);
	trace(ptr,6);

	ptr = strstr(str,"78");
	for(i=0;i<2;i++,ptr++);
	time(ptr,6);

	ptr = strstr(str,"578132710");
	for(i=0;i<9;i++,ptr++);
	date_issue(ptr,4);

	ptr = strstr(str,"100428");
	for(i=0;i<6;i++,ptr++);
	limit_date(ptr,4);

	ptr = strstr(str,"04280428");
	for(i=0;i<8;i++,ptr++);
	expiration_date(ptr,4);

	ptr = strstr(str,"2803");
	for(i=0;i<4;i++,ptr++);
	acquiring_institution_identi(ptr,3);
    
	ptr = strstr(str,"45617");
	for(i=0;i<5;i++,ptr++);
	track_2_date(ptr,17);
    
	ptr = strstr(str,"0=");
	for(i=0;i<2;i++,ptr++);
	reference_num(ptr,12);
    
	ptr = strstr(str,"0579");
	for(i=0;i<4;i++,ptr++);
	card_accepter(ptr,10);

	ptr = strstr(str,"E5");
	for(i=0;i<2;i++,ptr++);
	card_accepter_name(ptr,22);
	
	ptr = strstr(str,"MX010");
	for(i=0;i<5;i++,ptr++);
	additional_data(ptr,10);
    
	ptr = strstr(str,"hij");
	for(i=0;i<3;i++,ptr++);
	currency_code_transaction(ptr,3);

    ptr = strstr(str,"j484012");
	for(i=0;i<7;i++,ptr++);
	reserved_for_private_us(ptr,12);
    
	ptr = strstr(str,"13 ");
	for(i=0;i<3;i++,ptr++);
	reserved_for_private_us1(ptr,5);

	ptr = strstr(str,"P03");
	for(i=0;i<3;i++,ptr++);
	receiving_institution_identif(ptr,3);
	
	ptr = strstr(str,"904");
	for(i=0;i<3;i++,ptr++);
	Account_identification_1(ptr,4);
}
