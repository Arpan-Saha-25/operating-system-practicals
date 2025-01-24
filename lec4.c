#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

// Return value of wait()
// if successful, wait() returns a value that is PID of the child whose status information has been obtained.
// If unsucessful, wait() returns -1

int main()
{
    int pid;

    if (fork() == 0)
    {
        printf("Hello! I am the 1st child\n");
        sleep(3);
        printf("First child is done\n");
        // exit(0);
    }

    else
    {
        if (fork() == 0)
        {
            printf("I'm the 2nd child.\n");
            sleep(5);
            printf("2nd child is done.\n");
            // exit(0);
        }
        else
        {
            while ((pid = wait(0)) == 0)
                printf("the child with process id=%d has completed his job.\n", pid);
            printf("Hello! All of the children have done their job.\n");
        }
    }

    return 0;
}
