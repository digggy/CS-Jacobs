class Node:
    # Defining a Node
    def __init__(self, key=None, value=None):
        """A Node Class

        Keyword Arguments:
            key {int} -- The unique key for a Node (default: {None})
            value {int} -- The data for the the Node (default: {None})
        """
        self.key = key
        self.value = value


class HashTable:
    """
    This is a class for HashTable that generates HashCode for different keys and 
    stored the values.

    Attributes:
        maxsize (int) : The max number of elements in the HashTable
        currentsize (int): The number of current elements in the Hash Table

    """

    def __init__(self):
        self.maxsize = 100
        self.currentsize = 0
        self.arr = [None]*self.maxsize

    # Hashing function
    def hashCode(self, key):
        """ This function generates a hashcode

        Arguments:
            key {integer} -- The key for generating the hashcode

        Returns:
            integer -- Returns the hashcode for the particular given key
        """
        # The hash function here is the python based hash-function
        # I felt no need to change the hash function as it is working fine

        return hash(key) % self.maxsize

    # Insert a Value with help of hashing

    def insertNode(self, key, value):
        """ This method Inserts a Value with help of hashing and checks for collision
        and if it collides follows a linear probing.

        Arguments:
            key {integer} -- This is the key for generating the hashcode
            value {integer} -- This is the value that is going to be inserted in the 
                            hashtable as a Node
        """

        if self.arr[self.hashCode(key)] is None:
            # If the cell is Empty
            self.arr[self.hashCode(key)] = Node(key, value)

        else:
            # Collision found
            status = False
            HashCode = self.hashCode(key)
            while self.arr[HashCode] is not None:
                # If the adjecent cell of the hash table is occupied
                HashCode = (HashCode + 1)
                # if the increment exceeds the max size of the hash table
                if HashCode >= self.maxsize and status == True:
                    raise Exception('\n ------ | OverFlow of Data |--------- ')
                elif (HashCode >= self.maxsize):
                    HashCode = HashCode % self.maxsize
                    status = True

            self.arr[HashCode] = Node(key, value)

        # Incrementing the current size of the elements in the hash table
        self.currentsize = self.currentsize+1

    # Get the value at the key

    def get(self, key):
        """ Retrive the value at the postion of the key.

        Arguments:
            key {integer} -- The key for the generating the hashCode to retrieve value

        Returns:
            {integer} -- The actual value that is stored at the hashcode of key 
        """
        HashCode = self.hashCode(key)
        if self.arr[HashCode] is None:
            return None
        else:
            while self.arr[HashCode].key != key:
                HashCode = HashCode+1
                if HashCode >= self.maxsize:
                    HashCode = HashCode % self.maxsize
                elif self.arr[HashCode] is None:
                    # If the array's position with Hash Codes is empty
                    # It ensures that the item with that Hash code is missing
                    return None
                elif HashCode == self.hashCode(key):
                    # If the Hash Codes takes one round searching for the key
                    return None

            return self.arr[HashCode].value

    # Method to find if the hash table is empty
    def isEmpty(self):
        """ Checks if the HashTable is empty

        Returns:
            bool -- Returns false if the hashTable is empty
        """
        return self.currentsize == 0


if __name__ == "__main__":

    mytable = HashTable()

    """ Inserting Values in the table with keys """

    mytable.insertNode(1, 1)
    mytable.insertNode(11, 2)
    mytable.insertNode(101, 3)
    mytable.insertNode(102, 4)
    mytable.insertNode(111, 5)
    mytable.insertNode(1001, 6)
    mytable.insertNode(1011, 7)

    """
        Getting a vlaue for a particular key
    """
    print("\nChecking for the values for keys in Hash Table:\n")
    print('The value for key 1 is : {}'.format(mytable.get(1)))
    print('The value for key 101 is : {}'.format(mytable.get(101)))
    print('The value for key 111 is : {}'.format(mytable.get(111)))
