class Activity:
    def __init__(self, start, end):
        """ Activity Class

        Arguments:
            start {int} -- Starting time of the Activity
            end {int} -- Ending Time of the Activity
        """
        self.start = start
        self.end = end

    def print(self):
        """ Method to Print the Activity properties
        """
        print("(", self.start, ",", self.end, ")")


def ActivitySelect(list):
    """ This function refines the list and selecs the activities according to the latest starting time

    Arguments:
        list {Activity Object} -- The list of all the activities 

    Returns:
        newlist {Activity Object} -- The activities that are selected based on the latest starting
                        time
    """
    newList = []
    for i in range(0, len(list)-1):
        newList = inspect(newList, list[i])
    return newList


def inspect(newList, newel):
    """ This function refines the list of activities according the the latest starting time

    Arguments:
        newList {Activitiy} -- The Activity Array that is being refined according to the latest starting time
        newel {Activitiy} -- The item that is being compared within the the refined list of selected activities

    Returns:
        newList {Activity Object Array} -- The activities that are selected based on the latest starting time
    """
    i = 0
    for activity in newList:
        # Condition to check if the newelement's start is greater than current loop element's start in the list
        if newel.start > activity.start:
            # Condition to check if the newelement's start is greater than current loop element's end in the list
            if activity.end < newel.start:
                # If true then add the new element after the current loop element in the list
                return newList[0:i] + [newel] + newList[i:len(newList)]
            else:
                # If false then replace  the current loop element in the list with the new element
                return newList[0:i] + [newel] + newList[i+1:len(newList)]
        else:

            if newel.end < activity.start:
                # If newelement's end is less than current loop element's start in the list  carry on with the loop
                i = i+1
            else:
                # Collision case with start time being less than current loop element
                return newList
    # Reaches here only in the intial call or when the newelement's end time is less than all the element's in the newlist
    newList.append(newel)
    return newList


if __name__ == "__main__":
    """ Creating the activities
    """

    A = Activity(112, 115)
    B = Activity(222, 1226)
    C = Activity(64, 108)
    Z = Activity(68, 109)
    D = Activity(161, 202)
    Y = Activity(2226, 126526)
    E = Activity(2225, 126526)
    F = Activity(66, 69)
    X = Activity(110, 126526)
    arr = [Z, X, Y, A, B, C, D, E, F]

    print("\nThe selected activities are :\n")
    for act in ActivitySelect(arr):
        act.print()
