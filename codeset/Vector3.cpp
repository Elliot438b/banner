//
// Created by liuwenbin on 18-4-16.
//

#include "Container.h"
#include "Vector2.h"

class Vector_container : public Container {// 派生自（derived）Container，或者实现了Container接口
    Vector2 v;
public:
    Vector_container(int s) : v(s) {}

    ~Vector_container() {}// 覆盖了基类的析构函数~Container()

    double &operator[](int i) {
        return v[i];
    }

    int size() const {
        return v.size();
    }
};

void use(Container &c) {// 方法体内部完全使用了Container的方法，但是要知道目前这些方法还没有类来实现。
    const int sz = c.size();
    for (int i = 0; i != sz; i++) {
        std::cout << c[i] << '\n';
    }
}

void g() {
    //TODO: Vector_container vc{1, 2, 3, 4, 5, 6};
    //use(vc);
}