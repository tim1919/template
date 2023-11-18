#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>



struct HashNode
{
    std::string data;
    HashNode* next;
};



class File_Creator
{
private:
    int num = 1;
public:
    bool init(void);
    std::string create(const std::string& path);//键盘输入文件并写入 txt
    // bool format(void);//格式化
};



class Similarity_Calculator
{
private:
    // HashNode** HashTable_1 = 0;
    // HashNode** HashTable_2 = 0;
    std::map<std::string, HashNode**> HashTable;


    int BASE = 10;
    int M = 997;
    int HASH_TABLE_LENGTH = 1000;//哈希函数用

    // int dictionary_length = 0;//公共字典的长度
    // int equal_word_num = 0;//相同词汇的个数

    int Hash(const std::string& elem);
    // bool insert_Hash(HashNode** const& table, std::string& elem);
    // bool format_and_insert_1(std::ifstream& fin);//插入第一个哈希表
    // bool format_and_insert_2(std::ifstream& fin);

    // bool isEqual(const std::string& str, const int& n);
public:
    // bool init(void);
    std::string input_and_format(const std::string& file);
    float insert_and_cal(const std::string& file_1, const std::string& file_2);
    // bool input(const std::string& file_1, const std::string& file_2);
    // float cal_similarity(void);

};