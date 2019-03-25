def insertion_sort(arr):
    for i in range(1, len(arr)):
        temp = arr[i]
        j = i - 1
        while (j >= 0 and temp < arr[j]):
            arr[j + 1] = arr[j]
            j = j - 1
        arr[j + 1] = temp


def bucket_sort(arr):
    maximum = 1.0
    length = len(arr)
    size = maximum/length

    buckets = [[] for _ in range(length)]
    for i in range(length):
        j = int(arr[i]/size)
        if j != length:
            buckets[j].append(arr[i])
            # print(j," -> ",buckets[j])
        # else:
        #     buckets[length - 1].append(arr[i])

    for i in range(length):
        insertion_sort(buckets[i])

    result = []
    for i in range(length):
        result = result + buckets[i]
    return result


arr = [0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1, 0.01, 0.65]
sorted_list = bucket_sort(arr)
print('Sorted list: ')
print(sorted_list)
