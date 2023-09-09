/*
============================================================================
Name : 7.c
Author : Nikita Gupta
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 29th Aug, 2023.
============================================================================
*/


#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc,char*argv[]){
	
	// checking if all the files are provided
	if(argc !=3){
		printf("no sourcefile only  %s preesent",argv[0]);
		return 1;
	}

	int srcfd, destfd;
	int rd, wr;
	char buffer;
	
	//opening the srcfile for reading
	srcfd = open(argv[1],O_RDONLY);
	if (srcfd == -1){
		printf("error opening source file");
		return 1;
	}

	//open the destfile  for writing , create if not exists, truncate if exists
	destfd =open(argv[2], O_WRONLY| O_CREAT| O_TRUNC,0644);
	if( destfd ==-1){
		printf("Error opening destination file");
		close(srcfd);
		return 1;
	}

	//copy data 
	while(rd = read(srcfd,&buffer,sizeof(buffer)) >0){
		wr= write(destfd,&buffer,rd);
		if(wr!=rd){
			printf("error writing ");
			close(srcfd);
			close(destfd);
			return 1;
		}
	}
	printf("Contents %s copied succesfully to %s\n",argv[1],argv[2]);

	//close files
	close(srcfd);
	close(destfd);

	return 0;
}

