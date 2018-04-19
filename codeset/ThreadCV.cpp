//
// Created by liuwenbin on 18-4-19.
//
#include <queue>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;

class Message {// 通信对象
};

queue<Message> mqueue;// 消息队列
condition_variable mcond;//通信用的条件变量
mutex mmutex;// 锁机制

/**
 * 消费者
 */
void consumer() {
    while (true) {//无限循环
        unique_lock<mutex> lck{mmutex};//获取mmutex锁：上锁
        while (mcond.wait_for(lck, chrono::milliseconds{20}, true)) {//释放lck并等待20毫秒
        }
        // 被唤醒后重新获取lck
        auto m = mqueue.front();//获取消息
        mqueue.pop();// 从队列中弹出消息
        lck.unlock();// 释放lck
    }
}

/*
 * 生产者
 */
void producer() {
    while (true) {
        Message m;
        //...处理
        unique_lock<mutex> lck{mmutex};//保护队列上的操作：上锁
        mqueue.push(m);// 队列压入信息对象
        mcond.notify_one(); // 通知
        // 释放锁（在作用域结束）
    }
}