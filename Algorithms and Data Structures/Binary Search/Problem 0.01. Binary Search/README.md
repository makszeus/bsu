# Binary search

| Parameter | The value |
| -------------------- | ------------- |
| Input file name | Standard input |
| Output file name | Standard output|
| Time limit | 2 with |
| Memory limit | 256 Mb |

Perform a binary search on an array of numbers sorted in non-decreasing order. The use of ready-made binary search functions from standard libraries is prohibited.</br>

# Input
The first line contains an integer $n$ — the number of numbers in the array $(1 ⩽ n ⩽ 3*10^5).$ </br>
In the second line, $n$ numbers of the array are written with a space. All numbers are integers and belong to the interval from $-2^{31}$ to $2^{31} - 1$ exactly. The numbers in the array are ordered by nonexistence. from $-2^{31}$ to $2^{31} - 1$ on the street.

# Output
For each query number $x$ on a separate line, output the numbers $b$, $l$ and $r$ through the space, where $b$ is $1$ if $x$ is present in the array, or $0$ otherwise; $l$ – the index of the first element, greater than or equal to $x$; $r$ is the index of the first element greater than $x.$</br>
The elements of the array are numbered with signifiers from $0$ to $n-1.$ If there are no suitable elements in the array, let's agree that the return value will be equal to $n.$
