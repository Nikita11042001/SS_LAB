/*
============================================================================
Name : 18a.c
Author : Nikita Gupta
Description : Write a program to perform Record locking.
	      a. Implement write lock
Date: 29th Aug, 2023.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
        int fd=open("records.txt",O_RDWR);
        if(fd<0){
        printf("file doesn't exist..\n");
        return 0;
        }

        struct{
        int flight_no;
        int flight_tno;
        }f[3];

        int n;
        printf("enter flight number(1,2,3): \n");
        scanf("%d",&n);

        struct flock f1;
        f1.l_type = F_WRLCK;
        f1.l_whence=SEEK_SET;
        f1.l_start = (n - 1) * sizeof(f);
        f1.l_len = sizeof(f);
        f1.l_pid = getpid();

        fcntl(fd,F_SETLKW,&f1);
        int l=lseek(fd,(n-1)*sizeof(f),SEEK_SET);
        read(fd,&f,sizeof(f));
        printf("Before entering into critical section\n");
        printf("current ticket number %d \n",f->flight_tno);
        f->flight_tno++;
        lseek(fd,(n-1)*sizeof(f),SEEK_SET);
        write(fd,&f,sizeof(f));

        printf("ticket number after %d \n",f->flight_tno);
        char c;
        printf("press Q to book ticket\n");
        scanf("%c",&c);
        while(c!='Q'){
        scanf("%c",&c);
        }
        fcntl(fd,F_GETLK,&f1);
        printf("Ticket number %d\n",f->flight_tno);
        return 0;

}

