#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void sig_alrm(int n);//prototype of signal handler
int main()
{
signal(SIGALRM,sig_alrm);//instaling handler for SIGALRM
alarm(10);//instalin alarm for 10 sec
int i=0;
while(i<11)
{
printf("watting to catch sigalarm signal\n");
sleep(1);
i++;
}
while(1);
return 0;
}
/*************************signal handler***********************/
void sig_alrm(int n)
{
printf("time out\n");
printf("process is going to terminate\n");
exit(1);
}
