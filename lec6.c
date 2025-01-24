#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

    int pid;
    int a = 100, status;

    if (fork() == 0)
    {
        a = a * 5;
        printf("%d, %p\n", a, &a);
    }
    else
    {
        // wait(&status);
        a = a - 5;
        printf("%d, %p\n", a, &a);
    }
    return 0;
}