# Binomial heap

| Parameter | The value |
| -------------------- | ------------- |
| Input file name | input.txt |
| Output file name | output.txt |
| Time limit | 1 with |
| Memory limit | 64 Mb |

A binomial tree of height $k$ is denoted by $B_k$ and is defined as follows.

&nbsp;• Binomial tree $B_0$ consists of one unique vertex.</br>
&nbsp;• A binomial tree $B_k$ is formed by joining a binomial tree of height $k − 1$ to the root of another binomial tree of height $k − 1$ (during joining, the root of one of the trees belongs to one of the children of the root of the other tree).</br>

Thus, the binomial tree $B_k$ has a root vertex whose children are the roots of the binomial trees $B_0$, $B_1$, $B_2$, ..., $B_k − 1.$

![image](https://user-images.githubusercontent.com/115582642/204354796-393ee9da-a8fb-4075-8b3d-1cd05c8f70b6.png)

A binomial heap consists of a set of binomial trees in pairs of different heights. In other words, for any $k ≥ 0$, the binomial tree $B_k$ is either not included in the heap or is included exactly once.

Given the total number of vertices in the binomial heap. Determine which binomial trees this pile might consist of.

# Input
A single number $n$ of vertices in the heap $(1 ≤ n ≤ 1018) is specified at the input.$

# Output
For each binomial tree $B_k$ in the heap, output one integer - height $k$ - in a separate line. Trees should be removed in order of height. All trees must have different orders, and the sum of the orders must be $n$.

If there are several solutions, display any one. If there are no solutions and the binomial heap with the specified number of vertices cannot be constructed, output $−1$.
