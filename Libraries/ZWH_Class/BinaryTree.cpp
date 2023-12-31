#pragma once

template <typename ValueType>
SQBinaryTree<ValueType>::~SQBinaryTree(void)
{
    delete[] Tree;
}

template <typename ValueType>
bool SQBinaryTree<ValueType>::init(void)
{
    Tree = new ValueType[1];
    depth = 1;
    length = 1;
    return 1;
}

template <typename ValueType>
bool SQBinaryTree<ValueType>::destroy(void)
{
    delete[] Tree;
    return 1;
}


template <typename ValueType>
LinkBinaryTree<ValueType>::~LinkBinaryTree(void)
{
    delete[] Root;
}

// template <typename ValueType>
// bool LinkBinaryTree<ValueType>::init(void)
// {
//     Root = new Node[1];
//     Root->lchild = 0;
//     Root->rchild = 0;
//     depth = 1;
//     length = 1;
//     return 1;
// }

template <typename ValueType>
Node<ValueType>* LinkBinaryTree<ValueType>::create_recurse(int depth)//这是什么语法？？？能过编译？？？
{
    if (0 == depth)
    {
        Node<ValueType>* null = 0;
        return null;
    }
    else
    {
        Node<ValueType>* tmp = new Node<ValueType>[1];
        tmp->data = 6;

        --depth;

        tmp->lchild = create_recurse(depth);
        tmp->rchild = create_recurse(depth);

        return tmp;
    }
}


template <typename ValueType>
bool LinkBinaryTree<ValueType>::create_recurse_scanf(Node<ValueType>*& T, const ValueType& null)
{
    ValueType val;
    std::cin >> val;
    // std::cout << "val: " << val << std::endl;
    // scanf("%c", &ch);
    if (null == val)
    {
        T = 0;
    }
    else
    {
        T = new Node<ValueType>[1];
        T->data = val;
        create_recurse_scanf(T->lchild, null);
        create_recurse_scanf(T->rchild, null);
    }
    return 1;
}


template <typename ValueType>
void LinkBinaryTree<ValueType>::func(const int& func, Node<ValueType>* const& T)
{
    switch (func)
    {
        case PRINTF:
        {
            std::cout << T->data << ' ' << std::flush;
            break;
        }
        case SCANF:
        {
            std::cin >> T->data;
            break;
        }
    }
}

template <typename ValueType>
bool LinkBinaryTree<ValueType>::create(const int& depth)
{
    Root = create_recurse(depth);

    // this->depth = depth;//树的高度

    // this->length = 1;
    // for (int i = 0; i < depth; ++i)
    // {
    //     this->length *= 2;
    // }
    // this->length -= 1;//计算树的元素个数

    // std::cout << "depth = " << this->depth << std::endl;
    return 1;
}

template <typename ValueType>
bool LinkBinaryTree<ValueType>::create_scanf(const ValueType& null)
{
    create_recurse_scanf(Root, null);
    return 1;
}

template <typename ValueType>
bool LinkBinaryTree<ValueType>::create_child(Node<ValueType>* const& T, const int& LorR, const ValueType& val)
{
    switch (LorR)
    {
        case LEFT:
        {
            if (0 != T->lchild)
            {
                std::cout << "error! already have lchild! (from BinaryTree.cpp/create_child)" << std::endl;
                return 0;
            }
            T->lchild = new Node<ValueType>[1];
            T->lchild->lchild = 0;
            T->lchild->rchild = 0;
            T->lchild->data = val;
            break;
        }
        case RIGHT:
        {
            if (0 != T->rchild)
            {
                std::cout << "error! already have rchild! (from BinaryTree.cpp/create_child)" << std::endl;
                return 0;
            }
            T->rchild = new Node<ValueType>[1];
            T->rchild->lchild = 0;
            T->rchild->rchild = 0;
            T->lchild->data = val;
            break;
        }
        default:
        {
            std::cout << "error! invalid param! (from BinaryTree.cpp/create_child)" << std::endl;
            return 0;
        }
    }

    return 1;
}


template <typename ValueType>
Node<ValueType>*& LinkBinaryTree<ValueType>::root(void)//这是什么语法？？？能过编译？？？
{
    return Root;
}

