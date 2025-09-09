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