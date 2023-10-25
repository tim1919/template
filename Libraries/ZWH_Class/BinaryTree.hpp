#pragma once
#include <iostream>

template <typename ValueType>
struct Node
{
    ValueType data;
    Node* lchild;
    Node* rchild;
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
    bool create_scanf(const ValueType& null);
    Node<ValueType>*& root(void);//获取根结点
    Node<ValueType>*& get(Node<ValueType>* const& T, const int& LorR);
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

    void getPreOrderSequence(const std::string& str);
    void getInOrderSequence(const std::string& str);
    void handle(void);
    void recurse(Node<ValueType>*& T, std::string str);
private:

    Node<ValueType>* Root = 0;
    // int depth = 0;
    // int length = 0;

    int tmp = 0;
    int i_max = 0;

    std::string preOrder_sequence;
    std::string inOrder_sequence;


    Node<ValueType>* create_recurse(int depth);//递归
    
    bool create_recurse_scanf(Node<ValueType>*& T, const ValueType& null);

};

#include <BinaryTree.cpp>