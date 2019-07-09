/*************************************************************************
 > File Name: message.h
 > Author: XinYuan Wang
 > Mail: xywang@aiit.org.cn
 > Created Time: Tue Jul  9 13:47:19 2019
 ************************************************************************/

#include <iostream>
#include "auto_factory.h"
 
class BaseMessage {
public:
    virtual void display() = 0;
};
/**
 * 注册基类
 */
#define AF_OBJECT oly::auto_factory<BaseMessage>
/**
 * 注册子类，这里没有对继承关系进行判断，需要保证继承关系
 */
#define REGISTER_MESSAGE_VNAME(T) reg_msg_##T##_
#define REGISTER_AF_OBJECT_CLASS(T, ...) AF_OBJECT::register_t<T> REGISTER_MESSAGE_VNAME(T)(#T, ##__VA_ARGS__)
#define QUERY_AF_OBJECT_BY_CLASS(T) AF_OBJECT::normal_ptr (#T) 
#define QUERY_AF_OBJECT_BY_KEY(key) AF_OBJECT::normal_ptr (key) 


