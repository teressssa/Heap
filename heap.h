#ifndef HEAP_H
#define HEAP_H

const int Max = 100000;

int parent(int i);
int left(int i);
int right(int i);
void min_heapify(int A[Max], int i, int n);
void build_min_heapify(int A[Max], int n);

class Heap
{
private:
    int A[Max];
    int n;

public:
    Heap(int A[Max], int n);
    int pop();
    void push(int x);
    int top();
    int size();
    void print();
};

#endif