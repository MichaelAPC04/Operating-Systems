/*************************
 * Date: 26/08/2024
 * Version: 1.0.0
 *************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to calculate the factorial of a given number
int factorial(int n) {
    // Define int fact var at 1
    int fact = 1;
    // While i less than the parsed num, fact is reassigned to itself multiplied by 1
    for(int i = 1; i <= n; i++){
        fact = fact * i;
    }
    return fact;
}

int main() {
    int N, i;
    // Take user input
    printf("Enter the number of child processes to create: ");
    scanf("%d", &N);

    // Begin creating and executing child processes 
    for (i = 0; i < N; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            // Fork failed
            printf("Fork failed for child %d\n", i);
            exit(1);
        } else if (pid == 0) {
            // Child process
            printf("Child process with PID: %d and Parent PID: %d\n", getpid(), getppid());
            
            int result = factorial(i + 1); // Calculation of input
            // Print the result
            printf("The factorial of %d is %d\n", i + 1, result);
            
            exit(0); // Child process ends
        } else {
            // Parent process
            // Print message indicating the creation of a child process
            printf("Parent process created a child process with the PID: %d\n", pid);
        }
    }

    // A loop for parent to wait for all child processes
    for (i = 0; i < N; i++) {
        wait(NULL);
    }

    // Print successful child process termination
    printf("All children have terminated. Parent process exiting.\n");
    return 0;
}
