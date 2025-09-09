## Hashing: Analysis


## Sorting 
2 types of sort we have come across - Non-comparison sorting, e.g. Map items to known positions

Comparison sorting, e.g. comparing all possible pairs (O(n^2)), but this is not the most efficient method. 

### Selection sort
Select the smallest element from the unsorted partition, and then move it to the last idx of the sorted partition - this starts at 0.

### Insertion sort
Start from the 1st index, and then look at the remaining elements on the right. If there's an element that's smaller than the current one, swap them. The current one is then updated to the smaller one. 

Worst case: O(n^2)

But we use it becasue for small n, it outperforms (generally) O(nlogn) operations. 

This is alsi a stable sort
### Divide and Conquer
It is a common strategy in efficient algorithms. 

It divide instances of problem into smaller instances. 

Solve smaller instances, - usually recursively. 

Example: Split - Solve - Join. 

Merge sort use a trivial method to split, sort, while joining groups. 

Quick sort: Sort while splitting, and use a trivial method to join groups. 

They are usually O(nlogn) - quite efficient!

## Quicksort
It's O(nlogn), but in  the worst case, it is O(n^2). 


Why we use it? - It's on average still faster than merge sort. It works better in practice. 

However, you still want to get away from that worst case... If your business can tolerate it, then so be it. 

Partition the array:
- Choose a pivot. - this is make or break for qsort. Simplest choice is the 1st item in the array.  
- Step through the arry, items < pivot go to start, items > pivot goes to end. 
- then choose a pivot within those set
- Continue partitioning, until sorted. 

Worst case: If the array is sorted and the pivot we choose is the 1st element. 

Last element: Same as 1st. 

Middle: Works well for nearly sorted array. 

Randomly: Avoids worst case on average. O(nlogn)- Note the cost of computation to generate a random number. 

Median of three: Median of 1st, last, and middle elements, avoids worst case scenario, and most commonly used. The C version uses this. 