template <typename ValueType>
Node<ValueType>*& LinkBinaryTree<ValueType>::get_child(Node<ValueType>* const& T, const int& LorR)
{
    if (T == 0)
    {
        std::cout << "Node address error!" << std::endl;
        return 0;
    }

    switch (LorR)
    {
        case LEFT:
        {
            return T->lchild;
            break;
        }
        case RIGHT:
        {
            return T->rchild;
            break;
        }
        default:
        {
            std::cout << "error! function should take LEFT or RIGHT!" << std::endl;
            return 0;
            break;
        }
    }
}

template <typename ValueType>
int LinkBinaryTree<ValueType>::height(Node<ValueType>* const& T)//
{
    if (T)
    {
        int lchild_height = height(T->lchild);
        int rchild_height = height(T->rchild);

        if (lchild_height > rchild_height)
        {
            return 1 + lchild_height;
        }
        else
        {
            return 1 + rchild_height;
        }
    }
    else
    {
        return 0;
    }
}

template <typename ValueType>
int LinkBinaryTree<ValueType>::height_2(Node<ValueType>* const& T)
{
    Node<ValueType>* ptr = T;
    Stack<Node<ValueType>*> myStack;
    Node<ValueType>* tmp = 0;
    int height = 0;
    myStack.initStack_SQ();

    while (1)
    {
        if (myStack.length() > height)
        {
            height = myStack.length();
        }

        if (myStack.isEmpty() && 0 == ptr)
            break;

        if (ptr)
        {
            myStack.push_back(ptr);
            ptr = ptr->lchild;//入栈+访左
        }
        else
        {
            ptr = myStack.getTop();
            if (ptr->rchild != 0 && ptr->rchild != tmp)
            {

                ptr = ptr->rchild;
            }
            else if (ptr->rchild == 0 || ptr->rchild == tmp)//直接else也行
            {
                ptr = 0;
                tmp = myStack.pop_back();
            }
        }
    }

    myStack.destroyStack();
    return height;

}

template <typename ValueType>
void LinkBinaryTree<ValueType>::preOrder_recurse(Node<ValueType>* const& T, const int& function)
{
    if (T != 0)
    {
        func(function, T);
        // ++tmp;
        // test();
        preOrder_recurse(T->lchild, function);
        // ++tmp;
        // test();
        preOrder_recurse(T->rchild, function);
    }
    // --tmp;
    test();
}


template <typename ValueType>
void LinkBinaryTree<ValueType>::inOrder_recurse(Node<ValueType>* const& T, const int& function)
{
    if (T != 0)
    {
        inOrder_recurse(T->lchild, function);
        func(function, T);
        inOrder_recurse(T->rchild, function);
    }
}

template <typename ValueType>
void LinkBinaryTree<ValueType>::postOrder_recurse(Node<ValueType>* const& T, const int& function)
{
    if (T != 0)
    {
        postOrder_recurse(T->lchild, function);
        postOrder_recurse(T->rchild, function);
        func(function, T);
    }
}

template <typename ValueType>
void LinkBinaryTree<ValueType>::preOrder_loop(Node<ValueType>* T, const int& function)
{
    Stack<Node<ValueType>*> myStack;
    myStack.initStack_SQ();

    while (1)
    {
        // std::cout << "length of stack is: " << myStack.length() << std::endl;
        if (myStack.isEmpty() && 0 == T)
            break;

        if (T)//操作1：往左下走
        {
            func(function, T);
            myStack.push_back(T);         
            T = T->lchild;//入栈+访左
        }
        else//操作2：往上走（左右都有可能，且不一定只有1步） + 往右走
        {
            T = myStack.pop_back();
            T = T->rchild;//出栈+访右
        }
    }

    myStack.destroyStack();
}

// template <typename ValueType>
// void LinkBinaryTree<ValueType>::preOrder_loop_1(Node* T, const int& function)//前序遍历（循环）（法一）
// {
//     Node* node[depth] = {0};
//     int top = 0;
//     while (1)
//     {
//         while (1)//实现功能+入栈
//         {
//             if (0 == T)
//                 break;

//             func(function, T);//执行功能

//             node[top] = T;
//             ++top;//入栈条件：二叉树指针非空

//             T = T->lchild;
//         }

//         if (top > 0)//退栈+向右（注意：是平行向右！）
//         {
//             --top;//出栈条件：二叉树指针为空，且栈非空

//             T = node[top];
//             T = T->rchild;//指针平行向右
//         }

//         if (top <= 0 && 0 == T)//若栈和指针均空则结束
//             break;
//     }
// }

