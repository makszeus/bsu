# Labyrinth-3

| Parameter | The value |
| -------------------- | ------------- |
| Input file name | labyrinth.in |
| Output file name | labyrinth.out |
| Time limit | 1 with |
| Memory limit | 1024 Mb |

A table of size $n × m$ defines some maze (numbering of rows and columns of the table starts from 1). In the table, a cell with a number of 1 denotes a wall, and a cell with a number of 0 - an empty space. In the first line of the table, the inputs $x_и$ are defined, and in the last output - $y_и, и = 1, …, k$, which must contain zeros. (But not every cell with a zero in the first (last) line is an input (output).) At each input there is one person with the number $i.$

It is necessary to determine the maximum number of people who can be guided through the maze so that each free place of the maze is visited no more than once, taking into account that several people can pass through one exit. Movement in the maze is carried out only to a cell that has at least one point in common with the current cell.

# Input
The first line contains three numbers: $n, m$ and $k (1 ≤ n, m, k ≤ 1000).$

The second line contains the numbers $x_i$ for $i = 1, …, k,$ which correspond to the column numbers of the first line of the maze table, which are inputs for the $i$th person (the first column has the number 1).

The third line contains the numbers $y_i$ for $i = 1, …, k,$ which correspond to the column numbers of the last line of the maze table, which are the outputs.

In the following rows, the rows of the maze table are set: 0 - free space, 1 - wall.

# Output
In the first line, display the maximum number of people you managed to transfer.

In the following lines, display the maze table containing the paths of the people who managed to be guided by elements in each of the following lines: positions of the maze, along which a person must go to the invention, with numbers denoted by the number $и + 1$ (since several people can use one exit, then the exit position is indicated by the number $i + 1$ of the last person ($i$ who exited through it).

Note. Numbers in rows are separated by a single space.
