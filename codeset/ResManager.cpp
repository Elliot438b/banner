//
// Created by liuwenbin on 18-4-19.
//
#include <vector>
#include <bits/unique_ptr.h>
#include <iostream>

using namespace std;

void f(int i, int j) {
    vector<int> *p = new vector<int>;// New是分配内存空间，所以要用指针类型变量来接收
    unique_ptr<vector<int>> sp{new vector<int>};
    // p和sp的区别就是，如果在下面操作中发生异常中止或者直接返回，p会执行不了delete，而因为sp是unique_ptr指针分配的，所以会保证在程序中止时释放掉sp的资源。
    if (i < 77) {
        return;
    }
    // 释放普通指针变量的资源。
    delete p;
}

int main() {
    f(1, 1);
    // 其实我们完全不必要使用new，以及指针和引用，因为很容易不小心就变成了滥用。
    vector<int> p;
    p = {1, 2};
    cout << p[1];
}

