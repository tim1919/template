
template <typename T>
bool Graph<T>::DFS_recurse(const int& function, const int& index)
{
    func(function, index);
    DFS_isVisited[index] = 1;
    // std::cout << index << "func" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        if (0 != Edge[index][i] && __FLT_MAX__ != Edge[index][i] && 0 == DFS_isVisited[i])
        {
            // std::cout << index << "recurse" << std::endl;
            DFS_recurse(function, i);
        }
    }

    return 1;
}

template <typename T>
Graph<T>::~Graph(void)
{}

template <typename T>
bool Graph<T>::init_MGraph(const int& size)
{
    Vex = new T[size];

    Edge = new float*[size];
    for (int i = 0; i < size; ++i)
    {
        Edge[i] = new float[size];
    }

    for (int i = 0; i < size; ++i)
    {
        //Vex[i] = 0;
        for (int k = 0; k < sizeof(T); ++k)
        {
            Vex[i] &= ~(1 << k);
        }
        for (int j = 0; j < size; ++j)
        {
            Edge[i][j] = 0;
        }
    }

    // DFS_isVisited = new bool[size];

    this->size = size;

    return 1;
}

template <typename T>
bool Graph<T>::init_ALGraph(const int& size)
{
    AdjList = new VNode<T>*[size];
    for (int i = 0; i < size; ++i)
    {
        AdjList[i].first = 0;
        for (int j = 0; j < sizeof(T); ++j)
        {
            AdjList[i].data &= ~(1 << j);
        }
    }

    // DFS_isVisited = new bool[size];

    this->size = size;

    return 1;
}


template <typename T>
bool Graph<T>::create_MGraph(bool isYOUXIANG, bool isDAIQUAN)
{
#define YOUXIANG 1
#define WUXIANG 0
#define DAIQUAN 1
#define WUQUAN 0

    std::cout << "pls enter your data([index] [data]), press -1 to quit: " << std::endl;

    int index;

    while (1)
    {
        std::cin >> index;

        if (-1 == index)
        {
            break;
        }

        std::cin >> Vex[index];
    }


    int index_1, index_2;
    float weight;

    if (0 == isYOUXIANG && 0 == isDAIQUAN)
    {
        std::cout << "pls enter edges(from [where] to [where]), press -1 to quit: " << std::endl;

        while (1)
        {
            std::cin >> index_1;

            if (-1 == index_1)
            {
                break;
            }

            std::cin >> index_2;

            Edge[index_1][index_2] = 1;
            Edge[index_2][index_1] = 1;
        }
    }
    else if (0 == isYOUXIANG && 1 == isDAIQUAN)
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                Edge[i][j] = __FLT_MAX__;
            }
        }

        std::cout << "pls enter edges(from [where] to [where]) and [weight], press -1 to quit: " << std::endl;
        
        while (1)
        {
            std::cin >> index_1;

            if (-1 == index_1)
            {
                break;
            }

            std::cin >> index_2;
            std::cin >> weight;

            Edge[index_1][index_2] = weight;
            Edge[index_2][index_1] = weight;
        }


    }
    else if (1 == isYOUXIANG && 0 == isDAIQUAN)
    {
        std::cout << "pls enter edges(from [where] to [where]), press -1 to quit: " << std::endl;

        while (1)
        {
            std::cin >> index_1;

            if (-1 == index_1)
            {
                break;
            }

            std::cin >> index_2;

            Edge[index_1][index_2] = 1;
        }

    }
    else if (1 == isYOUXIANG && 1 == isDAIQUAN)
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                Edge[i][j] = __FLT_MAX__;
            }
        }

        std::cout << "pls enter edges(from [where] to [where]) and [weight], press -1 to quit: " << std::endl;
        
        while (1)
        {
            std::cin >> index_1;

            if (-1 == index_1)
            {
                break;
            }

            std::cin >> index_2;
            std::cin >> weight;

            Edge[index_1][index_2] = weight;
        }
    }

    return 1;
}

template <typename T>
bool Graph<T>::DFS(const int& function)
{
    DFS_isVisited = new bool[size];

    for (int i = 0; i < size; ++i)//初始化辅助数组
    {
        DFS_isVisited[i] = 0;
    }

    for (int j = 0; j < size; ++j)//为了遍历所有连通分量
    {
        if (0 == DFS_isVisited[j])
        {
            DFS_recurse(function, j);
        }
    }

    delete[] DFS_isVisited;
    return 1;
}

template <typename T>
bool Graph<T>::BFS(const int& function, const int& num)
{
    BFS_isVisited = new bool[size];

    for (int i = 0; i < size; ++i)//初始化辅助数组
    {
        BFS_isVisited[i] = 0;
    }
    linkQueue<int> myQueue;
    myQueue.initQueue();//队列初始化

    for (int i = 0; i < size; ++i)
    {
        if (0 == BFS_isVisited[num])
        {
            func(function, num);
            BFS_isVisited[num] = 1;
            myQueue.enQueue(num);
            while (1)
            {
                if (myQueue.isEmpty())
                {
                    break;
                }

                for (int j = 0; j < size; ++j)//队头下崽，崽入队，置标志位
                {
                    if (0 != Edge[myQueue.get_from_front(0)][j] && __FLT_MAX__ != Edge[myQueue.get_from_front(0)][j] && 0 == BFS_isVisited[j])
                    {
                        // std::cout << "enqueue:" << k << std::endl;
                        func(function, j);
                        BFS_isVisited[j] = 1;
                        myQueue.enQueue(j);
                    }
                }

                myQueue.deQueue();
            }
        }
    }

    myQueue.destroyQueue();
    delete[] BFS_isVisited;
    return 1;
}

template <typename T>
T* Graph<T>::func(const int& function, const int& index)
{
#define PRINTF_GRAPH 0
#define SCANF_GRAPH 1
#define GET_PTR_GRAPH 2
    T* ptr = 0;
    switch (function)
    {
        case PRINTF_GRAPH:
        {
            std::cout << Vex[index] << std::endl;
            break;
        }
        case SCANF_GRAPH:
        {
            std::cin >> Vex[index];
            break;
        }
        case GET_PTR_GRAPH:
        {
            ptr = &(Vex[index]);
            break;
        }
    }
    return ptr;
}