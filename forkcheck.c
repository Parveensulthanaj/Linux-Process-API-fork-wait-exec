//C Program to create new process using Linux API system calls fork() and exit()
#include <stdio.h>    // For printf, perror
#include <unistd.h>   // For fork(), getpid(), getppid()
#include <stdlib.h>   // For exit()
#include <sys/types.h> // For pid_t

int main() {
    pid_t pid;

    pid = fork(); // Create a new process

    if (pid < 0) {
        // If fork() returns negative, it means creation of child process failed
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // Child process
        printf("This is the child process.\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
        exit(0); // Child exits
    }
    else {
        // Parent process
        printf("This is the parent process.\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
        exit(0); // Parent exits
    }
}