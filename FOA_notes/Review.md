
# Review of other data structures and algorithms
## Linear data structure: 
- Arrays: elements are stored in contiguous memory
  - Insert at front, O(N)
  - Insert at end, O(1) 
  - Insert at random, O(N)
  - Delete at end: O(1)
  - Delete at random: O(N)
  - search: O(N) or logn if binary search
  - Use array for: Binary search, randomly accessing elements, quicksort, fast iteration 
- Linked list: 
  - elements are linked using pointers. 
  - search: O(N), so still is O(N) for insertion and deletion. 
  - Removing tail is O(N) for single linked list
  - Doubly linked list can delete tail at O(1)
  - useful in real-life scenarios such as handling requests to a web service, where requests need to be processed in the order they were received, and inserting or removing elements at the beginning or end of the list can be done efficiently. Also should use when adding lists together, or adding / removing from start to end. 
- Stacks: 
  - Last in, first out (LIFO) data structure.
  - Operations: push (insert), pop (remove), peek (get top element).
  - Time complexity: O(1) for all operations.
  - Use cases: Undo functionality in text editors, function call stack in programming languages, parsing expressions.
  - Implementation: 
    - Using array: 
      - Push: Add element to the end of the array. (Don't add it at the start, as that would be O(N) to shift all elements)
      - Pop: Remove element from the end of the array.
      - Pros: Fast access, easy to implement.
      - Cons: Fixed size, resizing can be expensive.
    - Using linked list:
      - Push: Add element to the head of the linked list.
      - Pop: Remove element from the head of the linked list.
      - Pros: Dynamic size, no resizing needed.
      - Cons: Pointer overhead, i.e. more memory used.
- Queues:
  - First in, first out (FIFO) data structure.
  - Operations: enqueue (insert), dequeue (remove), peek (get front element).
  - Time complexity: O(1) for all operations.
  - Use cases: Task scheduling, print queue, breadth-first search in graphs.
  - Implementation:
    - Using array:
      - Enqueue: Add element to the end of the array.
      - Dequeue: Remove element from the front of the array.
      - Pros: Fast access, easy to implement.
      - Cons: Removing the front is O(N). 
    - Using linked list:
      - Enqueue: Add element to the tail of the linked list.
      - Dequeue: Remove element from the head of the linked list.
      - Pros and Cons: Same as stack. 
## String searchings
### Linear search:
- Iteratively search through each character in each string in the list. 
- Time complexity: O(n * m), where n is the number of strings and m is the length of the string.
## Substring search: 
### Naive search: 
- Iteratively move through each index in the string, and check if every character from that index onwards matches the pattern. Break early if a mismatch is found. Complexity: O(n * m), where n is the length of the string and m is the length of the pattern.
```
for (int i = 0; i < n - m + 1; i++) {
  for (int j = 0; j < m; j++) {
    if (string[i + j] == pattern[j]) {
      // match found
    } else {
      break; // no match, break inner loop
    }
  }
}
```
### KMP search:
- Goal: Reduce uneccessary comparisons in string searching. 
- To do this, we want our algorithm to skips over characters that we know won't mathch. We do this though a prefix table (failure function). This table tells us how much we should fall back in the pattern when a mismatch occurs.
Example: 
```
string = "abababacababaca" 
pattern ="ababaca"
prefix table = [-1, 0, 0, 1, 2, 3, 0] // To construct this, we look at the pattern and see how many characters match with the prefix of the pattern.
// Note: The first element is -1, because we don't have any prefix for the first character. The last element we dont include in the prefix table. 
// Visualisation of the seach: 
- First, we let index i be the index of the string, and index j be the index of the pattern.
then, we check string[i] == pattern[j]. If they match, we increment both i and j. If they don't match, we look at the prefix table to see how much we should fall back in the pattern.
- In the case when the 1st mismatch occurs, "b" != "c", we change the value of j = prefix[j - 1], which is "b". Coninue to fall back if not match, until we find a match or j = 0.

```
### Indexing
- Indexing is a data structure that uses extra space to store a mapping from keys to values, hence allowing for faster lookups.
- Navigating through index can be done through a fast way, such as binary search. 
### Suffix arrays: 
- A suffix is a substring at the end of a string. Example: "abc" has suffixes "abc", "bc", "c".
- Suffix arrays are used to store all suffixes of a string in sorted order.
```
| Suffix   | Start Index | Sorted index (alphabetically)
| -------- | ----------- | ------------                  
| banana\$ | 0           | 4
| anana\$  | 1           | 3
| nana\$   | 2           | 6
| ana\$    | 3           | 2
| na\$     | 4           | 5
| a\$      | 5           | 1
| \$       | 6           | 0

// Then when stored inside a suffix array, it looks like this:
SA = [6, 5, 3, 1, 0, 4, 2]
// Then when you want to find a substring, you can use binary search on the suffix array to find the starting index of the substring.
example: "ana" target. First, look at the middle sorted index, which is 3 corresponding to "anana\$". Then you can see that "ana" is less than "anana", so you can discard the right half of the suffix array. Then you look at the next middle index, which is 1 corresponding to "a\$". Then you can see that "ana" is greater than "a\$", so you can discard the left half of the suffix array. Then you look at the next middle index, which is 2 corresponding to "ana\$". Then you can see that "ana" is equal to "ana\$", so you have found the starting index of the substring.
```
- This is efficient in for large amount of data, as it has sacrifice some precomputating time, to allow for faster subsequent lookups.
- Constructing a suffix takes O(n^2 log n + n) -> overall O(n^2 log n) time, where n is the length of the string.
- The sorting we do to achiveve this is ternary quick sort, which is like quicksort, but with an additional 
## Trees
- Trees are data structures that consists of nodes, and each node leading to other nodes, called children. 
### Binary search trees:
- A binary tree is a tree where each node has at most two children, called left and right. The left node is less than the parent node, and the right node is greater than the parent node.
- Balanced tree: The height of the tree is minimized to optimize insertion, search, deletion operations. It is when the difference between the height of the left and right subtrees is at most 1 for every node.
- Complete tree: Every level of the tree is fully filled, except possibly for the last level, which is filled from left to right.
- The average case to find a node is O(log n). But if every parent has only one child, the tree is unbalanced, and the time complexity to find a node is O(n).
- Height of the tree, is the number of times you have to go down from the root to the furthest leaf node.
### BST traversal: 
- Inorder traversal: Visit left subtree, then root, then right subtree. This gives a sorted order of the elements in the tree.
LEFT -> ROOT -> RIGHT
```
       A
      / \
     B   C
    / \   \
   D   E   F
Inorder traversal: D, B, E, A, C, F
```
- Preorder traversal: Visit root, then left subtree, then right subtree. This is useful for creating a copy of the tree. ROOT -> LEFT -> RIGHT
```
       A
      / \
     B   C
    / \   \
   D   E   F
Preorder traversal: A, B, D, E, C, F  
```
- Postorder traversal: Visit left subtree, then right subtree, then root. This is useful for deleting the tree, as it ensures that the children are deleted before the parent. LEFT -> RIGHT -> ROOT
```
       A
      / \
     B   C
    / \   \
   D   E   F
Postorder traversal: D, E, B, F, C, A
```
- Level order traversal: Visit all nodes at the current level before moving on to the next level. This is useful for printing the tree in a breadth-first manner.
### Finding an element in a binary search tree:
- Start at node, and compare if the current node is less than or larger than the target. If its less than target, go to the right, and vice versa. If reaching a leaf node, then the target isnt found. If find the node, return found. 
### Insertion in BST: 
- Important note: When we insert, it always become a leaf node. No arrangement is done. Also, we do not allow duplicates.
- Start at root, and compare, and traverse, until finding a position for it. 
### Deletion in BST:
- If the node to be deleted is a leaf node, simply remove it. Set the parent node's pointer to null.
- If the node has one child, simply remove that node, and set its parent pointer to its (the deletion) child node. This guarantees the tree remains a BST. 
- If the node has 2 children, we find the next biggest, so its located in the very far left (has no more left child) of the right subtree. Then we replace the deletion node is this node. If this replacement node has children, we recursivelt delete its most furthest left child on its right subtree again. This is repeated until we reach a leaf node, which is then deleted.
- In the lecture, we can also swapped the deletion node with the successor node, until it falls into one of the two firtst cases.
## Priority queues
- A priority queue is a data structure that allows for efficient retrieval of the highest (or lowest) priority element.
- Operations: 
  - Insert: O(log n)
  - Remove: O(log n)
  - Peek: O(1)
- Implementation:
  - Binary heap: A complete binary tree where each node is greater than or equal to its children (max heap) or less than or equal to its children (min heap).
  - The root node is the highest (or lowest) priority element.
  - Inserting takes O(log n) average, and O(n) worst case. 
  - Find any takes O(log n) average, and O(n) worst. 
  - Creating takes O(n log n) average, and O(n^2) worst case (inserting worst case everytime).
  - Removing takes O(log n) average, and O(n) worst case.

Sifting down operation:
- Given a tree that's not a heap, we can fix it by swapping the root with the largest child, and then recursively sifting down the child until the tree is a heap. It is applied to all non leaf nodes.
- The complexity of sifting down is O(log n) average and worst case, as we traverse down the height of the tree.
```
void
sift_down(data_t A[], int parent, int n) {
    int child;
    // 2*parent + 1 gives the index of the left child. 
    if ((child = 2*parent+1) < n) {
        /* there is at least one child to be checked */
        if (child+1<n && cmp(A+child, A+child+1)<0) {
            /* the right child exists, and is larger */
            child += 1;
        }
        if (cmp(A+parent, A+child)<0) {
            /* parent is smaller than larger child */
            swap_data(A+parent, A+child);
            sift_down(A, child, n);
        }
    }
}
```
### Heap sort: 
- A sorting algorithm that uses binary heaps to sort an array. 
- By popping the root node until the heap is empty, we can get the elements in sorted order.
- Time complexity: O(n log n) average and worst case. Because we are sifting down n elements. 

## Merge sort: 
- A sorting algorithm that uses the divide and conquer approach to sort an array.
- Divide the array into two halves, sort each half recursively, and then merge the two sorted halves.
```
Pseudocode:
def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    merge(left, right)

// Merging takes O(n) time, where n is the sum of both left and right number of elements. 
def merge(left, right): 
    result = left; 
    i = 0; j = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
```
- The time complexity can be evaluated as T(n) <= 2T(n/2) + O(n), which is O(n log n) using the master theorem.
The advantage of merge sort is that it guarantess O(n log n) time complexity in all cases, and it is stable (does not change the order of equal elements).
- Note that the space complexity is high, and if there's not enough space on the RAM, it may need to use disk space (by swapping some of the data onto disk), which makes it slower. 
## Insertion sort
- At every index i in array of size n, swap it with the number smaller number in front of it. 
```

void insertion_sort(int array[], int n) {
  for (int i = 1; i < n; i++) {
    int j = i; 
    while (j > 0) {
      if (array[j] < array[j - 1]) {
        swap(array + j, array + j - 1); 
        j--; 
      }
      else break; 
    }
  }
}
```
## Selection sort
- At every index i in an array of size n, find the minimum number on its right. Swap i with that minimum number's index. 
```
void selection_sort(int array[], int n) {
  for (int i = 0; i < n - 1; i ++) {
    for (int j = i + 1; j < n; j++) {
      if (array[j] < array[i]) {
        swap(array + j, array + i); 
      }
    }
  }
}
```
## Quick sort (2 way)
1. Choose a pivot, define i pointing to the start of the list and end pointing to the end of the list. 
2. We increment i until we find an element that's greater than the pivot <b>STOP</b>, and continue to decrement j until we find the element that's smaller than pivot. We swap them. 
3. Continue until j is smaller than i. Then swap the pivot position with j. Now the pivot is guaranteed to be in its correct position.  
4. Continue the process on each half, [start, pivot), and (pivot, end - 1]. Continue until 
## Bubble sort
- At every index, swap it with the adjacent index if in the incorrect order. This way, the highest number naturally "bubbles" up to the end of the list. 
```
void bubble_sort(int array[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
        if (array[j] > array[j + 1]) {
            swap(&array[j], &array[j + 1]);
        }
    }
  }
}
```
## Hash Tables: 
- This is a data structure that allows fast access to data by using a has function to map keys to values.
$$hash(key) = index$$
- Chance of a collision is randomly distributed. So H(key) = index should be uniformly distributed.
- Ways to handle collisions:
  - Chaining: Store a linked list of values at each index in the hash table. This allows for multiple values to be stored at the same index.
  - Linear probing: If a collision occurs, we look for the next available index in the hash table. This can lead to clustering, where multiple collisions occur in a row.
  - Perfect hashing: Use a second (or more) hash function to map keys to values. 
- Also, we can use a load factor to determine when to resize the hash table. The load factor is the number of elements in the hash table divided by the size of the hash table. When the load factor exceeds a certain threshold (e.g. 0.7), we can resize the hash table to a larger size and rehash all the elements.
Time complexity: 
- Expected cost for a successful look up is $$ O(1 + (1 - \alpha)^{-1})$$
- Expected cost for an insertion is $$ O(1 + (1 - \alpha)^{2})$$
- think of it as O(1), but as you add more, it costs more. 

# Integer representation
### Fixed decimal representation
- Decimal numbers are represented using a fixed number of digits before and after the decimal point.
- It's useful when you know your range of values, and precision is reuqired. 
### Floating point representation
- Floating point representation allows for a wider range of values by using a mantissa and an exponent, while also maintaining some accuracy level.

Mechanics: $sM\times 2^e$
- sign: s, use 1 bit to represent. 
- mantissa:M, use a fixed number of bits to represent the significant figures. 
- exponent: e. In the case of 8 bits, there's 2^8 = 256 possible values, so we can use 8 bits to represent the exponent. But we need to account for negative exponents, so the exponent can range from -126 to +127.

Standards of floating point representation: 
- IEEE 754: The most widely used standard for floating point representation.
  - Single precision (32 bits): 1 bit for sign, 8 bits for exponent, 23 bits for mantissa.
  - Double precision (64 bits): 1 bit for sign, 11 bits for exponent, 52 bits for mantissa.

Application: Music production, scientific calculations, graphics, machine learning. It is now the standard way to represent real numbers. 
- And the exponent is actually not the full bits, since they also use some bits of the exponent to represent edge cases such as zero, infinity, and NaN (not a number).
- Significant representation: 
Example: $0.375 = 0 \times 2^{-1} + 1 \times 2^{-2} + 1 \times 2^{-3}$, so the mantissa is 0.011, and the exponent is -2.

- negative numbers representation: 
  - One's complement: The most significant bit (MSB) is used to represent the sign of the number. If it is negative, swap all bits of the positive representation into the opposite. 
  - Two's complement: The most significant bit (MSB) is used to represent the sign of the number. The largest positive number is always 1 bigger than the smallest negative number. 

### Steps to convert numbers into their binary operations: 
1. Check the sign and determine the sign bit
2. Convert the number into binary representation
    - example: 13.625 => 13 = 1101; $0.625 =0.5 + 0.125 = 2^{-1} + 2^{-3} = 0.101$ $$ 13.625 = 1101.101_2$$
    - then we convert that into scientific notation (in the example below, we left shift three bits): 
    $$ 1101.101_2 = 1.101101 \times 2^{3}$$
3. The exponent is 3 + bias. Bias = 127 in 32bit, and 1023 in 64bit
    - if bias = 127, stored exponent = $127 + 3 = 130 = 10000010_2$
4. and the mantissa (only counts the decimals).  
### Fast fourier transform (FFT)
- FFT is an algorithm to compute the discrete Fourier transform (DFT) and its inverse efficiently. Uses to break down waveforms into their constituent 
frequencies.

### Bit operations: 
- Shifting: 
  - Left shift: `x << n` shifts the bits of x to the left by n positions, effectively multiplying x by 2^n.
  - Right shift: `x >> n` shifts the bits of x to the right by n positions, effectively dividing x by 2^n.
- Bitwise AND: `x & y` performs a bitwise AND operation between x and y, resulting in a number where each bit is set to 1 if both corresponding bits in x and y are 1.
- Bitwise OR: `x | y` performs a bitwise OR operation between x and y, resulting in a number where each bit is set to 1 if at least one of the corresponding bits in x or y is 1.
- XOR: `x ^ y` performs a bitwise XOR operation between x and y, resulting in a number where each bit is set to 1 if the corresponding bits in x and y are different.
- NOT: `~x` performs a bitwise NOT operation on x, flipping all bits in x.
### Tricks with bit operations: 



## Degrees of separation: 
- The concept of degrees of separation refers to the number of steps it takes to connect two people in a social network.
- An interesting question is to figure out how many degrees of separation there are between two people in a social network, such as Facebook or LinkedIn.
- We can use a graph to represent the social network, where each person is a node and each connection between two people is an edge.
- The degrees of separation can be found by performing a breadth-first search (BFS) or depth-first search (DFS) on the graph, starting from one person and traversing through their connections until reaching the other person.
###  BFS
- The idea: Put all of the nodes in a queue, and then process each node by adding its neighbors to the queue. This way, we can explore all nodes at the current level before moving on to the next level.

### DFS
- The idea: Use a stack to keep track of the nodes to be processed. Start at the root node, and then recursively visit each child node until reaching a leaf node. Then backtrack to the previous node and continue processing the next child node.

### Graph implementation in C: 
```
typedef struct Node {
    int data;
    list_t *edges; // linked list of edges to other nodes
} Node_t;

Node_t *nodes = (Node_t *)malloc(sizeof(Node_t) * num_nodes);
```

# Takeaways: 
- Problems can be categorised into different types, such as searching, sorting, ... 
- Design techniques, such as divide and conquer, dynamic programming, greedy algorithms, can be used to solve these problems.
  - Generate and test: Generate all possible solutions, and test to see if its a valid solution. This is good if the problem is good. But it is not very efficient. 
  - You can use generate and test for Subset sum, otherwise known as backpack / knapsack problem. You have a backpack that can hold a certain weight, and you want to fill it with items that have a certain weight and value. The goal is to maximize the value of the items in the backpack without exceeding the weight limit.
  - Another is to determine what's a vlid solution, such as in the case of Sudoku. Fun fact, SUDOKU cannot contains less than 17 clues for it to be solvable. The algorithm to solve Sudoku is to use backtracking, which is a form of generate and test.
### Constraints: 
- A Constraint sastifaction problem (CSP) is a problem where we have a set of variables, each with a domain of possible values, and we want to find a solution that satisfies a set of constraints, like Sudoku.

### Programming paradigms:
- Divide and conquer. 
- Simulation and randomization.
  - Most random generators, take some sort of initial values (like the current time) to generate a random number.
  - There's some caveat, like if you were to terminate the program immaturely, then the results can be incorrect. But also the determination of a termination point is arbitrary. 
  - Hence, there's another type of radnomized algorithms, called Las Vegas, which guarantees a stopping point and a correct solution. 
- Numerical analysis: A field of study that develops mathematical algoirhthms to solve hard problems
- Optmization: Given a input X, find the best function f(X) that gets me closest to the desired output. THings like supervised learning, unsupervised learning, reinforcement learning, are all optimization problems.

### Complexity theory: 
- SAT problem: The problem of determining whether a given boolean formula can be satisfied by some assignment of truth values to its variables.
- the study of how to classify problems based on their resource usage and model of computation.
- There's a distinction between asking: if a problem can be solved, and what is that solution. 
- Sastifiability: GIven constraints, can we find a solution that sastifies all constraints? 
- Checking a sudoku is in NP, as we can check if a solution is valid in polynomial time O(n^k).
- Exaple of NP: 
  - Two color map: Given a map, can we color it with two colors such that no two adjacent regions have the same color?
  - we can prove that we can validate a solution in polynomial time. If we imagine a map where we have colored everything, but there's one redion that's not colored, then if that region is adjavent to regions of every color, then a soltuion is not possible. A constraint can be written as: 
  $ s_{0,0} \land s_{0,1} \land s_{0,2}$, where it's sayong that node 0 has to be one of the colors. 
- 