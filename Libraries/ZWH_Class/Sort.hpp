#pragma once



template <typename T>
class Sort
{
public:
    // bool init(const int& size);
    // T& operator[](const int& n);

/****************************************一、插入排序*****************************************/
    bool InsertionSort(T* const& arr, const int& elem_size, bool (* compare)(T a, T b));
    //直接插入排序，不要在第0个位置放内容！！！
    bool InsertionSort_Bi(T* const& arr, const int& elem_size, bool (* compare)(T a, T b));
    //折半插入排序，不要在第0个位置放内容！！！
    bool ShellSort(T* const& arr, const int& elem_size, bool (* compare)(T a, T b));
    //希尔排序

/****************************************二、交换排序*****************************************/
    bool BubbleSort(T* const& arr, const int& elem_size, bool (* compare)(T a, T b));
    //冒泡排序
    void QuickSort(T* const& arr, int low, int high, bool (* compare)(T a, T b));//注意这里的形参！！
    //快速排序

/****************************************三、选择排序*****************************************/
    bool SelectSort(T* const& arr, const int& elem_size, bool (* compare)(T a, T b));
    //简单选择排序
    bool HeapSort(T* const& arr, const int& elem_size, bool (* compare)(T a, T b));
    //堆排序

/****************************************四、归并排序*****************************************/
    bool MergeSort(T*& arr, const int& elem_size, bool (* compare)(T a, T b));
    //归并排序

/****************************************五、基数排序*****************************************/
    bool RadixSort(T* const& arr, const int& elem_size, bool (* compare)(T a, T b));
    //基数排序
    
private:
    // T* elem = 0;
    // int size = 0;

    int QuickSort_Partition(T* const& arr, int low, int high, bool (* compare)(T a, T b));//快速排序函数里调用的分治方法
    bool Heap_Adjust(T* const& arr, int top, const int& elem_size, bool (* compare)(T a, T b));//堆排序函数里调用的堆调整
    bool Heap_Adjust_2(T* const& arr, int rear, bool (* compare)(T a, T b));
};



#include <Sort.cpp>