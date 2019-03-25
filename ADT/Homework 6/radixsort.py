def MSD_radix_string_sort(L, i):
    maxlen = 4
    # The base case
    if len(L) <= 1:
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
        buckets[bucket] = MSD_radix_string_sort(buckets[bucket], i + 1)

    # Joining all the sorted buckets together
    for bucket in buckets:
        for element in bucket:
            finall_bucket.append(element)
    output = finall_bucket
    return output


arr = [6, 7, 4, 3, 22, 23, 21, 444, 123, 1233, 1123, 1, 0, 12, 440, 11]
print(MSD_radix_string_sort(arr, 0))
