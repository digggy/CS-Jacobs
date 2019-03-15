
# Defining the left function
def left(i):
    return 2*i+1
# Defining the right function
def right(i):
    return 2*i+2

# Max_Heapify 
def max_heapify(arr,n,i):
    l=left(i)
    r=right(i)
    largest=i
    if n>l and arr[largest]<arr[l] :
        largest=l
    if n>r and arr[largest]<arr[r]:
        largest=r
    if largest!=i :
        arr[largest],arr[i]=arr[i],arr[largest]
        #Hepify the root again
        max_heapify(arr,n,largest)

# build_max_heap function
def build_max_heap(arr):
    for i in range(len(arr)//2,-1,-1):
        max_heapify(arr,len(arr),i)

#Heapsort Algorithm
def heapsort(arr):
    size=len(arr)
    #Build max heap
    build_max_heap(arr)

    for i in range(size-1, 0, -1):
        #Swapping the last element and the first
        arr[i], arr[0] = arr[0], arr[i]
        max_heapify(arr, i, 0) 

