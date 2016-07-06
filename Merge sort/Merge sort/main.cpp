#include <iostream>
using namespace std;

void merge_sort(int*,int head,int tail,int* tmp);
void merge_array(int* array,int head, int mid,int tail,int* tmp);

int main(int argc, const char * argv[]) {
    cout << "将对几个数据进行归并排序?" << endl;
    int size;
    cin >> size;
    int* array = new int[size];
    int* tmp = new int[size];
    for (int i = 0 ; i < size; i++) {
        cout << "请输入第 " << i+1 << " 个数字:";
        cin >> array[i];
    }
    //开始排序
    merge_sort(array, 0, size-1, tmp);
    
    for (int i = 0; i < size; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
    delete [] tmp;
}

void merge_sort(int* array,int head,int tail,int* tmp)
{
    if (head < tail) {
        int mid = (head + tail) / 2;
        
        //分而治之..先左边排序,,再右边
        merge_sort(array, head, mid, tmp);
        merge_sort(array, mid+1, tail, tmp);
        
        //形参 mid 代表第二个有序表的头...所以传入时要 +1...
        merge_array(array, head, mid+1, tail, tmp);
    }
}

//这里的 mid 代表右边有序表的头下表
void merge_array(int* array,int head, int mid,int tail,int* tmp)
{
    int first = head;
    int second = mid;
    int cur_tmp = 0;
    while (first <= mid-1 && second <= tail) {
        if (array[first] <= array[second]) {
            tmp[cur_tmp] = array[first];
            cur_tmp++;
            first++;
        } else {
            tmp[cur_tmp] = array[second];
            cur_tmp++;
            second++;
        }
    }
    
    // first 已经到达最后
    while (first == mid && second <= tail) {
        tmp[cur_tmp] = array[second];
        cur_tmp++;
        second++;
    }
    
    // second 已经到达最后
    while (second == tail+1 && first <= mid-1) {
        tmp[cur_tmp] = array[first];
        cur_tmp++;
        first++;
    }

    int equal_head = head;
    
    //这前测试发现 5 个数字下可以运行..超过 5 为就会出错..
    //原来是 循环条件没弄对
    //这里要注意 tmp 数组往 array 数组复制的时候,复制次数为 tail-head+1 
    for (int i = 0; i <= tail - head; i++) {
        array[equal_head++] = tmp[i];
    }
}