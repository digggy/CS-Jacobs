
#Recursive or the naive appoach of finding fibonacci number
def frecursive(number):
    if number==0:
        return 0
    if number==1:
        return 1
    return frecursive(number-1)+frecursive(number-2)
