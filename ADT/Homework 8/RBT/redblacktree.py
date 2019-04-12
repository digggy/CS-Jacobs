# Red Black Tree Implementation

# References
'''
    Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (n.d.). Introduction to algorithms.
'''
# This is the color class


class Color:
    Red = "Red"
    Black = "Black"


# This is the Node class
'''
    Node class has the properties of a Node in a 
    Red Black Tree.
'''


class Node():
    def __init__(self, ncolor=Color.Red, data=None):
        self.data = data
        self.parent = None
        self.right = None
        self.left = None
        self.color = ncolor

# This is a T class with a property of nil node


class T():
    nil = Node(Color.Black)


# This is the Implementation of Red Black Tree
'''
    The below class can construct a RBT and maintain the 
    RBT.Also it has the methods to add, delete ,search,
    getminimum,getmaximum,find the sucessor and the predecessor 
    Node.
'''


class RedBlackTree():

    def __init__(self):
        self.root = T.nil

    # Method to rotateLeft
    def rotateLeft(self, x):
        y = x.right
        x.right = y.left
        if (y.left != T.nil):
            y.left.parent = x
        y.parent = x.parent
        if(x.parent == T.nil):
            self.root = y
        elif(x == x.parent.left):
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    # Method to rotateRight
    def rotateRight(self, x):
        y = x.left
        x.left = y.right
        if (y.right != T.nil):
            y.right.parent = x
        y.parent = x.parent
        if(x.parent == T.nil):
            self.root = y
        elif(x == x.parent.left):
            x.parent.left = y
        else:
            x.parent.right = y
        y.right = x
        x.parent = y

    # Method to insert a new element in the Red Black Tree
    def insert(self, data):
        newNode = Node()
        newNode.data = data
        self.RB_Inserter(newNode)

    def RB_Inserter(self, z):
        y = T.nil
        x = self.root
        while x != T.nil:
            y = x
            if z.data < x.data:
                x = x.left
            else:
                x = x.right
        z.parent = y
        if(y == T.nil):
            self.root = z
        elif (z.data < y.data):
            y.left = z
        else:
            y.right = z
        z.left = T.nil
        z.right = T.nil
        z.color = Color.Red
        self.RB_Insert_Fixup(z)

    def RB_Insert_Fixup(self, z):
        while z.parent.color == Color.Red:
            if z.parent == z.parent.parent.left:
                y = z.parent.parent.right
                if y.color == Color.Red:
                    z.parent.color = Color.Black
                    y.color = Color.Black
                    z.parent.parent.color = Color.Red
                    z = z.parent.parent
                else:
                    if (z == z.parent.right):
                        z = z.parent
                        self.rotateLeft(z)

                    z.parent.color = Color.Black
                    z.parent.parent.color = Color.Red
                    self.rotateRight(z.parent.parent)
            else:
                # considering the condition z.parent = z.parent.parent.right
                y = z.parent.parent.left
                if (y.color == Color.Red):
                    z.parent.color = Color.Black
                    y.color = Color.Black
                    z.parent.parent.color = Color.Red
                    z = z.parent.parent
                else:
                    if (z == z.parent.left):
                        z = z.parent
                        self.rotateRight(z)

                    z.parent.color = Color.Black
                    z.parent.parent.color = Color.Red
                    self.rotateLeft(z.parent.parent)
        self.root.color = Color.Black

    # Method to delete a Node
    def delete(self, z):
        y = z
        yOriginalColor = y.color
        if(z.left == T.nil):
            x = z.right
            self.RB_Transplant(z, z.right)
        elif(z.right == T.nil):
            x = z.left
            self.RB_Transplant(z, z.left)
        else:
            y = self.getMinimum(z.right)
            x = y.right
            if (y.parent == z):
                x.parent = y
            else:
                self.RB_Transplant(y, y.right)
                y.right = z.right
                y.right.parent = y
            self.RB_Transplant(z, y)
            y.left = z.left
            y.left.parent = y
            y.color = z.color
        if yOriginalColor == Color.Black:
            self.RBDeleteFixup(x)

    def RBDeleteFixup(self, x):
        while x != self.root and x.color == Color.Black:
            if x == x.parent.left:
                w = x.parent.right
                if w.color == Color.Red:
                    w.color = Color.Black
                    x.parent.color = Color.Red
                    self.rotateLeft(x.parent)
                    w = x.parent.right
                if w.left.color == Color.Black and w.right.color == Color.Black:
                    w.color = Color.Red
                    x = x.parent
                else:
                    if w.right.color == Color.Black:
                        w.left.color = Color.Black
                        w.color = Color.Red
                        self.rotateRight(w)
                        w = x.parent.right
                    w.color = x.parent.color
                    x.parent.color = Color.Black
                    w.right.color = Color.Black
                    self.rotateLeft(x.parent)
                    x = self.root
            else:
                w = x.parent.left
                if w.color == Color.Red:
                    w.color = Color.Black
                    x.parent.color = Color.Red
                    self.rotateRight(x.parent)
                    w = x.parent.left
                if w.right.color == Color.Black and w.left.color == Color.Black:
                    w.color = Color.Red
                    x = x.parent
                else:
                    if w.left.color == Color.Black:
                        w.right.color = Color.Black
                        w.color = Color.Red
                        self.rotateLeft(w)
                        w = x.parent.left
                    w.color = x.parent.color
                    x.parent.color = Color.Black
                    w.left.color = Color.Black
                    self.rotateRight(x.parent)
                    x = self.root
            x.color = Color.Black

    # Method to Transplant
    def RB_Transplant(self, u, v):
        if u.parent == T.nil:
            self.root = v
        elif u == u.parent.left:
            u.parent.left = v
        else:
            u.parent.right = v
        v.parent = u.parent
    # Method to get the minimum

    def getMinimum(self, x):
        while x.left != T.nil:
            x = x.left
        return x

    # Method to get the maximum
    def getMaximum(self, x):
        while x.right != T.nil:
            x = x.right
        return x

    # Method to get the sucessor Node
    def successor(self, x):
        if x.right != T.nil:
            return self.getMinimum(x.right)
        y = x.parent
        while y != T.nil and x == y.right:
            x = y
            y = y.parent
        return y

    # Method to get the predecessor Node
    def predecessor(self, x):
        if x.left != T.nil:
            return self.getMaximum(x.left)
        y = x.parent
        while y != T.nil and x == y.left:
            x = y
            y = y.parent
        return y

    # Method to search a particular Node with data
    def search(self, info):
        current = self.root
        while current != T.nil:
            if info == current.data:
                return current
            elif info > current.data:
                current = current.right
            else:
                current = current.left
        return T.nil

    # Method to print inoder tree traversal
    def printTree(self):
        current = self.root
        self.inoder(current)
        print("\n")

    def inoder(self, current):
        if(current == T.nil):
            return
        self.inoder(current.left)
        print(current.data, end=" ")
        self.inoder(current.right)


# Main function
if __name__ == "__main__":
    rbt = RedBlackTree()
    # Insertion same as the  Problem 8.1
    rbt.insert(13)
    rbt.insert(44)
    rbt.insert(37)
    rbt.insert(7)
    rbt.insert(22)
    rbt.insert(16)

    # Printing the inorder tree traversal
    print("Initially after insertion : \n")
    rbt.printTree()

    # Searching for an element
    inval = input("Input a value to search : ")
    value = int(inval)
    if(T.nil == rbt.search(value)):
        print("No Such Element found")
    else:
        print("Element ", rbt.search(value).data, " is found in the RBT")

    # Delete an element in a Tree
    inval = input("\nInput a value to delete : ")
    value = int(inval)
    rbt.delete(rbt.search(value))

    # Printing the tree after deletion
    print("\nAfter deletion :")
    rbt.printTree()
