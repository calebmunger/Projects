#include "QuickQueue.h"
#include <iostream>
using namespace std;
template <typename T>
void QuickQueue<T>::copyFrom(const QuickQueue& other) 
{
    capacity = other.capacity;
    size = other.size;
    front = other.front;
    rear = other.rear;
    queue = new T*[capacity];
    for (int i = 0; i < capacity; ++i) {
        if (other.queue[i] != nullptr) {
            queue[i] = new T(*other.queue[i]);
        } else {
            queue[i] = nullptr;
        }
    }
}

template <typename T>
QuickQueue<T>::QuickQueue(int capacity)
{
    front = 0;
    rear = -1;
    size = 0;
    this->capacity=capacity;
    queue = new T*[capacity];
    for (int i = 0; i < capacity; ++i) 
    {
        queue[i] = nullptr;
    }
}

template <typename T>
QuickQueue<T>::QuickQueue(const QuickQueue& other) 
{
    copyFrom(other);
}

template <typename T>
QuickQueue<T>& QuickQueue<T>::operator=(const QuickQueue& other) 
{
    if (this != &other) 
    {
        for (int i = 0; i < capacity; ++i) 
        {
            delete queue[i];
        }
        delete[] queue;
        copyFrom(other);
    }
    return *this;
}

template <typename T>
QuickQueue<T>::~QuickQueue() {
    for (int i = 0; i < capacity; ++i) {
        delete queue[i];
    }
    delete[] queue;
}

template <typename T>
bool QuickQueue<T>::Enqueue(const T& element) 
{
    if (size == capacity) 
    {
        cerr << "Error: Queue is full" << endl;
        return false;
    }
    rear = (rear + 1) % capacity;
    queue[rear] = new T(element);
    ++size;
    return true;
}

template <typename T>
bool QuickQueue<T>::Dequeue(T& element) 
{
    if (size == 0) 
    {
        cerr << "Error: Queue is empty" << endl;
        return false;
    }
    element = *queue[front];
    delete queue[front];
    queue[front] = nullptr;
    front = (front + 1) % capacity;
    --size;
    return true;
}

template <typename T>
bool QuickQueue<T>::isEmpty() const 
{
    return size == 0;
}

template <typename T>
int QuickQueue<T>::getSize() const 
{
    return size;
}

int main() 
{
    QuickQueue<int> intQueue;

    for (int i = 1; i <= 5; ++i) 
    {
        if (intQueue.Enqueue(i)) 
        {
            cout << "Enqueued: " << i << endl;
        }
    }

    int value;
    for (int i = 1; i <= 5; ++i) 
    {
        if (intQueue.Dequeue(value)) 
        {
            cout << "Dequeued: " << value << endl;
        }
    }

    QuickQueue<string> stringQueue;


    stringQueue.Enqueue("one");
    stringQueue.Enqueue("two");
    stringQueue.Enqueue("three");
    stringQueue.Enqueue("four");
    stringQueue.Enqueue("five");

    cout << endl;


    string strValue;
    for (int i = 1; i <= 5; ++i) {
        if (stringQueue.Dequeue(strValue)) {
            cout << "Dequeued: " << strValue << endl;
        }
    }

    return 0;
}
