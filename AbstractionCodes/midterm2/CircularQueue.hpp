

#ifndef Circular_Queue
#define Circular_Queue

#include "console.h"
#include <cstdlib>

using namespace std;

class CircularQueue {
    
    // 0 0 0
    // 1 2 3
    // 1 2 3
    // 0 2 3 // head - 1 tail - 2 // realSize - 2
    // 4 2 3 // head - 1 tail - 0 // realSize - 3
private:
    int *vals;
    int head;
    int tail;
    int realSize;
    int size;
public:
    CircularQueue(int size);
    bool Enqueue(int val);
    int Peek();
    int Dequeue();
    bool IsEmpty();
    bool IsFull();
};


#endif

