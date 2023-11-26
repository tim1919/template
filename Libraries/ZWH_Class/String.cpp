int Match_Force(const std::string& S, const std::string& T)//法一：暴力匹配法
{
    int i = 0, j = 0;
    while (1)
    {
        if (T.length() > S.length() || (0 == j && i > S.length() - T.length()))
        {
            break;
        }
        if (S[i] == T[j])
        {
            if (j == T.length() - 1)
            {
                return i - T.length() + 1;
            }
            ++i;
            ++j;
        }
        else
        {
            j = 0;
            i = i - j + 1;
        }
        // ++i;
    }
    return -1;
}

int KMP(const std::string& S, const std::string& T)//法二：KMP 算法
{
    int* next = new int[T.length()];
    next[0] = -1;// -1 表示若第一位就匹配失败，则令 j 指向子串前面的一位，即令子串后移一位
    int i = 0, j = -1;// i 在 T[i] 与 T[j] 比较之前是已匹配的后缀后面的第一个字符，j 是前缀后面的第一个字符
    while (i < T.length() - 1)
    {
        if (-1 == j || T[i] == T[j])// -1 == j 其实是：1. 对第二个字符（即 next[1] ）的特殊处理 2. 收住一直回退的 j 
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];//j一直回退直到匹配或者到头
        }
    }
    //第一步：求 next 数组


    i = 0;
    j = 0;
    while (j < (int)T.length() && i < (int)S.length())
    {
        std::cout << "??" << std::endl;
        if (-1 == j || S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    //第二步：主串和子串相匹配

    if (j == T.length())
    {
        return i - T.length();
    }
    else
    {
        return -1;
    }
}

