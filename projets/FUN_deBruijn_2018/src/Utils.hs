--
-- EPITECH PROJECT, 2019
-- ouioui
-- File description:
-- oui
--

module Utils
    ( getWords
    , isDeBruijnSequence
    , areUniques
    , areEquivalents
    , filter2
    ) where

import Prelude hiding(sequence, words)
import DeBruijn
import Data.List hiding(words)

getWords :: Int -> [a] -> [[a]]
getWords size xs = zguah xs'
    where
        xs' = xs ++ take (size - 1) xs
        zguah xs''
            | length xs'' == size   = [take size xs'']
            | otherwise             = take size xs'' : zguah (drop 1 xs'')


isDeBruijnSequence :: Int -> String -> String -> Bool
isDeBruijnSequence order zgueg sequence = reference == words
    where
        reference   = sort (getWords order . deBruijn order $ zgueg)
        words       = sort (getWords order sequence)

areUniques :: (Ord a) => [a] -> Bool
areUniques xs = chipolatas sorted (drop 1 sorted)
    where
        sorted = sort xs
        chipolatas (x:xs') (y:ys)  = if x /= y then chipolatas xs' ys else False
        chipolatas [] _            = True
        chipolatas _ []            = True

revolution :: Int -> [a] -> [a]
revolution _ [] = []
revolution 0 xs = xs
revolution n xs = revolution (n - 1) (last xs : init xs)

areEquivalents :: (Eq a) => [a] -> [a] -> Bool
areEquivalents [] [] = True
areEquivalents xs ys = foldr (||) False [ revolution x xs == ys | x <- [0..(length xs)] ]

filter2 :: (a -> a -> Bool) -> [a] -> [a]
filter2 _ []        = []
filter2 _ [x]       = [x]
filter2 f (x:xs)    = x : [ y | y <- filter2 f xs, f y x ]
