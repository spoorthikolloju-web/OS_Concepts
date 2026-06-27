

# Process Synchronization

## Definition

**Process Synchronization** is the technique used to coordinate multiple processes or threads so they can safely access shared resources without causing data inconsistency or race conditions.

### Why is it needed?

* Prevents **Race Condition**
* Ensures **Mutual Exclusion**
* Maintains data consistency
* Avoids deadlock (when designed properly)

---

# Synchronization Tools Used

### Semaphore

A semaphore is a synchronization variable used to control access to shared resources.

Functions:

```c
sem_init()
```

Initializes a semaphore.

```c
sem_wait()
```

Decrements the semaphore. If its value is 0, the thread waits.

```c
sem_post()
```

Increments the semaphore and wakes a waiting thread.

```c
sem_destroy()
```

Deletes the semaphore.

---

# 1. Producer-Consumer Problem

### Definition

One thread (**Producer**) produces data and stores it in a shared buffer.

Another thread (**Consumer**) removes and uses the data.

Synchronization ensures:

* Producer doesn't insert into a full buffer.
* Consumer doesn't remove from an empty buffer.

### Semaphores Used

* `empty` → Number of empty slots.
* `full` → Number of filled slots.
* `mutex` → Allows only one thread to access the buffer at a time.

### Flow

```text
Producer
   |
Produce Item
   |
Buffer
   |
Consume Item
   |
Consumer
```

### Program Flow

1. Producer waits for an empty slot.
2. Locks the buffer using `mutex`.
3. Inserts an item.
4. Unlocks the buffer.
5. Signals `full`.

Consumer:

1. Waits for a filled slot.
2. Locks the buffer.
3. Removes an item.
4. Unlocks the buffer.
5. Signals `empty`.

### Sample Output

```text
Produced: 1
Consumed: 1
Produced: 2
Consumed: 2
Produced: 3
Consumed: 3
...
Produced: 10
Consumed: 10
```

---

# 2. Readers-Writers Problem

### Definition

Many readers can read the shared data **simultaneously**.

A writer needs **exclusive access**.

### Rule

✅ Multiple Readers → Allowed

❌ Reader + Writer → Not Allowed

❌ Two Writers → Not Allowed

### Semaphores Used

`mutex`

* Protects the `readcount` variable.

`wrt`

* Gives exclusive access to writers.

### Flow

```text
Reader 1 ----\
Reader 2 -----\
Reader 3 -------> Shared Data
Writer --------/
```

### Program Flow

Reader:

* Increments `readcount`.
* First reader blocks writers.
* Reads data.
* Last reader allows writers.

Writer:

* Waits until no readers are reading.
* Writes data.
* Releases the resource.

### Sample Output

```text
Reader 1 is reading
Reader 2 is reading
Reader 3 is reading
Reader 1 left
Reader 2 left
Reader 3 left
Writer 1 is writing
Writer 1 left
Writer 2 is writing
Writer 2 left
```

**Note:** The order can change because thread scheduling is controlled by the operating system.

---

# 3. Dining Philosophers Problem

### Definition

Five philosophers sit around a circular table.

Each philosopher needs **two forks** to eat.

The problem demonstrates synchronization while avoiding conflicts over shared resources.

### Semaphore Used

One binary semaphore for each fork.

### Flow

```text
Fork   P0   Fork   P1   Fork   P2   Fork   P3   Fork   P4
```

Each philosopher:

1. Picks up the left fork.
2. Picks up the right fork.
3. Eats.
4. Puts both forks back.
5. Thinks.

### Sample Output

```text
Philosopher 0 is Eating
Philosopher 0 is Thinking
Philosopher 2 is Eating
Philosopher 2 is Thinking
Philosopher 4 is Eating
Philosopher 4 is Thinking
Philosopher 1 is Eating
Philosopher 1 is Thinking
Philosopher 3 is Eating
Philosopher 3 is Thinking
```

Again, the order may differ each time you run the program.

---

#  Questions

### What is process synchronization?

It is the coordination of multiple processes or threads so they safely access shared resources without conflicts.

### What is a semaphore?

A semaphore is a synchronization mechanism used to control access to shared resources.

### Difference between `mutex` and semaphore?

* **Mutex:** Only one thread owns and unlocks it.
* **Semaphore:** A counter that allows one or more threads depending on its value.

### What is a race condition?

A race condition occurs when multiple threads access and modify shared data simultaneously, leading to unpredictable results.

### Why is `mutex` used in Producer-Consumer?

To ensure only one thread accesses the shared buffer at a time.

### Why are `empty` and `full` used?

* `empty` tracks available buffer slots.
* `full` tracks occupied buffer slots.

### Why can multiple readers read together?

Reading does not modify shared data, so concurrent reads are safe.

### Why can't a writer write while readers are reading?

Writing changes the shared data, so exclusive access is required to maintain consistency.

### What is the main idea of the Dining Philosophers problem?

It demonstrates synchronization when multiple processes compete for limited shared resources (forks) while avoiding conflicts and illustrating the need to prevent deadlock.

