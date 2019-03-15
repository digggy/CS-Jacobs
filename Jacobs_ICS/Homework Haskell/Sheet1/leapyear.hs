
{-| The program finds if given year is  leap year -}

isLeapYear' :: Integer-> Bool
isLeapYear' year
 |year `mod` 400 == 0 = True
 |year `mod` 4 == 0 = if (year `mod` 100 /= 0) then True else False
 |otherwise = False

isLeapYear :: Integer-> Bool
isLeapYear year
 |year `mod` 4 == 0 && year `mod` 100 /= 0 || year `mod` 400 == 0 =True
 |otherwise = False
