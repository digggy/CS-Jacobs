def radixsort_MSD(L, i, size):
    maxlen = size
    # The base case
    if len(L) <= 1:
        return L

    if i >= maxlen:
        return L

    # The final list
    finall_bucket = []

    # 10 buckets for different digits
    buckets = [[] for x in range(10)]  # one for each letter in 0-9

    for s in L:
        d = (int)(s//10**(maxlen-1-i)) % 10
        buckets[d].append(s)

    # Recursively sort buckets
    for bucket in range(0, len(buckets)):
        buckets[bucket] = radixsort_MSD(buckets[bucket], i + 1, size)

    # Joining all the sorted buckets together
    for bucket in buckets:
        for element in bucket:
            finall_bucket.append(element)
    output = finall_bucket
    return output


arr = [6, 7, 4, 3, 22, 22, 23, 21, 444, 123,
       1233, 1233, 1123, 1, 0, 12, 440, 11]
# arr = [1, 2, 2, 3, 44, 44, 55]
size = max(len(str(b)) for b in arr)
print(radixsort_MSD(arr, 0, size))
