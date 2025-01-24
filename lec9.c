#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void main()
{
    int stat;
    for (int i = 0; i < 5; i++)
    {
        if (fork() == 0)
        {
            printf("I am child %d , parent %d \n", getpid(), getppid());
            sleep(3);
            printf("I %d process id done\n", getpid());
            //      exit(0);
        }
        printf("DONE\n");
    }
    printf("Hello! Made children...\n");
    for (int i = 0; i < 5; i++)
    {
        wait(0);
    }

    return;
}