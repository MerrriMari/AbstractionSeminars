
#include "CircularQueue.hpp"

#include "simpio.h"
#include "foreach.h"
#include "console.h"
#include <iostream>
#include <string>
using namespace std;

CircularQueue::CircularQueue(int size) {
    vals = new int[size];
    this -> size = size;
    realSize = 0;
    head = 0;
    tail = 0;
}

bool CircularQueue::Enqueue(int val) {
    // 0 0 0
    // 0 2 0 // tail - 2
    // 0 2 3 // tail - (2 + 1) % 3 - 0
    if(IsFull()) return false;
    vals[tail] = val;
    tail = (tail + 1) % size;
    realSize ++;
    return true;
}

int CircularQueue::Peek() {
    return vals[head];
}

int CircularQueue::Dequeue() {
    // 0 0 3 // head - (2 + 1) % 3 - 0
    int val = Peek();
    head = (head + 1) % size;
    realSize --;
    return val;
}

bool CircularQueue::IsEmpty() {
    return realSize == 0;
}

bool CircularQueue::IsFull() {
    return realSize == size;
}
