//
// Created by liuwenbin on 18-4-19.
//
#include <vector>
#include <numeric>
#include <functional>
#include <iostream>
#include <future>

using namespace std;

double accum(double *beg, double *end, double init) {
    // 注意：accumulate在库<numeric>中。
    return accumulate(beg, end, init);// 计算（beg:end）中元素的和，计算的初始值是init。
}

double comp2(vector<double> &v) {
    // using 别名关键字。可以全局命名空间，也可以定义一个结构的别名：任何作用域内提到别名的时候就可以用它的定义代替。
    using Task_type = double(double *, double *, double);
    packaged_task<Task_type> pt0{accum};
    packaged_task<Task_type> pt1{accum};

    future<double> f0{pt0.get_future()};
    future<double> f1{pt1.get_future()};

    double *first = &v[0];
    thread t1{move(pt0), first, first + v.size() / 2, 0};
    thread t2{move(pt1), first + v.size() / 2, first + v.size(), 0};

    return f0.get() + f1.get();
}