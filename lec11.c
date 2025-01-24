#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Function to generate Fibonacci sequence
void generate_fibonacci(int n)
{
    int a = 0, b = 1, next;
    printf("Fibonacci sequence up to %d terms:\n", n);
    if (n > 2)
    {
        printf("0 1 ");
        for (int i = 3; i <= n; i++)
        {
            next = a + b;
            a = b;
            b = next;
            printf("%d ", next);
        }
    }
    printf("\n");
}

int main()
{
    int pid;
    pid = fork();

    if (pid == 0)
    {
        // Child process: Generate Fibonacci sequence up to 'n'
        int n;
        printf("Enter the value up to which Fibonacci sequence you want: ");
        scanf("%d", &n);

        // Clear the input buffer to prevent issues with fgets in the parent
        getchar(); // This consumes the leftover newline from scanf

        generate_fibonacci(n); // Call the Fibonacci function
    }
    else
    {
        wait(0);
        // Parent process: Calculate the sum of first 'n' numbers
        int n;
        printf("Enter the value of n to compute the sum of the first n numbers: ");
        scanf("%d", &n);

        // Clear the input buffer to prevent issues with fgets in the child
        getchar(); // This consumes the leftover newline from scanf

        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += i;
        }
        printf("Sum of the first %d numbers is: %d\n", n, sum);
    }

    return 0;
}