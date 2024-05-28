#  kkorenn1@gmail.com 209271535


about the code :
First I implemented the graph ; checked to see if its a square matrix by checking sizes of rows and colomns, then checked the see if the diagnoal values are set to be 0 (no edge from a vertex to itself).
and then checked if it is infact adjoint (by comparing places [i][j] to [j][i]).
printGraph - went through all edges of the matrix and added to the sum of edges.

Algorithms - 
isConnected : using a BFS algorithm , checks if all vertices are connected to eachother.

shortestPath:
Using Bellman - Ford algorithm , checks the shortest path between tho vertices relaxing after every iteration, while checking for negative cycles in the last iteration.
keeping every vertex that was visited and lastly returns the order of the vertices by switching their order.

dfsCheckCycle :
returns the print of the cycle that was found after using DFS algorithm to check if the vertex was visited.

isContainsCycle :
using the dfsCheckCycle to see if there's a cycle in the graph or not.

isBipartite :
using an algorithm i found online , to color the graph in two colors without having an edge from two vertices of the same color.
using BFS , using the private method of isBipartiteUtil.

isNegativeCycle :
using bellman ford algorithm , checks to see if theres a negative cycle by running it V-1 times and then in the V time chekcs if theres reduced weights - a sign of a negative cycle.

HOW TO :
Simply enter "make" in the terminal or CMD to make the files needed to run.
"make clean" to clear the files created.


//EX_2 

About the code - 
Implementing basic operations on Matrices ;
+ , - : simply checks if both of the same size , creates a new vector to be used as the new return matrix - add / subtracts into new matrix

+= , -+ : Checks if both of same size , then adds or subs to the matrix we operate on by the 2nd matrix values.

== , != - Checks if all values are the same in corresponding places.

> , < : checks if the matrix edges are fewer or larger than the corresponding matrix.

>= , <= : checks if edges are valid , then compares each vertex of the smaller matrix and compare it to the larger if its larger than 1.

* : creates new matrix and multiply by Matrix multiplition.


