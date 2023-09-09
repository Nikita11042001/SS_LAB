/*
============================================================================
Name : 1.c
Author : Nikita Gupta
Description : Write a C program to create softlink,hardlink, and fifo files
Date: 29th Aug, 2023.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
	int v =symlink("destination","softlink");
	if(v<0)
	{
		perror("Failed1");
		return 1;
	}
	int f= link("destination", "hardlink");
	if(f<0)
	{
		perror("Failed2");
		return 1;
	}
	int e=mknod("destfifo",S_IFIFO,0);
	if(e>0)
	{
		perror("Failed3");
	}

}

