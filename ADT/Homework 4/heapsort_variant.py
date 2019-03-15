
# Defining the left function
def left(i):
    return 2*i+1

# Defining the right function
def right(i):
    return 2*i+2

# Defining the parent node function
def parent(i):
        return (i-1)//2

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

#Push Up function
def pushup(arr,i):
    if arr[parent(i)]<arr[i]:
        arr[i],arr[parent(i)]=arr[parent(i)],arr[i]
        pushup(arr, parent(i))

# Push Down function
def push_down(arr,n,i):
        l=left(i)
        r=right(i)

        if l >=n :
                return i
        elif r>=n:
                arr[i], arr[l] = arr[l], arr[i]
                return l
        else: 
                if arr[l]>arr[r]:
                        arr[i],arr[l]=arr[l],arr[i]
                        largest=l
                else:
                        arr[i],arr[r]=arr[r],arr[i]
                        largest=r
                return push_down(arr,n,largest)
        
               
# Heapsort Algorithm
def heapsort_variant(arr):
    size=len(arr)
    # Build max heap
    build_max_heap(arr)
    for i in range(size-1, 0, -1):
        # Swapping the last element and the first
        arr[i], arr[0] = arr[0], arr[i]
        # Maintaining the heap
        leafpos = push_down(arr,i-1,0)
        pushup(arr, leafpos)

