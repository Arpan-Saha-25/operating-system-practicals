#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    // A null terminated array of char pointers
    char *args[] = {"./exec1", NULL};
    // char *args[] = ("./exec2","S","7",NULL);
    execvp(".exec2", args);
    // execvp(args[0],args);
    // execvp(./exec1",args);
    // printf("Hello\n");
    execvp(args[0], &args[0]);
    // execvp( args[0],args );

    printf("Ending..........\n");

    return 0;
}