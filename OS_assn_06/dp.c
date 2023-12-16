#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5 

enum { THINKING, HUNGRY, EATING }; 

sem_t mutex;
sem_t semaphore[N];

int state[N];

void think(int philosopher_number) {
    printf("Philosopher %d is thinking.\n", philosopher_number);
    sleep(rand() % 3 + 1); 
}

void eat(int philosopher_number) {
    printf("Philosopher %d is eating.\n", philosopher_number);
    sleep(rand() % 3 + 1); 
}

void test(int philosopher_number) {
    if (state[philosopher_number] == HUNGRY &&
        state[(philosopher_number + 1) % N] != EATING &&
        state[(philosopher_number + N - 1) % N] != EATING &&
        (philosopher_number % 2 == 0 || state[(philosopher_number + 2) % N] != EATING)) {
       
        state[philosopher_number] = EATING;
        sem_post(&semaphore[philosopher_number]);
    }
}

void grab_forks(int philosopher_number) {
    sem_wait(&mutex);
    state[philosopher_number] = HUNGRY;
    test(philosopher_number);
    sem_post(&mutex);
    sem_wait(&semaphore[philosopher_number]);
}

void release_forks(int philosopher_number) {
    sem_wait(&mutex);
    state[philosopher_number] = THINKING;
    test((philosopher_number + 1) % N);
    test((philosopher_number + N - 1) % N);
    sem_post(&mutex);
}

void *philosopher(void *arg) {
    int philosopher_number = *(int *)arg;

    while (1) {
        think(philosopher_number);
        grab_forks(philosopher_number);
        eat(philosopher_number);
        release_forks(philosopher_number);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t philosophers[N];
    int philosopher_numbers[N];

    
    sem_init(&mutex, 0, 1);
    for (int i = 0; i < N; ++i) {
        sem_init(&semaphore[i], 0, 0);
        philosopher_numbers[i] = i;
    }

    
    for (int i = 0; i < N; ++i) {
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_numbers[i]);
    }

  
    sleep(30);

  
    for (int i = 0; i < N; ++i) {
        pthread_cancel(philosophers[i]);
    }

    
    sem_destroy(&mutex);
    for (int i = 0; i < N; ++i) {
        sem_destroy(&semaphore[i]);
    }

    return 0;
}

