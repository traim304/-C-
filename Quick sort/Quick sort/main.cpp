//快速排序（英语：Quicksort），又称划分交换排序（partition-exchange sort）
//在平均状况下，排序n个项目要Ο(n log n) 次比较。
//在最坏状况下则需要Ο(n2) 次比较，但这种状况并不常见。
//事实上，快速排序通常明显比其他Ο(n log n) 算法更快，
//因为它的内部循环（inner loop）可以在大部分的架构上很有效率地被实现出来。

//                      挖坑填数 + 分治法
#include <iostream>
using namespace std;

void quick_sort(int*,int,int);
void swap(int& a,int& b);

int main(int argc, const char * argv[]) {
    cout << "将对几个数据进行快速排序?" << endl;
    int size;
    cin >> size;
    int* array = new int[size];
    for (int i = 0 ; i < size; i++) {
        cout << "请输入第 " << i+1 << " 个数字:";
        cin >> array[i];
    }
    
    //开始排序
    
    quick_sort(array, 0, size-1);
    
    
    for (int i = 0; i < size; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
    
    return 0;
}

void swap(int& a,int& b)
{
    a = a^b;
    b = a^b;
    a = a^b;
}

void quick_sort(int* array,int head, int tail)
{
    if (head >= tail) {
        return;
    }
    
    int low = head;
    int high = tail;
    //base 是第一个坑
    int base = array[head];
    
    while (low < high) {
        //先从右往左,找到一个小于等于 base 的数
        while (array[high] > base) {
            high--;
        }
        //将前一个坑填上,high 为新坑
        if (low < high) {
            swap(array[low], array[high]);
            low++;
        }
        //先从右往左,找到一个小于等于 base 的数,继续填
        while (low < high && array[low] < base) {
            low++;
        }
        if (low <high) {
            swap(array[low], array[high]);
        }
    }
    //把最开始那个数往最后这个坑填坑填上
    array[low] = base;
    
    //分而治之
    quick_sort(array, head, low-1);
    quick_sort(array, low+1, tail);
}






