//
// Created by liuwenbin on 18-4-19.
//
#include <thread>
#include <iostream>
#include <string>

using namespace std;

void task1(string msg) {
    cout << "task1: " << msg << endl;
}

void task2(int i) {
    cout << " task2:" << i << " Hello" << endl;
};

struct F {
    void operator()() {
        cout << " F():" << "Parallel World!" << endl;
    };// 调用运算符（）
};

int main() {
    thread t1(task1, "Hello");
    thread t2(task2, 2);
    thread t3{F()};
    cout << "Concurrency has started!" << endl;
    t1.join();
    t2.join();
    t3.join();
    cout << "Concurrency completed!" << endl;

}

