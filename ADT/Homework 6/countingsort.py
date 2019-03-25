def counting_sort(arr):
    maximum=max(arr)
    count = [0] * (maximum + 1)
    output = [None] * len(arr)
    for i in arr:
        count[i] = count[i] + 1
    for j in range(len(count) - 1):
        count[j + 1] = count[j + 1] + count[j]
    for i in arr:
        output[count[i] - 1] = i
        count[i] = count[i] - 1

    return output

arr = arr = [9, 1, 6, 7, 6, 2, 1]
print(counting_sort(arr))