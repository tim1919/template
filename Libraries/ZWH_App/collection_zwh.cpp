#include <collection_zwh.hpp>

void erase_vector_val(std::vector<int>& vec, int val)
{
    for (auto iter = vec.begin(); iter != vec.end();)
    {
        if (*iter == val)
        {
            iter = vec.erase(iter);//安全删除，并获取有效迭代器，只有 erase 方法的返回值才是有效的迭代器。
        }
        else
        {
            ++iter;
        }
    }
}