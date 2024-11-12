/*
 * Description: This program takes a command line argument of a specified date format and text file. The porgram then outputs the current date in the specified format, as well as reading and outputting the contents of the specified text file.  
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
        
    pid_t pid = fork();   // fork off new child process

    // if pid less than 0, it has failed
    if (pid < 0) {
        perror("Fork failed!");
        exit(1);
    }
    
    // if successful, enter child process
    else if (pid == 0){
        printf("Child process: 'date' command in execution for current date\n");
        execlp("date", "date", NULL);   // execute sys date command
    }
    
    // if successful, enter parent process
    else {
        printf("Parent process: 'cat' command in execution for parsed txt file\n");
        execlp("cat", "cat", argv[2], NULL);   // read parsed file, store the command line filename in argv[2]
    }
    
    return 0;

}