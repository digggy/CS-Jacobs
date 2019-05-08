def LOS(arr):
    """The function is to find the maximum ordered subarray in a array

    Arguments:
        arr {int} -- It is a list of numbers

    Returns:
        arr {int} -- Returns the the maximum ordered subarray and Length 
    """

    n = len(arr)
    # Declare the list (array) for LIS and initialize LIS
    # values for all indexes
    Los = []
    helper = []

    for i in range(0, n):
        helper.append(i)
        Los.append(1)

    # In bottom up manner generating the LOS(Longest Ordered Subarray)
    for i in range(1, n):
        for j in range(0, i):
            if arr[i] > arr[j] and Los[i] < Los[j] + 1:
                Los[i] = Los[j]+1
                helper[i] = j

    # maximum is the length of the LOS
    maximum = max(Los)

    # Gives the index of the last item of the in the LOS
    idx = Los.index(maximum)

    ordersequence = []
    for _ in range(0, maximum):
        # Pushing the elements to a list orderedsequence
        ordersequence.append(arr[idx])
        idx = helper[idx]

    ordersequence.reverse()
    # Returning the reverse of the ordered sequence
    return (max(Los), ordersequence)
# end of lis function


# Program to test above function
# arr = [8, 3, 6, 50, 10, 8, 100, 30, 60, 40, 80]
if __name__ == "__main__":

    arr = list(map(int, input().split()))
    ans = LOS(arr)
    for x in ans[1]:
        print(x, end=" ")
    print("\n")
