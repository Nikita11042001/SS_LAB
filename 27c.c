#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Define a custom environment with a single variable
    char *my_env[] = {NULL};

    // Execute the "ls -Rl" command with the custom environment
    execle("/bin/ls", "ls", "-Rl", NULL, my_env);

    // If execle fails
    perror("execle");
    return 1;
}

