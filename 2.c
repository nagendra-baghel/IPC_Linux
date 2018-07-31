#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#define MSGSIZE 16
void main()
{
fork();
int j;
char *msg1="hello,world#1";
char *msg2="hello,world#2";
char *msg3="hello,world#3";
char inbuf[MSGSIZE];
int p[2];
pipe(p);
if(fork()==0)
{
write(p[1],msg1,MSGSIZE);
write(p[1],msg2,MSGSIZE);
write(p[1],msg3,MSGSIZE);
}
else
{
for(j=0;j<3;j++)
{read(p[0],inbuf,MSGSIZE);
printf("%s\n",inbuf);
}
}
}
