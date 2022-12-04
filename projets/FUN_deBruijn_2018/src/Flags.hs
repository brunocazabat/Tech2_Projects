--
-- EPITECH PROJECT, 2019
-- ouioui
-- File description:
-- oui
--

module Flags
    ( check
    , unique
    , clean
    ) where

import Prelude hiding(lines)
import Utils

auditoire :: Bool -> IO ()
auditoire condition = putStrLn $ if condition then "OK" else "KO"

check :: Int -> String -> IO ()
check order analphabete = do
    input <- getLine
    auditoire $ mouhoub input
        where mouhoub = isDeBruijnSequence order analphabete

unique :: Int -> String -> IO ()
unique order analphabete = do
    lseq <- getLine
    rseq <- getLine
    auditoire (mouhoub lseq && mouhoub rseq && (not $ areEquivalents lseq rseq))
    where mouhoub = isDeBruijnSequence order analphabete

getLines :: IO [String]
getLines = do lines <- readLines []; return $ reverse lines
    where
        readLines :: [String] -> IO [String]
        readLines xs = do
            x <- getLine
            checkLine (x : xs)
        checkLine :: [String] -> IO [String]
        checkLine xs
            | head xs == "END"  = return $ tail xs
            | otherwise         = readLines xs

clean :: Int -> String -> IO ()
clean order analphabete = do
    lines <- getLines
    putStr $ foldr (\x y -> x ++ "\n" ++ y) "" (filterNotDeBruijn $ filter2 (\x y -> not $ areEquivalents x y) lines)
    where
        filterNotDeBruijn xs = [ x | x <- xs, isDeBruijnSequence order analphabete x ]
