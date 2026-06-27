
# IPC (Inter-Process Communication)

## Definition

**Inter-Process Communication (IPC)** is a mechanism that allows two or more processes to exchange data and synchronize their execution.

Processes normally have separate memory spaces, so IPC provides a way for them to communicate.

---

# Types of IPC 

| Program                       | IPC Method                            | Related/Unrelated   |
| ----------------------------- | ------------------------------------- | ------------------- |
| `unnamed_pipe.c`              | Unnamed Pipe (`pipe()`)               | Parent ↔ Child      |
| `named_pipe.c`                | Named Pipe (FIFO)                     | Parent ↔ Child      |
| `p_sender.c` + `p_receiver.c` | Named Pipe (FIFO)                     | Unrelated Processes |
| `message_queue.c`             | Message Queue                         | Parent ↔ Child      |
| `shared_memory.c`             | Shared Memory (`shmget()`, `shmat()`) | Parent ↔ Child      |


---

# 1. unnamed_pipe.c

### Definition

An **Unnamed Pipe** is a temporary communication channel created using `pipe()`. It exists only while the processes are running.

It can communicate **only between related processes** (parent and child).

### Functions used

```c
pipe()
```

Creates the pipe.

```c
fork()
```

Creates the child process.

```c
write()
```

Parent writes data into the pipe.

```c
read()
```

Child reads data from the pipe.

```c
close()
```

Closes the unused end of the pipe.

### Flow

```
Parent
   |
write()
   |
Unnamed Pipe
   |
read()
   |
Child
```

---

# 2. named_pipe.c

### Definition

A **Named Pipe (FIFO)** is a special file created in the operating system.

Unlike an unnamed pipe, it has a filename and can exist even after the creating process exits.

### Function used

```c
mkfifo()
```

Creates a FIFO file.

```c
open()
```

Opens the FIFO.

```c
write()
```

Writes data.

```c
read()
```

Reads data.

```c
close()
```

Closes FIFO.

### Flow

```
Parent
   |
write()
   |
FIFO File
   |
read()
   |
Child
```

---

# 3. p_sender.c & p_receiver.c

### Definition

This demonstrates communication between **two unrelated processes**.

Both processes access the same FIFO file.

One program sends.

One program receives.

### Sender

Creates FIFO

↓

Opens FIFO in Write Mode

↓

Writes Message

↓

Closes FIFO

---

### Receiver

Opens FIFO in Read Mode

↓

Reads Message

↓

Prints Message

↓

Closes FIFO

### Flow

```
Sender Program
      |
      | write()
      |
 Named Pipe (FIFO)
      |
      | read()
      |
Receiver Program
```

---

# 4. message_queue.c

### Definition

A **Message Queue** is an IPC mechanism where messages are stored inside a kernel-managed queue.

The sender and receiver do **not** have to execute at exactly the same time.

Messages remain in the queue until they are read or deleted.

### Functions used

```c
ftok()
```

Generates a unique IPC key.

```c
msgget()
```

Creates or accesses a message queue.

```c
msgsnd()
```

Sends a message to the queue.

```c
msgrcv()
```

Receives a message from the queue.

```c
msgctl()
```

Deletes the queue.

### Flow

```
Parent
   |
msgsnd()
   |
Message Queue
   |
msgrcv()
   |
Child
```

---

# Difference between Pipe and Message Queue

| Pipe                                     | Message Queue                      |
| ---------------------------------------- | ---------------------------------- |
| Data flows like a stream                 | Data stored as individual messages |
| FIFO order                               | Message types supported            |
| Sender and receiver usually run together | Can run independently              |
| Simpler                                  | More flexible                      |

---


### Difference between Related and Unrelated Processes

**Related Processes**

* Created using `fork()`
* Example: Parent and Child

**Unrelated Processes**

* Started independently
* Example: `p_sender.c` and `p_receiver.c`

Good catch. Here's the **Shared Memory** section you can add to your IPC README.

---

# Shared Memory

## Definition

**Shared Memory** is an IPC mechanism where two or more processes communicate by accessing the **same memory segment**.

Unlike pipes or message queues, data is **not copied** between processes. Instead, both processes read and write directly to the shared memory, making it one of the **fastest IPC methods**.

---

## Functions Used

### `ftok()`

Generates a unique key.

```c
key_t key = ftok("shmfile",65);
```

---

### `shmget()`

Creates or accesses a shared memory segment.

```c
shmget(key,1024,0666|IPC_CREAT);
```

---

### `shmat()`

Attaches the shared memory to the process's address space.

```c
shmat(shmid,NULL,0);
```

---

### `shmdt()`

Detaches the shared memory.

```c
shmdt(data);
```

---

### `shmctl()`

Removes the shared memory segment.

```c
shmctl(shmid,IPC_RMID,NULL);
```

---

## Program Flow

```text
Parent
   |
Writes Message
   |
Shared Memory
   |
Reads Message
   |
Child
```

---

## How Your Program Works

1. Generate a unique key using `ftok()`.
2. Create shared memory using `shmget()`.
3. Attach it using `shmat()`.
4. Create a child process using `fork()`.
5. Parent writes the message into shared memory.
6. Child waits briefly (`sleep()`) and reads the same message.
7. Both processes detach using `shmdt()`.
8. Parent removes the shared memory using `shmctl()`.

---

## Sample Output

**Input**

```text
Enter message: Hello World
```

**Output**

```text
Parent wrote to shared memory
Child read from shared memory: Hello World
```

---

# Difference Between Message Queue and Shared Memory

| Message Queue                            | Shared Memory                      |
| ---------------------------------------- | ---------------------------------- |
| Data is sent as messages                 | Processes share the same memory    |
| Uses `msgsnd()` and `msgrcv()`           | Uses `shmat()` to access memory    |
| Slower due to copying                    | Faster because no data copying     |
| Suitable for message-based communication | Suitable for large amounts of data |


# Questions

### What is IPC?

IPC (Inter-Process Communication) is a mechanism that allows multiple processes to exchange data and synchronize with each other.

---

### What is an Unnamed Pipe?

An unnamed pipe is a temporary communication channel created using `pipe()` and used only between related processes.

---

### What is a Named Pipe?

A named pipe (FIFO) is a special file created using `mkfifo()` that allows communication between related or unrelated processes.

---

### Why is `fork()` used?

`fork()` creates a child process from the parent process.

---

### Why do we close one end of the pipe?

A pipe has two ends:

* Read end
* Write end

The parent closes the read end because it only writes.

The child closes the write end because it only reads.

---

### Why is `mkfifo()` used?

It creates a FIFO (named pipe) in the file system.

---

### Why is `ftok()` used?

It generates a unique key used to identify a message queue.

---

### Difference between Related and Unrelated Processes

**Related Processes**

* Created using `fork()`
* Example: Parent and Child

**Unrelated Processes**

* Started independently
* Example: `p_sender.c` and `p_receiver.c`


### What is Shared Memory?

Shared Memory is an IPC mechanism where multiple processes communicate by accessing the same memory segment.

---

### Why is Shared Memory the fastest IPC method?

Because processes directly access the same memory without copying data between them.

---

### Why is `shmat()` used?

To attach the shared memory segment to the process's address space.

---

### Why is `shmdt()` used?

To detach the shared memory after use.

---

### Why is `shmctl()` used?

To delete the shared memory segment and free system resources.

---

### Which process writes and which process reads in your program?

* **Parent process** → Writes the message.
* **Child process** → Reads the message from shared memory.

This section matches the style of the rest of your IPC notes and completes the coverage of all the message-passing programs.
