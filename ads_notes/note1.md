### Modular Programming: 
- Each module should be independent from each other, so that when a module's implementation changes won't change another related module. 
- When taken to the extreme, this closely resembles the principles of Object Oriented Design. 

### Abstract data type
- A collection of data types that describes what it does, but not how it's implemented. 
- Example: Stack, Queue: store sets of items. Dictionary: look up item by key. 

### Concrete data structure
- Implements a abstract data type
- Example: Tree, Linked list, Array. 

### Random Access Memory
- Each cell in RAM is 8 bits (1 byte). The computer can access anylocation of the RAM to read and write to it. 


### ASCII TO BITS COMPARISON
- When we are comparing, we move from byte to byte, and check for each byte until finding a mismatch. 


### GDB 
- Compilation step
```
```
- Commands to navigate around: 
    - `p <name variable>` for printing
    - `b <line num>` to set a break point where you want to stop and investigate manually. 
    - `d <line num>` to delete a previously set break point
    - `n` to go to the next command. 
    - `bt` to backtracks
    - `info locals`: give info of all locals variables