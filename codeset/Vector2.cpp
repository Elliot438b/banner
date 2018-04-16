//
// Created by liuwenbin on 18-4-14.
//

#include "Vector2.h"//头文件声明（接口），cpp文件实现，名称要一致。
#include <stdexcept>

Vector2::Vector2(int s)
        : elem{new double[s]}, sz{s} {

}

Vector2::Vector2(std::initializer_list<double> lst) : elem{new double[lst.size()]}, sz{lst.size()} {
    copy(lst.begin(), lst.end(), elem);
}

Vector2::Vector2(std::initializer_list<double> lst) {
    elem{new double[lst.size()]}, sz{lst.size()};
    copy(lst.begin(), lst.end(), elem);
}

double &Vector2::operator[](int i) {
    if (i >= size())throw std::out_of_range("Vector2::operator[]");// std是标准库的意思，上面包含了<stdexcept>库，这里统一使用std作为命名空间。
    return elem[i];
}

int Vector2::size() const {//Vector2::这种写法用来代表实现了哪个接口的哪个方法
    return sz;
}

// 加入析构函数
~Vector2() {
    delete[] elem;
}