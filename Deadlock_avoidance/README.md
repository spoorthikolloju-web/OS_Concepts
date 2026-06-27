
# Banker's Algorithm

## Definition

**Banker's Algorithm** is a **deadlock avoidance algorithm** proposed by **Edsger Dijkstra**.

It checks whether granting a resource request will keep the system in a **safe state**. If yes, the request is granted; otherwise, it is denied to avoid deadlock.

---

## Why is it called Banker's Algorithm?

Like a banker giving loans, the operating system grants resources only if it can still satisfy all processes safely.

---

## Important Terms

### Available

Resources currently available in the system.

### Maximum

Maximum resources a process may need.

### Allocation

Resources currently allocated to a process.

### Need

```text
Need = Maximum − Allocation
```

---

## Safe State

A system is in a **safe state** if all processes can finish execution without causing deadlock.

---

## Unsafe State

A system is **unsafe** if granting a request may lead to deadlock.

---

## Steps of Banker's Algorithm

### Step 1

Calculate the Need Matrix.

```text
Need = Maximum − Allocation
```

### Step 2

Check whether:

```text
Need ≤ Available
```

### Step 3

If true,

* Allocate resources.
* Update Available.
* Process finishes.
* Release allocated resources.

### Step 4

Repeat until every process finishes.

If no process can proceed,

```text
System is NOT Safe.
```

---

## Program Flow

```text
Input
   ↓
Calculate Need Matrix
   ↓
Safety Check
   ↓
Safe?
 ↓      ↓
Yes     No
 ↓       ↓
Print    Request Denied
Safe Sequence
```

---

## Sample Output

```text
System is Safe

Safe Sequence:
P1 P3 P4 P0 P2

Enter Process ID:
1

Enter Request Vector:
1 0 2

Request Granted
```

---

## Functions Used

No special library functions.

Only:

* Arrays
* Loops
* Conditions

---

## Questions

### What is Deadlock?

A situation where two or more processes wait forever for resources held by each other.

---

### What is Banker's Algorithm?

It is a deadlock avoidance algorithm that grants resources only if the system remains safe.

---

### What is Need Matrix?

```text
Need = Maximum − Allocation
```

---

### What is a Safe Sequence?

An order in which all processes can complete successfully.

Example:

```text
P1 → P3 → P4 → P0 → P2
```

---

### Why is Banker's Algorithm used?

To avoid deadlock by checking system safety before allocating resources.

---
