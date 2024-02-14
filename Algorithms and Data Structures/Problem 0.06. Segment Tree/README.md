# Tree of segments

| Parameter | The value |
| -------------------- | ------------- |
| Input file name | in.txt |
| Output file name | out.txt |
| Time limit | 1 with |
| Memory limit | Missing |

There is a sequence $s_0, …, s_n − 1$ consisting of zeros. The following types of queries can be executed on this sequence:

&nbsp;• Set the value of $s_i$ equal to $v$.</br>
&nbsp;• Add to each element with an index from the segment $[a, b]$ the number $v.$</br>
&nbsp;• Find the sum of elements with indices from the segment $[a, b].$</br>
&nbsp;• Find the minimum among elements with indices from the segment $[a, b].$</br>
&nbsp;• Find the maximum among elements with indices from the segment $[a, b].$</br>
</br>
You are required to write a program that will handle the specified requests.

# Input
The first line contains one integer $n$ $(1 ≤ n ≤ 300 000)$ — the length of the sequence. The following lines have the following format: the first number is the request type (see condition), followed by two numbers for a type 1 request: $i$, the index of the element in the array, and the value of $v$; for query type 2, three numbers: $a, b, v;$ for queries of type $3–5$, two numbers: $a$ and $b$. The input ends with a line with the single value $0$. The number of lines does not exceed $300,003. The absolute value of the number $v$ in each request does not exceed $1,000,000$. The numbers $a, b$ and $i$ in each request satisfy the inequalities $0 ≤ a ≤ b < n, 0 ≤ i < n.$

# Output
For each request of type $3-5$, output the response to the request.
