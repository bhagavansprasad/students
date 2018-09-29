/*structer for open*/

struct open
{
	char* filename;
	int moade;
	int flage;
}os;

/*structer for read*/

struct read
{
	int fd;
	char* buff;
	int len;
}rs;

/* structer for write*/

struct write
{
	int fd;
	char*buff;
	int len;
}ws;
/*structer for close*/


struct close
{
	int fd;
}cs;

/*structer for lseek*/

struct lseek
{
	int fd;
	int move;
	int pos;
}ls;

/*union for all structer*/

union utag
{
struct open os;
struct read rs;
struct write ws;
struct close cs;
struct lseek ls;
}t;

/*structer for whole structer*/

struct data
{
int falg;
union utag t;
}d;
