{- Module: p6-boolexpr/boolexpr.hs-}
module BoolExpr (Variable, BoolExpr(..), evaluate) where
type Variable = Char
data BoolExpr
= T
| F
| Valr Variable
| Not BoolExpr
| And BoolExpr BoolExpr
| Or BoolExpr BoolExpr
deriving (Eq, Ord, Show)

 -- evaluates an expression
 evaluate :: BoolExpr -> [Variable] -> Bool
 evaluate T ts = True
 evaluate F ts = False
 evaluate (Var v) ts = elem v ts
 evaluate (Not e) ts = not (evaluate e ts)
 evaluate (And e1 e2) ts = evaluate e1 ts && evaluate e2 ts
 evaluate (Or e1 e2) ts = evaluate e1 ts || evaluate e2 ts