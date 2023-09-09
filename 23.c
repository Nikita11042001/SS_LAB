/*
============================================================================
Name : 23.c
Author : Nikita Gupta
Description : Write a program to create a Zombie state of the running program.
Date: 29th Aug, 2023.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int f=fork();
	if(f>0)
	{
		printf("parent pid= %d\n",getpid());
		printf("parent process \n");
		sleep(10);
		printf("parent awake\n");
	}
	else
	{
		printf("child pid= %d\n",getpid());
		printf("child process");
	}
}
