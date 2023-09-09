#include<stdio.h>
#include<unistd.h>

int main()
{   execl("/bin/ls","ls","-l",(char*)0);
}

