#include <pthread.h>
#include <stdio.h>
int count = 0;
pthread_mutex_t thread_lock;
void* run_thread()
{
pthread_mutex_lock(&thread_lock);
pthread_t thread_id = pthread_self();
printf("Thread %u: Current value of count = %u\n", thread_id, count);
printf("Thread %u incrementing count ...\n");
count++;
sleep(1);
printf("Value of count after incremented by thread %u = %u\n", thread_id, count);
pthread_mutex_unlock(&thread_lock);
pthread_exit(NULL);
}
int main ( )
{
pthread_t thread_array[4];
int i = 0, ret, thread_num = 4;
for (i = 0; i < thread_num; i++) 
{
if ((ret = pthread_create(&thread_array[i], NULL, run_thread, NULL)) == -1) 
{
printf("Thread creation failed with return code: %u", ret);
exit(ret);
}
}
pthread_exit(NULL);
}
