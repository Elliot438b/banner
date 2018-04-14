//
// Created by liuwenbin on 18-4-14.
//
#include <iostream>

using namespace std;

double square(double x) {
    return x * x;
}

void print_square(double x) {
    cout << "the square of " << x << " is " << square(x) << "\n";
}

bool accept() {
    cout << "Do you want to accept?(y or n)\n";
    char answer = 0;
    cin >> answer;
    if (answer == 'y')return true;
    return false;
}


struct Vector {
    int a;
    double *b;
};

class Vector2 {// 在源文件中定义一个类
public: //公开的方法，通过方法与属性进行交互
    Vector2(int s) : elem{new double[s]}, sz{s} {}

    double &operator[](int i) { return elem[i]; }

    int size() { return sz; }

private: //不可以直接访问属性
    double *elem;
    int sz;
};

// Vector 初始化方法
void vector_init(Vector &v, int s) {//注意这里要用引用，否则v在后面的操作会在内存中复制一份变量而不是修改引用本身（这与java是不同的）
    v.a = s;
    v.b = new double[s];// new运算符是从一个自由存储，又称作动态内存或堆中分配内存。
}

// Vector 应用：从cin中读取s个整数，返回Vector
Vector read_and_sum(int s) {
    Vector v;
    vector_init(v, s);
    for (int i = 0; i != s; ++i) {
        cin >> v.b[i];
    }
    return v;
}

enum class Color {// 作用域
    red, blue, green
};
enum class traffic_light {
    green, yellow, red
};

traffic_light &operator++(traffic_light &t) {// 枚举属于自定义类型，那么也可以自定义运算符++
    switch (t) {
        case traffic_light::green:
            return t = traffic_light::yellow;
        case traffic_light::yellow:
            return t = traffic_light::red;
        case traffic_light::red:
            return t = traffic_light::green;
    }
}

int main() {
//    print_square(12);
//    const int kim = 38;// const“我承诺这个变量一旦赋值不会再改变”，编译器负责确认并执行const的承诺
//    constexpr double max = square(kim); // 编译时求值，参数必须是const类型，方法也必须是静态表达式，本行报错error: call to non-constexpr function
//    bool a = accept();
//    cout << a;
//    int v[8] = {0, 1, 2, 3, 4, 5, 6, 7};// 越界会报错
//    int t[] = {0, 1, 2, 3, 4, 5};// 没有设定边界，自动边界
//    for (auto i:t) {
//        cout << "-" << i;
//    }
//    Vector v;
//    v = read_and_sum(3);
//    cout << v.a << " " << v.b;

    Color col = Color::red;
    traffic_light light = traffic_light::red;
    traffic_light a = ++light;
    //枚举类型是自定义类型，它不是基本类型，red是它的一个对象，它的运算需要通过自定义运算符操作。
}

