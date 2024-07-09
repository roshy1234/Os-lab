#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define S 5
#define MAX 20

int buffer[S];
int in = 0, out = 0;

int produced = 0, consumed = 0;

sem_t empty, full, mutex;

void *producer(void *args) {
    int item = 1;
    while(produced < MAX) {
        sem_wait(&empty);
        sem_wait(&mutex);
        //Critical Section
        buffer[in] = item++;
        in = (in + 1) % S;
        printf("Produced item %d\n", item);
        produced++;
        //End of Critical Section

        sem_post(&mutex);
        sem_post(&full);
    }
    pthread_exit(NULL);
}

void *consumer(void *args) {
    while(consumed < MAX) {
        sem_wait(&full);
        sem_wait(&mutex);
        //Critical Section
        printf("Consumed item %d\n", buffer[out]); // Corrected typo in "Consumeded"
        out = (out + 1) % S;
        consumed++; // Corrected from produced++ to consumed++
        //End of Critical Section

        sem_post(&mutex);
        sem_post(&empty);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producerThread , consumerThread;

    sem_init(&empty, 0, S);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
}