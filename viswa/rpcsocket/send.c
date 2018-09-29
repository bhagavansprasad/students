//#include "prototypes.h"
#include "struct.h"
#include "second_struct.h"

int  client_write(struct students * );

int send_data(struct students *student , struct school *sch)
{
 client_write( student );
 return 0;
}

