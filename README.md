# push_swap
This is the push_swap project within 42 Codam's curriculum.
You have to create an algorythm to sort the given numbers.

## restrictions:
- You are only allowed to use 2 stacks.
- At the beginning stack a is filled with with the input and stack b is empty.
- The goal is to sort in ascending order numbers into stack a, to reach this you are only allowed to use the following operations:
```sh
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrr : rra and rrb at the same time.
```

## Installation and Usage:
To create the executable:
```sh
make | make bonus
```
To run the program:
```sh
./push_swap [any amount of numbers]
To use the checker:
Store the numbers inside a shell variable ARGS="insert your numbers here"
Run push_swap with the numbers as parameter and pipe it to the checker, given the same numbers.
./push_swap $ARGS | ./checker $ARGS
```
