
template <typename T>
bool StaticSearchTable<T>::init(const int& size)
{
    elem = new T[size + 1];
    this->size = size;
    return 1;

}

template <typename T>
T& StaticSearchTable<T>::operator[](const int& i)
{
    return elem[i];
}

template <typename T>
int StaticSearchTable<T>::get_size(void)
{
    return size;
}

template <typename T>
int StaticSearchTable<T>::Search_Seq(const T& key)
{
    elem[0] = key;//给监视哨赋值
    int i;
    for (i = size; i >= 0; --i)
    {
        if (key == elem[i])
        {
            break;
        }
    }

    return i;
}

template <typename T>
int StaticSearchTable<T>::Search_Bin(const T& key)
{
    int low = 1;
    int high = size;
    int mid;
    while (1)
    {
        if (low > high)
        {
            break;
        }

        mid = (low + high) / 2;
        if (key == elem[mid])
        {
            return mid;
        }
        else if (key > elem[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    std::cout << "not found!" << std::endl;
    return 0;
}

template <typename T>
int StaticSearchTable<T>::Search_Bin_Recurse(const int& low, const int& high, const T& key)
{
    if (low > high)
    {
        return 0;
    }

    int mid = (low + high) / 2;
    if (key == elem[mid])
    {
        return mid;
    }
    else if (key > elem[mid])
    {
        return Search_Bin_Recurse(mid + 1, high, key);
    }
    else if (key < elem[mid])
    {
        return Search_Bin_Recurse(low, mid - 1, key);
    }
}


template <typename T>
bool StaticSearchTable<T>::index_init(const int& maxblock)
{
    index = new indextype<T>[maxblock];
    for (int i = 0 ; i < maxblock; ++i)
    {
        std::cout << "请输入第" << i << "块区域的起始地址和最大键值：" << std::endl;
        std::cin >> index[i].addr >> index[i].max_key;
    }
    this->maxblock = maxblock;
    return 1;
}

template <typename T>
int StaticSearchTable<T>::Search_Index(const T& key)
{
    if (key > index[maxblock - 1].max_key)
    {
        std::cout << "error! to large! (from Search.cpp/Search_Index)" << std::endl;
        return -1;
    }

    int block_tmp;
    for (block_tmp = 0; block_tmp < maxblock; ++block_tmp)
    {
        if (index[block_tmp].max_key > key)
        {
            break;
        }
    }

    for (int i = index[block_tmp].addr; i < size && i < index[block_tmp + 1].addr; ++i)
    {
        if (key == elem[i])
        {
            return i;
        }
    }

    std::cout << "error! elem not found! (from Search.cpp/Search_Index)" << std::endl;
    return 0;
}


/**************************二叉排序树**************************/


template <typename T>
Node<T>* BST<T>::Search_BST(Node<T>* const& root, const T& key)
{
    Node<T>* ptr = root;
    while (1)
    {
        if (0 == ptr)
        {
            break;
        }

        if (key == ptr->data)
        {
            return ptr;
        }
        else if (key > ptr->data)
        {
            ptr = ptr->rchild;
        }
        else
        {
            ptr = ptr->lchild;
        }
    }
    std::cout << "no such key! (from Search.cpp/Search_BST)" << std::endl;
    return 0;
}

template <typename T>
bool BST<T>::Insert_BST(Node<T>* root, const T& key)
{
    if (0 == root)
    {
        root = new Node<T>[1];
        root->data = key;
        root->lchild = 0;
        root->rchild = 0;
        std::cout << "tree is empty! new val added! (from Search.cpp/InsertBST)" << std::endl;
        return 1;
    }
    
    Node<T>* ptr = root;
    while (1)
    {

        if (key == ptr->data)
        {
            std::cout << "error! your value already exits! (from Search.cpp/InsertBST)" << std::endl;
            return 0;
        }
        else if (key > ptr->data)
        {
            if (0 == ptr->rchild)
            {
                ptr->rchild = new Node<T>[1];
                ptr->rchild->lchild = 0;
                ptr->rchild->rchild = 0;
                ptr->rchild->data = key;
                return 1;
            }
            ptr = ptr->rchild;
        }
        else
        {
            if (0 == ptr->lchild)
            {
                ptr->lchild = new Node<T>[1];
                ptr->lchild->lchild = 0;
                ptr->lchild->rchild = 0;
                ptr->lchild->data = key;
                return 1;
            }
            ptr = ptr->lchild;
        }
    }
}

template <typename T>
bool BST<T>::Create_BST_Scanf(Node<T>* root, const T& null)
{
    T tmp_key;
    std::cin >> tmp_key;
    while (1)
    {
        if (null == tmp_key)
        {
            break;
        }

        if(!Insert_BST(root, tmp_key))
        {
            return 0;
        }
        std::cin >> tmp_key;
    }
    return 1;
}
