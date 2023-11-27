#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "heap.h"
#include <cassert>
using namespace std;
int main()
{
    int k = 1000;
    srand((unsigned)time(NULL));
    int A[Max];
    int B[Max];
    for (int i = 1; i <= k; i++)
    {
        A[i] = rand();
    }
    build_min_heapify(A, k);
    Heap heap(A, k);
    // 测试堆的大小
    assert(heap.size() == k);
    // 测试堆的最小值
    for (int i = 1; i <= k; i++)
    {
        assert(heap.top() <= A[i]);
    }
    // 测试堆的push
    heap.push(-1);
    assert(heap.top() == -1);
    // 测试堆排序
    for (int i = 1; i <= heap.size(); i++)
    {
        B[i] = heap.pop();
    }
    for (int i = 1; i <= heap.size() - 1; i++)
    {
        assert(B[i] <= B[i + 1]);
    }
    return 0;
}
