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


    Node* create_recurse(int depth);//递归
    void func(const int& func, Node* const& T);
public:

#define PRINTF 1
#define SCANF 2

    ~LinkBinaryTree(void);
    bool create(const int& depth);
    Node* root(void);


    void preOrder_recurse(Node* const& T, const int& function);//前序遍历（递归）
    void inOrder_recurse(Node* const& T, const int& function);//中序遍历
    void postOrder_recurse(Node* const& T, const int& function);//后续遍历

    void preOrder_seq(Node* T, const int& function);//前序遍历（顺序）（法一）（还是用法一吧。。。）
    void preOrder_seq_1(Node* T, const int& function);//前序遍历（顺序）（法二）
    void inOrder_seq(Node* T, const int& function);//中序遍历（顺序）（法一）
    void postOrder_seq(Node* T, const int& function);//后序遍历（顺序）（法一）

    void tmp(Node* T, const int& function);
};

#include <BinaryTree.cpp>