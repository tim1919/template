template <typename myType>
circularQueue<myType>::circularQueue(const int& n)
{
    arr = new myType[n + 1];
    front = 0;
    rear = 0;
    max_size = n + 1;
}

template <typename myType>
circularQueue<myType>::~circularQueue(void)
{
    delete[] arr;
}

template <typename myType>
int circularQueue<myType>::length(void) const
{
    return (rear - front + max_size) % max_size;
}

template <typename myType>
bool circularQueue<myType>::isEmpty(void) const
{
    return rear == front;
}

template <typename myType>
bool circularQueue<myType>::isFull(void) const
{
    return (rear + 1) % max_size == front;
}

template <typename myType>
bool circularQueue<myType>::enqueue(const myType& elem)
{
    if (isFull())
    {
        std::cout << "Full already!" << std::endl;
        return 0;
    }
    else
    {
        arr[rear] = elem;
        rear = (rear + 1) % max_size;
        return 1;
    }
}

template <typename myType>
myType circularQueue<myType>::dequeue(void)
{
    if (length() == 0)
    {
        myType tmp;
        return tmp;
    }
    else
    {
        myType tmp = arr[front];
        arr[front] = 0;
        front = (front + 1) % max_size;
        return tmp;
    }
}

template <typename myType>
myType& circularQueue<myType>::operator[](const int& n)
{
    // if (n + 1 >= length() || n < 0)
    // {
    //     std::cout << "Out of scope!" << std::endl;
    //     return arr[rear];
    // }
    // else
    // {
        return arr[(front + n) % max_size];
    // }
}

template <typename myType>
myType& circularQueue<myType>::get(const int& n) const
{
    return arr[(rear + max_size - n) % max_size];
}

template <typename myType>
bool circularQueue<myType>::clear(void)
{
    while (!isEmpty())
    {
        dequeue();
    }
    return 1;
}

template <typename myType>
bool circularQueue<myType>::remove(const int& n)
{
    if (n < 0)
    {
        std::cout << "Num of remove error!" << std::endl;
        return 0;
    }
    else if (n >= length())
    {
        clear();
    }
    else
    {
        for (int tmp = 0; tmp < n; ++tmp)
        {
            dequeue();
        }
    }
}


//下面是链队列

template <typename myType>
bool linkQueue<myType>::initQueue(void)
{
    front = new linkNode[1];
    rear = front;
    front->next = 0;
    return 1;
}

template <typename myType>
bool linkQueue<myType>::enQueue(myType elem)
{
    linkNode* tmp = new linkNode[1];
    rear->next = tmp;
    rear = tmp;
    rear->data = elem;
    rear->next = 0;
    return 1;
}

template <typename myType>
myType linkQueue<myType>::deQueue(void)
{
    if (front == rear)
    {
        myType tmp;
        return tmp;
    }
    else
    {
        linkNode* tmp = front->next;
        myType val = front->next->next;
        front->next = front->next->next;
    }
}