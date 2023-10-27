#pragma once

#include <limits.h>
#include <iostream>
#include <float.h>

// template <typename T>
struct ArcNode
{
    int adjvex = 0;//该弧指向的顶点的位置
    ArcNode* next = 0;
    float weight = 0;
};//弧结点

template <typename T>
struct VNode
{
    T data;
    ArcNode* first = 0;//指向第一条依附于该顶点的弧
    
};//顶点表结点



template <typename T>
class Graph
{
#define YOUXIANG 1
#define WUXIANG 0
#define DAIQUAN 1
#define WUQUAN 0
private:

    int size = 0;//图顶点个数

    float** Edge = 0;//邻接矩阵
    T* Vex = 0;//顶点数据

    float** MST = 0;//最小生成树

    VNode<T>* AdjList;//邻接表

    bool* DFS_isVisited;
    bool* BFS_isVisited;

    int* inDegree = 0;//各顶点入度（邻接表用）

    bool DFS_recurse(const int& function, const int& index, float** const& Edge);
public:
    ~Graph(void);
    bool init_MGraph(const int& size);
    bool init_ALGraph(const int& size);
    bool create_MGraph(bool isYOUXIANG, bool isDAIQUAN);
    bool create_ALGraph(bool isYOUXIANG, bool isDAIQUAN);
    float**& get_Edge(void);
    float**& get_MST(void);
    T*& get_Vex(void);

    bool DFS(const int& function, const int& num, float** const& Edge);
    bool BFS(const int& function, const int& num, float** const& Edge);

    bool Prim(const int& num);

    bool get_inDegree(void);//求各顶点入度（邻接表用）
    bool topologicalSort(void);//拓扑排序，失败返回 0 ，说明图中存在回路



    T* func(const int& function, const int& index);
};


#include <Graph.cpp>
