/*
============================================================================
Name : 3.c
Author : Nikita Gupta
Description : Write a C program to create a file and print the file descriptor 
              value. Use creat() system call
Date: 29th Aug, 2023.
============================================================================
*/





#include<stdio.h>
#include<fcntl.h>
int main(){
	int fd =creat("three.txt",0744);
	printf("file descriptor val: %d\n",fd);
	if (fd==-1)
		printf("file creation failed");
	else
		printf("file creation successful{file name:three.txt}\n");
}

