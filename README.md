---

<div align="center">
  
![push_swape](https://github.com/AndreGomesSilva/push_swap/assets/59901704/de1ad6a3-9e1a-46d8-81cf-c4c13b2c4c01)

</div>

---


# Push_Swap

Push_Swap is a sorting algorithm project that aims to sort a stack of integers using a limited set of operations. The project is written in C and is a part of the curriculum at [School 42SP](https://www.42sp.org.br/).

## Description

The goal of Push_Swap is to take an unsorted stack of integers and sort it in ascending order using two stacks and a set of predefined operations. The operations allowed are:

- `sa`: swap the first two elements of stack A
- `sb`: swap the first two elements of stack B
- `ss`: do `sa` and `sb` simultaneously
- `pa`: push the first element of stack B to stack A
- `pb`: push the first element of stack A to stack B
- `ra`: rotate all elements of stack A by one position upwards
- `rb`: rotate all elements of stack B by one position upwards
- `rr`: do `ra` and `rb` simultaneously
- `rra`: rotate all elements of stack A by one position downwards
- `rrb`: rotate all elements of stack B by one position downwards
- `rrr`: do `rra` and `rrb` simultaneously

The program takes a list of integers as arguments and outputs a series of operations that, when executed, will sort the stack in the fewest possible moves.

## Usage

To compile the program, run the following command:

```bash
make

```

To execute the program, run the following command:

```bash
./push_swap [list of integers]

```

For example:

```bash
./push_swap 5 2 1 3 4

```

The program will output a series of operations that can be used to sort the stack.

## Algorithm

Push_Swap uses a combination of different sorting algorithms based on the number of elements in the stack. For small stacks (less than 3 elements), it employs a simple sorting algorithm. For larger stacks, it uses a more complex algorithm that divides the stack into smaller chunks and applies various operations to sort them.

Feel free to explore the Push_Swap repository for the full source code and additional information.
