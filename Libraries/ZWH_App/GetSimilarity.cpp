#include <GetSimilarity.hpp>

bool File_Creator::init(void)
{
    num = 1;
    return 1;
}

std::string File_Creator::create(const std::string& path)
{
    std::stringstream fname;
    std::ofstream fout;

    fname << path << num << ".txt";
    fout.open(fname.str());

    if (!fout.is_open())
    {
        std::cout << "error! failed to create new file! (from GetSimilarity.cpp/Create)" << std::endl;
        return 0;
    }

    char ch;

    while (std::cin.get(ch) && ch != '#')
    {
        fout << ch;
    }

    fout.close();
    ++num;
    return fname.str();
}

// bool File_Creator::format(void)
// {}
int Similarity_Calculator::Hash(const std::string& elem)
{
    int hash_val = 0;
    for (char ch : elem)
    {
        hash_val = (hash_val * BASE + (int)ch) % M;
    }
    return hash_val;
}

// bool Similarity_Calculator::insert_Hash(HashNode** const& table, std::string& elem)
// {
//     int n = Hash(elem);
//     if (0 == table[n])
//     {
//         table[n] = new HashNode[1];
//         table[n]->data = elem;
//         table[n]->next = 0;
//     }
//     else
//     {
//         HashNode* ptr = table[n];
//         while (1)
//         {
//             if (0 == ptr->next)
//             {
//                 break;
//             }
//             ptr = ptr->next;
//         }
//         ptr->next = new HashNode[1];
//         ptr->next->data = elem;
//         ptr->next->next = 0;
//     }
//     return 1;
// }


// bool Similarity_Calculator::format_and_insert_1(std::ifstream& fin)
// {
//     // std::ofstream tmp;
//     // tmp.open("test_1.txt");
//     while (1)
//     {
//         std::string word;
//         if (!(fin >> word))
//         {
//             break;
//         }

//         std::string word_handled;
//         for (int i = 0; i < word.length() + 1; ++i)
//         {
//             char ch = word[i];
//             if ((!std::isalpha(ch)) || i == word.length())//如果遇到了非字母字符
//             {
//                 if (word_handled.length() >= 3)
//                 {
//                     if (word_handled.length() > 10)
//                     {
//                         word_handled.erase(10);
//                     }
//                     // insert_Hash(table, word_handled);
//                     int n = Hash(word_handled);
//                     if (0 == HashTable_1[n])
//                     {
//                         HashTable_1[n] = new HashNode[1];
//                         HashTable_1[n]->data = word_handled;
//                         HashTable_1[n]->next = 0;
//                         ++dictionary_length;
//                     }
//                     else
//                     {
//                         HashNode* ptr = HashTable_1[n];
//                         while (1)
//                         {
//                             if (word_handled == ptr->data)//如果表中有重复的
//                             {
//                                 break;
//                             }
//                             if (0 == ptr->next)
//                             {
//                                 ptr->next = new HashNode[1];
//                                 ptr->next->data = word_handled;
//                                 ptr->next->next = 0;
//                                 ++dictionary_length;
//                                 break;
//                             }
//                             ptr = ptr->next;
//                         }

//                     }
//                     // tmp << word_handled << ' ';
//                 }
//                 word_handled.clear();
//             }
//             else
//             {
//                 word_handled += std::tolower(ch);
//             }
//         }
//     }
//     // tmp.close();
//     return 1;

// }


// bool Similarity_Calculator::format_and_insert_2(std::ifstream& fin)
// {
//     // std::ofstream tmp;
//     // tmp.open("test_1.txt");
//     while (1)
//     {
//         std::string word;
//         if (!(fin >> word))
//         {
//             break;
//         }

