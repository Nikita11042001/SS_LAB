/*
============================================================================
Name : 16b.c
Author : Nikita Gupta
Description : Write a program to perform mandatory locking.
	      b. Implement write lock
Date: 29th Aug, 2023.
============================================================================
*/





#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

int main(void){
	struct flock lock;
	int fd;
	fd=open("lck.txt",O_RDWR,0744);
	lock.l_type=F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start =0;
	lock.l_len=0;
	lock.l_pid=getpid();
	
	fcntl(fd,F_SETLKW,&lock);

	printf("Write lock-----enter text\n");
	char c[30];
	read(0,c,sizeof(c));
	write(fd,c,sizeof(c));
	lock.l_type =F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
}	

