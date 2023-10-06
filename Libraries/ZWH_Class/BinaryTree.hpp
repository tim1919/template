#pragma once
#include <iostream>

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
private:
    struct Node
    {
        ValueType data;
        Node* lchild;
        Node* rchild;
    };
    Node* Root = 0;
    int depth = 0;
    int length = 0;

    int tmp = 0;
    int i_max = 0;


    Node* create_recurse(int depth);//递归
    bool create_recurse_scanf(Node*& T);
    void func(const int& func, Node* const& T);
public:

#define PRINTF 1
#define SCANF 2
#define LEFT 0
#define RIGHT 1

    ~LinkBinaryTree(void);
    bool create(const int& depth);
    bool create_scanf(void);
    Node* root(void);//获取根结点
    Node* get(Node* const& T, const int& LorR);


    void preOrder_recurse(Node* const& T, const int& function);//前序遍历（递归）
    void inOrder_recurse(Node* const& T, const int& function);//中序遍历
    void postOrder_recurse(Node* const& T, const int& function);//后续遍历

    void preOrder_seq(Node* T, const int& function);//前序遍历（顺序）（法一）（还是用法一吧。。。）
    void preOrder_seq_1(Node* T, const int& function);//前序遍历（顺序）（法二）
    void preOrder_seq_2(Node* T, const int& function);//前序遍历（顺序）（法三）
    void inOrder_seq(Node* T, const int& function);//中序遍历（顺序）（法一）
    void postOrder_seq(Node* T, const int& function);//后序遍历（顺序）（法一）

    // void tmp(Node* T, const int& function);
    void test(void);
};

#include <BinaryTree.cpp>