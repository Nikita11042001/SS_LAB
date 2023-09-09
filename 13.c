/*
============================================================================
Name : 13.c
Author : Nikita Gupta
Description : Write a program to wait for a STDIN for 10 seconds using select. 
	      Write a proper print statement to verify whether the data is 
	      available within 10 seconds or not (check in $man 2 select). 
Date: 29th Aug, 2023.
============================================================================
*/


#include<stdio.h>
#include<sys/select.h>
#include<sys/time.h>

int main(void){
        fd_set rfds;
        struct timeval tv;
        int retval;

        tv.tv_sec=10;
	tv.tv_usec=0;

        FD_SET(0, &rfds);
	printf("Enter the input within 10 sec..\n");
        retval= select(1,&rfds,NULL,NULL,&tv);

        if(retval)
                printf("Data is available within 5 seconds...\n");
        else
                printf("Data is not available within 5 seconds...\n");
}