// template <typename ValueType>
// void LinkBinaryTree<ValueType>::preOrder_loop_2(Node* T, const int& function)//前序遍历（循环）（法二）（容易理解）
// {
//     Node* node[depth] = {0};//注意：这个队列的第一个值一定得是0！（第一个值其实不存任何地址，置0是为了函数最后的if(0 == T)能够退出）
//     int top = 0;
//     if (0 == T)
//     {
//         std::cout << "The tree is empty!" << std::endl;
//     }
//     else
//     {
//         while (1)
//         {
//             func(function, T);

//             if (0 != T->rchild)//入栈条件：若有右孩子
//             {
//                 ++top;
//                 node[top] = T->rchild;//注意：和法一不同，这里入的是右孩子！！
//                 //++top;
//             }

//             T = T->lchild;

//             if (0 == T)//出栈条件：若无左孩子
//             {
//                 T = node[top];//返回上一个有右孩子结点的右孩子
//                 --top;
//             }
            
//             if (0 == T)
//                 break;
//         }
//     }
// }

template <typename ValueType>
void LinkBinaryTree<ValueType>::inOrder_loop(Node<ValueType>* T, const int& function)//中序遍历（循环）（法二）（容易理解）
{
    Stack<Node<ValueType>*> myStack;
    myStack.initStack_SQ();

    while (1)
    {
        if (myStack.isEmpty() && 0 == T)
            break;

        if (T)
        {
            myStack.push_back(T);
            T = T->lchild;//入栈+访左
        }
        else
        {
            T = myStack.pop_back();
            func(function, T);
            T = T->rchild;//出栈+访右
        }
    }

    myStack.destroyStack();
}

template <typename ValueType>
void LinkBinaryTree<ValueType>::postOrder_loop(Node<ValueType>* T, const int& function)//后序遍历（循环）（法二）（容易理解）
{
    Stack<Node<ValueType>*> myStack;
    Node<ValueType>* tmp = 0;
    myStack.initStack_SQ();

    while (1)
    {
        // std::cout << "stack length:" << myStack.length() << std::endl;
        if (myStack.isEmpty() && 0 == T)
            break;

        if (T)
        {
            myStack.push_back(T);
            T = T->lchild;//入栈+访左
        }
        else
        {
            T = myStack.getTop();
            if (T->rchild != 0 && T->rchild != tmp)
            {
                // if (tmp != T->rchild)
                // {
                //     func(function, T);
                // }
                T = T->rchild;
            }
            else if (T->rchild == 0 || T->rchild == tmp)//直接else也行
            {
                // if (T->rchild == tmp)
                // {
                //     func(function, T);
                // }
                T = 0;
                tmp = myStack.pop_back();
                func(function, tmp);
            }
        }
    }

    myStack.destroyStack();

}

template <typename ValueType>
void LinkBinaryTree<ValueType>::levelOrder(Node<ValueType>* T, const int& function)
{
    linkQueue<Node<ValueType>*> myQueue;
    myQueue.initQueue();

    myQueue.enQueue(T);
    func(function, T);

    while (1)
    {
        if (myQueue.isEmpty())
            break;
    
        T = myQueue.deQueue();
        // func(function, T);
        if (T->lchild != 0)
        {
            myQueue.enQueue(T->lchild);
            func(function, T->lchild);
        }

        if (T->rchild != 0)
        {
            myQueue.enQueue(T->rchild);
            func(function, T->rchild);
        }   
    }
}

template <typename ValueType>
void LinkBinaryTree<ValueType>::test(void)
{
    if (tmp > i_max)
    {
        i_max = tmp;
    }
    std::cout << "i_max: " << i_max << std::endl;
}

// template <typename ValueType>
// void LinkBinaryTree<ValueType>::getPreOrderSequence(const std::string& str)
// {
//     preOrder_sequence = str;
// }

// template <typename ValueType>
// void LinkBinaryTree<ValueType>::getInOrderSequence(const std::string& str)
// {
//     inOrder_sequence = str;
// }

// template <typename ValueType>
// void LinkBinaryTree<ValueType>::handle(void)
// {
//     Root = new Node<ValueType>[1];
//     // Root->data = inOrder_sequence;
//     Root->lchild = 0;
//     Root->rchild = 0;

//     recurse(Root, inOrder_sequence);
// }

// template <typename ValueType>
// void LinkBinaryTree<ValueType>::recurse(Node<ValueType>*& T, std::string str)
// {

