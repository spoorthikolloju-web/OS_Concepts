/* This program (p_receive.c) receives a message from the named pipe from an unrelated process (p_sender.c) */ 
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
int fd = open(fifo, O_RDONLY); 
read(fd, buffer, sizeof(buffer)); 
printf("Child received message: %s", buffer); 
fflush(stdout); 
close(fd); 
return 0; 
} 