#include<stdio.h>
#include<unistd.h>

int main()
{  
	char *cammands[]= {"ls","-Rl",NULL};
	execv("/bin/ls",cammands);

	perror("execv");
	return 1;
}

