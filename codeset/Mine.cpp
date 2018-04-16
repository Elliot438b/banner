#include <iostream>

namespace Mine {
    class complex {
        double re, im;//复数包含两个双精度浮点数。一个是实部，一个是虚部
    public:
        //定义三个构造函数，分别是两个实参、一个实参以及无参
        complex(double r, double i) : re{r}, im{i} {

        }

        complex(double r) : re{r}, im{0} {

        }

        complex() : re{0}, im{0} {// 无参的构造函数是默认构造函数

        }

        // getter setter
        double real() const {// 返回实部的值，const标识这个函数不会修改所调用的对象。
            return re;
        }

        void real(double d) {// 设置实部的值
            re = d;
        }

        double imag() const {// 返回虚部的值，const标识这个函数不会修改所调用的对象。
            return im;
        }

        void imag(double d) {// 设置虚部的值
            im = d;
        }

        // 定义运算符
        complex &operator+(complex z) {
            re += z.re;
            im += z.im;
            return *this;
        }

        complex &operator-(complex z) {
            re -= z.re;
            im -= z.im;
            return *this;
        }

        // 接口，只描述方法，实现在外部的某处进行。
        complex &operator*=(complex);

        complex &operator/=(complex);

    };

    complex test();
}

Mine::complex Mine::test() {
    complex z1{1, 2};
    complex z2{3, 4};
    return z1 + z2;
}

using namespace std;

int main() {
    //complex a{1,2}; // 静态报错，这里complex的作用域是全局，而不是上面Mine中定义的那个。
    cout << Mine::test().imag();
}