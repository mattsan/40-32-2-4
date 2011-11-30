import Text.Printf
import System

factorials  = scanl (*) 1 [1..]
factorial n = factorials !! n

values = filter (\(a, b, c, n) -> (((a - c) `mod` c) == 0) && (((a - b) `div` c) == n))
                [ (a, b, c, n) | a         <- [1..],
                                 (n, b, c) <- [ (n, b, c) | n      <- takeWhile (\x -> factorial x < a) [0..],
                                                            (b, c) <- takeWhile (\(x, _) -> x < a) [ ((a - factorial n) * c, c) | c <- [2..]]
                                              ]
                ]

print_abcn (a, b, c, n) = printf "(%d - %d) / %d = %d\n %d - %d  / %d = %d! = %d\n\n" a b c n a b c n (factorial n)

main = do
  args <- getArgs
  let max  = (read $ head args)::Int
  sequence_ $ map print_abcn $ takeWhile (\(a, _, _, _) -> a <= max) values