
# Multithreading

## Definition

**Multithreading** is the execution of multiple threads within a single process.

Threads run concurrently and share the same memory space.

---

## Thread

A **thread** is the smallest unit of execution inside a process.

One process can contain multiple threads.

---

## Advantages

* Faster execution
* Better CPU utilization
* Resource sharing
* Parallel execution

---

## Functions Used

### `pthread_create()`

Creates a new thread.

```c
pthread_create(&thread,NULL,function,NULL);
```

---

### `pthread_join()`

Waits until the thread finishes execution.

```c
pthread_join(thread,NULL);
```

---

### `pthread_exit()`

Terminates the thread.

```c
pthread_exit(NULL);
```

---

## Program Flow

```text
Main Thread
     |
Creates 3 Threads
     |
-------------------------
|        |             |
Even     Odd      Natural Sum
|        |             |
Compute  Compute   Compute
-------------------------
        |
pthread_join()
        |
Print Results
```

---

## In Your Program

Three threads are created:

### Thread 1

Calculates

```text
Sum of Even Numbers
```

---

### Thread 2

Calculates

```text
Sum of Odd Numbers
```

---

### Thread 3

Calculates

```text
Sum of Natural Numbers
```

---

After all threads finish,

```text
pthread_join()
```

waits for every thread.

Finally,

the program prints all three sums.

---

## Sample Output

```text
Enter a number:
10

Sum of Natural Numbers = 55
Sum of Even Numbers = 30
Sum of Odd Numbers = 25

Even Numbers
2
4
6
8
10

Odd Numbers
1
3
5
7
9
```

---

## Questions

### What is a Process?

A process is a program in execution.

---

### What is a Thread?

A thread is the smallest unit of execution inside a process.

---

### Difference between Process and Thread

| Process         | Thread            |
| --------------- | ----------------- |
| Independent     | Part of a process |
| Separate memory | Shared memory     |
| More overhead   | Less overhead     |

---

### What is Multithreading?

Running multiple threads concurrently within the same process.

---

### Which library is used?

```c
pthread.h
```

---

### Why is `pthread_create()` used?

To create a new thread.

---

### Why is `pthread_join()` used?

To wait until a thread completes execution.

---

### Why is `pthread_exit()` used?

To terminate the thread.

---

### How many threads are created in your program?

**Three threads**:

1. Sum of even numbers
2. Sum of odd numbers
3. Sum of natural numbers
