#pragma once//这个相当于#ifndef
#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>
class RandomBag
{
public:
    void add(int value);
    int removeRandom(void);
    int size(void) const;
    bool isEmpty(void) const;
private:
    std::vector<int> elems;
};