add_library(ZWH_App RandomBag.cpp BankAccount.cpp string_zwh.cpp collection_zwh.cpp Stacks&Queues.cpp maze.cpp)
set_target_properties(ZWH_App PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(ZWH_App PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/.)
target_include_directories(ZWH_App PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../ZWH_Class)