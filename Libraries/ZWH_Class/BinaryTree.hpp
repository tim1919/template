#pragma once
#include <iostream>

template <typename ValueType>
struct Node
{
    ValueType data;
    Node* lchild;
    Node* rchild;
};

template <typename T>
struct Thread_Node
{
    T data;
    bool lflag = 0;
    Thread_Node* lchild = 0;
    bool rflag = 0;
    Thread_Node* rchild = 0;
};

template <typename ValueType>
class SQBinaryTree
{
public:
    ~SQBinaryTree(void);
    bool init(void);
    bool destroy(void);
private:
    ValueType* Tree;
    int depth = 0;
    int length = 0;
};

template <typename ValueType>
class LinkBinaryTree
{
    
public:

#define PRINTF 1
#define SCANF 2
#define LEFT 0
#define RIGHT 1


    void func(const int& func, Node<ValueType>* const& T);

    ~LinkBinaryTree(void);

    bool create(const int& depth);
    bool create_scanf(const ValueType& null);//输入先序序列（带空指针）以创建一颗二叉树
    bool create_child(Node<ValueType>* const& T, const int& LorR, const ValueType& val);//创建一个左/右孩子

    Node<ValueType>*& root(void);//获取根结点
    Node<ValueType>*& get_child(Node<ValueType>* const& T, const int& LorR);

    int height(Node<ValueType>* const& T);//法一：递归求高度
    int height_2(Node<ValueType>* const& T);//法二：非递归后序遍历求高度


    void preOrder_recurse(Node<ValueType>* const& T, const int& function);//前序遍历（递归）
    void inOrder_recurse(Node<ValueType>* const& T, const int& function);//中序遍历
    void postOrder_recurse(Node<ValueType>* const& T, const int& function);//后续遍历

    void preOrder_loop(Node<ValueType>* T, const int& function);//前序遍历（循环）（法一）（还是用法一吧。。。）
    // void preOrder_loop_1(Node* T, const int& function);//前序遍历（循环）（法二）
    // void preOrder_loop_2(Node* T, const int& function);//前序遍历（循环）（法三）
    void inOrder_loop(Node<ValueType>* T, const int& function);//中序遍历（循环）（法一）
    void postOrder_loop(Node<ValueType>* T, const int& function);//后序遍历（循环）（法一）

    void levelOrder(Node<ValueType>* T, const int& function);//层次遍历（循环）
    // void tmp(Node* T, const int& function);
    void test(void);

    // void getPreOrderSequence(const std::string& str);
    // void getInOrderSequence(const std::string& str);
    // void handle(void);
    // void recurse(Node<ValueType>*& T, std::string str);
private:

    Node<ValueType>* Root = 0;
    // int depth = 0;
    // int length = 0;

    int tmp = 0;
    int i_max = 0;

    // std::string preOrder_sequence;
    // std::string inOrder_sequence;


    Node<ValueType>* create_recurse(int depth);//递归   
    bool create_recurse_scanf(Node<ValueType>*& T, const ValueType& null);

};

template <typename T>
class Thread_BiTree
{
public:
    Thread_Node<T>*& root(void);

    bool create_scanf(Thread_Node<T>*& root, const T& null);//输入先序序列以创建一棵普通二叉树
    bool inOrder_Threading(Thread_Node<T>*& root);//中序线索化
    Thread_Node<T>* get_inOrder_pre(Thread_Node<T>* const& p);//获取p的前驱结点
    Thread_Node<T>* get_inOrder_next(Thread_Node<T>* const& p);//获取p的后继结点
    bool inOrder_traverse(Thread_Node<T>* const& root);//线索化后的中序遍历
    //test
    bool test_print_preOrder_recurse(Thread_Node<T>* const& root);
    bool test_print_inOrder_recurse(Thread_Node<T>* const& root);
private:
    Thread_Node<T>* Root = 0;
};

#include <BinaryTree.cpp>