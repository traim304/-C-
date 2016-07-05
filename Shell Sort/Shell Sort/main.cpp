#include <iostream>
using namespace  std;

int main(int argc, const char * argv[]) {
    cout << "将对几个数据进行希尔排序?" << endl;
    int size;
    cin >> size;
    int* array = new int[size];
    for (int i = 0 ; i < size; i++) {
        cout << "请输入第 " << i+1 << "个数字:";
        cin >> array[i];
    }
    
    //开始排序
    int d = size/2;         //增量 d
    while (d) {
        //对相距 d 的元素,使用插入排序
        //i <= size-1
        for (int i = d; i <= size-d; i = i + d) {
            int tmp = array[i];
            int j = 0;
            for (j = i-d; j >= 0 && tmp < array[j]; j = j - d) {
                array[j+d] = array[j];
            }
            array[j+d] = tmp;
        }
        d = d/2;
    }
    for (int i = 0; i < size; i++) {
        cout << array[i] << ' ';
    }

    return 0;
}
