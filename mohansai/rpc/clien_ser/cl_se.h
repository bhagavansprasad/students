# define AURA_open  1 
# define AURA_close 2 
# define AURA_read  3 
# define AURA_write 4 


typedef struct info_t
{
	int cmd;
	char fname[100];
	int mode;	
	int len;
	char buff[100];
}info;

