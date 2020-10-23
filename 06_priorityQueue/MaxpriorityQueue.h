#ifndef MAX_PRIORITY_QUEUE_H
#define MAX_PRIORITY_QUEUE_H

#include "../05_heap/heap.h"

template<class T>
class MaxpriorityQueue : private heap<T>
{
private:
    /* data */
public:
    MaxpriorityQueue(int capacity):heap<T>(capacity){
    }
    ~MaxpriorityQueue(){}
    void enqueue(T t){
        heap<T>::insert(t);
    }

    T dequeue(){
        return heap<T>::delMax();
    }

    bool isEmpty(){
        return heap<T>::isEmpty();
    }
};


#endif
