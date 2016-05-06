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
    char c;
    cout << "---Now, Start? <Y/N>---" << endl;
    cin >> c;
    while (c == 'Y' || c == 'y') {
        D2X();
        cout << endl << endl << "##################################" << endl;
        cout << endl << "---Continue ? <Y/N>---" << endl;
        cin >> c;
    }
    
    exit(66);
}