//     if (0 == str.size())
//     {
//         T = 0;
//     }
//     else
//     {
//         char ch = preOrder_sequence[0];
//         // std::cout << "ch = " << ch << std::endl;
//         preOrder_sequence.erase(0, 1);
//         int i = str.find(ch);
//         std::string str_lch = str.substr(0, i);
//         // std::cout << "str_lch = " << str_lch << std::endl;
//         std::string str_rch = str.substr(i + 1);
//         // std::cout << "str_rch = " << str_rch << std::endl;

//         T = new Node<ValueType>[1];
//         T->data = ch;
//         recurse(T->lchild, str_lch);
//         recurse(T->rchild, str_rch);
//     }
    


// }

template <typename T>
Thread_Node<T>*& Thread_BiTree<T>::root(void)
{
    return Root;
}

template <typename T>
bool Thread_BiTree<T>::create_scanf(Thread_Node<T>*& root, const T& null)
{
    T val;
    std::cin >> val;
    if (null == val)
    {
        root = 0;
    }
    else
    {
        root = new Thread_Node<T>[1];
        root->data = val;
        root->lflag = 0;
        root->rflag = 0;
        create_scanf(root->lchild, null);
        create_scanf(root->rchild, null);
    }
    return 1;
}

template <typename T>
bool Thread_BiTree<T>::inOrder_Threading(Thread_Node<T>*& root)
{
    Thread_Node<T>* thrt = new Thread_Node<T>[1];//头结点
    thrt->lflag = 0;
    thrt->lchild = root;
    root = thrt;

    Thread_Node<T>* pre = root;
    Thread_Node<T>* p = root->lchild;

    // Thread_Node<T>* p = root;

    Stack<Thread_Node<T>*> myStack;
    myStack.initStack_SQ();
    while (1)//中序非递归
    {
        if (myStack.isEmpty() && 0 == p)
        {
            break;
        }

        if (p)
        {
            myStack.push_back(p);
            p = p->lchild;
        }
        else
        {
            p = myStack.pop_back();
            std::cout << p->data;
            if (0 == p->lchild)
            {
                p->lflag = 1;
                p->lchild = pre;
            }
            if (0 == pre->rchild)
            {
                pre->rflag = 1;
                pre->rchild = p;
            }
            pre = p;
            p = p->rchild;
        }
    }

    pre->rflag = 1;
    pre->rchild = root;
    root->rflag = 1;
    root->rchild = pre;
    return 1;
}

template <typename T>
Thread_Node<T>* Thread_BiTree<T>::get_inOrder_pre(Thread_Node<T>* const& p)
{
    if (0 != p->lflag)
    {
        return p->lchild;
    }
    else
    {
        Thread_Node<T>* ptr = p->lchild;
        while (1)
        {
            if (0 != ptr->rflag)
            {
                break;
            }
            ptr = ptr->rchild;
        }
        return ptr;
    }
}

template <typename T>
Thread_Node<T>* Thread_BiTree<T>::get_inOrder_next(Thread_Node<T>* const& p)
{
    if (0 != p->rflag)
    {
        return p->rchild;
    }
    else
    {
        Thread_Node<T>* ptr = p->rchild;
        while (1)
        {
            if (0 != ptr->lflag)
            {
                break;
            }
            ptr = ptr->lchild;
        }
        return ptr;
    }
}

template <typename T>
bool Thread_BiTree<T>::inOrder_traverse(Thread_Node<T>* const& root)
{
    Thread_Node<T>* ptr = root->lchild;
    while (1)//先找到中序的第一个结点
    {
        if (0 != ptr->lflag)
        {
            break;
        }
        ptr = ptr->lchild;
    }


    while (1)
    {
        if (root == ptr)
        {
            break;
        }
        std::cout << ptr->data << ' ' << std::endl;//即func(ptr);
        ptr = get_inOrder_next(ptr);
    }

    return 1;
}

template <typename T>
bool Thread_BiTree<T>::test_print_preOrder_recurse(Thread_Node<T>* const& root)
{
    if (0 != root)
    {
        std::cout << root->data << ' ';
        test_print_preOrder_recurse(root->lchild);
        
        test_print_preOrder_recurse(root->rchild);
    }

    return 1;
}

template <typename T>
bool Thread_BiTree<T>::test_print_inOrder_recurse(Thread_Node<T>* const& root)
{
    if (0 != root)
    {
        std::cout << root->lflag << ' ' << root->data << ' ' << root->rflag << std::endl;
        test_print_inOrder_recurse(root->lchild);
        test_print_inOrder_recurse(root->rchild);
    }

    return 1;
}