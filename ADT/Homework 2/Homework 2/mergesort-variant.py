import random
import time
import matplotlib.pyplot as plt

# Selection Sort


def selectionSort(array):
    # go through all the array elements
    for i in range(len(array)):

        min_idx = i
        for j in range(i+1, len(array)):
            if array[min_idx] > array[j]:
                min_idx = j

        # swap the minimum element
        array[i], array[min_idx] = array[min_idx], array[i]

# InsertionSort


def insertionSort(array, l, r):
    for i in range(l, r+1):
        key = array[i]
        j = i-1
        while j >= l and key < array[j]:
            array[j+1] = array[j]
            j -= 1
        array[j+1] = key
# MergeSort


def mergeSort(arr, l, r, k):
    # print("Working Array Length is : ", (r-l+1))
    if ((r-l+1) <= k):
        insertionSort(arr, l, r)
    else:
        m = (l+(r-1))//2
        mergeSort(arr, l, m, k)
        mergeSort(arr, m+1, r, k)
        return merge(arr, l, m, r)

# Merge


def merge(arr, l, m, r):

    # Size of the two splitted arrays
    sizel = m-l+1
    sizer = r-m

    # Temporary Arrays
    left = [None]*sizel
    right = [None]*sizer

    # Copying values to temporary arrays from arr
    for i in range(0, sizel):
        left[i] = arr[l + i]

    for j in range(0, sizer):
        right[j] = arr[m + 1 + j]

    # Indexes for the two arrays
    i = 0
    j = 0

    # Going throught the array and arranging
    for d in range(l, r+1, 1):
        if i < sizel and j < sizer:
            if left[i] <= right[j]:
                arr[d] = left[i]
                i += 1
            else:
                arr[d] = right[j]
                j += 1
        elif i == sizel:
            arr[d] = right[j]
            j += 1
        elif j == sizer:
            arr[d] = left[i]
            i += 1

# Generate Random Case Array


def generateRandom(n):
    array = [None]*n
    for i in range(n):
        array[i] = random.randint(0, 100)
    return array

# Generate Best Case Array


def generateBest(n):
    array = [None]*n
    for i in range(n):
        array[i] = i
    return array

# Generate Worst Case Array


def generateWorst(n):
    array = [None]*n
    for i in range(n):
        array[i] = n-i
    return array


# Testing the code
nend = 1000
nstart = 0
stepn = 4

# the value of k
maxk = 1000
mink = 1
stepk = 10

count = 0

for k in range(mink, maxk, stepk):

    worstCase = []
    bestCase = []
    averageCase = []
    index = []

    for i in range(nstart, nend, stepn):

        arr = generateWorst(i)
        start = time.time()
        mergeSort(arr, 0, i-1, k)
        end = time.time()
        worstCase.append((end-start))

        arr = generateBest(i)
        start = time.time()
        mergeSort(arr, 0, i-1, k)
        end = time.time()
        bestCase.append((end-start))

        arr = generateRandom(i)
        start = time.time()
        mergeSort(arr, 0, i-1, k)
        end = time.time()
        averageCase.append((end-start))

        index.append(i)

        # print(i)

    count += 1
    print(count)
    axes = plt.gca()

    axes.set_ylim([0, 0.05])

    plt.suptitle('K ='+str(k), fontsize=16)
    plt.plot(index, worstCase, label="Worst Case", linewidth=0.5)
    plt.plot(index, bestCase, label="Best Case", linewidth=0.5)
    plt.plot(index, averageCase, label="Avg Case", linewidth=0.5)

    plt.legend(loc='upper center', bbox_to_anchor=(0.5, -0.05),
               fancybox=True, shadow=True, ncol=5)

    plt.ylabel('Time ')
    plt.savefig('merge_variant'+str(count)+'.png', dpi=300)
    plt.clf()
