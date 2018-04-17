//
// Created by liuwenbin on 18-4-16.
//

#ifndef BANNER_CONTAINER_H
#define BANNER_CONTAINER_H


#include <iostream>
// 多态类型
class Container {
public:
    virtual double &operator[](int) = 0;//纯虚函数，
    virtual int size() const = 0;// 常量成员
    virtual ~Container() {};//析构函数
};

#endif //BANNER_CONTAINER_H
