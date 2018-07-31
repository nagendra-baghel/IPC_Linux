#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main( )
{int ret;
char buf[5];
printf("enter your string\n");
ret=read(0,buf,5);
printf("retun value from read : %d\n",ret);
write(1,buf,5);
}
