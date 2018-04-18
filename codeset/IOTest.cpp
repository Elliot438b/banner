//
// Created by liuwenbin on 18-4-18.
//
#include <string>
#include <iostream>
#include <vector>

using namespace std;
struct Entry {
    string name;
    int number;
};


// 输出比较好实现，就是相当于拼串
ostream &operator<<(ostream &os, const Entry &e) {
    return os << "{\"" << e.name << "\"," << e.number << "}";
}

//// 输入要检查很多格式，所以比较复杂
//istream &operator>>(istream &is, Entry &e) {
//    char c, c2;
//    if (is >> c && c == '{') {// 以一个{开始，
//        string name;// 收集name的信息
//        while (is.get(c) && c != ',') {
//            name += c;
//        }
//        if (is >> c && c == ',') {// 以，间隔，开始收集number的信息
//            int number = 0;
//            if (is >> number >> c && c == '}') {// 直到遇到}结束
//                e = {name, number};
//                return is;
//            }
//        }
//    }
//    is.setf((ios_base::fmtflags) ios_base::failbit);
//    return is;
//}

int main() {
    Entry ee{"John Holdwhere", 3421};
    cout << ee << "\n";
    vector<int> v1{1, 2, 3, 4};
    vector<Entry> en2{{"John Holdwhere", 3421},
                      {"John Holdwhere", 3421},
                      {"John Holdwhere", 3421}};
    cout << v1[2];
    cout << en2[2].number;
}