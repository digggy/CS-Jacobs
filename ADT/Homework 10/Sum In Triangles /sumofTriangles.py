from copy import deepcopy

# Function for finding maximum sum


def maxPathSum(tri, m):
    tri = deepcopy(tri)

    # Copying the list of array to a new copied list ntri
    ntri = list(map(list, tri))

    for i in range(m-1, -1, -1):
        # From the bottom of the list toward the top finding the max sum between the adjacent elements below
        # and finding the sum to the top
        for j in range(i+1):

            if (tri[i+1][j] > tri[i+1][j+1]):
                tri[i][j] += tri[i+1][j]
            else:
                tri[i][j] += tri[i+1][j+1]

    # path is the way of connection between nodes
    path = []
    var = 0
    idx = 0
    # Going from the top to the bottom of the array of list and finding it's relational element
    for i in tri:
        if tri[var][idx] > tri[var][idx+1]:
            path.append(ntri[var][idx])
            idx = idx

        else:
            path.append(ntri[var][idx+1])
            idx = idx+1

        var = var+1

    # return the top element which stores the maximum sum and the path generating the max sum
    return tri[0][0], path


if __name__ == "__main__":

    tri = []
    print("Input the number of Lines : ", end=" ")
    max_lines = int(input())

    # Making a triangle based on the input
    for _ in range(max_lines):
        # splitting the user input to a list
        line = list(map(int, input().split()))
        # fill the empty spaces in the list with 0
        if (len(line) != max_lines):
            for i in range(len(line), max_lines):
                line.append(0)
        # Add the line to the array of list
        tri.append(line)

    # Printinng the max sum and the path
    print(maxPathSum(tri, max_lines-1)[0])
    for elem in maxPathSum(tri, max_lines-1)[1]:
        print(elem, end=" ")
    print(end="\n")
