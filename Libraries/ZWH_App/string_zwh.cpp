#include <string_zwh.hpp>

int getInteger(const std::string prompt, const std::string reprompt)
{
    while (1)
    {
        std::cout << prompt;
        std::string line;
        if (!getline(std::cin, line))
            throw std::domain_error("...");
        
        std::istringstream iss(line);
        int val; char remain;

        if (iss >> val && !(iss >> remain))
            return val;

        std::cout << reprompt << std::endl;
    }

    return 0;
}

int stringToInteger(const std::string& s)
{
    std::istringstream temp(s);
    printStatebits(temp);


    int result = 0;
    temp >> result;
    printStatebits(temp);


    if (temp.fail()) throw std::domain_error("error! no int at the beginning!");
    //方法二：去掉上面的temp >> result; 然后把此句改为：
    //if (!(temp >> result)) throw domain_error("错误！一开始就没有数字");
    //因为若temp >> result执行成功其会返回1，否则返回0

    if (!(temp.eof())) throw std::domain_error("error! not only single int!");
    //方法二：
    //char remain;
    //if (temp >> remain) throw domain_error("错误！不只一个数字！");

    std::cout << "result = " << result << std::endl;

    return result;
}

void printStatebits(const std::istream& iss)//检测状态位，其中“istream是一个通用的输入流类，而istringstream是专门用于处理字符串输入的类”
{
    std::cout << "State bits: ";

    std::cout << (iss.good() ? 'G' : '-');
    std::cout << (iss.fail() ? 'F' : '-');
    std::cout << (iss.eof() ? 'E' : '-');
    std::cout << (iss.bad() ? 'B' : '-');

    std::cout << "\n";
}