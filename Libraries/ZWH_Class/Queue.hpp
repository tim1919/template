#pragma once

template <typename myType>
class circularQueue
{
public:
    bool init(const int& length);
    bool destroyQueue(void);

    int length(void) const;
    bool isEmpty(void) const;
    bool isFull(void) const;
    bool enQueue(const myType& elem);
    myType deQueue(void);
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
    bool destroyQueue(void);

    int length(void) const;
    bool isEmpty(void) const;
    bool enQueue(const myType& elem);
    myType deQueue(void);
    myType& get_from_front(const int& n);
private:
    struct linkNode
    {
        myType data;
        linkNode* next;
    };
    linkNode* front = 0;
    linkNode* rear = 0;
    int max_size = 0;
};


#include <Queue.cpp>