*This project has been created as part of the 42 curriculum by tmachado, amateus-.*

# Push_swap

## Description

Push_swap is a sorting algorithm project developed as part of the 42 curriculum.

The goal of the project is to sort a list of integers in ascending order using two stacks, `a` and `b`, and a limited set of operations.

At the beginning of the program, all input values are stored in stack `a` and stack `b` is empty. The program must generate a sequence of Push_swap operations that sorts stack `a` with the smallest possible number of operations.

This project focuses on algorithmic complexity, stack manipulation, optimization, and the comparison of different sorting strategies.

The project implements four different strategies:

* **Simple** — `O(n²)`
* **Medium** — `O(n√n)`
* **Complex** — `O(n log n)`
* **Adaptive** — selects a strategy according to the measured disorder of the input

The four strategies can be selected at runtime.

---

## Features

* Sorting positive and negative integers
* Detection of invalid arguments
* Detection of duplicated values
* Detection of values outside the valid integer range
* Two-stack manipulation
* Four different sorting strategies
* Disorder calculation
* Benchmark mode
* Operation counting
* Performance testing with different input sizes

---

## Push_swap Operations

The program uses the following operations:

| Operation | Description                              |
| --------- | ---------------------------------------- |
| `sa`      | Swap the first two elements of stack `a` |
| `sb`      | Swap the first two elements of stack `b` |
| `ss`      | Execute `sa` and `sb` simultaneously     |
| `pa`      | Push the top element of `b` onto `a`     |
| `pb`      | Push the top element of `a` onto `b`     |
| `ra`      | Rotate stack `a` upward                  |
| `rb`      | Rotate stack `b` upward                  |
| `rr`      | Execute `ra` and `rb` simultaneously     |
| `rra`     | Reverse rotate stack `a`                 |
| `rrb`     | Reverse rotate stack `b`                 |
| `rrr`     | Execute `rra` and `rrb` simultaneously   |

---

# Instructions

## Compilation

Clone the repository and compile the project using:

```bash
make
```

The Makefile provides the standard rules:

```bash
make
make clean
make fclean
make re
```

The project is compiled using `cc` with the required warning flags:

```text
-Wall -Wextra -Werror
```

---

## Basic Usage

The program receives the integers as arguments.

Example:

```bash
./push_swap 2 1 3 6 5 8
```

The program outputs Push_swap operations, one operation per line.

To verify the generated sequence with the checker:

```bash
./push_swap 2 1 3 6 5 8 | ./checker 2 1 3 6 5 8
```

The expected result after a correct sequence is:

```text
OK
```

---

# Strategy Selection

The program supports four strategy selectors.

## Simple

```bash
./push_swap --simple 5 4 3 2 1
```

Forces the `O(n²)` strategy.

## Medium

```bash
./push_swap --medium 5 4 3 2 1
```

Forces the `O(n√n)` strategy.

## Complex

```bash
./push_swap --complex 5 4 3 2 1
```

Forces the `O(n log n)` strategy.

## Adaptive

```bash
./push_swap --adaptive 5 4 3 2 1
```

Forces the adaptive strategy.

When no strategy selector is provided, the adaptive strategy is used by default.

---

# Disorder

Before executing any sorting operation, the program calculates the disorder of the initial stack.

Disorder is a value between `0` and `1` that represents how far the initial stack is from being sorted.

* `0` means the stack is already sorted.
* `1` represents the worst possible ordering.
* Values between `0` and `1` represent intermediate levels of disorder.

The calculation is based on inversions.

For every pair of elements:

```text
a[i] and a[j] where i < j
```

the pair is counted as a mistake when:

```text
a[i] > a[j]
```

The disorder is then calculated as:

```text
mistakes / total_pairs
```

This follows the metric required by the project subject.

---

# Algorithms

## 1. Simple Algorithm — O(n²)

The simple strategy is the baseline sorting algorithm.

Its objective is to provide a straightforward solution that works correctly while remaining within the required `O(n²)` complexity class.

The implementation uses stack operations such as:

