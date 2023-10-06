#include <maze.hpp>
//#include <Stack.hpp>


maze::maze(void)
{}

maze::~maze(void)
{}

bool maze::traverse(int& x, int& y, int val)
{
    if (Map[y - 1][x] == val)//上
    {
        --y;
        return 1;
    }
    else if (Map[y][x - 1] == val)
    {
        --x;
        return 1;
    }
    else if (Map[y + 1][x] == val)
    {
        ++y;
        return 1;
    }
    else if (Map[y][x + 1] == val)
    {
        ++x;
        return 1;
    }
    else 
    {
        //std::cout << "no place matches traverse condition!" << std::endl;
        return 0;
    }
}

bool maze::init(std::vector<std::vector<int>>& myMaze, int start_x, int start_y, int dst_x, int dst_y)
{
    Map = myMaze;

    std::vector<int> tmp(Map[0].size(), 1);

    Map.insert(Map.begin(), tmp);
    Map.insert(Map.end(), tmp);

    for (auto& a : Map)
    {
        a.insert(a.begin(), 1);
        a.insert(a.end(), 1);
    }

    this->start_x = start_x + 1;
    this->start_y = start_y + 1;
    this->dst_x = dst_x + 1;
    this->dst_y = dst_y + 1;

    return 1;
}

void maze::print_map(void)
{
    for (auto& tmp_1 : Map)
    {
        for (auto& tmp_2 : tmp_1)
        {
            std::cout << tmp_2 << ' '; 
        }
        std::cout << std::endl;
    }
}

bool maze::find_dst(void)
{
    std::cout << "dst_x = " << dst_x << dst_y << std::endl;
    std::cout << "map = " << Map[start_x][start_y] << std::endl;
    if (Map[start_y][start_x] != 0 || Map[dst_y][dst_x] != 0)
    {
        std::cout << "start or end error!" << std::endl;
        return 0;
    }

    Stack<stackType> myStack;
    myStack.initStack_SQ();

    myStack.push_back({start_x, start_y});
    x = start_x;
    y = start_y;
    std::cout << "91" << std::endl;
    while (1)
    {
        if (myStack.isEmpty())
        {
            std::cout << "error! no solution!" << std::endl;
            return 0;
        }

        if (x == dst_x && y == dst_y)
        {
            std::cout << "102" << std::endl;
            break;
        }


        if (traverse(x, y, 0))
        {
            //std::cout << "x = " << x << "y = " << y << std::endl;
            Map[y][x] = -1;
            myStack.push_back({x, y});
        }
        else
        {
            myStack.pop_back();

            stackType tmp;
            tmp = myStack.getTop();
            x = tmp.x;
            y = tmp.y;
        }
    }
    
    Stack<stackType> temp;
    temp.initStack_link();
    while (1)
    {
        if (myStack.isEmpty())
            break;
        temp.push_back(myStack.pop_back());
    }

    while (1)
    {
                
        if (temp.isEmpty())
            break;
        std::cout << temp.getTop().x - 1 << ", " << temp.getTop().y - 1 << std::endl;
        temp.pop_back();
    }
    return 1;
}
