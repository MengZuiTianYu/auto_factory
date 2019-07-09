/*************************************************************************
 > File Name: message.h
 > Author: XinYuan Wang
 > Mail: xywang@aiit.org.cn
 > Created Time: Tue Jul  9 13:49:29 2019
 ************************************************************************/

#include "base_message.h"


class FirstB : public BaseMessage {
public:
    void display() override
    {
        std::cout << __func__ << " FirstB\n";
    }
};
REGISTER_AF_OBJECT_CLASS(FirstB);

class SecondB : public BaseMessage {
public:
    SecondB(const std::string name = "")
    {
        nameString = name;
    }

    void display() override
    {
        std::cout << __func__ << " SecondB\n";
        std::cout << nameString << "\n";
    }

private:
    std::string nameString;
};
REGISTER_AF_OBJECT_CLASS(SecondB, "Welcome");  //带参构造函数

class ThirdB : public BaseMessage { 
public:
    ThirdB(int age, const std::string name = "")
    {
        nameString = name;
        ageInt     = age;
    }
    void display() override
    {
        std::cout << __func__ << " ThirdB\n";
        std::cout << nameString << ":" << ageInt << "\n";
    }

private:
    std::string nameString;
    int         ageInt;
};
REGISTER_AF_OBJECT_CLASS(ThirdB, 20, "Tom"); //带参构造函数
