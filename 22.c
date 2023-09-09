/*
============================================================================
Name : 22.c
Author : Nikita Gupta
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
              parent processes. Check output of the file.
Date: 29th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{

	int fd =open("22.txt",O_CREAT|O_RDWR,0744);
	
	char c[] ="This is a child process";
	char p[] = "This is a parent process";
	if(!fork())
		write(fd,c,sizeof(c));
	else
		write(fd,p,sizeof(p));
}
