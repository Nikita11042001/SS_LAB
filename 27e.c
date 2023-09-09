#include<stdio.h>
#include<unistd.h>

int main()
{       char *arg[]={"ls","-Rl",NULL};
       	execvp("ls",arg);

	perror("execvp");
	return 1;
}

