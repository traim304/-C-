//直接插入排序的时间复杂度为O(n2),空间复杂度为O(1),适合于原始数据基本有序的情况
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    cout << "将对几个数据进行直接插入排序?" << endl;
    int size;
    cin >> size;
    int* array = new int[size];
    for (int i = 0 ; i < size; i++) {
        cout << "请输入第 " << i+1 << "个数字:";
        cin >> array[i];
    }
    
    //开始排序

    for (int i = 1; i <= size-1; i++) {
        int tmp = array[i];
        int j;
        for (j = i-1; j >= 0 && tmp < array[j]; j--) {
                array[j+1] = array[j];
        }
        
        array[j+1] = tmp;
    }
    
    
    for (int i = 0; i < size; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
        return 0;
}
