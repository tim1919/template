template <typename myType>
bool List<myType>::initList_SQ(void)
{
    list = (myType *)malloc(sizeof(myType));
    if (list == 0)
        return 0;

    Status = SQ;
    LENGTH = 0;
    SIZE = 1;
    return 1;
}

template <typename myType>
bool List<myType>::initList_link(void)
{
    Header = (listNode<myType>*)malloc(sizeof(listNode<myType>));//创建一个表头
    
    if (Header == 0)
        return 0;
    Header->next = 0;//初始化表头
    Status = link;
    LENGTH = 0;
    SIZE = 0;
    return 1;
}

template <typename myType>
bool List<myType>::destroyList(void)
{
    if (Status == SQ)
    {
        free(list);
        list = 0;
        SIZE = 0;
        LENGTH = 0;
        return 1;
    }
    else if (Status == link)
    {
        for (int i = 0; i < LENGTH; ++i)
        {
            deleteElem(0);
        }
        free(Header);
        Header = 0;
        SIZE = 0;
        LENGTH = 0;
        return 1;
    }
}


template <typename myType>
bool List<myType>::clearList(void)
{
    if (Status == SQ)
    {}
    else if (Status == link)
    {
        if (LENGTH == 0)
        {
            return 1;
        }
        else
        {
            listNode<myType>* p = Header;
            for (int i = 0; i < LENGTH; ++i)
            {
                p = p->next;
                p->data = 0;
            }
        }
        
    }
}


template <typename myType>
bool List<myType>::isEmpty(void)
{
    if (LENGTH == 0)
        return 1;
    else
        return 0;
}

template <typename myType>
int List<myType>::length(void)
{
    return LENGTH;
}

template <typename myType>
myType List<myType>::getElem(int i)
{
    if (i < 0 || i >= LENGTH)
    {
        return 0;
    }
    else
    {
        if (Status == SQ)
        {
            return list[i];
        }
        else
        {
            listNode<myType>* p = Header->next;
            for (int j = 0; j < i; ++j)
            {
                p = p->next;
            }
            return p->data;
        }
    }
}

template <typename myType>
myType& List<myType>::getElem_link(int i)
{
    listNode<myType>* ptr = Header;
    for (int j = 0; j <= i; ++j)
    {
        if (ptr->next == 0)
        {
            std::cout << "out of scope" << std::endl;
            return Header->data;
        }    
        ptr = ptr->next;
    }
    return ptr->data;
}

template <typename myType>
myType List<myType>::priorElem(int i)
{
    if (i <= 0 || i >= LENGTH)
    {
        return 0;
    }
    else
    {
        return getElem(i - 1);
    }
}


template <typename myType>
bool List<myType>::insertElem(int i, myType elem)
{
    if (i < 0 || i > LENGTH)
    {
        std::cout << "Out of scope!" << std::endl;
        return 0;
    }

    if (Status == SQ)
    {
        if (SIZE == LENGTH)
        {
            list = (myType*)realloc(list, 2 * SIZE * sizeof(myType));
            SIZE *= 2;
        }

        for (int j = LENGTH - 1; j >= i; --j)
        {
            list[j + 1] = list[j];
        }

        list[i] = elem;
        ++LENGTH;

    }
    else if (Status == link)
    {
        listNode<myType>* p = Header;
        for (int j = 0; j < i; ++j)
        {
            p = p->next;
        }
        listNode<myType>* tmp = (listNode<myType>*)malloc(sizeof(listNode<myType>));
        tmp->data = elem;
        if (i == LENGTH - 1)
        {
            tmp->next = 0;
        }
        else
        {
            tmp->next = p->next;//有问题
        }
        p->next = tmp;
        ++SIZE;
        ++LENGTH;
    }
    return 1;
}

template <typename myType>
bool List<myType>::push_back_link(const myType& elem)
{
    listNode<myType>* ptr = Header;
    while (1)
    {
        if (0 == ptr->next)
        {
            break;
        }
        ptr = ptr->next;
    }
    listNode<myType>* tmp = (listNode<myType>*)malloc(sizeof(listNode<myType>));
    tmp->data = elem;
    tmp->next = 0;
    ptr->next = tmp;
    ++SIZE;
    ++LENGTH;
    return 1;
}

template <typename myType>
bool List<myType>::deleteElem(int i)
{
    if (i < 0 || i >= LENGTH)
    {
        std::cout << "Out of scope!" << std::endl;
        return 0;
    }

    if (Status == SQ)
    {
        for (int j = i; j < LENGTH - 1; ++j)
        {
            list[j] = list[j + 1];
        }
        --LENGTH;
        return 1;
    }
    else if (Status == link)
    {
        listNode<myType>* p = Header;
        for (int k = 0; k < i; ++k)
        {
            p = p->next;
        }
        listNode<myType>* tmp = p->next;
        p->next = p->next->next;
        free(tmp);
        tmp = 0;
        --SIZE;
        --LENGTH;
        return 1;
    }
}

template <typename myType>
listNode<myType>* List<myType>::getPtr_link(const int& i)
{
    listNode<myType>* ptr = Header->next;
    int count = 0;
    while (1)
    {
        if (0 == ptr)
        {
            std::cout << "error! out of scope! (from List.cpp/getPtr_link)" << std::endl;
            return 0;
        }

        if (count == i)
        {
            break;
        }

        ptr = ptr->next;
        ++count;
    }
    return ptr;
}
