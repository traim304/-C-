#include <iostream>
using namespace std;

void quick_sort(int*,int,int);
void swap(int& a,int& b);

int main(int argc, const char * argv[]) {
    cout << "将对几个数据进行归并排序?" << endl;
    int size;
    cin >> size;
    int* array = new int[size];
    for (int i = 0 ; i < size; i++) {
        cout << "请输入第 " << i+1 << " 个数字:";
        cin >> array[i];
    }
    
    //开始排序
    
    
}