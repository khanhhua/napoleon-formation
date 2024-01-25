Napoleon Formation
====

## Legend
How did Napoleon quickly figure out the size of his army units?
Legend has it that he ordered his men to form different rectangular formations.
Afterwards he immediately knew how many of them.

## Math Theory
The number of men in rectangular formations can be formulated as:

    A = x . y + r

where A is the number of men to be determined, x and y are length in men of the rectangle,
r is the number of men who cannot form a full column.

For example, given A = 50, we could have the following different formations

| Columns | Rows    | Remainder |
| ------- | ------- | --------- |
| 7       | 7       | 1         |
| 8       | 6       | 2         |
| 9       | 5       | 5         |
| 10      | 5       | 0         |
| 11      | 4       | 6         |
| 12      | 4       | 2         |
| 13      | 3       | 11        |

For a different A, the combination of formations (x, y, r) is different. Theoretically, by
noting the remainder and either columns or rows, Napoleon could have inferred with high
confidence the value of A.

## Our Programming Exercises

1. Write a program which challenges the user to guess to correct value of A. User is
presented with Columns and Remainder for each iteration. A new formation is created whenever
the guess is wrong.

2. Write a program which determines the optimal solutions of N different formations before a
possible guess can be made.

The general objectives are:

- Minimize the number of alternations
- Maximize of the likelihood of achieving the correct value of A
