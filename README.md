# Push Swap

Push Swap is a sorting algorithm project as part of the 42 Network curriculum. It aims to sort a stack of integers using a limited set of operations.

## Table of Contents

-   [Introduction](#introduction)
-   [Usage](#usage)
-   [Bonus](#bonus)
-   [Building](#building)
-  [Resources](#resources)

## Introduction

Push Swap challenges you to sort a stack of integers in ascending order using only a specified set of operations on two stacks: `stack A` and `stack B`. The goal is to do this with the fewest possible operations.

## Usage

To use the Push Swap program, follow these steps:

1.  Clone the repository: `git clone https://github.com/rlabbiz/push_swap.git`
2.  Build the program using the provided Makefile: `make`
3.  Run the program with a list of integers to be sorted:
```bash
./push_swap 3 1 4 2
```
The program will output a series of operations that can be applied to `stack A` to sort it, such as `sa` (swap the first two elements of `stack A`), `pb` (push the top element of `stack A` onto `stack B`), and `ra` (rotate `stack A`).
### Bonus

A checker program is provided to validate the sorting result. After running `push_swap` with a list of integers, you can use the checker to verify if the sorting operations are correct:
```bash
ARG="3 1 4 2"; ./push_swap $ARG | ./checker $ARG
```
The checker will output `OK` if the sorting operations are valid, and `KO` otherwise.
### Instructions

Here are the available instructions for the Push Swap program:
-   `sa` swap a swaps the 2 top elements of stack a
-   `sb`swap b swaps the 2 top elements of stack b
-   `ss` swap a + swap b both  `sa`  and  `sb`
-   `pa`: Push a - Moves the top element of stack B to the top of stack A.
-   `pb`: Push b - Moves the top element of stack A to the top of stack B.
-   `ra`: Rotate a - Shifts all elements of stack A from bottom to top.
-   `rb`: Rotate b - Shifts all elements of stack B from bottom to top.
-   `rr`: Rotate a + rotate b - Combines `ra` and `rb`.
-   `rra`: Reverse rotate a - Shifts all elements of stack A from top to bottom.
-   `rrb`: Reverse rotate b - Shifts all elements of stack B from top to bottom.
-   `rrr`: Reverse rotate a + reverse rotate b - Combines `rra` and `rrb`.

## Building

To build the Push Swap program, use the provided Makefile. Run `make` in the root directory of the project to compile the program.
```bash
make
```
to generate `push_swap` program, and if you want to generate `checker` program use:
```bash
make bonus
```
## Resources
- [https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/](https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/)