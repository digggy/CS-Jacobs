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


def ActivitySelect(arr):
    """The function to select the activities 

    Arguments:
        arr {Activity} -- [description]

    Returns:
        selected {Activity} -- The activities that are selected based on the latest starting
                        time
    """
    selected = []
    temp = arr.copy()
    latest = latest_activity(temp)
    del temp[temp.index(latest)]

    selected.append(latest)
    while temp:
        # Picks the activity with latest starting time
        latest = latest_activity(temp)
        # Deletes the current item from temp
        del temp[temp.index(latest)]
        # Add's the element if the end is less than the list's last element's start
        if latest.end <= selected[len(selected)-1].start:
            selected.append(latest)

    return selected


def latest_activity(arr):
    max = arr[0]
    for act in arr:
        if max.start < act.start:
            max = act
    latest = max
    return latest


if __name__ == "__main__":
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
