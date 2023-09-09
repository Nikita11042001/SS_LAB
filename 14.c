/*
============================================================================
Name : 14.c
Author : Nikita Gupta
Description : Write a program to find the type of a file.
	      a. Input should be taken from command line.
	      b. program should be able to identify any type of a file.
Date: 29th Aug, 2023.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
//#include<sys/types.h>
//#include<sys/sysmacros.h>

int main(int argc, char *argv[]){
	struct stat sb;
	int fd=open(argv[1],O_RDONLY,0744);
	int x =fstat(fd,&sb);
	printf("File type:  ");
	switch(sb.st_mode & S_IFMT){
	case S_IFBLK : printf("Block file\n");break;
	case S_IFCHR : printf("Character file\n");break;
	case S_IFDIR : printf("Directory file\n");break;
	case S_IFIFO : printf("Fifo/pipr \n");break;
	case S_IFLNK : printf("Symlink \n");break;
	case S_IFREG : printf("Regular file\n");break;
	case S_IFSOCK : printf("Socket file\n");break;
	default: printf("unknown");
	}
}
