
# Function to rescale the values of the alphabets
'''
    This is done inorder to consume less array size
'''


def scaledown(i, string):
    return ord(string[i])-96


# Function to get the value of the letter in the word
'''
    If the index i is greater than the length it returns 0 the 
    minimum value among all the letters.
    This is done inoder to take into account various length of the words.
'''


def Alphabet_value(string, i):
    size = len(string)
    if size > i:
        return scaledown(i, string)
    else:
        return 0


# Function to sort the the given array of the words with respect to the index of letter
'''
    This function is primarly doing all the sorting within various positions
    for the letters within the words.
    It has a parameter current which is the index of the letter in the word

    Other than that it is similar as that of counting sort
'''


def current_pos_sort(words, current):
    array_size = len(words)
    counter = [0 for _ in range(0, 27)]

    for a in range(array_size):
        val = Alphabet_value(words[a], current)
        counter[val] = counter[val]+1

    for b in range(1, 27):
        counter[b] += counter[b-1]

    output = [' ' for _ in range(array_size)]

    for c in range(array_size-1, -1, -1):
        temp = Alphabet_value(words[c], current)
        output[counter[temp]-1] = words[c]
        counter[temp] = counter[temp]-1
    return output


# Function to sort the array of the words
'''
This function finds the max number of letters and iterates through 
all of their position calling current_pos_sort function 
the starting from the max number of letter to 0.

'''


def sort_words(arr):
    maximum = max([len(word) for word in arr])
    words = arr
    for current_bit in range(maximum-1, -1, -1):
        words = current_pos_sort(words, current_bit)

    return words


# Main
if __name__ == "__main__":
    words = ["word", "category", "cat", "new",
             "news", "world", "bear", "at", "work", "time"]
    sortedwords = sort_words(words)
print(sortedwords)
