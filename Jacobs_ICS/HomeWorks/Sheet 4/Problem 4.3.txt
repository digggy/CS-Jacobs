{-Problem 4.3-}

suffixes ::[a]->[[a]]
suffixes[]=[]
suffixes (x:xs) = [xs] ++ suffixes xs

{-Explanation suffixes :
 The suffixes is a recursive function where x is the first term in the list [a];
 So every time when the function is called, the element of the list is narrowed down elemenating the first element of the list xs.So the new list is formed by concatination of returns of recursive function.
-}


prefixes ::[a]->[[a]]
prefixes xs = find xs 0

find xs index
    |index == (length xs ) = [] 
    |otherwise = [take index xs] ++ find xs (index+1)

{-Explanation prefixes :
  The find is a recursive function which is called when prefix is run. So every time the find function is called, recursively the index increases thus a the take function takes a extra element of the list until the index is equall to the length of the list (ie : xs )  
-}