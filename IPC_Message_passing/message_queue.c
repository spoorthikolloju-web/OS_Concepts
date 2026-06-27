#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

// message structure
struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {

    key_t key = ftok("msgfile", 75);      // generate key
    int msgid = msgget(key, 0666 | IPC_CREAT);   // create message queue

    struct msgbuf message;

    pid_t pid = fork();

    if (pid > 0) {    // Parent sends message
        message.mtype = 1;

        printf("Enter message: ");
        fgets(message.mtext, sizeof(message.mtext), stdin);

        msgsnd(msgid, &message, sizeof(message.mtext), 0);

        printf("Parent sent message\n");
    }
    else {            // Child receives message
        msgrcv(msgid, &message, sizeof(message.mtext), 1, 0);

        printf("Child received message: %s", message.mtext);
    }

    // delete queue after use (parent)
    if (pid > 0)
        msgctl(msgid, IPC_RMID, NULL);

    return 0;
}