#ifndef __COLLECTION_ZWH_HPP
#define __COLLECTION_ZWH_HPP

#include <vector>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <list>


extern void erase_vector_val(std::vector<int>& vec, int val);


template <typename DataType>
inline bool isEven(DataType val)//当您将函数声明为 inline 时，编译器会尝试将函数的定义插入到调用该函数的地方，而不是实际生成函数调用。
{
    return val % 2 == 0;
}

template <typename InputIterator, typename DataType>
int countOccurences_1(InputIterator begin, InputIterator end, DataType val)
{
    int count = 0;
    for (auto iter = begin; iter != end; ++iter)
    {
        if (*iter == val)
            ++count;
    }
    return count;
} 


template <typename Collection, typename DataType>
int countOccurences_2(const Collection& list, DataType val)
{
    int count = 0;
    for (int i = 0; i < list.size(); ++i)
    {
        if (list[i] == val)
            ++count;
    }
    return count;
}

// template <typename It, typename Type>
//     requires Input_Iterator<It> && Iterator_of<It> && Equality_comparable<Value_type<It>, Type>
// int countOccerences_3(It begin, It end, Type val)
// {
//     int count = 0;
//     for (auto iter = begin; iter != end; ++iter)
//     {
//         if (*iter == cal)
//             ++count;
//     }
//     return count;
// }

template <typename InputIterator, typename UniaryPredicate>
int countOccurences_4(InputIterator begin, InputIterator end, UniaryPredicate predicate)//这里的predicate传入的是一个“谓词函数”，你可以试着调用一下函数isEven()
{
    int count = 0;
    for (auto iter = begin; iter != end; ++iter)
    {
        if (predicate(*iter))//注意这里的细节
            ++count;
    }
    return count;
}

#endif