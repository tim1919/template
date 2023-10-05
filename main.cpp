#include <include.hpp>



int main(void)
{
   LinkBinaryTree<int> myTree;
   myTree.create(3);
   myTree.preOrder_recurse(myTree.root(), SCANF);
   myTree.postOrder_seq(myTree.root(), PRINTF);
   std::cout << myTree.root() << std::endl;
   return 0;
}