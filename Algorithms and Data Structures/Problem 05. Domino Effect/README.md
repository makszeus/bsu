# The domino effect

| Parameter | The value |
| -------------------- | ------------- |
| Input file name | in.txt |
| Output file name | out.txt |
| Time limit | 1 with |
| Memory limit | Missing |

A figure is built from $n$ dominoes, which will later be beautifully collapsed. For each die with number $i$, we know the set of $D_i$ dice that will fall at time $t + 1$, if they remained standing until this moment, and die $i$ will fall at time $t.$ It is necessary to determine which bone should be knocked down at the moment of time so that the piece falls for the maximum amount of time. It is also required to calculate the time that will pass before the complete collapse of the figure.

# Input
The number $n$ $(1 ≤ n ≤ 1000) is written in the first line.$ In each of the following lines, the power of the set $D_and$ and the numbers of the bones included in it is written. The numbers in the string are separated by one or more spaces.

# Output
In the first line, output the time when the last die will fall. In the second line - the number of the bone that must be knocked down first. If the maximum collapse time is reached with different starting bones, the maximum possible number must be specified. If complete collapse of the structure is impossible, output a single line $impossible.$
$i$
