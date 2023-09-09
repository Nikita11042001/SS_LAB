/*
============================================================================
Name : 27.c
Author : Nikita Gupta
Description : Write a program to execute ls -Rl by the following system calls
	      a. execl
	      b. execlp
	      c. execle
	      d. execv
	      e. execvp
Date: 29th Aug, 2023.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    // Using execl
    printf("Using execl:\n");
    if (fork() == 0) {
        execl("/bin/ls", "ls", "-Rl", NULL);
    } else {
        wait(NULL);
    }

    // Using execlp
    printf("\nUsing execlp:\n");
    if (fork() == 0) {
        execlp("ls", "ls", "-Rl", NULL);
    } else {
        wait(NULL);
    }

    // Using execle
    printf("\nUsing execle:\n");
    if (fork() == 0) {
        char *envp[] = { "PATH=/bin", NULL };
        execle("/bin/ls", "ls", "-Rl", NULL, envp);
    } else {
        wait(NULL);
    }

    // Using execv
    printf("\nUsing execv:\n");
    if (fork() == 0) {
        char *args[] = { "/bin/ls", "ls", "-Rl", NULL };
        execv("/bin/ls", args);
    } else {
        wait(NULL);
    }

    // Using execvp
    printf("\nUsing execvp:\n");
    if (fork() == 0) {
        char *args2[] = { "ls", "-Rl", NULL };
        execvp("ls", args2);
    } else {
        wait(NULL);
    }

    return EXIT_SUCCESS;
}

