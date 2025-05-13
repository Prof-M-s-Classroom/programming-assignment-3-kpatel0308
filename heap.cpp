#include "heap.h"
#include <climits>
#include <algorithm>

MinHeap::MinHeap(int cap) : size(0), capacity(cap) {
    heapArray = new MinHeapNode[cap];
    pos = new int[cap];
}

MinHeap::~MinHeap() {
    delete[] heapArray;
    delete[] pos;
}

bool MinHeap::isEmpty() const {
    return size == 0;
}

void MinHeap::heapifyUp(int idx) {
    while (idx && heapArray[idx].key < heapArray[(idx - 1) / 2].key) {
        std::swap(heapArray[idx], heapArray[(idx - 1) / 2]);
        pos[heapArray[idx].vertex] = idx;
        pos[heapArray[(idx - 1) / 2].vertex] = (idx - 1) / 2;
        idx = (idx - 1) / 2;
    }
}

void MinHeap::heapifyDown(int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && heapArray[left].key < heapArray[smallest].key)
        smallest = left;

    if (right < size && heapArray[right].key < heapArray[smallest].key)
        smallest = right;

    if (smallest != idx) {
        std::swap(heapArray[smallest], heapArray[idx]);
        pos[heapArray[smallest].vertex] = smallest;
        pos[heapArray[idx].vertex] = idx;
        heapifyDown(smallest);
    }
}

void MinHeap::insertKey(int v, int key) {
    heapArray[size] = {v, key};
    pos[v] = size;
    heapifyUp(size);
    size++;
}

MinHeapNode MinHeap::extractMin() {
    MinHeapNode root = heapArray[0];
    heapArray[0] = heapArray[size - 1];
    pos[heapArray[0].vertex] = 0;
    size--;
    heapifyDown(0);
    return root;
}

void MinHeap::decreaseKey(int v, int key) {
    int i = pos[v];
    heapArray[i].key = key;
    heapifyUp(i);
}

bool MinHeap::isInMinHeap(int v) const {
    return pos[v] < size;
}
