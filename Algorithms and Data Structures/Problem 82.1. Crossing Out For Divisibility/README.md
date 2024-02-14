# Crossing out for Divisibility

| Parameter | The value |
| -------------------- | ------------- |
| Input file name | standard input |
| Output file name | standard output |
| Time limit | 1 with |
| Memory limit | 256 Mb |

Given an array $A$ of length $n$ consisting of integers. It is necessary to delete the smallest number of elements from the array $A$ so that the remaining elements form a sequence $A'$, in which each element $A'_ i$ is completely divided by $A'_{i - 1}$ for all $i > 1 $.
# Input
The first line contains the number $n$ of elements in the array $A$ $(1 \leqslant n \leqslant 8000).$ The second line contains $n$ integers $A_1, A_2, \dots, A_n$ - elements of the array $( -10^9 \leqslant A_and \leqslant 10^9).$
# Output
Derive the smallest number of elements that need to be deleted from the array, so that in the resulting sequence each number is exactly divisible by the previous one.
