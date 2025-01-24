#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int status = 0;
    int pid;
    printf("I am the parent \n");
    pid = fork();

    if (pid < 0)
    {
        printf("\nError.");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("\nHello I am the child process.");
        printf("\nMy pid is %d", getpid());
        printf("\nThe ppid is %d\n", getppid());
        exit(0);
    }
    else
    {
        printf("I am the parent\n");
        wait(&status);
        // sleep(5);
        printf("\nHello I am the parent process.");
        printf("\nMy actual pid is %d ", getpid());
        printf("\nThe ppid is %d\n", getppid());
        exit(0);
    }
}
