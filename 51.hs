

module Main where
import Data.List

main = print $ queens' 8
removeAt:: Int->[a] -> [a]
removeAt i xs = take i xs ++ drop (i+1) xs
sameDiag:: Int ->[Int]->Bool
sameDiag x xs = any (\(colDist,q) -> abs (x - q) == colDist) $ zip [1..] xs
queens' :: Int->[[Int]]
queens' n = prem' n [1..n] where
  prem' 0 _ = [[]]
  prem' n xs =[ xs !! i : ys | i <-[0..length xs -1],ys <- prem'(n-1) (removeAt i xs) , not $ sameDiag (xs !! i) ys]
  

