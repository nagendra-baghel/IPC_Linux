#include<stdio.h>
#include <unistd.h>    /* fork(), etc.*/
#include <sys/types.h> /* various type definitions.*/
#include <sys/ipc.h>   /* general SysV IPC structures*/
#include <sys/sem.h>   /* semaphore functions and structs.*/
main()
{
int sem_id; /* ID of the semaphore set.*/
int i; /* counter for loop operation.*/
struct sembuf sop; /* structure for semaphore ops. */
system("clear");
sem_id = semget(25,1, IPC_CREAT | 0666);
perror("get");
printf("semaphore set created, semaphore set id '%d'.\n", sem_id);
semctl(sem_id,0 , SETVAL,1);
perror("semctl");
if (fork()==0)
{
sop.sem_num = 0;
sop.sem_op = -1;
sop.sem_flg = SEM_UNDO;
semop(sem_id, &sop, 1);
for(i=0;i<=10;i++)
{sleep(1);
printf("\n child =%d",i);
}
}
else
{
sop.sem_num = 0;
sop.sem_op = -1;
sop.sem_flg = SEM_UNDO;
semop(sem_id, &sop, 1);
for(i=0;i<=10;i++)
{sleep(1);
printf("\n parent =%d\n",i);
}
}
}

