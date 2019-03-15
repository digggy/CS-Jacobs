#Fibonacci Numbers using matrix multiplication 

class Matrix:
    def __init__(self,a,b,c,d):
        self.a=a
        self.b=b
        self.c=c
        self.d=d
    def multiply(self,matb):
        new=Matrix(0,0,0,0)
        new.a=self.a*matb.a +self.b*matb.c
        new.b=self.a*matb.b +self.b*matb.d
        new.c=self.c*matb.a +self.d*matb.c
        new.d=self.c*matb.b +self.d*matb.d 
        return new

def mul(n):
    if n==1:
        return Matrix(1,1,1,0)
    return Matrix(1,1,1,0).multiply(mul(n-1))

def fmatrix(n):
    if(n==0):
        return 0
    return mul(n).b

