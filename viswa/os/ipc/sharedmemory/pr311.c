#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>

main()
{
	struct shmid_ds set;
	int shmid;
	
	shmid = shmget((key_t)20000,1, IPC_CREAT|0666);
	shmctl(shmid, IPC_STAT, &set);
	printf("owners userid is %d\n",set.shm_perm.uid);
	printf("owner's groupid is %d\n",set.shm_perm.gid);
	printf("creators groupid is %d\n",set.shm_perm.cuid);
	printf("permission mode %o\n",set.shm_perm.mode);
	printf("slot sequence number is %d\n",set.shm_perm.__seq);
	printf("queue name is %d\n",set.shm_perm.__key);
	printf("size of segment is %d\n",set.shm_segsz);
	printf("pid of processor last operator  is %d\n",set.shm_lpid);
	printf("pid of creator is %d\n",set.shm_cpid);
	printf("current number of shared memory attached is %d\n",set.shm_nattch);
	//printf("in_core number of shared memory attached is %d\n",set.shm_cnattch);
	printf("last attached time is %s\n",ctime(&set.shm_atime));
	printf("last detached time  is %s\n",ctime(&set.shm_dtime));
	printf("last changed time  is %s\n",ctime(&set.shm_ctime));
}
