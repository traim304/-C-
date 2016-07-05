const int INF = 6666666;
#include <iostream>
using namespace std;

void swap(int& a,int& b);
    
int main(int argc, const char * argv[]) {
    cout << "将对几个数据进行简单(直接)选择排序?" << endl;
    int size;
    cin >> size;
    int* array = new int[size];
    for (int i = 0 ; i < size; i++) {
        cout << "请输入第 " << i+1 << " 个数字:";
        cin >> array[i];
    }
    
    //开始排序
    
    int will_be_swap = 0;
    for (; will_be_swap < size-2; will_be_swap++) {
        int cur_min = INF;
        int cur_min_flag = -1;
        for (int i = will_be_swap; i < size; i++) {
            if (cur_min > array[i]) {
                cur_min = array[i];
                cur_min_flag = i;
            }
        }
        swap(array[cur_min_flag], array[will_be_swap]);
    }
    
    for (int i = 0; i<size; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
    return 0;
}

//用位运算进行数据交换时,当两数指向的地址位相等,  其值会变成 0
void swap(int& a,int& b)
{
    if (a == b) {
        return;
    }
    a = a^b;
    b = a^b;
    a = a^b;
}