//         std::string word_handled;
//         for (int i = 0; i < word.length() + 1; ++i)
//         {
//             char ch = word[i];
//             if ((!std::isalpha(ch)) || i == word.length())//如果遇到了非字母字符
//             {
//                 if (word_handled.length() >= 3)
//                 {
//                     if (word_handled.length() > 10)
//                     {
//                         word_handled.erase(10);
//                     }
//                     // insert_Hash(table, word_handled);
//                     int n = Hash(word_handled);
//                     if (0 == HashTable_2[n])
//                     {
//                         HashTable_2[n] = new HashNode[1];
//                         HashTable_2[n]->data = word_handled;
//                         HashTable_2[n]->next = 0;
//                         if (isEqual(word_handled, n))
//                         {
//                             ++equal_word_num;
//                         }
//                         else
//                         {
//                             ++dictionary_length;
//                         }
//                     }
//                     else
//                     {
//                         HashNode* ptr = HashTable_2[n];
//                         while (1)
//                         {
//                             if (word_handled == ptr->data)//如果表中有重复的
//                             {
//                                 break;
//                             }
//                             if (0 == ptr->next)
//                             {
//                                 ptr->next = new HashNode[1];
//                                 ptr->next->data = word_handled;
//                                 ptr->next->next = 0;
//                                 if (isEqual(word_handled, n))
//                                 {
//                                     ++equal_word_num;
//                                 }
//                                 else
//                                 {
//                                     ++dictionary_length;
//                                 }
//                                 break;
//                             }
//                             ptr = ptr->next;
//                         }

//                     }
//                     // tmp << word_handled << ' ';
//                 }
//                 word_handled.clear();
//             }
//             else
//             {
//                 word_handled += std::tolower(ch);
//             }
//         }
//     }
//     // tmp.close();
//     return 1;

// }

// bool Similarity_Calculator::isEqual(const std::string& str, const int& n)
// {
//     HashNode* ptr = HashTable_1[n];
//     while (1)
//     {
//         if (0 == ptr)
//         {
//             return 0;
//         }

//         if (str == ptr->data)
//         {
//             return 1;
//         }
//         ptr = ptr->next;
//     }
// }

// bool Similarity_Calculator::init(void)
// {
//     // delete[] HashTable_1;
//     // delete[] HashTable_2;
//     // HashTable_1 = new HashNode*[HASH_TABLE_LENGTH];
//     // HashTable_2 = new HashNode*[HASH_TABLE_LENGTH];
//     // // HashTable_1 = (HashNode**)malloc(sizeof(HashNode*));
//     // // HashTable_2 = (HashNode**)malloc(sizeof(HashNode*));
//     // for (int i = 0 ; i < HASH_TABLE_LENGTH; ++i)
//     // {
//     //     HashTable_1[i] = 0;
//     //     HashTable_2[i] = 0;
//     // }
//     dictionary_length = 0;
//     equal_word_num = 0;
//     return 1;
// }

std::string Similarity_Calculator::input_and_format(const std::string& file)
{
    // auto iter = file.end();
    // while (iter > file.begin() && (* iter) != '/')
    // {
    //     --iter;
    // }
    int i = file.length() - 1;
    while (i >= 0 && file[i] != '/')
    {
        --i;
    }
    std::string file_name = file.substr(i + 1);
    std::cout << file_name << std::endl;
    std::stringstream formatted_file_name;
    formatted_file_name << "../Data/ZWH_App/GetSimilarity/Similarity_Calculator/formatted/" << file_name;

    std::ofstream fout;
    fout.open(formatted_file_name.str());
    if (!fout.is_open())
    {
        std::cerr << "failed to open file! (from GetSimilarity.cpp/input_and_format)" << std::endl;
        return 0;
    }

    std::ifstream fin;
    fin.open(file);
    if (!fin.is_open())
    {
        std::cerr << "failed to open file! (from GetSimilarity.cpp/input_and_format 2)" << std::endl;
        return 0;
    }

    std::string word, word_handled;
    while (fin >> word)
    {
        for (int i = 0; i < word.length() + 1; ++i)
        {
            char ch = word[i];
            if (std::isalpha(ch) && i != word.length())
            {
                word_handled += std::tolower(ch);
            }
            else
            {
                if (word_handled.length() >= 3)//如果长度大于3，则不筛去，进一步处理后存入新文件
                {
                    if (word_handled.length() > 10)
                    {
                        word_handled.erase(10);
                    }
                    fout << word_handled << ' ';
                }
                word_handled.clear();
            }
        }
    }

    HashTable[file_name] = 0;

    fout.close();
    fin.close();

    return file_name;
}

