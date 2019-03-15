
def partition(arr,low,high):

    arr[low+1], arr[high]= arr[high],arr[low+1]
    if arr[low] > arr[high]:
        arr[low], arr[high]=arr[high],arr[low]
    
    pivot1 = arr[low]
    pivot2 = arr[high]
    p1 = low + 1
    p2 = high - 1
    index = low + 1
    
    while index <= p2 :
        if arr[index] < pivot1:
            arr[index], arr[p1]=arr[p1],arr[index]
            p1+=1
        elif arr[index] >= pivot2: 
            while arr[p2] > pivot2 and index < p2 :
                p2-=1
            arr[index], arr[p2]= arr[p2],arr[index]
            p2-=1

            if arr[index] < pivot1:
                arr[index], arr[p1]=arr[p1],arr[index]
                p1+=1
                
        index+=1
    

    p1-=1
    p2+=1

    #Swapping the end pivots within the array
    arr[low], arr[p1]=arr[p1],arr[low]
    arr[high], arr[p2]= arr[p2],arr[high]

    return p1,p2


def quicksort(arr, low,high):
    if low < high:
        pvt_1, pvt_2 = partition(arr, low, high)
        quicksort(arr, low, pvt_1-1)
        quicksort(arr, pvt_1+1, pvt_2-1)
        quicksort(arr, pvt_2+1, high)
    

arr=[134,23123,34312,3,123,-4132,1,5,4,-2,9,-300,300,-4123,-324,0,5,4,3,2,1,0,-1,-4,321,324,423,2341]

# print (arr)
quicksort(arr,0,len(arr)-1)
print(arr)