#pragma once

#include <limits.h>
#include <iostream>
#include <float.h>

// template <typename T>
struct ArcNode
{
    int adjvex;//该弧指向的顶点的位置
    ArcNode* next;
};//弧结点

template <typename T>
struct VNode
{
    T data;
    ArcNode* first;//指向第一条依附于该顶点的弧
};//顶点表结点



template <typename T>
class Graph
{
private:
    float** Edge = 0;//邻接矩阵
    T* Vex = 0;//顶点数据

    float** MST = 0;//最小生成树

    VNode<T>* AdjList;//邻接表

    bool* DFS_isVisited;
    bool* BFS_isVisited;

    int size = 0;

    bool DFS_recurse(const int& function, const int& index, float** const& Edge);
public:
    ~Graph(void);
    bool init_MGraph(const int& size);
    bool init_ALGraph(const int& size);
    bool create_MGraph(bool isYOUXIANG, bool isDAIQUAN);
    float**& get_Edge(void);
    float**& get_MST(void);
    T*& get_Vex(void);

    bool DFS(const int& function, const int& num, float** const& Edge);
    bool BFS(const int& function, const int& num, float** const& Edge);

    bool Prim(const int& num);

    T* func(const int& function, const int& index);
};


#include <Graph.cpp>
