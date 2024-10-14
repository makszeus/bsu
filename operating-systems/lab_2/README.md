# Task Condition

## Overview

This project involves writing programs for two console processes: **Parent** and **Child**. The Parent process will handle user input and setup, while the Child process will perform operations on an array based on the Parent's input.

## Parent Process

The Parent process will perform the following actions:

1. **Input Array Size**: Prompt the user to enter the size of the array.
2. **Input Array Elements**: Prompt the user to enter the elements of the array.
3. **Form Command Line**: Create a command line that contains information about the size of the array, the elements, etc.
4. **Set Console Background Color**: Set any background color (not black) for the console of the Child process.

## Child Process

The Child process will perform the following actions:

1. **Search Array**: Search the array for elements greater than a specified value `A`.
2. **Rearrange Array**: Place the elements greater than `A` on the left side of the array and fill the remaining elements with zeros.
3. **Output Resulting Array**: Print the resulting array to the console. The type of elements is integers.

## Note

To wait for the completion of the Child process, use the following function:

```c
DWORD WaitForSingleObject(
    HANDLE hHandle, // object handle
    DWORD dwMilliseconds // wait interval in milliseconds
);
```
The second parameter should be set to INFINITE, for example:
```
WaitForSingleObject(hProcess, INFINITE); // wait for the process to complete
```

Here, hProcess is the handle of the Child process.
