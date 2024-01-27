module Main where

type Rows = Int
type Cols = Int
type Remainder = Int
type Formation = (Rows, Cols, Remainder)
type Contraint = (Rows, Remainder)

type Solution = [Int] -> Contraint -> [Int]

main :: IO ()
main = do
  putStrLn "Bonjour, Napoleon!"
  givenAnswer <- read <$> getLine :: IO Int

  [answer] <- process []
  putStrLn $ "Answer: " <> show answer

process :: [Int] -> IO [Int]
process proposals = do
  elements <- (fmap read . words <$> getLine) :: IO [Int]

  let
    rows : remainder : _ = elements
    constraint = (rows, remainder)
    newProposals = solve proposals constraint
  if length newProposals == 1
    then return newProposals
    else process newProposals

solve :: Solution
solve proposals (rows, remainder) =
  if null proposals
    then take 10 newProposals
    else fmap fst $ filter (uncurry (==)) $ zip proposals newProposals
 where
  generator n = rows * n + remainder
  newProposals = generator <$> [1 ..]
