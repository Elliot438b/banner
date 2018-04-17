//
// Created by liuwenbin on 18-4-16.
//

#include "Container.h"
#include "Vector2.h"
#include <list>

// 实现Vector2.h头文件中拷贝操作
// 先用初始化器按照实参原对象的大小将内存空间分配出来。
Vector2::Vector2(const Vector2 &a) : elem{new double[sz]}, sz{a.sz} {
    // 执行数据的复制操作
    for (int i = 0; i != sz; i++)
        elem[i] = a.elem[i];
}

// 实现Vector2.h头文件中的移动构造函数
// 先用初始化器按照实参原对象的大小将内存空间分配出来。
Vector2::Vector2(Vector2 &&a) : elem{a.elem}, sz{a.sz} {
    // 清除a的数据
    a.elem = nullptr;
    a.sz = 0;
}


/**
 * Container接口有两个实现类：Vector_container以及List_container
 */

// Vector_container类的定义
class Vector_container : public Container {// 派生自（derived）Container，或者实现了Container接口
    Vector2 v = Vector2(0);
public: // 成员方法都重用了Vector2的具体实现方法。
    Vector_container(int s) : v(s) {}


    ~Vector_container() {}// 覆盖了基类的析构函数~Container()

    double &operator[](int i) {
        return v[i];
    }

    int size() const {
        return v.size();
    }

    Vector_container(const Vector_container &vc) : v(vc.size()) {
        v = Vector2(vc.v);
    }
};

// List_container类的定义
class List_container : public Container {
    std::list<double> ld;// 与Vector_container的成员是我们自定义的Vector2不同的是，这里的成员是采用的标准库的list。
public:
    List_container() {}

    // 由于标准库的list的初始化器列表实现更加高可用，所以这里可以采用初始化器列表，更加方便
    List_container(std::initializer_list<double> il) : ld{il} {}

    ~List_container() {}

    double &operator[](int i);// 没有花括号的方法体，说明这个方法在类声明期间并没有实现

    int size() const { return ld.size(); }
};

// 实现操作符[]
double &List_container::operator[](int i) {
    for (auto &x:ld) {
        if (i == 0)return x;
        --i;
    }
    throw std::out_of_range("List container");
}

// 接收Container接口类型对象为实参，不考虑其实现类的实现细节的通用方法。
void use(Container &c) {// 方法体内部完全使用了Container的方法，但是要知道目前这些方法还没有类来实现。
    const int sz = c.size();
    for (int i = 0; i != sz; i++) {
        std::cout << c[i] << '\n';
    }
}

void g() {
//    Vector_container vc{1, 2, 3, 4, 5, 6};
    Vector_container vc(3);// 使用了Vector_container
    vc[0] = 112;
    vc[1] = 11;
    vc[2] = 32;
//    use(vc);
    Vector_container vc1 = Vector_container(vc);
    use(vc1);
}

void h() {
    List_container lc = {1, 2, 3};// 使用了List_container，采用初始化器列表的方式构造函数，十分方便。
    use(lc);
}

// 入口函数，分别调用以上方法测试。
int main() {
    g();
//    h();
}