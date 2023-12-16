#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include<semaphore.h>
#include <time.h>
sem_t lock;
int hr,min,sec;
void clock_set()
{
sec++;
if(sec==60)
{
sec=0;
min++;
}
if(min==60)
{
min=0;
hr++;
}
if(hr==24)
{
hr=0;
}
}
void* writer(void* _args)
{
sem_wait(&lock);
printf("\n\n\nTime Posted by Writer : ");
printf("\n%d:%d:%d\n",hr,min,sec);
sem_post(&lock);
}
void* reader(void *readnum)
{
sem_wait(&lock);
printf("\nTime Read by Reader %d : ",*((int *)readnum));
printf("\n%d:%d:%d\n",hr,min,sec);
sem_post(&lock);
}
int main()
{
hr=23;
min=59;
sec=57;
int r[3]={1,2,3},i,j;
pthread_t write,read[3];
sem_init(&lock,0,1);
for(j=0;j<5;j++)
{
sleep(2);
pthread_create(&write,NULL,writer,NULL);
clock_set();
for(i=0;i<3;i++)
{
sleep(rand() % 3);
pthread_create(&read[i],NULL,reader,&r[i]); }
pthread_join(write,NULL);
for(i=0;i<3;i++)
{
pthread_join(read[i],NULL);
}
}
sem_destroy(&lock);
return 0;
}
