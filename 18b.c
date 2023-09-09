/*
============================================================================
Name : 18b.c
Author : Nikita Gupta
Description : Write a program to perform Record locking.
              b. Implement read  lock
Date: 29th Aug, 2023.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

        struct{
        int flight_no;
        int flight_tno;
        }f[3];

        for(int i=0;i<3;i++){
        f[i].flight_no =i+1;
        f[i].flight_tno=0;
        }

        int fd=open("records.txt",O_RDWR);
        if(fd<0){
        perror("file doesn't exist\n");
        return 0;
        }
        int wrcount =write(fd,f,sizeof(f));
        if(wrcount<0)
        {
        printf("error\n");
        return 0;

        }
        else
                printf("sucess");
        return 0;
}

