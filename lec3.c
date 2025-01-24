#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void forkexample()
{
    int i, n = 4, pid, status;

    for (i = 0; i <= n; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            printf("Hello I am child process");
            printf("My pid is %d\n", getpid());
        }
        else
        {
            wait(&status);
        }
    }
}

int main()
{
    forkexample();
    return 0;
}