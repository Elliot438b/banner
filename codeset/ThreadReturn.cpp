//
// Created by liuwenbin on 18-4-19.
//
#include <vector>
#include <iostream>
#include <thread>

using namespace std;

void f(const vector<double> &v, double *res) {};// 从v获取输入，将结果放入*res

class F {
public:
    F(const vector<double> &vv, double *p) : v{vv}, res{p} {}

    void operator()() {};// 将结果放入*res

private:
    const vector<double> &v;// 输入源
    double *res;//输出目标
};

int main() {
    vector<double> some_vec;
    vector<double> vec2;

    double res1;
    double res2;

    thread t1{f, some_vec, &res1};// f(some_vec,&res1)在一个独立线程中执行
    thread t2{F{vec2, &res2}};// 相当于F{vec2,&res2}()，在一个独立线程中执行

    t1.join();
    t2.join();

    cout << res1 << ' ' << res2 << '\n';
}