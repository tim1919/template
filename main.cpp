#include <include.hpp>
#include <string>


int main(void)
{
/****************************************实验一*****************************************/
   // List<Polynomial> myList;
   // myList.initList_link();

   // myList.input();
   // myList.handle();
   // myList.output();

   // myList.destroyList();
   
/****************************************实验二*****************************************/
   // LinkBinaryTree<std::string> myTree;
   // std::string str_preOrder, str_inOrder;
   // int str_length;

   // std::cout << "input: " << std::endl;
   // std::cin >> str_length >> str_preOrder >> str_inOrder;

   // myTree.create_rc(myTree.root(), str_preOrder, str_inOrder);
   // std::cout << "output: \n" << myTree.height(myTree.root()) << std::endl;

   
/***************************************实验三*****************************************/
   // int size_graph = 0, size_edge = 0;
   // std::cout << "input: " << std::endl;
   // std::cin >> size_graph >> size_edge;

   // Graph<int> myGraph;
   // myGraph.init_MGraph(size_graph);
   // myGraph.create_edge(size_edge);
   // std::cout << "output: " << std::endl;
   // myGraph.BFS(6);

/****************************************test*****************************************/
   // Graph<int> myGraph;
   // myGraph.init_MGraph(4);
   // myGraph.create_MGraph(WUXIANG, WUQUAN);
   // myGraph.BFS(PRINTF_GRAPH, 2);
   // return 0;

/****************************************Graph*****************************************/
   // Graph<int> myGraph;
   // myGraph.init_MGraph(6);
   // myGraph.create_MGraph(WUXIANG, DAIQUAN);
   // myGraph.Prim(2);
   // myGraph.BFS(PRINTF_GRAPH, 2, myGraph.get_MST());
   // Graph<int> myGraph;
   // myGraph.init_MGraph(6);
   // myGraph.create_MGraph(YOUXIANG, DAIQUAN);
   // std::cout << "??";
   // myGraph.topologicalSort_AOE();
   // myGraph.criticalPath();
   // myGraph.dijkstra(0);
 
   // myGraph.print_result_of_dijkstra(0);
   // myGraph.floyd();
   // myGraph.print_result_of_floyd(0, 2);

/****************************************Graph*****************************************/
   // List<int> myList;
   // myList.initList_link();
   // myList.insertElem(0, 9);
   // myList.insertElem(1, 5);
   // std::cout << myList.getElem_link(0) << myList.getElem_link(1) << std::endl;

/****************************************Tree*****************************************/
   LinkBinaryTree<int> myTree;
   myTree.create_scanf(-1);
   // myTree.preOrder_loop(myTree.root(), PRINTF);
   myTree.levelOrder(myTree.root(), PRINTF);
   return 0;
}