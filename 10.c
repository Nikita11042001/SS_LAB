/*
============================================================================
Name :10.c
Author : Nikita Gupta
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
	      bytes (use lseek) and write again 10 bytes.
	      a. check the return value of lseek
	      b. open the file with od and check the empty spaces in between the data. 
Date: 29th Aug, 2023.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd =open("10file.txt",O_CREAT | O_RDWR,0744);
	char f[]= "hello world !!";
	write(fd,f,sizeof(f));
	lseek(fd,10L,SEEK_CUR);
	char s[]="I am learning software system";
	write(fd,s,sizeof(s));
	close(fd);
}
