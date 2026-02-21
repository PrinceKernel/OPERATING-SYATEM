// Question 1: File Writing Using Parent and Child Processes
// 
// Problem Statement:

// Develop a C program that demonstrates process synchronisation and shared file access. The program
// shall create a child process; both processes will then write unique identifiers to a common file.
// 
// Requirements:
// 
// • System Calls: Implement the solution using fork(), open(), write(), close(), and wait() or
// sleep().
// 
// • Output Strings:
// – Parent: ”This line is written by the parent process.”
// – Child: ”This line is written by the child process.”
// 
// • Concurrency: The parent process must wait for the child to terminate to prevent ”orphan”
// processes and ensure sequential logic.
// 
// • Data Persistence: Use O APPEND or careful offset management to ensure that the processes do
// not overwrite each other’s data.
// Implementation Guide
// To ensure the parent and child share the same file pointer, the file should be opened before the fork()
// call.
// 
// Listing 1: Template for fork and file I/O


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<string.h>
int main(){
 fd=("output.txt",O_CREAT | O_WRONLY | O_APPEND , 0664);
if(fd < 0){
    perror("file open filed ");
    exit(1);
}

pid_t pid = fork();
if(pid ==0){
    char child_text[]="this is a child text \n";
    write(fd , child_text ,strlen(child_text));
    close(fd);
    exit(0)
   
}

else{
    char parent_msg = "this is a parent msg";
    write(fd , parent_msg ,strlen(parent_msg));
    close(fd);
    wait(1);
}

return 0;
}