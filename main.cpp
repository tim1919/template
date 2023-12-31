#include <include.hpp>
#include <string>
#include <fstream>


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
   // std::ifstream fin;
   // fin.open("../Data/ZWH_App/GetSimilarity/Similarity_Calculator/formatted/tmp.txt");
   // std::cout << fin.is_open() << std::endl;



/****************************************Graph*****************************************/
   Graph<int> myGraph;
   myGraph.init_MGraph(6);
   myGraph.create_MGraph(WUXIANG, WUQUAN);
   // myGraph.Prim(2);
   myGraph.BFS(PRINTF_GRAPH, 2, myGraph.get_Edge());
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
   Thread_BiTree<char> myTree;
   myTree.create_scanf(myTree.root(), '#');
   myTree.inOrder_Threading(myTree.root());
   myTree.inOrder_traverse(myTree.root());
/****************************************Sort*****************************************/

   // Sort<int> mySort;
   // // int arr[6] = {1, 6, 5, 2, 3, 0};
   // int* arr = new int[14];
   // arr[0] = 0;
   // arr[1] = 100;
   // arr[2] = 96;
   // arr[3] = 70;
   // arr[4] = 20;
   // arr[5] = 19;
   // arr[6] = 65;
   // arr[7] = 13;
   // arr[8] = 1;
   // arr[9] = 16;
   // arr[10] = 15;
   // arr[11] = 2;
   // arr[12] = 63;
   // arr[13] = 71;
 
   // auto isBig = [](int a, int b)->bool{ return a > b; };
   // auto isSmall = [](int a, int b)->bool{ return a < b; };
   // mySort.RadixSort(arr, 13, isBig);
   // // mySort.QuickSort(arr, 1, 5, isSmall);
   // for (int i = 0; i < 14; ++i)
   // {
   //    std::cout << arr[i] << std::endl;
   // }

/****************************************实验四*****************************************/
   // File_Creator myCreator;
   // Similarity_Calculator myCalculator;

   // myCreator.init();

   // int num_of_file = 0;
   // std::cin >> num_of_file;

   // // std::stringstream strstr[num_of_file];
   // std::string file[num_of_file];//文件名
   // std::string file_handled[num_of_file];
   // for (int i = 0; i < num_of_file; ++i)
   // {
   //    file[i] = myCreator.create("../");
   //    file_handled[i] = myCalculator.input_and_format(file[i]);
   // }   

   // int num_of_cal = 0;
   // std::cin >> num_of_cal;
   // int toCal[num_of_cal][2] = {0};
   // for (int i = 0; i < num_of_cal; ++i)
   // {
   //    std::cin >> toCal[i][0] >> toCal[i][1];
   // }
   // //输入准备完毕

  
   // for (int i = 0; i < num_of_cal; ++i)
   // {
   //    printf("%f%%\n", myCalculator.insert_and_cal(file_handled[toCal[i][0] - 1], file_handled[toCal[i][1] - 1]) * 100);
   //    // std::cout << myCalculator.insert_and_cal(file_handled[toCal[i][0] - 1], file_handled[toCal[i][1] - 1]) << std::endl;
   // }
/****************************************实验五*****************************************/
   // // student amy = {"000010", "Amy", 90};
   // // student j2 = {"000002", "James", 98};
   // // student j7 = {"000007", "James", 85};
   // // std::cout << compare_name(amy, j2) << std::endl;
   // // std::cout << compare_name(amy, j7) <<std::endl;
   // // std::cout << compare_name(j2, j7) << std::endl;
   // // std::cout << compare_name(j7, j2) << std::endl;

   // int row = 0, col = 0;
   // std::cout << "Input: " << std::endl;
   // std::cin >> row >> col;

   // student s[row + 1];
   // for (int i = 1; i < row + 1; ++i)
   // {
   //    std::cin >> s[i].id;

   //    std::cin >> s[i].name;
   //    // for (int ptr = s[i].name.length(); ptr < 10; ++ptr)
   //    // {
   //    //    s[i].name[ptr] = '\0';
   //    // }

   //    std::cin >> s[i].score;
      
   // }

   // bool (* p)(student a, student b);
   // if (1 == col)
   // {
   //    p = compare_id;
   // }
   // else if (2 == col)
   // {
   //    p = compare_name;
   // }
   // else if (3 == col)
   // {
   //    p = compare_score;
   // }
   // else
   // {
   //    std::cout << "invalid value of col!" << std::endl;
   //    return 0;
   // }


   // Sort<student> mySorter;
   // mySorter.HeapSort(s, row, p);


   // std::cout << "Output: " << std::endl;
   // for (int i = 1; i < row + 1; ++i)
   // {
   //    std::cout << s[i].id << ' ' << s[i].name << ' ' << s[i].score << std::endl;
   // }

/****************************************String*****************************************/
   // std::string s = "stringstream";
   // std::string t = "ring";

   // std::cout << KMP(s, t) << std::endl;


   return 0;
}