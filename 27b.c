#include<stdio.h>
#include<unistd.h>

int main()
{ char *filename="ls";
  char *arg1="ls";	
  char *arg2="-Rl";
  execlp(filename,arg1,arg2,(char*)0);
}

