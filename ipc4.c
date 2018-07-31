#include<stdio.h>
void main()
{
int i,p;
p=fork();
if(p==0)
{
printf("\n");
for(i=0;i<10;i++)
printf("child=%d",i);
printf("\n");
}
else
{
printf("\n");
for(i=0;i<10;i++)
printf("parent =%d",i);
printf("\n");
}
}
