#include <include.hpp>



int main(void)
{
   LinkBinaryTree<char> myTree;
   // myTree.create(3);
   // myTree.preOrder_recurse(myTree.root(), SCANF);
   // myTree.postOrder_seq(myTree.root(), PRINTF);
   // std::cout << myTree.root() << std::endl;
   // myTree.test();

   myTree.create_scanf('X');
   myTree.levelOrder(myTree.root(), PRINTF);
   // myTree.preOrder_loop(myTree.root(), PRINTF);

   // Node<char>* ptr = myTree.root();
   // ptr = myTree.get(ptr, LEFT);
   // ptr = myTree.get(ptr, RIGHT);
   // ptr = myTree.get(ptr, LEFT);
   // ptr = myTree.get(ptr, RIGHT);
   // myTree.func(PRINTF, ptr);

   // myTree.postOrder_loop(myTree.root(), PRINTF);

   // std::cout << "height is " << myTree.height(myTree.root()) << std::endl;
   // std::cout << "height is " << myTree.height_2(myTree.root()) << std::endl;

   // linkQueue<char> myQueue;
   // myQueue.initQueue();
   // myQueue.enQueue('X');
   // myQueue.enQueue('Y');
   // myQueue.enQueue('Z');
   // myQueue.deQueue();
   // myQueue.deQueue();
   // std::cout << myQueue.isEmpty() << std::endl;
   // myQueue.deQueue();
   // std::cout << myQueue.isEmpty() << std::endl;

   return 0;
}