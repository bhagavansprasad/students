#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>

main()
{
	struct shmid_ds set;
	int shmid;

	if((shmid = shmget((key_t)200000,1, IPC_CREAT|0666))<0)
		printf("failed for 1st time \n");
	else
		printf("succeeded for1st time \n");
	set.shm_perm.uid = 1;
	set.shm_perm.gid = 1;
	set.shm_perm.mode = 0444;

	shmctl(shmid, IPC_SET, &set);
	printf("owners userid is %d\n",set.shm_perm.uid);
	printf("owner's groupid is %d\n",set.shm_perm.gid);
	printf("permission mode %o\n",set.shm_perm.mode);

	if((shmid = shmget((key_t)200000,1, IPC_CREAT|0666))<0)
		printf("failed for 2nd time \n");
	else
		printf("succeeded for2nd time \n");


}
