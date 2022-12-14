--
-- EPITECH PROJECT, 2019
-- ouioui
-- File description:
-- oui
--

module Main (main) where
import System.Exit
import Parser
import Flags
import DeBruijn

main :: IO ()
main = do
  opts <- parseCommand
  case opts of
    Left errorMessage -> do putStr errorMessage; exitWith (ExitFailure 84)
    Right opts'     -> case (flag opts') of
      Check       -> check    order alphabet
      Unique      -> unique   order alphabet
      Clean       -> clean    order alphabet
      _           -> do putStrLn (deBruijn order alphabet)
      where
        order = (argOrder opts')
        alphabet = (argAlphabet opts')