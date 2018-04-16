//
// Created by liuwenbin on 18-4-16.
//

#include "Vector2.h"
#include "Container.h"
#include <cmath>
#include <iostream>

using namespace std;

double sqrt_sum(Vector2 &v) {
    double sum = 0;
    for (int i = 0; i != v.size(); ++i) {
        sum += sqrt(v[i]);
    }
    return sum;
}

// CMakeLists.txt中add_executable只要加入实现类即可，换句话说不必加入.h文件
int main() {
    Vector2 v(4000);// 传入的整数为double数组的大小，但是由于Vector2中存储的只是“句柄”，这在上面已经提过了，Vector2对象的大小是永远不变的，是16。
//    v[0] = 1;
//    v[2] = 1;
//    try {
//        v[1] = 1;//没有越界处理（不是工程代码，还有很多待完善）
//    } catch (out_of_range) {
//        cout << "out_of_range error";
//        return 0;
//    }
//    cout << sqrt_sum(v);
    cout << sizeof(v);
    static_assert(32 <= sizeof(v), "size is too small!");
}
