/*
============================================================================
Name : 15.c
Author : Nikita Gupta
Description : Write a program to display the environmental variable of the user (use environ).
Date: 29th Aug, 2023.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>

extern char** environ;
int main(){
	int i;
	printf("Environment Variables\n");
	for (i=0;environ[i];i++)
		printf("%s\n",environ[i]);
	return 0;
}
