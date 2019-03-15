def hoare_partation(array, low, high):
    pivot = array[low]
    i=low-1
    j=high+1
    while 1:
        i = i + 1
        while array[i] < pivot:
            i = i + 1
        j=j-1
        while array[j] > pivot:
            j=j-1
        
        if i >= j:
            return j
        array[i],array[j]=array[j],array[i]

def Hoare_QuickSort (A , p , r ):
    if p < r :
        q = hoare_partation(A , p , r )
        Hoare_QuickSort (A , p , q )
        Hoare_QuickSort (A , q + 1 , r )
