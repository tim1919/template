#include <Stacks&Queues.hpp>

void convert_10_to_2(int val)
{
   Stack<int> myStack;
   myStack.initStack_link();
   while (1)
   {
      myStack.push_back(val % 2);
      val /= 2;
      if (val == 0)
         break;
   }
   // std::cout << myStack.length() << std::endl;
   while (myStack.length())
   {
      std::cout << myStack.getTop();
      myStack.pop_back();
   }
}

bool bracket_check(char ch[])//目前仅支持()和[]
{
   Stack<char> myStack;
   myStack.initStack_link();
   std::cout << "length = " << strlen(ch) << std::endl;
   for (int i = 0; i < strlen(ch); ++i)
   {
      if ('(' == ch[i] || '[' == ch[i])
      {
         myStack.push_back(ch[i]);
      }

      if (')' == ch[i] || ']' == ch[i])
      {
         //std::cout << (myStack.isEmpty() ? "empty" : "not empty") << std::endl;
         //std::cout << myStack.getTop() << std::endl;
         if (myStack.isEmpty())
         {
            //std::cout << "???";
            std::cout << "error: no left bracket!";
            return 0;
         }
         if (')' == ch[i])
         {
            if ('(' == myStack.getTop())
            {
               myStack.pop_back();
            }
            else
            {
               std::cout << "error: match error!" << std::endl;
               return 0;
            }
         }
         if (']' == ch[i])
         {
            if ('[' == myStack.getTop())
            {
               myStack.pop_back();
            }
            else
            {
               std::cout << "error: match error!" << std::endl;
            }
         }

      }
   }
   return 1;
}