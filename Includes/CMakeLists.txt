

add_library(Includes include.cpp)

target_link_libraries(Includes ZWH_App)
target_link_libraries(Includes ZWH_Class)
#target_link_libraries(Includes ZWH_Drive)
target_include_directories(Includes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/.)