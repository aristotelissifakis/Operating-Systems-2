#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t  p1,p2,p3;

void *thread1(void *);
void *thread2(void *);
void *thread3(void *);

int main(int argc,const char **argv)
{
    int i;
    pthread_t th[3];

    sem_init(&p1,0,0);
    sem_init(&p2,0,0);
    sem_init(&p3,0,1);


    pthread_create(&th[0],NULL,thread1,NULL);
    pthread_create(&th[1],NULL,thread2,NULL);
    pthread_create(&th[2],NULL,thread3,NULL);

    for(i = 0; i < 3; i++){
        pthread_join(th[i],NULL);
    }

    sem_destroy(&p1);
    sem_destroy(&p2);
    sem_destroy(&p3);

    return 0;


}

void *thread1(void *arg)
{
        while(1)
        {
            sem_wait(&p3);
            printf("What a");
            sem_post(&p1);
        }
}


void *thread2(void *arg)
{
        while(1)
        {
            sem_wait(&p1);
            printf("wonderful");
            sem_post(&p2);
        }
}


void *thread3(void *arg)
{
        while(1)
        {
            sem_wait(&p2);
            printf(" World!\n");
            sem_post(&p3);
        }
}
