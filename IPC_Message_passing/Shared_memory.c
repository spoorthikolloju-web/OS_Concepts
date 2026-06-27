/* Message passing from parent process to child process using Shared Memory */ 
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <string.h> 
int main() { 
key_t key = ftok("shmfile", 65); 
     //
 generate unique key 
int shmid = shmget(key, 1024, 0666 | IPC_CREAT);  // create shared memory 
char *data = (char*) shmat(shmid, NULL, 0);   // attach shared memory 
pid_t pid = fork(); 
if (pid > 0) {      
// Parent writes 
printf("Enter message: "); 
fgets(data, 100, stdin); 
printf("Parent wrote to shared memory\n"); 
} 
else {              
// Child reads 
sleep(10);  // wait for parent to write 
printf("Child read from shared memory: %s", data); 
} 
// Detach shared memory 
shmdt(data); 
// Remove shared memory (only parent should do this ideally) 
if (pid > 0) 
shmctl(shmid, IPC_RMID, NULL); 
return 0; 
} 