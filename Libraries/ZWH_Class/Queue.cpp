template <typename myType>
bool circularQueue<myType>::init(const int& length)
{
    arr = new myType[length + 1];
    front = 0;
    rear = 0;
    max_size = length + 1;
    return 1;
}

template <typename myType>
bool circularQueue<myType>::destroyQueue(void)
{
    delete[] arr;
    return 1;
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
bool circularQueue<myType>::enQueue(const myType& elem)
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
myType circularQueue<myType>::deQueue(void)
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
        deQueue();
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
            deQueue();
        }
    }
}


//下面是链队列

template <typename myType>
bool linkQueue<myType>::initQueue(void)
{
    front = new linkNode[1];// 头结点
    rear = front;
    front->next = 0;
    max_size = 0;
    return 1;
}

template <typename myType>
bool linkQueue<myType>::destroyQueue(void)
{
    while (1)
    {
        if (front == rear)
            break;
        
        deQueue();
    }
    delete[] front;
    return 1;
}

template <typename myType>
int linkQueue<myType>::length(void) const
{
    return max_size;
}

template <typename myType>
bool linkQueue<myType>::isEmpty(void) const
{
    return front == rear;
}

template <typename myType>
bool linkQueue<myType>::enQueue(const myType& elem)
{
    if (0 == front)
    {
        std::cout << "Queue hasn't been initialized!" << std::endl;
        return 0;
    }

    linkNode* tmp = new linkNode[1];
    rear->next = tmp;
    rear = tmp;
    rear->data = elem;
    rear->next = 0;
    ++max_size;
    return 1;
}

template <typename myType>
myType linkQueue<myType>::deQueue(void)
{
    myType tmp;
    if (0 == front)
    {
        std::cout << "Queue hasn't been initialized!" << std::endl;
        return tmp;
    }
    else if (front == rear)
    {
        std::cout << "Queue is empty!" << std::endl;
        return tmp;
    }
    
    
    linkNode* ptr = front->next;
    tmp = ptr->data;
    if (ptr != rear)
    {
        front->next = ptr->next;
    }
    else
    {
        front->next = 0;
        rear = front;
    }

    delete[] ptr;
    --max_size;
    return tmp;
}

template <typename myType>
myType& linkQueue<myType>::get_from_front(const int& n)
{
    if (n + 1 > max_size)
    {
        std::cout << "Index out of range!" << std::endl;
        return front->data;
    }

    linkNode* ptr = front->next;
    for (int i = 0; i < n; ++i)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}