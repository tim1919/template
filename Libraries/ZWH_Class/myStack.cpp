//#include <myStack.hpp>


template <typename myType>
bool Stack<myType>::initStack_SQ(void)
{
    base = new myType[STACK_INIT_SIZE];
    top = base;
    stacksize = STACK_INIT_SIZE;
    Status = SQ;
    return 1;
}

template <typename myType>
bool Stack<myType>::initStack_link(void)
{
    top_link = new linkNode[1];//头节点
    top_link->next = 0;

    stacksize = 0;
    Status = link;
    return 1;
}

template <typename myType>
bool Stack<myType>::destroyStack(void)
{
    if (Status == SQ)
    {
        delete[] base;
        return 1;
    }
    else if (Status == link)
    {
        while (1)
        {
            if (top_link->next == 0)
                break;
            pop_back();
        }
        delete[] top_link;
        return 1;
    }
    else
    {
        return 0;
    }

}

template <typename myType>
bool Stack<myType>::clear(void)
{
    if (Status == SQ)
    {
        while (1)
        {
            --top;
            if (top == base)
                break;
        }
        return 1;
    }
    else if (Status == link)
    {
        while (1)
        {
            if (top_link->next == 0)
                break;
            pop_back();
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

template <typename myType>
bool Stack<myType>::isEmpty(void)
{
    if (Status == SQ)
        return top == base;
    else if (Status == link)
        return top_link->next == 0;
    else
        return -1;

}

template <typename myType>
int Stack<myType>::length(void)
{
    if (Status == SQ)
        return top - base;
    else if (Status == link)
        return stacksize;
    else
        return 0;
}

template <typename myType>
myType Stack<myType>::getTop(void)
{
    if (isEmpty())
    {
        myType tmp;
        return tmp;
    }
        
    if (Status == SQ)
        return *(top - 1);
    else if (Status == link)
        return top_link->next->data;
    else
    {
        myType tmp;
        return tmp;
    }
}

template <typename myType>
bool Stack<myType>::push_back(myType elem)
{
    if (Status == SQ)
    {
        if (top - base == stacksize - 1)
        {
            base = (myType*)realloc(base, 2 * stacksize * sizeof(myType));
            if (base == 0)
            {
                return 0;
            }
            top = base + stacksize - 1;
            stacksize *= 2;
        }
        (* top) = elem;
        top++;
        return 1;
    }
    else if (Status == link)
    {
        linkNode* tmp = new linkNode[1];
        tmp->data = elem;
        tmp->next = top_link->next;
        top_link->next = tmp;
        ++stacksize;
        return 1;
    }
    else
    {
        return 0;
    }
}

template <typename myType>
myType Stack<myType>::pop_back(void)
{
    if (Status == SQ)
    {
        if (base == top)
        {
            std::cout << "Is empty already!" << std::endl;
            myType tmp;
            return tmp;
        }
        else
        {
            --top;
            return (* top);
        }
    }
    else if (Status == link)
    {
        if (top_link->next == 0)
        {
            myType tmp;
            return tmp;
        }
        else
        {
            linkNode* tmp = top_link->next;
            myType val = tmp->data;
            top_link->next = top_link->next->next;
            delete[] tmp;
            return val;
        }
    }
    else
    {
        myType tmp;
        return tmp;
    }
}

