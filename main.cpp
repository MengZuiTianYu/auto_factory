/*************************************************************************
 > File Name: main.cpp
 > Author: XinYuan Wang
 > Mail: xywang@aiit.org.cn
 > Created Time: Tue Jul  9 13:52:40 2019
 ************************************************************************/

#include "message.h"

int main()
{
    std::string class_name = "FirstB";
    REGISTER_AF_OBJECT_CLASS(FirstB);
    REGISTER_AF_OBJECT_CLASS(SecondB, "Welcome");  //带参构造函数
    REGISTER_AF_OBJECT_CLASS(ThirdB, 20, "Tom"); //带参构造函数


    QUERY_AF_OBJECT_BY_KEY(class_name)->display();
    
    QUERY_AF_OBJECT_BY_CLASS(SecondB)->display();

    QUERY_AF_OBJECT_BY_KEY("SecondB")->display();
    QUERY_AF_OBJECT_BY_KEY("ThirdB")->display();
    return 0;


}
