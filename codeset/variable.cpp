//
// Created by liuwenbin on 18-4-14.
//
#include <iostream>

using namespace std;

int main() {
//    int a{1}; // 使用初始化器，可以有效避免因为类型转换而被强制削掉的数据信息。例如int a {1.2}无法通过编译，而int a=1.2会直接削掉小数部分，a最后等于1
//    int b = 2.2;
//    cout << a << "  " << b;
    auto c = 1.2;
    auto d = 'x';
    auto e = true;
    cout << c <<" "<< d  <<" "<< e;
};