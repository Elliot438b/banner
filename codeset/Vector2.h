#include <initializer_list>
#include <algorithm>
#include <stdexcept>

class Vector2 {// 头文件中只放置类相关内容，复杂成员方法可不实现，但它与完全的抽象类作为多态类型的接口不同
private://不可以直接访问属性
    double *elem;
    int sz;
public: //公开的方法，通过方法与属性进行交互
    Vector2(int s) : elem{new double[s]}, sz{s} {// 构造函数的实现可以写在头文件中，属于简单公用方法

    }

//    Vector2(std::initializer_list<double> lst) : elem{new double[lst.size()]},
//                                                 sz{lst.size()} {// 构造函数的实现可以写在头文件中，属于简单公用方法
//        std::copy(lst.begin(), lst.end(), elem);
//    }

    double &operator[](int i) {
        if (i >= size())throw std::out_of_range("Vector2::operator[]");// std是标准库的意思，上面包含了<stdexcept>库，这里统一使用std作为命名空间。
        return elem[i];
    }

    int size() const {
        return sz;
    }

    ~Vector2() {// 加入析构函数，有实现，属于公用方法，实现方式都是一样的。
        delete[] elem;
    }

};