def lomuto_partition(array, low, high):
    pivot = array[low]
    i = low 
    for j in range(low+1, high+1):
        if array[j] <= pivot:
            i += 1
            array[j],array[i] = array[i],array[j] 
        # print(arr , "  j is :",j)
    #swapping the first element to be the pivot 
    array[i],array[low]=array[low],array[i]
    return i


def QuickSort (A , low , high ):
    if low < high :
        if (A[low]>A[low+1]):
            A[low],A[low+1]=A[low+1],A[low]

        p2 = lomuto_partition(A, low+1, high)
        p1 = lomuto_partition(A, low,(p2-1))

        QuickSort (A, low, p1-1)
        QuickSort (A, p1+1, p2-1)
        QuickSort (A, p2+1, high)


arr=[0,5,4,3,2,1,0,-1,-4,321,324,423,2341,134,23123,34312,3,123,2341,-3241,-4123,-324,-4132]
print (arr)
print("-----------------")
QuickSort(arr,0,len(arr)-1)
print("-----------------")
# QuickSort(arr,0,4)

print(arr)