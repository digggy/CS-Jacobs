def word_sort(L, i):

    if len(L) <= 1:
        return L
    done_bucket = []
    buckets = [[] for x in range(27)]

    for s in L:
        if i >= len(s):
            done_bucket.append(s)
        else:
            buckets[ord(s[i]) - ord('a')].append(s)

    buckets = [word_sort(b, i + 1) for b in buckets]

    return done_bucket + [b for blist in buckets for b in blist]


arr = ["word", "category", "cat", "new", "news",
       "world", "bear", "at", "work", "time"]
print(word_sort(arr, 0))
