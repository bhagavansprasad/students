#include "struct.h"
#include "struct_reply.h"
<<<<<<< send.c
#include "recvreq.h"

int send_request( struct student *stud,  struct reply_final *rep )
=======
#include "recv.h"

int send_reuest(struct student *stud,struct reply_final *rep)
>>>>>>> 1.2
{
return recv_request( stud , rep );
}

