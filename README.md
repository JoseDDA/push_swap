# Push Swap

## Overview

The **Push Swap** project is a sorting algorithm exercise where the goal is to sort a stack of integers using a limited set of operations. The project is typically part of coding challenges and focuses on algorithmic thinking, efficiency, and understanding stack operations.

This project aims to sort integers on two stacks with a limited number of operations, making it a good exercise for practicing algorithm design, stack manipulation, and efficient problem-solving.

## Table of Contents

* [Description](#description)
* [Installation](#installation)
* [Usage](#usage)
* [Project Structure](#project-structure)
* [Functions](#functions)
* [Error Handling](#error-handling)
* [License](#license)

## Description

The goal of the **Push Swap** project is to:

* Sort a list of integers using two stacks (`stack_a` and `stack_b`).
* Only a few operations are allowed to perform the sorting, which includes:

  * `push`: Move the top element of one stack to another.
  * `swap`: Swap the top two elements of a stack.
  * `rotate`: Move the top element of a stack to the bottom.
  * `reverse rotate`: Move the bottom element of a stack to the top.

You must sort the stack using the smallest number of operations possible. The number of operations used will determine the efficiency of your solution.

## Installation

To get started with the project, clone the repository:

```bash
git clone <repository-url>
cd push_swap
```

Make sure you have a C compiler (e.g., GCC) and `libft` (your custom library) set up before compiling the project.

## Usage

1. Compile the project with `make`:

```bash
make
```

2. To execute the program, use:

```bash
./push_swap <numbers>
```

Where `<numbers>` is a list of integers that you want to sort.

Example usage:

```bash
./push_swap 3 1 4 2
```
or with:
```bash
./push_swap "3 1 4 2"
```

## Project Structure

```plaintext
.
├── src/
│   ├── main.c
│   ├── argument_validation.c
│   ├── argument_validation_utils.c
│   ├── sort.c
│   ├── sort_utils.c
│   ├── cost_b.c
│   ├── cost.c
│   ├── move_cheapest.c
│   ├── stack_move.c 
│   └── ...
├── include/
│   └── push_swap.h
├── libft/
│   └── <libft-files>
├── checker_linux 
├── Makefile
└── README.md
```

### Key Files:

* **`src/main.c`**: Contains the main logic to parse input and invoke the sorting algorithm.
* **`src/argument_validation.c`**: Validates and processes the input arguments.
* **`src/sort.c`**: Implements the sorting algorithm.
* **`src/stack_operations.c`**: Contains the stack operation functions like `push`, `swap`, `rotate`, and `reverse_rotate`.
* **`src/cost.c`**: Calculates the costs associated with stack operations and helps find the optimal moves.

## Functions

### Program Functions:

* **`main`**: Entry point of the program that handles argument parsing and calls the sorting algorithm.

### Argument Validation Functions:

* **`check_init_stacks`**: Initializes the stacks based on input.
* **`validate_input`**: Validates the input to ensure it contains valid integers.
* **`is_valid_integer`**: Checks if an input string is a valid integer within the integer range.

### Sorting Functions:

* **`sort_stacks`**: Main function to sort the stacks using the allowed operations.
* **`sort_three`**: Sorts a stack with exactly three elements.
* **`sort_circular_stack`**: Sorts a circular stack.

### Stack Operations:

* **`push`**: Pushes the top element of one stack onto another.
* **`swap`**: Swaps the top two elements of a stack.
* **`rotate`**: Rotates a stack (moves the top element to the bottom).
* **`rev_rot`**: Reverses the rotation (moves the bottom element to the top).

## Error Handling

The program handles several error cases:

* Invalid integers (e.g., exceeding `INT_MAX` or `INT_MIN`).
* Duplicated numbers in the input list.
* Invalid input formats.
* Memory allocation errors.

In case of an error, the program will print `Error` to `stderr` and exit with a non-zero status.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

