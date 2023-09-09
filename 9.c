/*
============================================================================
Name :9.c
Author : Nikita Gupta
Description : Write a program to print the following information about a given file.
	      a. inode
	      b. number of hard links
	      c. uid
	      d. gid
	      e. size
	      f. block size
	      g. number of blocks
	      h. time of last access
	      i. time of last modification
	      j. time of last change	
Date: 29th Aug, 2023.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>

int main(){
	char f1[100];
	printf("Enter the file name: ");
	scanf("%s",f1);
	int fd=open(f1,O_RDONLY,0744);
	struct stat fileinfo;
	if(fd==-1)
		printf("file doesn't exist\n");
	else{
		int info =fstat(fd,&fileinfo);
		if(info!=0)
			printf("Error\n");
		else{
			printf("file information:  \n");
			printf("file inode no: %d \n",(int) (fileinfo.st_ino));
			printf("number of hardlinks: %d\n",(int)(fileinfo.st_nlink));
			printf("user id:  %d\n",(int)(fileinfo.st_uid));
			printf("group id:  %d\n",(int)(fileinfo.st_gid));
			printf("file size:  %d\n",(int)(fileinfo.st_size));
			printf("block size:  %d\n",(int)(fileinfo.st_blksize));
			printf("number of blocks: %d\n",(int)(fileinfo.st_blocks));
			printf("time of last access: %s",ctime(&fileinfo.st_atime));
			printf("time of last modification: %s",ctime(&fileinfo.st_mtime));
			printf("time of last change: %s",ctime(&fileinfo.st_ctime));
		}}
	close(fd);
}
