#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE 5

int buffer[SIZE], in=0, out=0, item=1;
sem_t empty, full, mutex;

void *producer()
{
    while(item<=10)
    {
        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in]=item;
        printf("Produced: %d\n", item);

        in=(in+1)%SIZE;
        item++;

        sem_post(&mutex);
        sem_post(&full);
    }
    return NULL;
}

void *consumer()
{
    int x;

    while(1)
    {
        sem_wait(&full);
        sem_wait(&mutex);

        x=buffer[out];
        printf("Consumed: %d\n", x);

        out=(out+1)%SIZE;

        sem_post(&mutex);
        sem_post(&empty);

        if(x==10)
            break;
    }
    return NULL;
}

int main()
{
    pthread_t p,c;

    sem_init(&empty,0,SIZE);
    sem_init(&full,0,0);
    sem_init(&mutex,0,1);

    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);

    pthread_join(p,NULL);
    pthread_join(c,NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}