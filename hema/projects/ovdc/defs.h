//#define OVDC_DBUG_INFO

#ifdef OVDC_DBUG_INFO
#define OVDC_DEBUG printf
#else
#define OVDC_DEBUG
#endif

extern int noe;

struct giffs_db
{
	int pid;
	int curr_giffs;
	int cpu_occ;
	int fd;
};


