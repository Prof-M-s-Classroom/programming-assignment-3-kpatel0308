#include "graph.h"
#include "heap.h"
#include <iostream>
#include <climits>

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        adjMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; ++j)
            adjMatrix[i][j] = 0;
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

void Graph::primMST() {
    int* key = new int[numVertices];
    int* parent = new int[numVertices];
    bool* inMST = new bool[numVertices];

    for (int i = 0; i < numVertices; ++i) {
        key[i] = INT_MAX;
        inMST[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;

    MinHeap heap(numVertices);
    for (int v = 0; v < numVertices; ++v)
        heap.insertKey(v, key[v]);

    heap.decreaseKey(0, 0);

    while (!heap.isEmpty()) {
        MinHeapNode minNode = heap.extractMin();
        int u = minNode.vertex;
        inMST[u] = true;

        for (int v = 0; v < numVertices; ++v) {
            if (adjMatrix[u][v] && !inMST[v] && adjMatrix[u][v] < key[v]) {
                key[v] = adjMatrix[u][v];
                parent[v] = u;
                heap.decreaseKey(v, key[v]);
            }
        }
    }

    int totalWeight = 0;
    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < numVertices; ++i) {
        std::cout << parent[i] << " - " << i << "\t" << adjMatrix[i][parent[i]] << "\n";
        totalWeight += adjMatrix[i][parent[i]];
    }
    std::cout << "Total Cost of MST: " << totalWeight << "\n";

    delete[] key;
    delete[] parent;
    delete[] inMST;
}
