#pragma once

template <typename myType>
class circularQueue
{
public:
    circularQueue(const int& n);
    ~circularQueue(void);

    int length(void) const;
    bool isEmpty(void) const;
    bool isFull(void) const;
    bool enqueue(const myType& elem);
    myType dequeue(void);
    myType& get(const int& n) const;
    bool clear(void);
    bool remove(const int& n);

    myType& operator[](const int& n);
private:
    myType* arr;
    int front;
    int rear;

    int max_size;
};

template <typename myType>
class linkQueue
{
public:
    bool initQueue(void);
    bool enQueue(myType elem);
    myType deQueue(void);
private:
    struct linkNode
    {
        myType data;
        linkNode* next;
    };
    linkNode* front;
    linkNode* rear;
};


#include <Queue.cpp>