/*
============================================================================
Name : 24.c
Author : Nikita Gupta
Description : Write a program to create an orphan process.
Date: 29th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	if(fork()==0)
	{
		printf("child process : %d \n,parent id: %d\n",getpid(),getppid());
		sleep(5);
		printf("orphan process : %d , parent of orphan id : %d\n", getpid(),getppid());
	}
	else
	{
		printf("parent process : %d\n",getpid());
		exit(0);
	}
	return 0;
}
