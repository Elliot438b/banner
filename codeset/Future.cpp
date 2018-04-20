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
    return accumulate(beg, end, init);// 计算（beg:end）中元素的和，结果的原始值是init，如果init为10，那么无论beg，end啥样，结果要先加10。
}

void comp2(vector<double> &v) {
    // using 别名关键字。可以全局命名空间，也可以定义一个结构的别名：任何作用域内提到别名的时候就可以用它的定义代替。
    using Task_type = double(double *, double *, double);

    packaged_task<Task_type> pt0{accum};// 封装了promise和future，通过别名的结构打包任务
    packaged_task<Task_type> pt1{accum};

    future<double> f0{pt0.get_future()};// 获取pt0的future，现在我们有一个future对象f0了。
    future<double> f1{pt1.get_future()};

    double *first = &v[0];// 找到起始位置。
    // 为pt0启动一个线程
    thread t1{move(pt0), first, first + v.size() / 2, 0};//packaged_task不能被拷贝，所以要使用移动move()操作。
    // 为pt1启动一个线程
    thread t2{move(pt1), first + v.size() / 2, first + v.size(), 0};

    cout << f0.get() << endl;
    cout << f1.get() << endl;
    // 别忘记加join，等待执行完毕在关闭总程序。
    t1.join();
    t2.join();
}

void comp3(vector<double> &v) {
    double *first = &v[0];// 找到起始位置。
    auto v0 = &v[0];
    auto sz = v.size();

    auto f0 = async(accum, v0, v0 + sz / 2, 0);// 先算前一半
    auto f1 = async(accum, v0 + sz / 2, v0 + sz, 0);// 再算后一半

    //通过async异步执行，不必再操心线程和锁，只考虑可能异步执行的任务拆分即可。

    cout << f0.get() << endl;
    cout << f1.get() << endl;
}

int main() {
    vector<double> v{33, 10, 123, 1, 3};
    comp3(v);
}