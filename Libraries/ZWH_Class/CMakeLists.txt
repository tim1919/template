
add_library(ZWH_Class BinaryTree.hpp linearList.hpp myQueue.hpp myStack.hpp )
set_target_properties(ZWH_Class PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(ZWH_Class PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/.)