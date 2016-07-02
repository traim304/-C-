#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cout << "所排序数的个数:";
    cin >> n;
    int* array = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "请输入第" << i+1 << "个数:";
        cin >> array[i];
    }
    
    cout << "排序后: ";

    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j+1] ) {
                int& a = array[j];
                int& b = array[j+1];
                a = a^b;
                b = a^b;
                a = a^b;
            }
        }
    }
    
    
    
    for (int i = 0; i < n; i++) {
        cout << array[i];
    }
    return 0;
}
