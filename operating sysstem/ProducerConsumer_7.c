#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <windows.h> // For Sleep function on Windows

#define BufferSize 5

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[BufferSize];
pthread_mutex_t mutex;

void *producer(void *pnum) {
    int item;
    while (1) {
        item = rand() % 100;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        buffer[in] = item;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)pnum), buffer[in], in);
        in = (in + 1) % BufferSize;

        Sleep(1000); // Windows Sleep (milliseconds)

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void *consumer(void *cnum) {
    while (1) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        printf("Consumer %d: Remove Item %d from %d\n", *((int *)cnum), buffer[out], out);
        out = (out + 1) % BufferSize;

        Sleep(1000); // Windows Sleep (milliseconds)

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main() {
    printf("This is Dhiaj sharma.\n");
    pthread_t pro[3], con[3];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, BufferSize);
    sem_init(&full, 0, 0);

    int a[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++) {
        pthread_create(&pro[i], NULL, producer, (void *)&a[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_create(&con[i], NULL, consumer, (void *)&a[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(pro[i], NULL);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(con[i], NULL);
    }

    return 0;
}
