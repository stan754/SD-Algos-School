//
// Created by stan754 on 11/15/23.
//

#ifndef STACKSANDQUEUES_QUEUE_TPP
#define STACKSANDQUEUES_QUEUE_TPP

template<typename T>
Queue<T>::Queue() {
    queueMeta = new QueueMeta<T>;
    queueMeta->stack_in = new Stack<T>;
    queueMeta->stack_out = new Stack<T>;
}

template<typename T>
Queue<T>::Queue(Stack<T> stack) {
    queueMeta = new QueueMeta<T>;
    queueMeta->stack_in = new Stack<T>(stack);
    queueMeta->stack_out = new Stack<T>;
}

template<typename T>
Queue<T>::~Queue() {
    delete queueMeta->stack_in;
    delete queueMeta->stack_out;
    delete queueMeta;
}


template<typename T>
int Queue<T>::Enqueue(const T &obj) {
    queueMeta->stack_in->Push(obj);
    return 0;
}

template<typename T>
int Queue<T>::Dequeue(T &obj) {
    if (queueMeta->stack_out->NOfElem() == 0) {
        T temp;
        while (queueMeta->stack_in->NOfElem() != 0) {
            queueMeta->stack_in->Pop(temp);
            queueMeta->stack_out->Push(temp);
        }
    }

    queueMeta->stack_out->Pop(obj);
    return 0;
}

#endif //STACKSANDQUEUES_QUEUE_TPP
