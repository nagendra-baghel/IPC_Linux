#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<stdlib.h>
int main(int argc , char *argv[])
{
printf("killing the calling process\n");
if(kill(atoi(argv[1]),SIGKILL)<0)
{
perror("kill fail ");
//exit(1);
}
return 0;
}
