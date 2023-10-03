add_library(ZWH_App string_zwh.cpp collection_zwh.cpp Stacks&Queues.cpp)

target_include_directories(ZWH_App PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/.)
target_include_directories(ZWH_App PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../ZWH_Class)