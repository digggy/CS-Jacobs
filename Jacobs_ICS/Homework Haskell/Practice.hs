{-Problem 4.3-}

bin ::Int->[Int]
bin 0 = [0]
bin 1 = [1]
bin x =  bin b ++ [a] 
 where 
  a= x `mod` 2 
  b = x `div` 2






{-Explanation 
-}

