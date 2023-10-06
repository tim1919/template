#pragma once
#include <cstdlib>
#include <string.h>

#define STACK_INIT_SIZE 1


//注意：链栈没有栈底指针！！！
template <typename myType>
class Stack
{
public:
    // Stack(void);
    // ~Stack(void);
    bool initStack_SQ(void);
    bool initStack_link(void);
    bool destroyStack(void);
    bool clear(void);
    bool isEmpty(void);
    int length(void);
    myType getTop(void);
    bool push_back(myType elem);
    myType pop_back(void);

private:
    enum 
    {
        initial = 0, SQ, link
    } Status = initial;

    myType* base = 0;
    myType* top = 0;
    int stacksize = 0;

    struct linkNode
    {
        myType data;
        linkNode* next;
    } *top_link;
};



#include <Stack.cpp>