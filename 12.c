/*
============================================================================
Name : 12.c
Author : Nikita Gupta
Description :  Write a program to find out the opening mode of a file. Use fcntl. 
Date: 29th Aug, 2023.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	int fd= open("8file.txt",O_RDONLY,0744);
	if(fd==-1)
		printf("file doesn't exist");
	else{
		int fval =fcntl(fd,F_GETFL);
	switch(fval & O_ACCMODE){
		case O_RDONLY: printf("read only mode"); break;
		case O_WRONLY: printf("write only mode"); break;
		case O_RDWR: printf("read write mode"); break;
		default: printf("unknown");
		}
	}
	close(fd);
}
