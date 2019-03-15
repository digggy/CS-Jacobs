
--Problem 8.2: ripple carry adder and carry lookahead adder (haskell)

xor :: Bool -> Bool -> Bool
xor a b = (a && not b)||(not a && b)
--Question a)
bin :: Int -> Int -> [Bool] 
bin 0 n = []
bin 1 0 = [False]
bin m n = bin (m-1) b ++ [a]
 where 
    a = numToBool(n`mod`2)
    b = n`div`2

numToBool :: Int -> Bool
numToBool a 
 |a==1 = True 
 |a==0 = False

 {-Explanation : 
 The main bin function is a recursive function where the base condition is when the parameter m is 1 and n is 0 or the bit number (m) is 0.
 The function runs recursively. numToBool converts the remainder to a boolean value ie: (True or False) and the boolean value is added to the list.  
 Here numToBool function converts the binary numbers to true or false.
-}

--Question b)
dec :: [Bool]-> Int
dec (x:xs)
 |length(xs) == 0 = if (x == True) then 1 else 0
 |x == True = (1*2^(length xs)+dec xs)
 |x == False = dec xs

{-Explanation : 
Dec funtion is a recursive function which terminates when the length of the tail is zero.The funtion compares the head of the Bool Array
 and check if it is True or False then performs the conversion and call the fuction again for further conversions.

-}

--Question c)

faS :: Bool->Bool->Bool->Bool
faS a b c = xor (xor a b) c

faC :: Bool -> Bool -> Bool -> Bool
faC a b c = (a && b )||(c && a)||(c && b)

rcAdd :: [Bool]-> [Bool]->[Bool]
rcAdd (ab) (xs) = reverse $ addit (reverse ab) (reverse xs) False

addit :: [Bool]-> [Bool]->Bool->[Bool]
addit (a:ab) (x:xs) cin 
 |length xs /= 0 = [faS a x cin] ++ addit ab xs cout 
 |length xs == 0 = [faS a x cin]
 where cout = faC a x cin

{-Explanation : 
faS function is the xor implementation of three inputs.
faC function is the finds the Current Carry.

rcAdd calls a addit function where the Boolean List are passed as reverese list to perform operations extracting out the head each of the list.
rcAdd returns the reverse list of the result of addit function.Addit is also a recursive function that finds the sum of three the boolean values that 
are passed in the function faS and adds them to the list.

-}

--Question d)
haC :: Bool -> Bool ->Bool
haC a b = a && b 

haS :: Bool -> Bool -> Bool 
haS a b = xor a b 

carry :: [Bool] -> [Bool]-> Bool
carry (a:ab) (x:xs)
 |length xs == 0 = a && x
 |otherwise = (haC a x) || ((haS a x) && (carry ab xs)) 

claAdd :: [Bool]->[Bool]->[Bool]
claAdd (a:ab) (x:xs) 
 | length ab == 0 = [haS a x] 
 | otherwise = [haS (haS a x) (carry ab xs)] ++ claAdd ab xs  

 {-Explanation : 
haS function is the and implementation of two inputs.
haC function is the xor implementation of two inputs.

claAdd calls a addit function where the Boolean List are passed as reverese list to perform operations extracting out the head each of the list.
claAdd returns the reverse list of the result of addit function.
Here in this case the carry funtion is recursive, so for each nth bits sum being calculated, carry function calculates the carry for that bits without
any dependance from older carrys.
-}