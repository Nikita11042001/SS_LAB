/*
============================================================================
Name : 21.c
Author : Nikita Gupta
Description : Write a program, call fork and print the parent and child 
	      process id.
Date: 29th Aug, 2023.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
int main()
{
	int f=fork();
	if(f==0)
	{
		printf("This is the child process\n");
		printf(" Child process id: %d\n", getpid());
	}

	else
	{
		printf("This is the parent process\n");
		printf("Parent process id: %d\n", getpid());
	}
}
