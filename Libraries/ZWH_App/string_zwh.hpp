#ifndef __STRING_ZWH
#define __STRING_ZWH

#include <iostream>
#include <sstream>


extern int getInteger(const std::string prompt, const std::string reprompt);
extern int stringToInteger(const std::string& s);
extern void printStatebits(const std::istream& iss);//检测状态位，其中“istream是一个通用的输入流类，而istringstream是专门用于处理字符串输入的类”


#endif