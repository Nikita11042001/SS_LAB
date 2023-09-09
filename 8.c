/*
============================================================================
Name : 8.c
Author : Nikita Gupta
Description :Write a program to open a file in read only mode, read line by line and display each line as it is read.
	     Close the file when end of file is reached. 
Date: 29th Aug, 2023.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
        char f1[100];
        printf("enter the file to open");
	scanf("%s",f1);
	int fd =open(f1,O_RDONLY,0744);
	char c[1];
	while(read(fd,c,1)){
		if(c[0]=='\n'){
			getchar();
		}
		else
			printf("%c",c[0]);
	}

         close(fd);
        }
