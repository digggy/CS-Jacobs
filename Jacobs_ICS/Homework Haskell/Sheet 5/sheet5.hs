{-Problem 5.4-}

bin ::Int->[Int]
bin 0 = [0]
bin 1 = [1]
bin x =  bin b ++ [a] 
 where 
  a= x `mod` 2 
  b = x `div` 2

{-Explanation 
-}

binf :: Double -> [Int]
binf n = sub_binf n [0] 0

sub_binf n list c
    | n==0 = [0]
    | n==1 || (c)==23 = list
    |otherwise = sub_binf (new_n) (list ++ [(floor (n*2)::Int)]) (c+1)
    where new_n = if(n*2>1) then (n*2-1) else n*2
          