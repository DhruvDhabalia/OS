#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
pthread_mutex_t mutex;
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
pthread_mutex_lock(&mutex);
printf("\n\n\nTime Posted by Writer : ");
printf("\n%d:%d:%d\n",hr,min,sec);
pthread_mutex_unlock(&mutex);
}
void* reader(void *readnum)
{
pthread_mutex_lock(&mutex);
printf("\nTime Read by Reader %d : ",*((int *)readnum));
printf("\n%d:%d:%d\n",hr,min,sec);
pthread_mutex_unlock(&mutex);
}
int main()
{  
hr=23;
min=59;
sec=57;
int r[3]={1,2,3},i,j;
pthread_t write,read[3];
pthread_mutex_init(&mutex,NULL);
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
pthread_mutex_destroy(&mutex);
return 0;
}
