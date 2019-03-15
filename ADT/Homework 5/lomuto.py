def lomuto_partition(array, low, high):
    pivot = array[high]
    i = low - 1
    for j in range(low, high):
        if array[j] < pivot:
            i += 1
            array[j],array[i] = array[i],array[j]
    array[i+1],array[high]=array[high],array[i+1]
    return i + 1


def lomuto_QuickSort (A , low , high ):
    if low < high :
        mid = lomuto_partition(A, low, high)
        lomuto_QuickSort (A, low, mid-1)
        lomuto_QuickSort (A, mid+1, high)

