--
-- EPITECH PROJECT, 2019
-- ouioui
-- File description:
-- oui
--

module Parser
    ( parseCommand
    , Options(..)
    , Flag(..)
    ) where

import Control.Monad
import System.Console.GetOpt
import System.Environment(getArgs)
import Utils

data Options = Options
    { argOrder :: Int
    , argAlphabet :: String
    , flag :: Flag
    } deriving Show

data Flag = Check | Unique | Clean | ShowUsage
    deriving (Eq, Show, Bounded, Enum)

usage :: String
usage = usageInfo "USAGE: ./deBruijn n [a] [--check|--unique|--clean]\n" options

options :: [OptDescr (Options -> Either String Options)]
options =
    [ Option [] ["check"] (NoArg (\opts -> Right opts { flag = Check })) "\tcheck if a sequence is a de Bruijn sequence"
    , Option [] ["unique"] (NoArg (\opts -> Right opts { flag = Unique })) "\tcheck if 2 sequences are distinct de Bruijn sequences"
    , Option [] ["clean"] (NoArg (\opts -> Right opts { flag = Clean })) "\tlist cleaning"
    ]

defaultOptions:: Options
defaultOptions = Options
    { argOrder      = 3
    , argAlphabet   = "01"
    , flag          = ShowUsage
    }

parseCommand :: IO (Either String Options)
parseCommand = do
    argv <- getArgs
    case getOpt Permute options argv of
        (opts, args, []) -> case foldM (flip id) defaultOptions opts of
            Right opts'         -> return (boumlingou opts' args)
            Left errorMessage   -> return $ Left (errorMessage ++ "\n" ++ usage)
        (_, _, _) -> return $ Left usage
    where
        boumlingou :: Options -> [String] -> Either String Options
        boumlingou opts (x:y:_)
            | isValid   = linkguage $ opts {argOrder = read x, argAlphabet = y}
            | otherwise = Left usage
            where isValid = length y > 1 || (length y /= 0 && length y == read x)
        boumlingou opts [x]  = linkguage $ opts {argOrder = read x}
        boumlingou _ []      = Left usage

linkguage :: Options -> Either String Options
linkguage opts
    | areUniques $ argAlphabet opts = Right opts
    | otherwise                     = Left usage
