
# Prim's Algorithm with Min Heap and Adjacency Matrix


Khush Patel

## Description
This program implements Prim’s Algorithm to find the Minimum Spanning Tree (MST) of a connected, undirected graph using:
- A custom-built Min Heap (no STL)
- An adjacency matrix representation of the graph

The MST edges and total cost are printed as output. All memory is managed properly using dynamic allocation.


## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation        |  Time Complexity |
| Insert in MinHeap | O(log V)        |
| Extract Min  |       O(log V)        |
| Decrease Key |      O(log V)        |
| Prim’s MST Overall | O(V^2 log V)   |

_Explain why your MST implementation has the above runtime._
- The input graph is connected and undirected
- Number of vertices ≤ 10
- Edge weights are non-negative
- Graph input is hardcoded in `main.cpp` 


## Test Case Description

Input:  Graph g(5);
g.addEdge(0, 1, 2);
g.addEdge(0, 3, 6);
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 8);
g.addEdge(1, 4, 5);
g.addEdge(2, 4, 7);
g.addEdge(3, 4, 9);