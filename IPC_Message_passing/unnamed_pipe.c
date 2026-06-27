/* Message passing between related processes using pipe() */ 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
void main() 
{ 
int fds[2] ,x; 
char buffer[6] ; 
pipe(fds) ; 
x=fork() ; 
if (x==0){ 
close(fds[1]) ; 
read(fds[0],buffer, 5); 
buffer[5]='\0' ; 
printf("%s\n",buffer) ; 
} 
else 
{ 
close(fds[0]) ; 
write(fds[1],"hello",5) ; 
} 
}