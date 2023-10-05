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
typename LinkBinaryTree<ValueType>::Node* LinkBinaryTree<ValueType>::create_recurse(int depth)//这是什么语法？？？能过编译？？？
{
    if (0 == depth)
    {
        Node* null = 0;
        return null;
    }
    else
    {
        Node* tmp = new Node[1];
        tmp->data = 6;

        --depth;

        tmp->lchild = create_recurse(depth);
        tmp->rchild = create_recurse(depth);

        return tmp;
    }
}

template <typename ValueType>
void LinkBinaryTree<ValueType>::func(const int& func, Node* const& T)
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

    this->depth = depth;//树的高度

    this->length = 1;
    for (int i = 0; i < depth; ++i)
    {
        this->length *= 2;
    }
    this->length -= 1;//计算树的元素个数

    std::cout << "depth = " << this->depth << std::endl;
    return 1;
}

template <typename ValueType>
typename LinkBinaryTree<ValueType>::Node* LinkBinaryTree<ValueType>::root(void)//这是什么语法？？？能过编译？？？
{
    return Root;
}


template <typename ValueType>
void LinkBinaryTree<ValueType>::preOrder_recurse(Node* const& T, const int& function)
{
    if (T != 0)
    {
        func(function, T);
        preOrder_recurse(T->lchild, function);
        preOrder_recurse(T->rchild, function);
    }
}


template <typename ValueType>
void LinkBinaryTree<ValueType>::inOrder_recurse(Node* const& T, const int& function)
{
    if (T != 0)
    {
        inOrder_recurse(T->lchild, function);
        func(function, T);
        inOrder_recurse(T->rchild, function);
    }
}

template <typename ValueType>
void LinkBinaryTree<ValueType>::postOrder_recurse(Node* const& T, const int& function)
{
    if (T != 0)
    {
        postOrder_recurse(T->lchild, function);
        postOrder_recurse(T->rchild, function);
        func(function, T);
    }
}

template <typename ValueType>
void LinkBinaryTree<ValueType>::preOrder_seq(Node* T, const int& function)
{
    Stack<Node*> myStack;
    myStack.initStack_SQ();

    while (1)
    {
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

template <typename ValueType>
void LinkBinaryTree<ValueType>::preOrder_seq_1(Node* T, const int& function)//前序遍历（顺序）（法一）
{
    Node* node[depth] = {0};
    int top = 0;
    while (1)
    {
        while (1)//实现功能+入栈
        {
            if (0 == T)
                break;

            func(function, T);//执行功能

            node[top] = T;
            ++top;//入栈条件：二叉树指针非空

            T = T->lchild;
        }

        if (top > 0)//退栈+向右（注意：是平行向右！）
        {
            --top;//出栈条件：二叉树指针为空，且栈非空

            T = node[top];
            T = T->rchild;//指针平行向右
        }

        if (top <= 0 && 0 == T)//若栈和指针均空则结束
            break;
    }
}

template <typename ValueType>
void LinkBinaryTree<ValueType>::preOrder_seq_2(Node* T, const int& function)//前序遍历（顺序）（法二）（容易理解）
{
    Node* node[depth] = {0};//注意：这个队列的第一个值一定得是0！（第一个值其实不存任何地址，置0是为了函数最后的if(0 == T)能够退出）
    int top = 0;
    if (0 == T)
    {
        std::cout << "The tree is empty!" << std::endl;
    }
    else
    {
        while (1)
        {
            func(function, T);

            if (0 != T->rchild)//入栈条件：若有右孩子
            {
                ++top;
                node[top] = T->rchild;//注意：和法一不同，这里入的是右孩子！！
                //++top;
            }

            T = T->lchild;

            if (0 == T)//出栈条件：若无左孩子
            {
                T = node[top];//返回上一个有右孩子结点的右孩子
                --top;
            }
            
            if (0 == T)
                break;
        }
    }
}

template <typename ValueType>
void LinkBinaryTree<ValueType>::inOrder_seq(Node* T, const int& function)//中序遍历（顺序）（法二）（容易理解）
{
    Stack<Node*> myStack;
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
void LinkBinaryTree<ValueType>::postOrder_seq(Node* T, const int& function)//后序遍历（顺序）（法二）（容易理解）
{
    Stack<Node*> myStack;
    Node* tmp = 0;
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
            T = myStack.getTop();
            if (T->rchild != 0 && T->rchild != tmp)
            {
                // if (tmp != T->rchild)
                // {
                //     func(function, T);
                // }
                T = T->rchild;
            }
            else if (T->rchild == 0 || T->rchild == tmp)
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


