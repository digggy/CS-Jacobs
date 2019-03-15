

rotate :: Int -> [a] -> [a]
rotate _ [] = []
rotate n xs = take (length xs) (drop n (cycle xs))

--  check Prime number
{-| Problem 3.3 a)   -}
prime :: Int -> Bool
prime x = check x x

check :: Int -> Int -> Bool
check a b
 |b == 1 = True
 |b == 2 = True
 |a`mod`(b-1) == 0 = False
 |otherwise = check a (b-1)

--check circprime :: Integer -> Bool
{-| Problem 3.3 b)   -}
circprime x = checkCircPrime (show x) 0

checkCircPrime num index
    |index == (length num) = True
    |not (prime thisNum) = False
    |otherwise = checkCircPrime num (index+1)
    where thisNum = read (rotate index num) :: Int
