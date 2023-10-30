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

struct Closedge
{
    int adjvex = 0;//U集中的顶点
    float dis_min = __FLT_MAX__;
};//prim算法的辅助数组

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

    float** MST = 0;//prim算法的最小生成树

    Closedge* dij = 0;
    // dijkstra 算法的输出数组，dij[i].adjvex 和 dij[i].dis_min 表示：从 adjvex 到 i ；且起点（注意这里与 prim 算法的区别）到 i 的最短距离是 dij[i].dis_min

    float** flo_dis = 0;// floyd 算法的距离迭代矩阵
    int** flo_path = 0;// floyd 算法的路径迭代矩阵
    

    VNode<T>* AdjList;//邻接表

    bool* DFS_isVisited;
    bool* BFS_isVisited;

    int* inDegree = 0;//各顶点入度（邻接表用）
    float* ve = 0;//顶点的最早发生时间
    float* vl = 0;//顶点的最迟发生时间
    float* e = 0;//活动的最早发生时间
    float* l = 0;//活动的最迟发生时间

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
    bool topologicalSort_AOV(void);//拓扑排序（AOV版本），失败返回 0 ，说明图中存在回路
    bool topologicalSort_AOE(Stack<int>& stack_topo_inverse);//拓扑排序（AOE版本），失败返回 0 ，说明图中存在回路
    bool topologicalSort_AOE_inverse(Stack<int>& stack_topo_inverse);//逆拓扑排序，必须用在上面函数之后
    bool criticalPath(void);

    bool dijkstra(const int& start);// dijkstra 算法
    bool print_result_of_dijkstra(const int& start);//打印出 dijkstra 算法的结果

    bool floyd(void);// floyd 算法
    bool print_result_of_floyd(const int& v1, const int& v2);//根据 floyd 算法的结果，求 v1 和 v2 的最短路径及其距离

    T* func(const int& function, const int& index);
};


#include <Graph.cpp>
