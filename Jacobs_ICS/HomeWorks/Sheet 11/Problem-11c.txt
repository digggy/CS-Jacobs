{-
Using results from HomeWork We can construct the following program
-}

data State = S0 | S1 | S2 | S3

accepts :: State -> String -> Bool

{-these are the equavalent delta functions from the documentation of the FSM-}
accepts S0 ('b':xs) = accepts S1 xs
accepts S0 ('a':xs) = accepts S2 xs
accepts S1 ('b':xs) = accepts S1 xs
accepts S1 ('a':xs) = accepts S0 xs
accepts S2 ('a':xs) = accepts S2 xs
accepts S2 ('b':xs) = accepts S2 xs


accepts S1 [] = True
accepts _ _ = False

fsm :: String -> Bool

{-Inital State-}
fsm = accepts S0
