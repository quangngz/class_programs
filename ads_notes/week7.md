# Tutorial
- Iterative: repeatedly applies some process towards generating a solution; uses a queue - FIFO; 
- Recursive: solves smaller subproblems towards generating a solution; uses a stack - LIFO. 
- Element ordering: 
    - Stable: Guarantees to sort equal elements in the same order they appear in the input. 
    - Unstable: May not do that. 
- Space requirements: 
    - in-place: transforms input without using any auxilliary data structures. 
    - not-in-place: transforms input with the help of auxiliary data structures. 
## quicksort
- Pick pivot. 
- Divide the remaining into 2 partitions. 
- Apply qsort to sub partitions. 

### Hoare's Partition Scheme: 
- 1st assign pivot, left pointer and right pointer. 
- If left pointer is less than pivot, move it up. 
- If right pointer is more than pivot, move it down. 
- When the left pointer crossed the right pointer, we finished the partition step. 

### Complexity: 
- n-elements partitions take O(n). 
- Partition qualities depends: 
    - Balanced elements: 1/2n remaining in each partition. => O(logn)
    - Non-balanced elements: n - 1 remaining in 1 partition. => O(n^2)

## Selection sort
- Is an in-place, iterative sorting algorithm. 
- Steps: 
    - Find smallest element from the unsorted array. 
    - Swap it into the 1st position of the array. 
    - Increment the sorted subarray size. 
    - Repeat steps 1-3 until the unsorted subarray has 1 elment left. 
- Finding 1st element: O(n)
- Swapping and incrementing until end: $\theta(n)$


## Insertion sort
- Swapping the 1st unsorted element into place. O(n)
- Inserting elements until array is sorted: $\theta(n)$
```
def insertion(array): 
    n_comp = 0
    for i in range(len(array) - 1): 
        if array[i] > array[i + 1]: # find 1st unsorted
            array[i], array[i + 1] = array[i + 1], array[i]
            j = i
            while j >= 0:
                # Keep swapping until j > previous j
                if (array[j] < array[j - 1]): 
                    array[j], array[j - 1] = array[j - 1], array[j]
                    j-=1
                    n_comp+=1
                else: 
                    n_comp+=1
                    break
        n_comp+=1
    return n_comp

array = [1, 3, 4, 3, 9, 6]
n_comp = insertion(array) 
print(array)
print("n_comp: ", n_comp)
```


5, 1, 8, 3, 4, 6, 8, 1