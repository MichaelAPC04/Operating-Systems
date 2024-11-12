/*************************
 * Date: 29/09/2024
 * Version: 1.0.0
 * Description: The following code implements mutexes to prevent race conditions in an ATM system that where the user can input the number of ATMs and the amount of money that they want to deposit.
 *************************/
/* Task3.c */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Shared account balance variable
int account_balance = 0;

// Mutex for synchronizing access to the account balance
pthread_mutex_t balance_mutex;

// Struct for thread arguments
typedef struct {
    int deposit_amount;
    int num_deposits;
} ThreadArgs;

// Function to be executed by each thread
void *deposit_money(void *args) {
    ThreadArgs *thread_args = (ThreadArgs *)args;
    int deposit_amount = thread_args->deposit_amount;
    int num_deposits = thread_args->num_deposits;

    // Lock the mutex
    pthread_mutex_lock(&balance_mutex);

    // Deposit the specified amount into the account balance
    for (int i = 0; i < num_deposits; i++) {
        account_balance += deposit_amount;
    }

    // Unlock the mutex
    pthread_mutex_unlock(&balance_mutex);

    return NULL;
}

// main function for execution
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s num_atms\n", argv[0]);
        return 1;
    }

    int num_atms = atoi(argv[1]);

    pthread_t atms[num_atms];
    ThreadArgs thread_args[num_atms];

    // Initialize the mutex
    pthread_mutex_init(&balance_mutex, NULL);

    // Create the ATMs (threads)
    for (int i = 0; i < num_atms; i++) {
        printf("Enter the deposit amount and the number of deposits for ATM %d (e.g. 10 1000): ", i);
        scanf("%d %d", &thread_args[i].deposit_amount, &thread_args[i].num_deposits);
        // Create the thread
        pthread_create(&atms[i], NULL, deposit_money, &thread_args[i]);
    }

    // Wait for all ATMs to finish
    for (int i = 0; i < num_atms; i++) {
        // Wait for the thread to finish
        pthread_join(atms[i], NULL);
    }

    // Print the final account balance
    printf("Final account balance: %d\n", account_balance);

    // Destroy the mutex
    pthread_mutex_destroy(&balance_mutex);

    return 0;
}
