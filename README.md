# C DSA Assignment

## Q1. Stack using Array
Implemented:
- PUSH(x)
- POP()
- PEEK()
- DISPLAY()
- Stack Overflow and Stack Underflow handling

### Complexity
- PUSH: O(1)
- POP: O(1)
- PEEK: O(1)
- DISPLAY: O(n)
- Space: O(n)

## Q2. Circular Queue using Array
Implemented:
- ENQUEUE(x)
- DEQUEUE()
- FRONT()
- DISPLAY()
- Full and empty queue detection

### Complexity
- ENQUEUE: O(1)
- DEQUEUE: O(1)
- FRONT: O(1)
- DISPLAY: O(n)
- Space: O(n)

### Circular Queue vs Linear Queue
A circular queue reuses positions freed at the beginning of the array.
In a linear queue, REAR can reach the last index even when unused
positions exist at the beginning, causing a false overflow condition.
