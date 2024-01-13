//
// Created by stan754 on 11/15/23.
//

//#include "Stack.h"
#ifndef STACKSANDQUEUES_STACK_TPP
#define STACKSANDQUEUES_STACK_TPP

template <typename T>
Stack<T>::Stack() {
    stackMeta = new StackMeta<T>;
    stackMeta->stack = nullptr;
    stackMeta->numelem = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& stack) {
    stackMeta = new StackMeta<T>;
    stackMeta->stack = nullptr;
    stackMeta->numelem = 0;

    StackNode<T>* temp = stack.stackMeta->stack;
    while (temp != nullptr) {
        Push(temp->obj);
        temp = temp->next;
    }
}

template <typename T>
Stack<T>::~Stack() {
    while (stackMeta->stack != nullptr) {
        StackNode<T>* temp = stackMeta->stack;
        stackMeta->stack = temp->next;
        delete temp;
    }
    delete stackMeta;
}

template <typename T>
int Stack<T>::Push(const T& obj) {
    StackNode<T>* newNode = new StackNode<T>{obj, stackMeta->stack};
    stackMeta->stack = newNode;
    stackMeta->numelem++;
    return 0;
}

template <typename T>
int Stack<T>::Pop(T& obj) {
    if (stackMeta->numelem == 0 || stackMeta->stack == nullptr){
        return -1;
    }

    StackNode<T>* temp = stackMeta->stack;
    obj = temp->obj;
    stackMeta->stack = temp->next;
    delete temp;
    stackMeta->numelem--;

    return 0;
}

template <typename T>
int Stack<T>::Peek(T& obj) {
    if (stackMeta->numelem == 0 || stackMeta->stack == nullptr){
        return -1;
    }
    obj = stackMeta->stack->obj;

    return 0;
}

template <typename T>
int Stack<T>::NOfElem() {
    return stackMeta->numelem;
}

#endif //STACKSANDQUEUES_STACK_TPP
//template class Stack<int>;