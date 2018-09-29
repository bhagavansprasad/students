#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>

main()
{
	struct shmid_ds set;
	int shmid;

	shmid = shmget((key_t)20000,1, IPC_CREAT|0666);
	shmctl(shmid, IPC_SET, &set);
	printf("owners userid is %d\n",set.shm_perm.uid);
	printf("owner's groupid is %d\n",set.shm_perm.gid);
	printf("permission mode %o\n",set.shm_perm.mode);

	set.shm_perm.uid = 1;
	set.shm_perm.gid = 1;
	set.shm_perm.mode = 0444;

	shmctl(shmid, IPC_SET, &set);
	printf("owners userid is %d\n",set.shm_perm.uid);
	printf("owner's groupid is %d\n",set.shm_perm.gid);
	printf("permission mode %o\n",set.shm_perm.mode);
}
