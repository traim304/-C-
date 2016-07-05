#include <iostream>
using namespace std;

void swap(int& a,int& b);
int child_max(int*,int,int);
void swap_array(int&,int&);

//为了方便.数组中第一位为空..与大根堆节点标志一致
int main(int argc, const char * argv[]) {
    cout << "将对几个数据进行堆排序?" << endl;
    int size;
    cin >> size;
    int* array = new int[size+1];
    for (int i = 1 ; i <= size; i++) {
        cout << "请输入第 " << i << " 个数字:";
        cin >> array[i];
    }
    array[0] = -99999;
    
    //开始排序
    
    //首先构造初始堆
    for (int i = size/2; i > 0; i--) {
        int child_max_flag = child_max(array,i,size);
        int cur_build= i;
        while (array[cur_build] < array[child_max_flag]) {
            swap_array(array[cur_build], array[child_max_flag]);
            cur_build = child_max_flag;
            child_max_flag = child_max(array,cur_build,size);
        }
    }
    
    cout << "大根堆为: ";
    for (int i = 1; i <= size; i++) {
        cout << array[i] << ' ';
    }
    cout <<endl;
    
    //进行排序
    //初始状态的 root 为最大节点
    
    int end = size;
    for (int i = 0; i < size; i++) {
        swap_array(array[1], array[end]);
        end--;
        int cur_build = 1;
        int child_max_flag = child_max(array, cur_build, end);
        while (array[cur_build] < array[child_max_flag]) {
            swap_array(array[cur_build], array[child_max_flag]);
            cur_build = child_max_flag;
            child_max_flag = child_max(array, cur_build, end);
        }
    }
    
    for (int i = 1; i <= size; i++) {
        cout << array[i] << ' ';
    }
    cout <<endl;
    return 0;
}





//该函数返回孩子节点中较大数的在大根堆中的节点号
int child_max(int* array,int x,int size)
{
    if (2*x > size) {
        return x;
    }
    
    //单孩子节点的情况
    if (2*x == size) {
        return 2*x;
    }
    
    
    if (array[2*x] > array[2*x+1]) {
        return 2*x;
    }
    else
    {
        return 2*x+1;
    }
}

void swap_array(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}