# Complexity Analysis
### Big O Notation
Big O notation is used to describe the upper bound of a function's growth rate. It provides a way to express the worst-case scenario for an algorithm's performance.
- It is defined as follows:
$$  
O(f(n)) = \{g(n) : \exists c > 0, n_0 \in \mathbb{N} \text{ such that } g(n) \leq c f(n) \text{ for all } n \geq n_0\}
$$

### Omega Notation
Omega notation is used to describe the lower bound of a function's growth rate. It provides a way to express the best-case scenario for an algorithm's performance.
- It is defined as follows:
$$
\Omega(f(n)) = \{g(n) : \exists c > 0, n_0 \in \mathbb{N} \text{ such that } g(n) \geq c f(n) \text{ for all } n \geq n_0\}
$$

### $\theta$ Notation
The $\theta$ notation is used to describe the asymptotic tight bound of a function. It provides a way to express that a function grows at the same rate as another function, both in upper and lower bounds.
- It is defined as follows:
$$
\theta(f(n)) = \{g(n) : \exists c_1, c_2 > 0, n_0 \in \mathbb{N} \text{ such that } 0 \leq c_1 f(n) \leq g(n) \leq c_2 f(n) \text{ for all } n \geq n_0\}

$$

# Linked List
### Definition
A linked list is a **concrete** data structure consisting of nodes, where each node contains a value and a reference (or pointer) to the next node in the sequence. The first node is called the head, and the last node points to null.
```
[Value | Next Node] -> [Value | Next Node] -> ... -> [Value | NULL]
```

### Building a sorted linked list
- Simply travese the list until finding the location to insert. 

### Operations on linked lists
- **Insertion**: O(1) if inserting at the head, O(n) if inserting at the tail or in the middle.
- **Deletion**: O(1) if deleting the head, O(n) if deleting the tail or a specific node.
- **Search**: O(n) for searching a specific value in the list. It's O(n) even when it's sorted. 
- **Cache Locality**: Linked lists have poor cache locality compared to arrays, as elements are not stored contiguously in memory.
### Advantages of Linked Lists
- Linked lists can grow and shrink dynamically, allowing for efficient memory usage.
- They can easily insert and delete elements without shifting other elements, unlike arrays. 

### Linked lists type: 
- **Singly Linked List**: Each node points to the next node, and the last node points to null.
- **Doubly Linked List**: Each node points to both the next and previous nodes, allowing for bidirectional traversal.
- **Skip list**: A linked list with extra pointers to search O(logn). But it is hard to implement, as you need to put the pointers probabilistically.

# Abstract Data Types (ADTs)
### Definition
An Abstract Data Type (ADT) is a mathematical model for a certain class of data structures that have similar behavior. An ADT defines the data and the operations that can be performed on that data, without specifying how these operations are implemented.
### Examples of ADTs
- **Stack**: A collection of elements with Last In First Out (LIFO) access. Operations include push (insert), pop (remove), and peek (view the top element).
- **Queue**: A collection of elements with First In First Out (FIFO) access. Operations include enqueue (insert), dequeue (remove), and peek (view the front element).
- **Dictionary**: A collection of key-value pairs, allowing for fast retrieval of values based on keys. Operations include insert (add a key-value pair), delete (remove a key-value pair), and lookup (retrieve a value by its key).

# Dynamic Memory
## Memory size of C variables(usual)
| Type          | Size (bytes) |
|---------------|--------------|
| int           | 4            |
| short         | atleast 2    |
| long          | atleast 4    | 
// on 64-bit systems, long is 8 bytes
| long long     | atleast 8    |
| float         | 4            |        
| double        | 8            |
| char          | 1            |
| pointer       | 8            |
| struct        | 8            |

## C library functions for dynamic memory
- `malloc(size_t size)`: Allocates a block of memory of the specified size and returns a pointer to it. The memory is uninitialized.
- `calloc(size_t num, size_t size)`: Allocates memory for an array of `num` elements, each of size `size`, and initializes all bytes to zero.
- `realloc(void *ptr, size_t size)`: Resizes the memory block pointed to by `ptr` to the new size. If the new size is larger, the additional memory is uninitialized.
- `free(void *ptr)`: Deallocates the memory block pointed to by `ptr`, making it available for future allocations.
- for small programs, the OS will automatically free the memory when the program exits. But for larger programs, it is important to free the memory to avoid memory leaks.
- THIS IS VERY IMPORTANT FOR CUDA PROGRAMMING. For Cpp, you probbaly will get away. 
- You should always check if the pointer successfully allocated memory before using it. 

## Why we use dynamic memory? 
- Dynamic memory allows resizing, very crucial if we need to store a variable amount of data, like when reading a file or user input. 
- While stack memory is faster, stack dosn't work if a variable leave its scope. 
- Also, stack memry is limited, so it can't store large data structures. (otherwise stack overflow)


# Header Files and Makefiles
