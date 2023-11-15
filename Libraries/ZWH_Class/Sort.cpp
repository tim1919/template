
template <typename T>
bool isBig(T a, T b)
{
    return a > b;
}


// template <typename T>
// bool Sort<T>::init(const int& size)
// {
//     elem = new T[size];
//     this->size = size;
//     return 1;
// }


// template <typename T>
// T& Sort<T>::operator[](const int& n)
// {
//     return elem[n];
// }


template <typename T>
bool Sort<T>::InsertionSort(T* const& arr, const int& elem_size, bool (* compare)(T a, T b))
{
    int i, j;
    for (i = 2; i < elem_size + 1; ++i)//i从无序区开始
    {
        if (compare(arr[i - 1], arr[i]))
        {          
            arr[0] = arr[i];
            for (j = i - 1; j > 0 && compare(arr[j], arr[0]); --j)//j从有序区开始
            {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = arr[0];
        }
    }
    
    return 1;
}

template <typename T>
bool Sort<T>::InsertionSort_Bi(T* const& arr, const int& elem_size, bool (* compare)(T a, T b))
{
    int low, high, mid;
    int i, j;
    for (i = 2; i < elem_size + 1; ++i)//i从无序区开始
    {
        if (compare(arr[i - 1], arr[i]))
        {
            arr[0] = arr[i];
            low = 1;
            high = i - 1;

            while (1)
            {
                if (high < low)
                {
                    break;//与折半查找相似，最后出循环时mid在要查元素向下取整的位置
                }

                mid = (low + high) / 2;

                if (compare(arr[mid], arr[0]))
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
                
            }

            for (j = i - 1; j > high; --j)//j从有序区开始
            {
                arr[j + 1] = arr[j];
            }
            arr[high + 1] = arr[0];
        }
        
        std::cout << "i = " << i << ", ";
        for (int k = 0; k < elem_size + 1; ++k)
        {
            printf("%d ", arr[k]);
        }
        std::cout << std::endl;
    }

    return 1;
}

template <typename T>
bool Sort<T>::ShellSort(T* const& arr, const int& elem_size, bool (* compare)(T a, T b))
{
    int dk, i, j;
    for (dk = elem_size / 2; dk > 0; dk /= 2)//这里 dk 的取值序列不固定，只需递减且最后一个值为 1 即可
    {
        for (i = 1 + dk; i < elem_size + 1; ++i)//这里课件上是纵向遍历（++i），按课件上的来
        {
            if (compare(arr[i - dk], arr[i]))
            {
                arr[0] = arr[i];
                for (j = i - dk; j > 0 && compare(arr[j], arr[0]); j -= dk)
                {
                    arr[j + dk] = arr[j]; 
                }
                arr[j + dk] = arr[0];
            }
        }
    }
    return 1;
}

template <typename T>
bool Sort<T>::BubbleSort(T* const& arr, const int& elem_size, bool (* compare)(T a, T b))
{
    bool flag_if_isbig = compare(1, 0);
    int flag_if_switched = 0;
    int i, j;

    switch (flag_if_isbig)
    {
        case 0:
        {
            for (i = 1; i < elem_size; ++i)
            {
                for (j = i; j < elem_size; ++j)
                {
                    if (compare(arr[j], arr[j + 1]))
                    {
                        int tmp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = tmp;
                        flag_if_switched = 1;
                    }
                }
                if (0 == flag_if_switched)
                {
                    break;
                }
                flag_if_switched = 0;
            }
            break;
        }
        case 1://升序排列，只需记这个，即 compare 为 a > b
        {
            for (i = 1; i < elem_size; ++i)//执行 elem_size - 1 次
            {
                for (j = 1; j < elem_size - i + 1; ++j)
                {
                    if (compare(arr[j], arr[j + 1]))
                    {
                        int tmp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = tmp;
                        flag_if_switched = 1;
                    }
                }
                if (0 == flag_if_switched)
                {
                    break;
                }
                flag_if_switched = 0;
            }
            break;
        }
    }
    return 1;
}

template <typename T>
void Sort<T>::QuickSort(T* const& arr, int low, int high, bool (* compare)(T a, T b))//注意 QuickSort 本身就是一个递归函数
{
    if (low >= high)
    {
        return;
    }
    else
    {
        int pivot = QuickSort_Partition(arr, low, high, compare);//求枢轴
        QuickSort(arr, low, pivot - 1, compare);
        QuickSort(arr, pivot + 1, high, compare);
        return;
    }
}

template <typename T>
bool Sort<T>::SelectSort(T* const& arr, const int& elem_size, bool (* compare)(T a, T b))
{
    int i, j;
    int chosen;
    for (i = 1; i < elem_size; ++i)//执行 elem_size - 1 次，注意选择排序的无序区从 1 开始而非从 2 开始
    {
        chosen = i;
        for (j = i; j < elem_size + 1; ++j)
        {
            if (compare(arr[chosen], arr[j]))
            {
                chosen = j;
            }
        }
        if (chosen != i)//这个 if 感觉也可以不要，但会降低一点运行效率
        {
            arr[0] = arr[chosen];
            arr[chosen] = arr[i];
            arr[i] = arr[0];
        }
    }
    return 1;
}

template <typename T>
bool Sort<T>::HeapSort(T* const& arr, const int& elem_size, bool (* compare)(T a, T b))
{
    for (int i = elem_size / 2; i > 0; --i)//注意：这里从第一个有孩子的结点开始，一个一个往前调用 Heap_Adjust 函数是因为：Heap_Adjust 函数只能调整只有堆顶有问题的大（小）顶堆，故在生成大（小）顶堆时只能从最下面一点一点往上生成
    {
        Heap_Adjust(arr, i, elem_size, compare);
    }//第一步：生成大（小）顶堆

    for (int i = elem_size; i > 1; --i)
    {
        arr[0] = arr[1];
        arr[1] = arr[i];
        arr[i] = arr[0];
        // std::cout << arr[0].name << ' ' << arr[1].name << arr[2].name << arr[3].name << "     ";

        Heap_Adjust(arr, 1, i - 1, compare);
        // std::cout << arr[0].name << ' ' << arr[1].name << arr[2].name << arr[3].name << std::endl;

    }//第二步：循环将堆顶元素塞到堆后面（即有序区），此时原大（小）顶堆只有对顶有问题，然后再次调整

    return 1;
}



template <typename T>
bool Sort<T>::MergeSort(T*& arr, const int& elem_size, bool (* compare)(T a, T b))
{
    T* tmp_arr = new T[elem_size + 1];//共轭数组
    int sub_length = 1;//子序列的长度
    int low, high, mid;//注意这里的 mid 指向两个要归并的序列中第一个序列的尾，不一定是中间（考虑整个序列最后面的特殊情况）
    while (1)//这个 while 用来增加子序列长度
    {
        if (sub_length >= elem_size)
        {
            break;
        }
        
        low = 1;
        mid = sub_length;
        high = (2 * sub_length > elem_size) ? elem_size : 2 * sub_length;
        while (1)//这个 while 用来往后走
        {
            int i = low, j = mid + 1;
            int sub_ptr = low;//这个数组下标用来复制到数组
            while (1)//这个 while 用来归并
            {
                if (i > mid || j > high)
                {
                    if (i > mid)//将剩下的元素加入
                    {
                        while (1)
                        {
                            if (j > high)
                            {
                                break;
                            }
                            tmp_arr[sub_ptr] = arr[j];
                            ++j;
                            ++sub_ptr;
                        }
                    }
                    else
                    {
                        while (1)
                        {
                            if (i > mid)
                            {
                                break;
                            }
                            tmp_arr[sub_ptr] = arr[i];
                            ++i;
                            ++sub_ptr;
                        }
                    }

                    break;
                }

                if (compare(arr[i], arr[j]))
                {
                    tmp_arr[sub_ptr] = arr[j];
                    ++j;
                }
                else
                {
                    tmp_arr[sub_ptr] =  arr[i];
                    ++i;
                }
                ++sub_ptr;
            }

            low = high + 1;
            mid = low + sub_length - 1;//指针往下两个子序列走
            if (mid >= elem_size)
            {
                break;
            }
            else
            {
                high = (mid + sub_length > elem_size) ? elem_size : (mid + sub_length);
            }
            
        }

        T* ptr = arr;
        arr = tmp_arr;
        tmp_arr = ptr;//副数组已完成合并，现在令主数组为副，令副为主

        sub_length *= 2;//因为是二路归并，所以下一次归并的数组长度一定是原来的二倍
    }

    return 1;
}


template <typename T>
bool Sort<T>::RadixSort(T* const& arr, const int& elem_size, bool (* compare)(T a, T b))
{
    linkQueue<T> Q[10];//这里表示在 10 进制下排序
    linkQueue<T> output;

    for (int i = 0; i < 10; ++i)
    {
        Q[i].initQueue();
    }
    output.initQueue();

    int num_of_zero_bit = 0;//此变量用于记录是否已经遍历到了最大的位数
    T base = 1;//基数
    T val;//暂存每个数
    T bit;//暂时存放每一位

    for (int i = 1; i < elem_size + 1; ++i)//收集队列初始化
    {
        output.enQueue(arr[i]);
    }

    while (1)
    {
        if (num_of_zero_bit == elem_size)
        {
            break;
        }

        num_of_zero_bit = 0;

        while (1)//第一步：将所有元素分散到辅助队列里面
        {
            if (output.isEmpty())
            {
                break;
            }

            val = output.deQueue();
            bit = val / base % 10;
            Q[bit].enQueue(val);

            if (0 == bit && val / base < 10)
            {
                ++num_of_zero_bit;
            }

        }

        for (int i = 0; i < 10; ++i)//第二步：将所有元素收集起来
        {
            while (1)
            {
                if (Q[i].isEmpty())
                {
                    break;
                }
                output.enQueue(Q[i].deQueue());
            }
        }

        base *= 10;//最后再让基数乘 10 
    }

    if (compare(1, 0))
    {
        for (int i = 1; i < elem_size + 1; ++i)
        {
            arr[i] = output.deQueue();
        }
    }
    else
    {
        for (int i = elem_size; i > 0; --i)
        {
            arr[i] = output.deQueue();
        }
    }
    return 1;
}


template <typename T>
int Sort<T>::QuickSort_Partition(T* const& arr, int low, int high, bool (* compare)(T a, T b))//注意这个子函数是分治而不是递归！
{
    arr[0] = arr[low];
    while (1)//注意：枢轴上的值始终是垃圾值
    {
        if (high <= low)
        {
            break;
        }

        while (1)//此时枢轴是 low 
        {
            if (high <= low || compare(arr[0], arr[high]))
            {
                break;
            }
            --high;
        }
        arr[low] = arr[high];

        while (1)//此时枢轴是 high 
        {
            if (high <= low || compare(arr[low], arr[0]))
            {
                break;
            }
            ++low;
        }
        arr[high] = arr[low];
    }
    arr[high] = arr[0];
    return high;
}

template <typename T>
bool Sort<T>::Heap_Adjust(T* const& arr, int top, const int& elem_size, bool (* compare)(T a, T b))
{
    for (int child = 2 * top; child < elem_size + 1; child *= 2)
    {
        if (child < elem_size && compare(arr[child + 1], arr[child]))//先选出两个孩子里最大（小）的
        {
            ++child;
        }
        if (!compare(arr[child], arr[top]))//如果孩子比父结点小（大），说明无须调整（注意，这里只能说明这三个结点无须调整！！！）
        {
            break;
        }

        //如果没有 break ，说明某个孩子结点需要调整，那就得一直沿着这个孩子结点往下调整直到无须调整
        arr[0] = arr[top];
        arr[top] = arr[child];
        arr[child] = arr[0];
        top = child;
    }

    return 1;
}

template <typename T>
bool Sort<T>::Heap_Adjust_2(T* const& arr, int rear, bool (* compare)(T a, T b))
{
    for (; rear / 2 > 0 && compare(arr[rear], arr[rear / 2]); rear /= 2)
    {
        arr[0] = arr[rear];
        arr[rear] = arr[rear / 2];
        arr[rear / 2] = arr[0];
    }
    return 1;
}