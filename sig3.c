#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void abc();
main()
{
printf("Press ctrl+c key.\n");
signal( SIGINT,abc /*SIG_IGN */ /*SIG_DFL*/);
for(;;);
}
void abc(int signo)
{
printf("You have pressed the ctrl+c key.%d\n",signo);
//exit(0);
}
