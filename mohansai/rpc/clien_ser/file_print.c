#include"cl_se.h"

void my_parser_data( info *pdata)
{
	int fd;
	
	switch(pdata->cmd)
	{
		case 1 :
			sys_open(pdata->fname , pdata->mode);
			break;
		case 2 :
	//		sys_read(*rbuff, pdata->len, &fcb);
			break;
		case 3 :
	//		sys_write(*rbuff,pdata->len,&fcb);
			break;
	//	case 4 :sys_close(fd);
			break;
		
		default :
			perror("not able to do the operations ..\r\n");
			break;
	}
}


