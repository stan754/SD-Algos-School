//
// Created by stan754 on 11/15/23.
//

#ifndef STACKSANDQUEUES_QUEUE_H
#define STACKSANDQUEUES_QUEUE_H
#include "../Stacks/Stack.h"

template <typename T>
class QueueMeta {
public:
    Stack<T>* stack_in;
    Stack<T>* stack_out;
};

template <typename T>
class Queue {
private:
    QueueMeta<T>* queueMeta;

public:
    Queue();
    explicit Queue(Stack<T> stack);
    ~Queue();

    int Enqueue(const T& obj);
    int Dequeue(T& obj);
};

#include "Queue.tpp"

#endif //STACKSANDQUEUES_QUEUE_H
