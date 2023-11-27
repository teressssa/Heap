#include "heap.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>

// const int Max = 100000;
using namespace std;
int parent(int i)
{
    return i / 2;
}
int left(int i)
{
    return 2 * i;
}
int right(int i)
{
    return 2 * i + 1;
}
void min_heapify(int A[Max], int i, int n)
{
    int l = left(i);
    int r = right(i);
    int min = i;
    if (l <= n && A[l] < A[i])
    {
        min = l;
    }
    else if (l <= n)
    {
        min = i;
    }
    if (r <= n && A[r] < A[min])
    {
        min = r;
    }
    if (min != i)
    {
        int temp = A[i];
        A[i] = A[min];
        A[min] = temp;
        min_heapify(A, min, n);
    }
}
void build_min_heapify(int A[Max], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        min_heapify(A, i, n);
    }
}

Heap::Heap(int A[Max], int n)
{
    for (int i = 1; i <= n; i++)
    {
        this->A[i] = A[i];
    }
    this->n = n;
}
int Heap::pop()
{
    int min = A[1];
    A[1] = A[n];
    min_heapify(A, 1, n - 1);
    return min;
}
void Heap::push(int x)
{
    A[n + 1] = x;
    build_min_heapify(A, n + 1);
}
int Heap::top()
{
    return A[1];
}
int Heap::size()
{
    return n;
}
void Heap::print()
{
    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
