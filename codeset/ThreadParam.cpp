//
// Created by liuwenbin on 18-4-19.
//
#include <vector>
#include <thread>

using namespace std;

void f(vector<double> &v){};//声明一个函数f

struct FF {
    vector<double> &v;// 以成员的方式保存了一个向量（vector是指向一个参数，变量都使用引用&）

    FF(vector<double> &vv) : v{vv} {}// 这里的单冒号是指使用成员。

    void operator()(){};
};

int main() {
    vector<double> some_vec{1, 2, 3, 4, 5, 6};
    vector<double> vec2{10, 11, 12, 13, 14, 15};

    thread t1{f, ref(some_vec)};// thread的可变参数模板构造函数。using the reference wraper with thread
    thread t2{FF{vec2}};// 以值传递的方式可保证其他线程不会访问vec2【因为值传递是复制一份值传递过去而不会修改vec2本身。】

    t1.join();
    t2.join();
}
//undefined reference to 'XXX' 错误都是因为使用了一个没有被实现的接口。所以将上面的方法声明都加入花括号空实现也可以。