```text
pb
pa
ra
rra
sa
```

to locate and move elements until stack `a` becomes sorted.

The main idea is to repeatedly identify an element that should be placed in its correct position and manipulate the stacks until that position is reached.

The subject requires at least one baseline algorithm in the `O(n²)` class.

---

## 2. Medium Algorithm — O(n√n)

The medium strategy uses a **chunk-based approach**.

Instead of trying to organize all elements at once, the input is divided into ranges of indexes called chunks.

The algorithm first moves suitable elements from stack `a` to stack `b`.

For smaller inputs, the implementation uses a smaller chunk size, while larger inputs use a larger chunk size.

Example of the strategy currently used:

```c
if (size <= 100)
    chunk_size = 19;
else
    chunk_size = 45;
```

While moving elements to `b`:

* elements inside the current range are pushed with `pb`;
* low-index elements can additionally be rotated with `rb`;
* elements outside the current range are skipped using `ra`.

This produces a strategic distribution of elements in stack `b`.

After the first phase, the algorithm repeatedly finds the largest index in `b`, rotates `b` in the shortest direction, and moves that element back to `a` with `pa`.

The decision between `rb` and `rrb` is based on the position of the element:

```text
position <= size / 2
```

means that the element is in the first half and rotating forward is cheaper.

Otherwise, reverse rotation is used.

The subject defines chunk-based sorting as one possible implementation of the required `O(n√n)` medium strategy.

---

## 3. Complex Algorithm — O(n log n)

The complex strategy uses a **radix sort adaptation**.

The values are first converted into indexes representing their relative order.

For example, if the sorted values are:

```text
1 2 3 4
```

their indexes can be represented as:

```text
0 1 2 3
```

The radix algorithm processes the indexes bit by bit, starting from the least significant bit.

For each bit:

* if the current bit is `0`, the element is moved to `b` using `pb`;
* if the current bit is `1`, the element is rotated in `a` using `ra`;
* after processing the current elements, the elements in `b` are moved back to `a`.

This process is repeated for all required bits until the indexes are sorted.

The subject explicitly lists a radix-sort adaptation as a valid approach for the required `O(n log n)` strategy.

---

## 4. Adaptive Algorithm

The adaptive strategy chooses an internal sorting method according to the disorder measured before sorting.

The required regimes from the subject are:

| Disorder               | Required complexity |
| ---------------------- | ------------------- |
| `< 0.2`                | `O(n²)`             |
| `0.2 ≤ disorder < 0.5` | `O(n√n)`            |
| `≥ 0.5`                | `O(n log n)`        |

The exact internal functions used by the implementation should be described here according to the final code.

For example:

```text
Low disorder
    → Simple strategy

Medium disorder
    → Medium / chunk strategy

High disorder
    → Complex / radix strategy
```

**Important:** this mapping must match the actual implementation in the submitted source code. The subject requires the README to document both the thresholds and the techniques used in each regime.

---

# Complexity Model

The complexity classes in this project are measured using the number of generated Push_swap operations.

The subject explicitly requires that complexity claims reflect the Push_swap operation model rather than the theoretical cost of a classical array-based implementation.

The implemented strategies are therefore classified as:

```text
Simple    → O(n²)
Medium    → O(n√n)
Complex   → O(n log n)
Adaptive  → depends on the measured disorder
```

---

# Benchmark

The project includes benchmark support to analyse the behaviour of each strategy.

Benchmark information includes:

* calculated disorder;
* selected strategy;
* theoretical complexity;
* total number of operations;
* number of each Push_swap operation.

Benchmark information is written to `stderr` and appears only when benchmark mode is enabled, while the normal operation stream remains on `stdout`.

Example:

```bash
ARG="4 67 3 87 23"
./push_swap --adaptive --bench $ARG
```

Operation counting can also be checked using:

```bash
ARG="4 67 3 87 23"
./push_swap --adaptive $ARG | wc -l
```

---

# Performance Targets

The project subject defines the following benchmark targets:

