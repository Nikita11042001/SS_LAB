/*
============================================================================
Name : 16.c
Author : Nikita Gupta
Description : Write a program to send and receive data from parent to child vice versa. Use two way
              communication.
        Date: 31th Aug, 2023.
============================================================================
*/
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int childToParentfd[2], parentToChildfd[2];
    int childToParentPipeStatus, parentToChildPipeStatus;
    int readBytes, writeBytes;
    char writeBuffer[] = "Hi! It's me!";
    char readBuffer[100];

    pid_t childPid;

    childToParentPipeStatus = pipe(childToParentfd);
    parentToChildPipeStatus = pipe(parentToChildfd);

    if (childToParentPipeStatus == -1 || parentToChildPipeStatus == -1)
    {
        perror("Error while creating the pipe!");
    }
    else
    {
        childPid = fork();

        if (childPid == -1)
        {
            perror("Error while forking child!");
        }
        else if (childPid == 0)
        {
            // Child process
            close(parentToChildfd[1]); // Close the write end of the pipe used to send data from parent to child
            close(childToParentfd[0]); // Close the read end of the pipe used to send data from child to parent

            // Read data from parent
            readBytes = read(parentToChildfd[0], readBuffer, sizeof(readBuffer));
            if (readBytes == -1)
            {
                perror("Error while reading from parent to child pipe!");
            }
            else
            {
                printf("The parent said: %s\n", readBuffer);
            }
        }
        else
        {
            // Parent process
            close(parentToChildfd[0]); // Close the read end of the pipe used to send data from parent to child
            close(childToParentfd[1]); // Close the write end of the pipe used to send data from child to parent

            // Write data to child
            writeBytes = write(parentToChildfd[1], writeBuffer, sizeof(writeBuffer));
            if (writeBytes == -1)
            {
                perror("Error while writing to parent to child pipe!");
            }
            else
            {
                printf("The child said: %s\n", writeBuffer);
            }
        }
    }

    return 0;
}
