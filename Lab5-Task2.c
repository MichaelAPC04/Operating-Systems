/*************************
 * Date: 29/09/2024
 * Version: 1.0.0
 * Description: The following program implements mutexes to lock each threads' access to the shared counter variable that is incremented to prevent race conditions.
 *************************/
/* task2.c */

#include <stdio.h>
#include <pthread.h>

#define NUM_ITERATIONS 1000000
#define NUM_THREADS 2

// Shared counter variable
int counter = 0;

// Global Mutex variable
pthread_mutex_t mutex;

// Function to be executed by each thread
void *updateCounter(void *args) {
    int id = *(int *)args;
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        // Lock mutex.
        pthread_mutex_lock(&mutex);
        int temp = counter;
        temp = temp + 1;
        counter = temp;
        // Unlock mutex.
        pthread_mutex_unlock(&mutex);
    }
    printf("Thread %d finished. Counter = %d\n", id, counter);
    return NULL;
}

// main function for execution
int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialise the mutex
    pthread_mutex_init(&mutex, NULL);
    
    // Create the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, updateCounter, &thread_ids[i]);
    }
    
    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);
    
    // Print the final value of the counter
    printf("Final value of counter: %d\n", counter);
    
    return 0;
}