float Similarity_Calculator::insert_and_cal(const std::string& file_1, const std::string& file_2)
{
    std::ifstream fin[2];
    fin[0].open("../Data/ZWH_App/GetSimilarity/Similarity_Calculator/formatted/" + file_1);
    fin[1].open("../Data/ZWH_App/GetSimilarity/Similarity_Calculator/formatted/" + file_2);
    if (!(fin[0].is_open() && fin[1].is_open()))
    {
        std::cerr << "failed to open file! (from GetSimilarity.cpp/insert_and_cal)" << std::endl;
        return 0;
    }

    delete[] HashTable[file_1];
    delete[] HashTable[file_2];

    HashTable[file_1] = new HashNode*[HASH_TABLE_LENGTH];
    HashTable[file_2] = new HashNode*[HASH_TABLE_LENGTH];

    HashNode** table[2] = {HashTable[file_1], HashTable[file_2]};//两个表改成数组，方便调用

    for (int i = 0; i < HASH_TABLE_LENGTH; ++i)
    {
        HashTable[file_1][i] = 0;
        HashTable[file_2][i] = 0;
    }//哈希表初始化

    int dictionary_length = 0, equal_word_num = 0;
    bool flag_if_inserted = 0;

    std::string word;
    for (int i = 0; i < 2; ++i)
    {
        while (fin[i] >> word)
        {
            int n = Hash(word);//求得哈希值

            if (0 == table[i][n])
            {
                table[i][n] = new HashNode[1];
                table[i][n]->data = word;
                table[i][n]->next = 0;
                flag_if_inserted = 1;
            }
            else
            {
                HashNode* ptr = table[i][n];
                while (word != ptr->data)
                {
                    if (0 == ptr->next)
                    {
                        ptr->next = new HashNode[1];
                        ptr->next->data = word;
                        ptr->next->next = 0;
                        flag_if_inserted = 1;
                        break;
                    }
                    ptr = ptr->next;
                }
            }//第一步：插入

            if (1 == flag_if_inserted)//如果存在插入操作
            {
                if (0 == i)
                {
                    ++dictionary_length;
                }
                else
                {
                    HashNode* ptr_2 = table[0][n];
                    while (1)
                    {
                        if (0 == ptr_2)
                        {
                            ++dictionary_length;
                            break;
                        }
                        if (word == ptr_2->data)
                        {
                            ++equal_word_num;
                            break;
                        }
                        ptr_2 = ptr_2->next;
                    }
                }
            } 
            flag_if_inserted = 0;
            word.clear();
        }
    }
    fin[0].close();
    fin[1].close();
    return (float)equal_word_num / dictionary_length;
}

// bool Similarity_Calculator::input(const std::string& file_1, const std::string& file_2)
// {
//     std::ifstream fin_1, fin_2;
//     fin_1.open(file_1);
//     fin_2.open(file_2);
//     // fin_2.open(file_2);

//     if (!(fin_1.is_open() && fin_2.is_open()))
//     {
//         std::cout << "error! failed to open file! (from GetSimilarity.cpp/input)" << std::endl;
//         return 0;
//     }

    
//     format_and_insert_1(fin_1);
//     format_and_insert_2(fin_2);
//     // while (1)
//     // {
//     //     std::string word;
//     //     if (!(fin >> word))
//     //     {
//     //         break;
//     //     }

//     //     std::string word_handled;
//     //     for (int i = 0; i < word.length() + 1; ++i)
//     //     {
//     //         char ch = word[i];
//     //         if ((!std::isalpha(ch)) || i == word.length())//如果遇到了非字母字符
//     //         {
//     //             if (word_handled.length() >= 3)
//     //             {
//     //                 if (word_handled.length() > 10)
//     //                 {
//     //                     word_handled.erase(10);
//     //                 }
//     //                 // insert_Hash(table, word_handled);
//     //                 int n = Hash(word_handled);
//     //                 if (0 == table[n])
//     //                 {
//     //                     table[n] = new HashNode[1];
//     //                     table[n]->data = elem;
//     //                     table[n]->next = 0;
//     //                 }
//     //                 else
//     //                 {
//     //                     HashNode* ptr = table[n];
//     //                     while (1)
//     //                     {
//     //                         if (0 == ptr->next)
//     //                         {
//     //                             break;
//     //                         }
//     //                         ptr = ptr->next;
//     //                     }
//     //                     ptr->next = new HashNode[1];
//     //                     ptr->next->data = elem;
//     //                     ptr->next->next = 0;
//     //                 }
//     //                 // tmp << word_handled << ' ';
//     //             }
//     //             word_handled.clear();
//     //         }
//     //         else
//     //         {
//     //             word_handled += std::tolower(ch);
//     //         }
//     //     }
//     // }
//     // std::string word;
//     return 1;
// }


// float Similarity_Calculator::cal_similarity(void)
// {
//     return (float)equal_word_num / dictionary_length;
//     // std::cout << dictionary_length << "  " << equal_word_num << std::endl;
//     // return 1;
// }