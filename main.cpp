#include <include.hpp>



int main(void)
{
   LinkBinaryTree<char> myTree;
   //myTree.create(3);
   // myTree.preOrder_recurse(myTree.root(), SCANF);
   // myTree.postOrder_seq(myTree.root(), PRINTF);
   // std::cout << myTree.root() << std::endl;
   // myTree.test();

   myTree.create_scanf();
   myTree.preOrder_seq(myTree.root(), PRINTF);
   return 0;
}