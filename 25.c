#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int child_count = 3;
    int i;

    for (i = 0; i < child_count; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {
            // Child process
            printf("Child %d with PID %d is running\n", i + 1, getpid());
            sleep(2); // Simulate some work in the child process
            exit(0);
        }
    }

    // Parent process
    printf("Parent process with PID %d is waiting for a specific child...\n", getpid());

    // Wait for a specific child (e.g., the second child)
    int status;
    pid_t specific_child_pid = waitpid(-1, &status, 0); // Change -1 to the specific child's PID if needed

    if (specific_child_pid != -1) {
        printf("Parent process has waited for child with PID %d to finish.\n", specific_child_pid);
    } else {
        perror("Wait failed");
        exit(1);
    }

    return 0;
}

