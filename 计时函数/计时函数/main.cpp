#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, const char * argv[]) {
    // clock_t 一种数据类型
    //typedef long clock_t;
    clock_t start, finish;
    //该程序从启动到函数调用占用CPU的时间。
    //这个函数返回从“开启这个程序进程”到“程序中调用clock()函数”时之间的CPU时钟计时单元（clock tick）数
    start = clock();
    
    
    for (int i = 99999; i > 0 ; i--) {
        cout << i << endl;
    }
    
    finish = clock();
    //必须有一个要转换成 double 类型 ..int/int 小数截断
    //CLOCKS_PER_SEC 它用来表示一秒钟会有多少个时钟计时单元
    double duration = (double)(finish-start) / CLOCKS_PER_SEC;
    cout << endl << "花费是时间:" << duration  << endl;
    return 0;
}
