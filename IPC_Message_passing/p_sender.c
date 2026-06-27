/* This program (p_sender.c) sends a message using named pipe to an unrelated process (p_receive.c) */ 
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
int fd = open(fifo, O_WRONLY); 
printf("Enter message : "); 
fflush(stdout); 
fgets(msg, sizeof(msg), stdin); 
msg[strcspn(msg, "\n")] = 0;   // remove newline 
write(fd, msg, strlen(msg)+1); 
close(fd); 
printf("Parent sent message\n"); 
fflush(stdout); 
} 