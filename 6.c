/*
============================================================================
Name : 6.c
Author : Nikita Gupta
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 29th Aug, 2023.
============================================================================
*/


#include<unistd.h>
#include<stdio.h>

int main(){
	char buffer[1024]; 
	int rd, wr;
	
	//read input from stdin (fiel descriptor 0) from the buffer
	rd= read(0,buffer,sizeof(buffer));

	if(rd == -1){
		perror("Error reading from stdin");
		return 1;
	}

	//write the content of the buffer to stdout(fiel descriptor 1)
	
	wr = write(1,buffer,rd);

	if(wr ==-1){
		perror("error writing to stdout");
		return 1;
	}

	return 0;

}
