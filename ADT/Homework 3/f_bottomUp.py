
#This is the bottom up approach of finding the nth fibonacci number
def fbottomUp (number):
    if number==0:
        return 0
    if number==1:
        return 1
    n1=0
    n2=1
    for _ in range(1,number):
        n2=n1+n2
        n1=n2-n1
    return n2
