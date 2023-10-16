#include <include.hpp>
#include <string>

struct Polynomial
{
   long int a = 0;
   long int n = 0;
};

int main(void)
{
/****************************************实验一*****************************************/
   // List<Polynomial> myList;
   // myList.initList_link();
   
   // while (1)//第一个循环用来输入
   // {
   //    Polynomial tmp;

   //    std::cin >> tmp.a >> tmp.n;
   //    myList.push_back_link(tmp);

   //    // std::cout << tmp.a << tmp.n << std::endl;
   //    if (std::cin.get() == '\n')
   //       break;
   // }

   // for (int i = 0; i < myList.length(); ++i)//第二个循环用来处理
   // {
   //    myList.getElem_link(i).a *= myList.getElem_link(i).n;

   //    if (myList.getElem_link(i).n == 0)
   //    {
   //       myList.getElem_link(i).n = 0;
   //    }
   //    else
   //    {
   //       myList.getElem_link(i).n -= 1;
   //    }
   // }

   // for (int i = 0; i < myList.length(); ++i)//第三个循环用来输出
   // {
   //    if (0 != myList.getElem_link(i).a)
   //    {
   //       std::cout << myList.getElem_link(i).a << ' ' << myList.getElem_link(i).n;
   //       if (i != myList.length() - 1)
   //       {
   //          std::cout << ' ';
   //       }
   //    }

   //    if (i == myList.length() - 1)
   //    {
   //       std::cout << std::endl;
   //    }
   // }
   
/****************************************实验二*****************************************/
   LinkBinaryTree<std::string> myTree;
   std::string tmp_preOrder, tmp_inOrder;
   int length_str;

   std::cin >> length_str;
   std::cin >> tmp_preOrder;
   std::cin >> tmp_inOrder;


   myTree.getPreOrderSequence(tmp_preOrder);
   myTree.getInOrderSequence(tmp_inOrder);
   // myTree.root().data
   myTree.f();
   std::cout << myTree.height(myTree.root()) << std::endl;
   return 0;
}