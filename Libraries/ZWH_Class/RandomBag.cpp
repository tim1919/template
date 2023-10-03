#include <RandomBag.hpp>


void RandomBag::add(int value)
{
    //elems += value;
    elems.push_back(value);
}


int RandomBag::removeRandom(void)
{
    if (isEmpty())
    {
        std::cout << ("error!\n") << std::endl;
    }
    srand(time(0));
    int index = rand() % size();
    int result = elems[index];
    elems.erase(elems.begin() + index);
    //std::remove(elems.begin(), elems.end(), result);
    return result;
}

int RandomBag::size(void) const
{
    return elems.size();
}

bool RandomBag::isEmpty(void) const
{
    return size() == 0;
}