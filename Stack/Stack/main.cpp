//
//  main.cpp
//  Stack
//
//利用栈的原理，实现的是进制的转换。
//
//  Created by JacobLan on 16/3/23.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#include <iostream>
#include "BinaryConversion.h"

int main(int argc, const char * argv[]) {
    cout << "---What is the number ? ---" << endl;
    int saveNum;
    cin >> saveNum;
    cout << "---Which binaty  do you want convert ?---" << endl;
    int saveBinary;
    cin >> saveBinary;
    Conversion(saveNum, saveBinary);
    return 0;
}
