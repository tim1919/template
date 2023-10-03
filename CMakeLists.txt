cmake_minimum_required(VERSION 3.14)
project(untitled)

add_subdirectory(./Includes)
add_subdirectory(./Libraries/ZWH_App)
add_subdirectory(./Libraries/ZWH_Class)
#add_subdirectory(./Libraries/ZWH_Drive)


add_executable(untitled main.cpp)
target_link_libraries(untitled Includes)
