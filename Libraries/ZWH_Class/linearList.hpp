#pragma once
#include <stdlib.h>

template <typename myType>
class List
{
public:
    bool initList_SQ(void);
    bool initList_link(void);
    bool destroyList(void);
    bool clearList(void);
    bool isEmpty(void);
    int length(void);
    myType getElem(int i);
    myType priorElem(int i);
    bool insertElem(int i, myType elem);
    bool deleteElem(int i);

private:
    int SIZE = 0; // size of the list
    int LENGTH = 0;
    myType* list; // pointer to the list

    struct listNode
    {
        myType data;
        listNode* next;
    } *Header;

    enum 
    {
        SQ = 0, link
    } Status;
};

#include <linearList.cpp>