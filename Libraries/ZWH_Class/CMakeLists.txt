add_library(ZWH_Class RandomBag.cpp BankAccount.cpp BinaryTree.hpp linearList.hpp maze.cpp myQueue.hpp myStack.hpp)

target_include_directories(ZWH_Class PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/.)