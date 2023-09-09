/*
============================================================================
Name : 11.c
Author : Nikita Gupta
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
	      descriptors and check whether the file is updated properly or not.
	      a. use dup
	      b. use dup2
	      c. use fcntl 
Date: 29th Aug, 2023.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
	int fd = open("11file.txt",O_RDWR,0744);
	if(fd ==-1)
		printf("file doen't exist");
	else{
		int fd1= dup(fd);
		lseek(fd,0,SEEK_END);
	char s[] ="using Dup";
	write(fd1,s,sizeof(s));
	
	int l = lseek(fd,0,SEEK_END);
	dup2(fd,l+1);
	char w[] = "using Dup2";
	write(fd1,w,sizeof(w));
	int fd2 =fcntl(fd,F_DUPFD);
	char u[]="using fcntl descriptor";
	write(fd2,u,sizeof(u));
	close(fd);
	close(fd1);
	close(fd2);
	}
}
