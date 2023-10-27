
template <typename T>
bool Graph<T>::DFS_recurse(const int& function, const int& index, float** const& Edge)
{
    func(function, index);
    DFS_isVisited[index] = 1;
    // std::cout << index << "func" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        if (0 != Edge[index][i] && __FLT_MAX__ != Edge[index][i] && 0 == DFS_isVisited[i])
        {
            // std::cout << index << "recurse" << std::endl;
            DFS_recurse(function, i, Edge);
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
    AdjList = new VNode<T>[size];
    for (int i = 0; i < size; ++i)
    {
        AdjList[i].first = 0;
        for (int j = 0; j < sizeof(T); ++j)
        {
            AdjList[i].data &= ~(1 << j);
        }
    }//初始化顶点表

    // DFS_isVisited = new bool[size];

    this->size = size;

    return 1;
}


template <typename T>
bool Graph<T>::create_MGraph(bool isYOUXIANG, bool isDAIQUAN)
{


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
bool Graph<T>::create_ALGraph(bool isYOUXIANG, bool isDAIQUAN)
{


    std::cout << "pls enter your data([index] [data]), press -1 to quit: " << std::endl;

    int index;

    while (1)
    {
        std::cin >> index;

        if (-1 == index)
        {
            break;
        }

        std::cin >> AdjList[index].data;
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

            // Edge[index_1][index_2] = 1;
            // Edge[index_2][index_1] = 1;
            if (0 == AdjList[index_1].first)
            {
                AdjList[index_1].first = new ArcNode[1];
                (AdjList[index_1].first)->adjvex = index_2;
                (AdjList[index_1].first)->next = 0;
                (AdjList[index_1].first)->weight = __FLT_MAX__;
            }
            else
            {
                ArcNode* ptr = AdjList[index_1].first;
                while (1)
                {
                    if (0 == ptr->next)
                    {
                        break;
                    }

                    ptr = ptr->next;
                }
                ptr->next = new ArcNode[1];
                ptr->next->adjvex = index_2;
                ptr->next->next = 0;
                ptr->next->weight = __FLT_MAX__;
            }

            if (0 == AdjList[index_2].first)
            {
                AdjList[index_2].first = new ArcNode[1];
                (AdjList[index_2].first)->adjvex = index_1;
                (AdjList[index_2].first)->next = 0;
                (AdjList[index_2].first)->weight = __FLT_MAX__;
            }
            else
            {
                ArcNode* ptr = AdjList[index_2].first;
                while (1)
                {
                    if (0 == ptr->next)
                    {
                        break;
                    }

                    ptr = ptr->next;
                }
                ptr->next = new ArcNode[1];
                ptr->next->adjvex = index_1;
                ptr->next->next = 0;
                ptr->next->weight = __FLT_MAX__;
            }
        }
    }
    else if (0 == isYOUXIANG && 1 == isDAIQUAN)
    {
        // for (int i = 0; i < size; ++i)
        // {
        //     for (int j = 0; j < size; ++j)
        //     {
        //         Edge[i][j] = __FLT_MAX__;
        //     }
        // }

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

            // Edge[index_1][index_2] = weight;
            // Edge[index_2][index_1] = weight;
            if (0 == AdjList[index_1].first)
            {
                AdjList[index_1].first = new ArcNode[1];
                (AdjList[index_1].first)->adjvex = index_2;
                (AdjList[index_1].first)->next = 0;
                (AdjList[index_1].first)->weight = weight;
                // std::cout << "index_2 = " << (AdjList[index_1].first)->adjvex << std::endl;
            }
            else
            {
                ArcNode* ptr = AdjList[index_1].first;
                while (1)
                {
                    if (0 == ptr->next)
                    {
                        break;
                    }

                    ptr = ptr->next;
                }
                ptr->next = new ArcNode[1];
                ptr->next->adjvex = index_2;
                ptr->next->next = 0;
                ptr->next->weight = weight;
                // std::cout << "ptr->next->adjvex is " << ptr->next->adjvex << std::endl;
            }

            if (0 == AdjList[index_2].first)
            {
                AdjList[index_2].first = new ArcNode[1];
                (AdjList[index_2].first)->adjvex = index_1;
                (AdjList[index_2].first)->next = 0;
                (AdjList[index_2].first)->weight = weight;
            }
            else
            {
                ArcNode* ptr = AdjList[index_2].first;
                while (1)
                {
                    if (0 == ptr->next)
                    {
                        break;
                    }

                    ptr = ptr->next;
                }
                ptr->next = new ArcNode[1];
                ptr->next->adjvex = index_1;
                ptr->next->next = 0;
                ptr->next->weight = weight;
            }
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

            // Edge[index_1][index_2] = 1;
            if (0 == AdjList[index_1].first)
            {
                AdjList[index_1].first = new ArcNode[1];
                (AdjList[index_1].first)->adjvex = index_2;
                (AdjList[index_1].first)->next = 0;
                (AdjList[index_1].first)->weight = __FLT_MAX__;
            }
            else
            {
                ArcNode* ptr = AdjList[index_1].first;
                while (1)
                {
                    if (0 == ptr->next)
                    {
                        break;
                    }

                    ptr = ptr->next;
                }
                ptr->next = new ArcNode[1];
                ptr->next->adjvex = index_2;
                ptr->next->next = 0;
                ptr->next->weight = __FLT_MAX__;
            }

        }

    }
    else if (1 == isYOUXIANG && 1 == isDAIQUAN)
    {
        // for (int i = 0; i < size; ++i)
        // {
        //     for (int j = 0; j < size; ++j)
        //     {
        //         Edge[i][j] = __FLT_MAX__;
        //     }
        // }

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

            // Edge[index_1][index_2] = weight;
            if (0 == AdjList[index_1].first)
            {
                AdjList[index_1].first = new ArcNode[1];
                (AdjList[index_1].first)->adjvex = index_2;
                (AdjList[index_1].first)->next = 0;
                (AdjList[index_1].first)->weight = weight;
            }
            else
            {
                ArcNode* ptr = AdjList[index_1].first;
                while (1)
                {
                    if (0 == ptr->next)
                    {
                        break;
                    }

                    ptr = ptr->next;
                }
                ptr->next = new ArcNode[1];
                ptr->next->adjvex = index_2;
                ptr->next->next = 0;
                ptr->next->weight = weight;
            }

        }
    }

    return 1;
}


