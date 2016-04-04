//
//  main.cpp
//  Queue
//
//  Created by JacobLan on 16/3/30.
//  Copyright © 2016年 JacobLan. All rights reserved.
//


#include <iostream>
#include "lk_queue.h"
#include "yh_triangle_ls.h"
#include "sq_queue.h"
#include "yh_triangle_sq.h"

using std::cout;
using std::endl;
using std::cin;


int main(int argc, const char * argv[]) {
    int n;
    cout << "---How many lines would you like to print ? ---" << endl;
    cin >> n;
    cout << "---Use Linklist---"<<endl;
    print_yh_triangle_ls(n);
    cout <<"*********************************"<< endl;
    cout << "---Use sequence----"<< endl;
    print_yh_triangle_sq(n);
    
    return 0;
}

























