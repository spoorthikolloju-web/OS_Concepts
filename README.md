# Operating Systems Lab Programs

This repository contains basic Operating Systems lab programs implemented in C. The programs demonstrate important OS concepts such as CPU Scheduling, Process Synchronization, Inter-Process Communication (IPC), Multithreading, and Deadlock Avoidance.

---
## Repository Structure

OPERATING_SYSTEMS/
│
├── CPU_Scheduling/
│   ├── FCFS.c
│   ├── SJF.c
│   └── RoundRobin.c
│
├── Deadlock_avoidance/
│   └── Bankers_algorithm.c
│
├── IPC_Message_passing/
│   ├── unnamed_pipe.c
│   ├── named_pipe.c
│   ├── p_sender.c
│   ├── p_receiver.c
│   ├── message_queue.c
│   └── shared_memory.c
│
├── MultiThreading/
│   └── multithreading.c
│
├── Process_Synchronization/
│   ├── Dining_philosophers.c
│   ├── Producer-consumer.c
│   └── Reader_writer.c
│
└── README.md

## Topics Covered

### 1. CPU Scheduling
**Definition:** CPU Scheduling determines which process gets the CPU for execution.

**Algorithms:**
- FCFS (First Come First Serve)
- SJF (Shortest Job First)
- Round Robin

**Applications:**
- Operating Systems
- Time-sharing systems
- Process management

**Main Concepts Used:**
- Arrival Time
- Burst Time
- Waiting Time
- Turnaround Time
- Gantt Chart

---

### 2. Multithreading
**Definition:** Multithreading allows multiple threads to execute concurrently within the same process.

**Applications:**
- Parallel computing
- Web servers
- Games
- Multitasking applications

**Main Functions Used:**
- `pthread_create()`
- `pthread_join()`
- `pthread_exit()`

---

### 3. IPC (Inter-Process Communication)
**Definition:** IPC enables multiple processes to exchange data and synchronize with each other.

**Programs Included:**
- Unnamed Pipe
- Named Pipe (FIFO)
- Message Queue
- Shared Memory

**Applications:**
- Client-Server communication
- Process coordination
- Data sharing between processes

**Main Functions Used:**
- `pipe()`
- `mkfifo()`
- `msgget()`
- `msgsnd()`
- `msgrcv()`
- `shmget()`
- `shmat()`
- `shmdt()`

---

### 4. Process Synchronization
**Definition:** Process Synchronization ensures multiple processes or threads safely access shared resources without conflicts.

**Problems Implemented:**
- Producer-Consumer
- Readers-Writers
- Dining Philosophers

**Applications:**
- Database systems
- Operating Systems
- Multi-threaded applications

**Main Functions Used:**
- `sem_init()`
- `sem_wait()`
- `sem_post()`
- `sem_destroy()`
- `pthread_create()`
- `pthread_join()`

---

### 5. Deadlock Avoidance
**Definition:** Deadlock avoidance prevents the system from entering an unsafe state during resource allocation.

**Algorithm Implemented:**
- Banker's Algorithm

**Applications:**
- Resource allocation
- Operating Systems
- Database management systems

**Main Concepts Used:**
- Available Matrix
- Allocation Matrix
- Maximum Matrix
- Need Matrix
- Safe Sequence

---

## Language Used
- **C**

## Platform
- Linux / Ubuntu
- GCC Compiler

---

## Repository Structure

```
OPERATING_SYSTEMS/
├── CPU_Scheduling/
├── Deadlock_avoidance/
├── IPC_Message_passing/
├── MultiThreading/
└── Process_Synchronization/
```

---

## How to Run

### 1. Open the terminal and navigate to the program directory.

```bash
cd path/to/program
```

### 2. Compile the C program using GCC.

```bash
gcc filename.c -o output
```

Example:

```bash
gcc FCFS.c -o fcfs
```

### 3. Run the executable.

```bash
./output
```

Example:

```bash
./fcfs
```

---

## Programs Using POSIX Threads and Semaphores

Compile with the **pthread** library.

```bash
gcc filename.c -o output -pthread
```

Example:

```bash
gcc Producer-consumer.c -o producer_consumer -pthread
./producer_consumer
```

---

## Programs Using Two Source Files

Compile both files separately.

Example:

```bash
gcc p_sender.c -o sender
gcc p_receiver.c -o receiver
```

Run them in **two different terminals**.

**Terminal 1**

```bash
./receiver
```

**Terminal 2**

```bash
./sender
```

---

## Requirements (Execution)

- Ubuntu / Linux
- GCC Compiler
- POSIX Threads (`pthread`)