template <typename T>
float**& Graph<T>::get_Edge(void)
{
    return Edge;
}

template <typename T>
float**& Graph<T>::get_MST(void)
{
    return MST;
}
template <typename T>
T*& Graph<T>::get_Vex(void)
{
    return Vex;
}

template <typename T>
bool Graph<T>::DFS(const int& function, const int& num, float** const& Edge)
{
    DFS_isVisited = new bool[size];

    for (int i = 0; i < size; ++i)//初始化辅助数组
    {
        DFS_isVisited[i] = 0;
    }

    DFS_recurse(function, num, Edge);
    for (int j = 0; j < size; ++j)//为了遍历所有连通分量
    {
        if (0 == DFS_isVisited[j])
        {
            DFS_recurse(function, j, Edge);
        }
    }

    delete[] DFS_isVisited;
    return 1;
}

template <typename T>
bool Graph<T>::BFS(const int& function, const int& num, float** const& Edge)
{
    BFS_isVisited = new bool[size];
    for (int i = 0; i < size; ++i)//初始化辅助数组
    {
        BFS_isVisited[i] = 0;
    }
    linkQueue<int> myQueue;
    myQueue.initQueue();//队列初始化

    func(function, num);
    BFS_isVisited[num] = 1;
    myQueue.enQueue(num);

    while (1)
    {
        if (myQueue.isEmpty())
        {
            break;
        }

        int index = myQueue.deQueue();

        for (int j = 0; j < size; ++j)
        {
            // std::cout << "dis from "<<index<<" to "<<j<<" is "<<Edge[index][j] <<std::endl;
            if (0 != Edge[index][j] && __FLT_MAX__ != Edge[index][j] && 0 == BFS_isVisited[j])
            {
                func(function, j);
                BFS_isVisited[j] = 1;
                myQueue.enQueue(j);
            }
        }
    }

    myQueue.destroyQueue();
    delete[] BFS_isVisited;
    return 1;
    /////////////////////////////

    // for (int i = 0; i < size; ++i)
    // {
    //     if (0 == BFS_isVisited[num])
    //     {
    //         func(function, num);
    //         BFS_isVisited[num] = 1;
    //         myQueue.enQueue(num);
    //         while (1)
    //         {
    //             if (myQueue.isEmpty())
    //             {
    //                 break;
    //             }

    //             for (int j = 0; j < size; ++j)//队头下崽，崽入队，置标志位
    //             {
    //                 if (0 != Edge[myQueue.get_from_front(0)][j] && __FLT_MAX__ != Edge[myQueue.get_from_front(0)][j] && 0 == BFS_isVisited[j])
    //                 {
    //                     // std::cout << "enqueue:" << k << std::endl;
    //                     func(function, j);
    //                     BFS_isVisited[j] = 1;
    //                     myQueue.enQueue(j);
    //                 }
    //             }

    //             myQueue.deQueue();
    //         }
    //     }
    // }

    // myQueue.destroyQueue();
    // delete[] BFS_isVisited;
    // return 1;
}

