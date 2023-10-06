#pragma once

#include <vector>
#include <iostream>
#include <Stack.hpp>
#include <Queue.hpp>

class maze
{
public:
    maze(void);
    ~maze(void);
    bool traverse(int& x, int& y, int val);
    bool init(std::vector<std::vector<int>>& myMaze, int start_x, int start_y, int dst_x, int dst_y);
    void print_map(void);
    bool find_dst(void);
private:
    std::vector<std::vector<int>> Map;
    int length = 0;
    int width = 0;
    int start_x = 0;
    int start_y = 0;
    int dst_x = 0;
    int dst_y = 0;
    int x = 0;
    int y = 0;
};

struct stackType 
{
    int x = 0;
    int y = 0;
};