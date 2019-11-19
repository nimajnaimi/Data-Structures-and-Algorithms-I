#ifndef STACK_QUEUE_H
#define STACK_QUEUE_H

template<class T>
class Queue {
public:
    virtual bool isEmpty() const = 0;

    virtual bool enqueue(const T &) = 0;

    virtual bool dequeue() = 0;

    virtual T peekFront() = 0;

    virtual ~Queue() {};
};

#endif //STACK_QUEUE_H