template <typename T>
bool Graph<T>::Prim(const int& num)
{
    MST = new float*[size];
    for (int i = 0; i < size; ++i)
    {
        MST[i] = new float[size];
        for (int j = 0; j < size; ++j)
        {
            MST[i][j] = __FLT_MAX__;
        }
    }//最小生成树初始化

    struct
    {
        int adjvex = 0;//U集中的顶点
        float dis_min = __FLT_MAX__;
    } closedge[size];

    closedge[num].adjvex = num;
    closedge[num].dis_min = 0;
    for (int i = 0; i < size; ++i)
    {
        if (0 != closedge[i].dis_min)
        {
            closedge[i].adjvex = num;
            closedge[i].dis_min = Edge[num][i];
        }
    }//辅助数组初始化

    for (int n = 0; n < size - 1; ++n)
    {
        int tmp_index = 0;
        float tmp_dis = __FLT_MAX__;
        for (int i = 0; i < size; ++i)//在 U - V 集合里找到最短距离的最小值
        {
            if (0 != closedge[i].dis_min)//在 U - V 集合里找
            {
                if (tmp_dis > closedge[i].dis_min)
                {
                    tmp_index = i;
                    tmp_dis = closedge[i].dis_min;
                }
            }
        }

        MST[closedge[tmp_index].adjvex][tmp_index] = closedge[tmp_index].dis_min;
        closedge[tmp_index].dis_min = 0;//并入U集

        for (int i = 0; i < size; ++i)//更新最短距离以及起始点
        {
            if (closedge[i].dis_min > Edge[tmp_index][i])
            {
                closedge[i].adjvex = tmp_index;
                closedge[i].dis_min = Edge[tmp_index][i];
            }
        }
    }

    return 1;
}

template <typename T>
bool Graph<T>::get_inDegree(void)
{
    inDegree = new int[size];
    for (int i = 0; i < size; ++i)
    {
        inDegree[i] = 0;
        // std::cout << "inDegree" << i << " is " << inDegree[i];
    }
    for (int i = 0; i < size; ++i)
    {
        ArcNode* ptr = AdjList[i].first;
        while (1)
        {
            if (0 == ptr)
            {
                break;
            }
            ++inDegree[ptr->adjvex];
            // std::cout << "ptr->adjvex is " <<ptr->adjvex << " inDegree[ptr->adjvex] is " << inDegree[ptr->adjvex] << std::endl;
            ptr = ptr->next;
            // std::cout << i << " indegree is" << inDegree[ptr->adjvex] << std::endl;;
        }
    }
    return 1;
}

template <typename T>
bool Graph<T>::topologicalSort(void)
{
    get_inDegree();
    int* tmp_inDegree = new int[size];
    for (int i = 0; i < size; ++i)
    {
        tmp_inDegree[i] = inDegree[i];
    }

    int count = 0;
    Stack<int> myStack;
    myStack.initStack_link();

    for (int i = 0; i < size; ++i)
    {
        if (0 == tmp_inDegree[i])
        {
            myStack.push_back(i);
        }
    }
    while (1)
    {
        if (myStack.isEmpty())
        {
            break;
        }

        int tmp_index = myStack.pop_back();
        std::cout << tmp_index << ' ';
        ++count;//出栈处理

        ArcNode* ptr = AdjList[tmp_index].first;
        while (1)
        {
            if (0 == ptr)
            {
                break;
            }
            --tmp_inDegree[ptr->adjvex];
            if (0 == tmp_inDegree[ptr->adjvex])
            {
                myStack.push_back(ptr->adjvex);
            }
            ptr = ptr->next;
        }
    }

    if (count == size)
    {
        std::cout << std::endl << "success!" << std::endl;
        return 1;
    }
    else
    {
        std::cout << "error! graph is not connected!" <<std::endl;
        return 0;
    }
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