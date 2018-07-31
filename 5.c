/* ======== sender.c=============== */
#define DEFINED_KEY 25
struct 
{
long mtype;
char content[256];
} msg;
main( )
{ int msg_qid;
fprintf(stdout, "=========SENDER==========\n");
if((msg_qid = msgget(DEFINED_KEY, IPC_CREAT | 0666)) < 0) 
{
perror("msgget: ");
exit(-1);
}
printf("Message Queue Id : %d" , msg_qid);
msg.mtype = 1;// for message type
while(1) 
{
gets(msg.content);
if(msgsnd(msg_qid, &msg, sizeof(msg.content), 0) < 0) // last argu is 0 as wait else IPC_NOWAIT
{perror("msgsnd: "); exit(-1);
}
}
}
/* ==================reciever.c====================== */
struct {long mtype;
char content[256];
} msg;
main()
{ int msg_qid;
fprintf(stdout, "=====RECEIVER=====\n");
if((msg_qid = msgget(25, IPC_CREAT | 0666)) < 0) 
{
perror("msgget: "); exit(-1);
}
printf("Message Queue Id : %d" , msg_qid);
while(1) 
{ memset(msg.content, 0x0, 256);
if(msgrcv(msg_qid, &msg, 256, 0, 0) < 0) 
{
perror("msgrcv: "); exit(-1);
}
puts(msg.content);
}
}
