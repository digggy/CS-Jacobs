def lomuto_partition(array, low, high):
    pivot = array[high]
    i = low - 1
    for j in range(low, high):
        if array[j] < pivot:
            i += 1
            array[j],array[i] = array[i],array[j]
    array[i+1],array[high]=array[high],array[i+1]
    return i + 1

def MedianOfThree(arr, left, right):
    mid = (left + right)//2
    if arr[right] < arr[left]:
        arr[left], arr[right]=arr[right],arr[left]        
    if arr[mid] < arr[left]:
        arr[left], arr[mid]=arr[mid],arr[left]
    if arr[right] < arr[mid]:
        arr[right], arr[mid]=arr[mid],arr[right]   
    return lomuto_partition(arr,left,right)


def Median_QuickSort (A , low , high ):
    if low < high :
        mid = MedianOfThree(A, low, high)
        Median_QuickSort (A, low, mid-1)
        Median_QuickSort (A, mid+1, high)
