#include <mutex>

using namespace std;

mutex m;//控制共享数据访问的mutex
int sh;// 共享的数据（模拟）

void f() {
    unique_lock<mutex> lck{m};//获取mutex
    sh += 7;// 处理共享数据（修改数据，不仅仅是查看）
}// 隐式释放mutex