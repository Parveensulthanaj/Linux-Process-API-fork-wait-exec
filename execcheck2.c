//C Program to execute Linux system commands using Linux API system calls exec() family
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Create a new process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child Process: Executing 'ls -l'\n");
        
        // Replace child process image with 'ls -l' command
        execlp("ls", "ls", "-l", (char *)NULL);

        // If execlp fails
        perror("execlp failed");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        wait(NULL);  // Wait for child to finish
        printf("Parent Process: Child finished execution\n");
    }

    return 0;
}
