#include <include.hpp>
#include <string>

struct Polynomial
{
   long int a = 0;
   long int n = 0;
};

int main(void)
{
   Graph<int> myGraph;
   myGraph.init_MGraph(5);
   myGraph.create_MGraph(WUXIANG, WUQUAN);
   myGraph.BFS(PRINTF_GRAPH, 3);
   return 0;
}