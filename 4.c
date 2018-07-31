#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
main()
{
int pd[2],ret; char Buff[7];
//memset(Buff,0x0,sizeof(Buff));
ret = pipe(pd);
printf("ret = %d\n",ret);
ret = fork();
if(ret == 0)
{
printf("Child Sending msg 2 the parent\n");
close(pd[0]);
sleep(5);
write(pd[1],"NEX-G",6);
printf("IN child writing is done\n");
}
else
{
close(pd[1]);
printf("In Parent\n");
printf("Rcved msg 4m the child\n");
read(pd[0],Buff,6);
printf("Message = %s\n",Buff);
}
}
