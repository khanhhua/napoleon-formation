module Main where

import Control.Monad.State.Lazy
import Data.List (nub)

type Rows = Int
type Cols = Int
type Remainder = Int
type Formation = (Rows, Cols, Remainder)
type Contraint = (Rows, Remainder)

type Solution = [Int] -> Contraint -> [Int]

type SolutionT = StateT [Int] IO Int

main :: IO ()
main = do
  putStrLn "Bonjour, Napoleon!"
  givenAnswer <- read <$> getLine :: IO Int

  answer <- evalStateT process []
  putStrLn $ "Answer: " <> show answer

  if givenAnswer == answer
    then putStrLn "Correct!"
    else putStrLn "Sorry, wrong answer."

process :: SolutionT
process = do
  line <- lift getLine
  proposals <- get

  let
    elements = (read <$> words line) :: [Int]
    rows : remainder : _ = elements
    constraint = (rows, remainder)
    newProposals = solve proposals constraint

  case newProposals of
    [answer] -> return answer
    _ -> do
      put newProposals
      process

solve :: Solution
solve proposals (rows, remainder) =
  if null proposals
    then newProposals
    else fmap fst $ filter (uncurry (==)) $ nub $ (,) <$> proposals <*> newProposals
 where
  generator n = rows * n + remainder
  newProposals = takeWhile (< 100) $ generator <$> [1 ..]
