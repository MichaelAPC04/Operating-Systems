/*
 * Version: 1.1
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int N, i;
    printf("Enter the number of child processes to create: ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            printf("Fork failed for child %d\n", i);
            exit(1);
        } else if (pid == 0) {
            // Child process
            printf("Child process with PID: %d and Parent PID: %d is starting\n", getpid(), getppid());
            // Simulating some work by sleeping for a fixed time
            sleep(3);
            printf("Child process with PID: %d has finished\n", getpid());
            exit(0);
        } else {
            // Parent process does nothing specific here
        }
    }

    for (i = 0; i < N; i++) {
        wait(NULL);
    }

    printf("All children have terminated. Parent process exiting.\n");
    return 0;
}