## 100 numbers

```text
< 2000 operations → minimum requirement
< 1500 operations → good performance
< 700 operations  → excellent performance
```

## 500 numbers

```text
< 12000 operations → minimum requirement
< 8000 operations  → good performance
< 5500 operations  → excellent performance
```

These values are verified during evaluation.

---

# Error Handling

The program must print:

```text
Error
```

to `stderr` when invalid input is detected.

Examples include:

* arguments that are not integers;
* values outside the valid integer range;
* duplicated values.

Examples:

```bash
./push_swap --adaptive 0 one 2 3
```

```text
Error
```

and:

```bash
./push_swap --simple 3 2 3
```

```text
Error
```

These error requirements are defined by the project subject.

---

# Project Structure

A possible project structure is:

```text
PUSH_SWAP/
│
├── includes/
│   └── push_swap.h
│
├── src/
│   ├── algorithms/
│   │   ├── bench.c
│   │   ├── sort_adaptive.c
│   │   ├── sort_complex.c
│   │   ├── sort_medium.c
│   │   └── sort_small.c
│   │
│   ├── libft/
│   │   ├── ft_atol.c
│   │   ├── ft_putnbr.c
│   │   ├── ft_putstr.c
│   │   └── ft_split.c
│   │
│   ├── operations/
│   │   ├── op_push.c
│   │   ├── op_rotate_reverse.c
│   │   ├── op_rotate.c
│   │   └── op_swap.c
│   │
│   ├── parsing/
│   │   ├── disorder.c
│   │   ├── ops_bench_init.c
│   │   ├── parse_flags.c
│   │   ├── parsing_utils.c
│   │   └── parsing.c
│   │
│   └── stack/
│       ├── free_stack.c
│       ├── is_sorted.c
│       ├── stack_add_to_top.c
│       ├── stack_new.c
│       └── stack_utils.c
│
├── main.c
├── Makefile
└── README.md
```

The exact structure should reflect the files present in the submitted repository.

---

# Testing

During development, different input sizes and ordering patterns were used to verify the algorithms.

Examples:

```bash
./push_swap 2 1 3
```

```bash
./push_swap --simple 5 4 3 2 1
```

```bash
./push_swap --medium 4 67 3 87 23
```

```bash
./push_swap --complex 4 67 3 87 23
```

```bash
./push_swap --adaptive 4 67 3 87 23
```

The generated operations can be validated with the checker.

For operation counting:

```bash
ARG="4 67 3 87 23"
./push_swap --adaptive $ARG | wc -l
```

---

# Resources

## Documentation

* 42 Push_swap subject
* C documentation for dynamic memory allocation
* C documentation for linked 
* Documentation about sorting algorithms
* Documentation about Big-O notation
* Resources about radix sort
* Resources about chunk-based sorting
* Resources about inversion counting and disorder metrics

## AI Usage

AI tools were used as a learning and development aid, not as a replacement for understanding the implementation.

AI was used for tasks such as:

* explaining algorithmic concepts;
* clarifying Big-O complexity;
* understanding stack operations;
* discussing possible test cases;
* explaining pointers and data structures;
* reviewing logic and identifying possible issues;
* helping understand and document the implemented algorithms.

All AI-assisted information was reviewed, tested, and adapted to the project before being used.

---

# Contributors

This is a group project completed by exactly two learners, as required by the subject. Both contributors must understand and be able to defend the complete implementation.

## tmachado

### Contributions

* Parsing and input validation
* Stack structure
* Push_swap operations
* Simple algorithm

## amateus-

### Contributions

* Disorder calculation
* Medium chunk algorithm
* Complex radix algorithm
* Adaptive strategy
* Benchmark mode

---

# Conclusion

Push_swap is a practical study of algorithmic complexity under strict operational constraints.

By implementing four different strategies and measuring disorder and operation counts, the project demonstrates how algorithm selection can affect sorting performance.

The main objective is not only to obtain a correctly sorted stack, but also to understand how different strategies behave and how their operation costs scale with the input size.
