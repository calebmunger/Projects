#ifndef QUICKQUEUE_H
#define QUICKQUEUE_H
#include <iostream>

using namespace std;

template <typename T>
class QuickQueue {
private:
    T** queue;
    int front;
    int rear;
    int size;
    int capacity;

    void copyFrom(const QuickQueue& other);

public:
    QuickQueue(int capacity = 10);
    QuickQueue(const QuickQueue& other);
    QuickQueue& operator=(const QuickQueue& other);
    ~QuickQueue();

    bool Enqueue(const T& element);
    bool Dequeue(T& element);
    bool isEmpty() const;
    int getSize() const;
};

#endif 
