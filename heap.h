#ifndef HEAP_H
#define HEAP_H

struct MinHeapNode {
    int vertex;
    int key;
};

class MinHeap {
public:
    MinHeap(int capacity);
    ~MinHeap();

    void insertKey(int vertex, int key);
    MinHeapNode extractMin();
    void decreaseKey(int vertex, int newKey);
    bool isInMinHeap(int vertex) const;
    bool isEmpty() const;

private:
    MinHeapNode* heapArray;   // Array of (vertex, key) pairs
    int* pos;                 // Maps vertex to its index in heapArray
    int capacity;
    int size;

    void heapifyUp(int idx);
    void heapifyDown(int idx);
};

#endif
