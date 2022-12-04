--
-- EPITECH PROJECT, 2019
-- ouioui
-- File description:
-- oui
--

module DeBruijn
  ( deBruijn
  , lyndonWord
  ) where

import Prelude hiding(sequence)

deBruijn :: Int -> String -> String
deBruijn 0 _            = ""
deBruijn _ ""           = ""
deBruijn order zbleh = [ zbleh !! x | x <- sequence]
  where
    base        = length zbleh
    sequence    = maroilles base order

maroilles :: Int -> Int -> [Int]
maroilles base order = concat (filter (\xs -> mod order (length xs) == 0) (reverse (dindon base order [[0]])))

dindon :: Int -> Int -> [[Int]] -> [[Int]]
dindon base order prevWords
    | word == []    = prevWords
    | otherwise     = dindon base order (word : prevWords)
  where word  = lyndonWord base order (head prevWords)

lyndonWord :: Int -> Int -> [Int] -> [Int]
lyndonWord base order prevWord = incr (dropZ word)
  where
    word    = take order (cycle prevWord)
    dropZ xs
      | length xs /= 0 && last xs == (base - 1) = dropZ (init xs)
      | otherwise = xs
    incr :: [Int] -> [Int]
    incr [] = []
    incr xs = (init xs) ++ [last xs + 1]
