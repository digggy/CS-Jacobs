import random
import time
import matplotlib.pyplot as plt

# Insertion Sort


def selectionSort(array):
    # go through all the array elements
    for i in range(len(array)):

        min_idx = i
        for j in range(i+1, len(array)):
            if array[min_idx] > array[j]:
                min_idx = j

        # swap the minimum element
        array[i], array[min_idx] = array[min_idx], array[i]

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

# Generate Best Case Array


def generateWorst(n):
    array = [None]*n
    for i in range(n):
        array[i] = n-i
    return array


# Testing the code
n = 8000

worstCase = []
bestCase = []
averageCase = []
index = []

for i in range(1, n, 120):
    start = time.time()
    selectionSort(generateWorst(i))
    end = time.time()
    worstCase.append((end-start))

    start = time.time()
    selectionSort(generateBest(i))
    end = time.time()
    bestCase.append((end-start))

    start = time.time()
    selectionSort(generateRandom(i))
    end = time.time()
    averageCase.append((end-start))

    index.append(i)

    print(i)

# print(*worstCase)
# print(*bestCase)
# print(*averageCase)

plt.plot(index, bestCase, label="Best Case")
plt.plot(index, averageCase, label="Avg Case")
plt.plot(index, worstCase, label="Worst Case")

plt.legend(bbox_to_anchor=(0., 1.02, 1., .102), loc=3,
           ncol=2, mode="expand", borderaxespad=0.)

plt.ylabel('Time ')
plt.show()
