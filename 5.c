/*
============================================================================
Name : 5.c
Author : Nikita Gupta
Description : Write a program to create five new files with infinite loop. Execute the program in the background
	      and check the file descriptor table at /proc/pid/fd.
Date: 29th Aug, 2023.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
int main()
{
	int fd1=creat("fiftha.txt",O_RDONLY);
	int fd2=creat("fifthb.txt",O_RDONLY);
	int fd3=creat("fifthc.txt",O_RDONLY);
	int fd4=creat("fifthd.txt",O_RDONLY);
	int fd5=creat("fifthe.txt",O_RDONLY);

	if(fd1 && fd2 && fd3 && fd4 && fd5)
	{
		perror("Files created successfully");
	}
	else
	{
		perror("Files can't be opened\n");
	}

	while(1)
	{
	}

	return 0;
}
