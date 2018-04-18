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

bool has_c(const string &s, char c) {
//    auto p = find(s.begin(), s.end(), c);
//    if (p != s.end()) {// 如果找不到，返回的是end();
//        return true;
//    } else {
//        return false;
//    }
    return find(s.begin(), s.end(), c) != s.end();// 短版
}

// 在字符串中查找一个字符出现的所有位置。我们返回一个string迭代器的vector。
vector<string::iterator> find_all(string &s, char c) {
    vector<string::iterator> res;
    for (auto p = s.begin(); p != s.end(); ++p) {
        if (*p == c) {// 找到位置相同的元素了
            res.push_back(p);
        }
    }
    return res;
}

void findall_test() {
    string m{"Mary had a little lamb"};
    for (auto p:find_all(m, 'a')) {
        if (*p != 'x') {
            cerr << "a bug" << endl;
        }
    }
}

struct Greater_than {
    int val;

    Greater_than(int v) : val{v} {};

    // 通过pair来配对map的搜索，pair是专门用来做predicate操作而存在的。
    bool operator()(const pair<string, int> &r) { return r.second > val; };
};

void f(map<string, int> &m) {
    auto p = find_if(m.begin(), m.end(), Greater_than{42});
    //...
}

int main() {
//    string name = "YANSUYI";
//    cout << has_c(name, 'Y') << endl;
//    cout << has_c(name, 'O') << endl;
//    for (auto p:find_all(name, 'Y')) {
//        cout << *p << endl;//cout标准输出默认是通过<< 传入一个值的位置（指针），然后输出这个值的内容。
//        cout << &p << endl;//这里的p是一个对象，它本身是存着一个值的位置，使用引用以后，打印的是这个位置本身的值。
//    }
//    cout << find_all(name, 'O').size() << endl;
//    findall_test();
//    map<string, int> m1{{"YANSUI", 55},
//                        {"AKA",    991},
//                        {"FYke",   0110}};
//    int cxx = count_if(m1.begin(), m1.end(), [](const pair<string, int> &r) { return r.second > 42; });
//    cout << cxx;
    vector<int> v23{122, 8, 42};
    sort(v23.begin(), v23.end());
    for (auto &x:v23) {
        cout << x << endl;
    }
}