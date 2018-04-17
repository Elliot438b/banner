#include <initializer_list>
#include <algorithm>
#include <stdexcept>
#include <iostream>

template<typename T>
class VecTemp {// 头文件中只放置类相关内容，复杂成员方法可不实现，但它与完全的抽象类作为多态类型的接口不同
private://不可以直接访问属性
    T *elem;
    int sz;
public: //公开的方法，通过方法与属性进行交互
    VecTemp(int s) : elem{new T[s]}, sz{s} {// 构造函数的实现可以写在头文件中，属于简单公用方法

    }

    double &operator[](int i) {
        if (i >= size())throw std::out_of_range("VecTemp::operator[]");// std是标准库的意思，上面包含了<stdexcept>库，这里统一使用std作为命名空间。
        return elem[i];
    }

    int size() const {
        return sz;
    }

    ~VecTemp() {// 加入析构函数，有实现，属于公用方法，实现方式都是一样的。
        delete[] elem;
    }

    VecTemp(const VecTemp &a);// 拷贝操作

    VecTemp(VecTemp &&a);// 移动构造函数
};

template<typename Container, typename Value>
Value sum(const Container &c, Value v) {
    for (auto x:c)
        v += x;
    return v;
};

template<typename T>
class Less_than {
    const T val;
public:
    Less_than(const T &v) : val(v) {}

    bool operator()(const T &x) const {
        return x < val;
    }
};

template<typename T, typename... Tail>
void f(T head, Tail... tail) {
    //对head做事
    f(tail...);
};

template<typename Key, typename Value>
class Map {
    //...
};

template<typename Value>
using String_map = Map<std::string, Value>;// 使用别名String_map
String_map<int> m;//m是一个Map<string,int>

int main() {
    void f() {}
    Less_than<int> lti{19};
    Less_than<std::string> lts{"hello"};
    std::cout << lti(2);
    std::cout << lti(50);
    std::cout << lts("world");
}