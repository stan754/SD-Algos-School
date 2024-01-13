//
// Created by stan754 on 11/15/23.
//

#ifndef STACKSANDQUEUES_STACK_H
#define STACKSANDQUEUES_STACK_H

template <typename T>
class StackNode {
public:
    T obj;
    StackNode* next;
};

template <typename T>
class StackMeta {
public:
    StackNode<T>* stack;
    int numelem;
};

template <typename T>
class Stack {
private:
    StackMeta<T>* stackMeta;

public:
    Stack();
    Stack(const Stack<T> &stack);
    ~Stack();

    int Push(const T& obj);
    int Pop(T& obj);
    int Peek(T& obj);
    int NOfElem();
};

#include "Stack.tpp"

#endif //STACKSANDQUEUES_STACK_H

