// OS Lab Programming Assignment on fork()

// Problem Statement

/* Write a C program that utilises fork() to perform a distributed sum calculation on a dataset. The
program must demonstrate sequential execution.
Requirements */

// 1. Array Initialisation : Populate an integer array of size 30 with random values between 1 and 50.


/* 2. Sequential Execution:
• Create Child 1 to calculate the sum of even integers in indices 0 − 14.
• The Parent must use waitpid() to ensure Child 1 completes before starting Child 2.
• Create Child 2 to calculate the sum of even integers in indices 15 − 29. */

// 3. Data Retrieval: Use WEXITSTATUS to collect the results from both children and print them from the Parent process.



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    int arr[30];
    int status;
    pid_t p1, p2;
    int final_sum_p1 = 0, final_sum_p2 = 0;

    srand(time(NULL));

    printf("Array initialized by Parent:\n");
    for (int i = 0; i < 30; i++) 
    {
    arr[i] = rand() % 50 + 1;
    printf("%d ,",arr[i]);
    
  }
  printf("\n");


// child 1
    p1 = fork();
    if (p1 == 0) {
        int sum = 0;
        for (int i = 0; i <= 14; i++) {
            if (arr[i] % 2 == 0) {  //even number ka liye conditation check hoga  even ha ya nhi even hoga to numbetr store ho jayega sum variable ma 
                sum += arr[i];
            }
        }
        exit(sum);
    }

    waitpid(p1, &status, 0);
    final_sum_p1 = WEXITSTATUS(status);

  // child 2
    p2 = fork();
    if (p2 == 0) {
        int add = 0;
        for (int i = 15; i <= 29; i++) {
            if (arr[i] % 2 == 0) {  //even number ka liye conditation check hoga  even ha ya nhi even hoga to numbetr store ho jayega add variable ma
                add += arr[i];
            }
        }
        exit(add); 
    }
//Parent waits for child 2
    waitpid(p2, &status, 0);
    final_sum_p2 = WEXITSTATUS(status);
    
  printf("\nTotal Even Sum of left side and right site are: %d and %d\n",final_sum_p1, final_sum_p2);

    return 0;
}

