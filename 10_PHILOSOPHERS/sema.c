#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

int			main(void)
{
	sem_t	*sem;
	char	*name = "new";

	sem = sem_open(name, O_CREAT, 0644, 2);
	if (sem == NULL)
		printf("fail to open it\n");
	printf("start!\n");
	if (sem_wait(sem) == -1)
		printf("fail to wait\n");
	printf("pass_1\n");
	if (sem_wait(sem) == -1)
		printf("fail to wait\n");
	printf("pass_2\n");
	usleep(1);
	if (sem_post(sem) == -1)
		printf("fail to post\n");
	if (sem_post(sem) == -1)
		printf("fail to post\n");
	printf("end!\n");
	if (sem_unlink(name))
		printf("fail to unlink\n");
	printf("unlink\n");
	//if (sem_close(sem))
	//	printf("fail to close\n");
	printf("close\n");
}
