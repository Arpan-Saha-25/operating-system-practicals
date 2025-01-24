#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
    int pid, status;
    pid = fork();

    if (pid == 0)
    {
        // child
        printf("\nIm from child");
        exit(0);
    }
    else if (pid < 0)
    {
        printf("Error in creating process");
        exit(1);
    }
    else
    {
        wait(&status);
        printf("\nIm from parent");
        printf("\nStatus obtained: %d", status);
    }
}