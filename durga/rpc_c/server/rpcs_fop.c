#include <stdio.h>
#include <stdlib.h>
#include "structer.h"
#include <fcntl.h>
#include"server_structer.h"
#include <string.h>
#include <errno.h>
int rpcs_fop(struct data *p,struct server *s)
{
	printf(" ------>operation %d\n",p->op);
	switch(p->op)
	{
		case 1 : 
			s->u.os.fd = open(p->t.open.filename,p->t.open.flag,p->t.open.mode);
			printf(" ---->path name: %s\n", p->t.open.filename);
			printf(" ---->flag : %d\n", p->t.open.flag);
			printf(" ---->mode : %d\n", p->t.open.mode);
			printf("----->open file id : %d\n ",s->u.os.fd);
			if(s->u.os.fd == -1)
			{
				perror("file is not opening due to:");
				printf("%d\n" ,errno);

				exit(1);
			}
			return s->u.os.fd;


		case 2 :  s->u.rs.r = read(p->t.read.fd, p->t.read.buff, p->t.read.len);
				  if(s->u.rs.r == -1)
				  {
					  printf("-----> server reading is failed\n");
				  }
				  p->t.read.buff[s->u.rs.r] = '\0';
				  strcpy(s->u.rs.buff,p->t.read.buff);
				  //  printf("---->data in buff\n %s\n",s->u.rs.buff);
				  //printf("---->data in buff\n %d\n",s->u.rs.r);
				  strcpy(s->u.rs.buff, p->t.read.buff);
				  return( s->u.rs.r) ;


		case 3 : s->u.ws.w = write(p->t.write.fd, p->t.write.buff, p->t.write.len);
				 if(s->u.ws.w == -1)
				 {
					 printf("----->writing a file is unsuccess\n");
				 }
				 strcpy(s->u.ws.buff, p->t.write.buff);
				 // printf(" the write data in the buff :\n%s\n", s->u.ws.buff);
				 printf("---->data in buff\n %s\n",s->u.ws.buff);

				 return (s->u.ws.w);

		case 4 : s->u.cs.fd = close(p->t.close.fd);
					 return s->u.cs.fd;

				 /*		case 5 : fd = lseek(p->t.ls.fd, p->t.ls.offset, p->t.ls.whence);
						return fd;
						break;*/
		default : printf("choose the correct option\n");
	}
}
