//
// Created by liuwenbin on 18-4-18.
//
#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct EntryC {
    int number;
    string name;
};

int main() {
    list<int> i2{1, 2, 3, 4};
//    list<int>::iterator p;
//    i2.insert(p, 2);
    for (auto &x:i2)// 引用指的是指针位置的值，指针指的是变量所在的位置，一个变量包括位置（指针）值（引用），赋值时可以修改自身（通过引用），拷贝一份（裸变量名）
        cout << x << endl;

    map<string, int> m1{{"YANSUI", 55},
                        {"AKA",    991},
                        {"FYke",   0110}};
    cout << "size = " << m1.size() << endl;
    cout << m1.at("AKA") << endl;
    cout << m1["FYke"] << endl;

}