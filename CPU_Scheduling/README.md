

# CPU Scheduling

## Definition

**CPU Scheduling** is the process of selecting one process from the ready queue and allocating the CPU to it.

### Objectives

* Maximize CPU utilization.
* Minimize waiting time.
* Minimize turnaround time.
* Improve system performance.

---

# Terms You Must Know

### 1. Arrival Time (AT)

The time at which a process enters the ready queue.

### 2. Burst Time (BT)

The amount of CPU time required by a process.

### 3. Completion Time (CT)

The time at which the process finishes execution.

### 4. Turnaround Time (TAT)

```text
TAT = CT − AT
```

### 5. Waiting Time (WT)

```text
WT = TAT − BT
```

---

# 1. FCFS (First Come First Serve)

### Definition

The process that arrives first gets the CPU first.

### Principle

**First Arrival → First Execution**

### Characteristics

* Non-preemptive
* Simple to implement
* Can suffer from the **Convoy Effect** (a long process delays all shorter ones)

### Flow

```text
P1 → P2 → P3 → P4
```

### Example

| Process | AT | BT |
| ------- | -: | -: |
| P1      |  0 |  5 |
| P2      |  1 |  3 |
| P3      |  2 |  2 |

### Gantt Chart

```text
0      5      8      10
| P1 | P2 | P3 |
```

---

# 2. SJF (Shortest Job First)

### Definition

The process with the **smallest burst time** executes first.

### Principle

**Shortest Burst Time → First Execution**

### Characteristics

* Non-preemptive (in your lab)
* Gives minimum average waiting time.
* Requires knowledge of burst times.

### Flow

```text
Shortest Job
      ↓
Execute First
```

### Example

| Process | BT |
| ------- | -: |
| P1      |  6 |
| P2      |  2 |
| P3      |  4 |

Execution Order:

```text
P2 → P3 → P1
```

### Gantt Chart

```text
0     2      6      12
| P2 | P3 | P1 |
```

---

# 3. Round Robin (RR)

### Definition

Each process gets the CPU for a fixed amount of time called the **Time Quantum**.

If the process is not finished, it goes to the end of the ready queue.

### Principle

**Time Sharing**

### Characteristics

* Preemptive
* Fair scheduling
* Used in time-sharing systems

### Flow

```text
P1 → P2 → P3 → P1 → P2 ...
```

### Example

Time Quantum = **2**

| Process | BT |
| ------- | -: |
| P1      |  5 |
| P2      |  3 |
| P3      |  2 |

### Gantt Chart

```text
0   2   4   6   8   9   10
|P1|P2|P3|P1|P2|P1|
```

---

# Comparison

| FCFS                   | SJF                         | Round Robin                       |
| ---------------------- | --------------------------- | --------------------------------- |
| First process gets CPU | Shortest job gets CPU       | Fixed time slice for each process |
| Non-preemptive         | Non-preemptive              | Preemptive                        |
| Simple                 | Better average waiting time | Fair to all processes             |
| Convoy effect          | Starvation possible         | Context switching overhead        |

---

# Questions

### What is CPU Scheduling?

CPU scheduling is the process of selecting a process from the ready queue and allocating the CPU to it.

---

### What is FCFS?

FCFS (First Come First Serve) schedules processes in the order they arrive.

---

### What is SJF?

SJF (Shortest Job First) executes the process with the smallest burst time first.

---

### What is Round Robin?

Round Robin gives each process a fixed time quantum. If it is not completed within that time, it is moved to the end of the ready queue.

---

### What is Time Quantum?

Time Quantum is the fixed amount of CPU time assigned to a process in Round Robin scheduling.

---

### Which algorithm gives the minimum average waiting time?

**Shortest Job First (SJF)**.

---

### Which algorithm is best for time-sharing systems?

**Round Robin (RR)**.

---

### Which algorithm can suffer from the Convoy Effect?

**FCFS**.

---

### What is Turnaround Time?

```text
Turnaround Time = Completion Time − Arrival Time
```

---

### What is Waiting Time?

```text
Waiting Time = Turnaround Time − Burst Time
```

---

### Which scheduling algorithm is preemptive among these three?

**Round Robin**.

