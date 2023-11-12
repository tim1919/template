#pragma once

#include <iostream>


template <typename T>
struct indextype//索引表结构体
{
    T max_key;//该块最大关键字
    int addr;//该块起始地址
};

template <typename T>
class StaticSearchTable
{
private:
    T* elem = 0;//elem[0]不要存元素，要作为“监视哨”！
    int size = 0;

    indextype<T>* index;//索引表
    int maxblock;//索引表的大小
public:
    bool init(const int& size);
    T& operator[](const int& i);
    int get_size(void);


    int Search_Seq(const T& key);//顺序查找表

    int Search_Bin(const T& key);//折半查找顺序表
    int Search_Bin_Recurse(const int& low, const int& high, const T& key);//折半查找（递归）

    bool index_init(const int& maxblock);//索引表初始化
    int Search_Index(const T& key);
};


template <typename T>
class BST//二叉排序树
{
private:
    // bool Delete_Recurse(Node<T>*& root, const T& key);
public:
    Node<T>* Search_BST(Node<T>* const& root, const T& key);//这个还是得改成返回指针
    Node<T>* Insert_BST(Node<T>* root, const T& key);
    bool Create_BST_Scanf(Node<T>* root, const T& null);
    bool Delete_BST(Node<T>*& root, const T& key);//递归实现删除，记不太住
};




#include <Search.cpp>