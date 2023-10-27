#include <include.hpp>
#include <string>


int main(void)
{
   // Graph<int> myGraph;
   // myGraph.init_MGraph(6);
   // myGraph.create_MGraph(WUXIANG, DAIQUAN);
   // myGraph.Prim(2);
   // myGraph.BFS(PRINTF_GRAPH, 2, myGraph.get_MST());
   Graph<int> myGraph;
   myGraph.init_ALGraph(3);
   myGraph.create_ALGraph(YOUXIANG, WUQUAN);
   // std::cout << "??";
   myGraph.topologicalSort();
   return 0;
}