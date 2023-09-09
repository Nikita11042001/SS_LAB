/*
============================================================================
Name : 4.c
Author : Nikita Gupta
Description : Write a program to open an existing file with read write mode. 
	      Try O_EXCL flag also.
Date: 29th Aug, 2023.
============================================================================
*/



#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd = open("createdfile.txt",O_EXCL,O_RDWR);
	if(fd<0)
	{
		perror("Error in Opening File\n");
	}
	else
	{
		printf("File opened Successfully\n");
		printf("File descriptor: %d\n" ,fd);
	}
	return 0;
}

