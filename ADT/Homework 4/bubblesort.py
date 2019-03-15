def bubbleSort(arr):
    size = len(arr)
    # Go through all the array elements
    for i in range(size):
        swapflag = False
        # The last i elements are in their sorted place.
        # So no need to go through the last i elements 
        for j in range(0, size-i-1):
            # Go through the array from 0 to size-i-1
            # If the element found is greater then swap 
            if arr[j] > arr[j+1] :
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapflag = True
            # This is a swap flag to check if there were any swaps in inner loop
        if swapflag == False: 
            break
