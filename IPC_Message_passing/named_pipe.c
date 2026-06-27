/* This program (namedpipe.c) sends a message from parent process to child process */ 
#include <stdio.h> 
#include <unistd.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
 
int main() { 
    char *fifo = "myfifo"; 
    char msg[100], buffer[100]; 
 
    mkfifo(fifo, 0666); 
 
    pid_t pid = fork(); 
 
    if (pid > 0) {   // Parent 
        int fd = open(fifo, O_WRONLY); 
 
        printf("Enter message for child: "); 
        fflush(stdout); 
 
        fgets(msg, sizeof(msg), stdin); 
        msg[strcspn(msg, "\n")] = 0;   // remove newline 
 
        write(fd, msg, strlen(msg)+1); 
        close(fd); 
 
        printf("Parent sent message\n"); 
        fflush(stdout); 
 
        wait(NULL);   // ensure child prints after parent 
    } 
    else {           // Child 
        int fd = open(fifo, O_RDONLY); 
        read(fd, buffer, sizeof(buffer)); 
 
        printf("Child received message: %s", buffer); 
        fflush(stdout); 
 
        close(fd); 
    } 
    return 0; 
} 