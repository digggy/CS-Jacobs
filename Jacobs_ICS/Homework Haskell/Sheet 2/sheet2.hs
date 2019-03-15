{-| Problem 2.3 a) The first function rotates -}

rotate :: Int -> [a] ->[a]
rotate _ [] = []
rotate 0 xs = xs
rotate n xs = rotate (n-1) (drop 1 xs ++[head xs] )   

{-| Problem 2.3 b)   -}
circle :: [a] -> [[a]]
circle[]=[]
circle xs = circulate (length xs) xs

circulate :: Int -> [a] -> [[a]]
circulate n string
 | (n == 1 ) = [string]
 | otherwise = [string] ++ (circulate (n-1) (rotate 1 string))
