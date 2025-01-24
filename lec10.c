/*
write a program in which parent process checks the palindrome
and child process generates prime number upto n.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int pid;
    pid = fork();

    if (pid == 0)
    {
        int terms;
        printf("Enter the value upto which prime you want: ");
        scanf("%d", &terms);
        getchar();

        int isPrime;

        for (int i = 0; i <= terms; i++)
        {
            isPrime = 1;
            for (int j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    isPrime = 0;
                }
            }
            if (isPrime)
            {
                printf("%d ", i);
            }
        }
    }
    else
    {
        wait(0);
        char str[100];
        // checks palindrome
        printf("Enter your string: ");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';
        puts(str);

        int len = strlen(str);
        int isPalin = 1;

        for (int i = 0; i < len / 2; i++)
        {
            if (str[i] != str[len - i - 1])
            {
                isPalin = 0;
                break;
            }
        }
        if (isPalin)
            printf("Palindrome\n");
        else
            printf("Not Palindrome\n");
    }
    return 0;
}