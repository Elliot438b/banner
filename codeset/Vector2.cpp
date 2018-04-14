//
// Created by liuwenbin on 18-4-14.
//

#include "Vector2.h"//头文件声明（接口），cpp文件实现，名称要一致。

Vector2::Vector2(int s) : elem{new double[s]}, sz{s} {}

double &Vector2::operator[](int i) { return elem[i]; }

int size() { return sz; }