#include<stdio.h>
main()
{ int ret,pid;
ret =fork();
//scanf("%d", &a);
printf ("ret is = %d\n", ret);
if(pid==1)
{
printf ("pid is = %d\n", pid);
printf("I am the child,my process ID is %d\n",getpid());
printf("The child's parent process ID is %d\n",getppid());
}
else
{
printf("I am the parent,my process ID is %d\n",getpid());
printf("The parent's parent process ID is %d\n",getppid());
}
}
