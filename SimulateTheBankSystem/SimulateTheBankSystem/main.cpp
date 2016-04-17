//
//  main.cpp
//  SimulateTheBankSystem
//
//  Created by JacobLan on 16/4/12.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#include <iostream>
#include "queue.h"
#include "minimum_queue.h"
#include "customer_arrival_time_random.h"
#include "sort_queue.h"
#include "ctime"
#include "print_queue_state.h"


//多人同时来的问题

int main(int argc, const char * argv[]) {
    
    srandom(0);
    int * array_customer = customer_arrival_time_random();
    
    //新建并初始化四个窗口（对列）
    Queue<int> queue_1,queue_2,queue_3,queue_4;
    queue_1.init(),queue_2.init(),queue_3.init(),queue_4.init();
    
    int time = 0;       //time（min）
    int next_customer = 0;     //第 next_customer＋1 个人
    
    //开门接客
    for (; time < 480; time++) {
        cout << "当前时间: " << time << endl;
        //当有人到来时
        cout << "当前时刻各个窗口状态: " << endl;
        
        print_queue_state(&queue_1,1);
        print_queue_state(&queue_2,2);
        print_queue_state(&queue_3,3);
        print_queue_state(&queue_4,4);
        
        while (array_customer[next_customer] == time) {
            //择优入列，给定处理时间
            
            //引用第一次初始化后就不在可以初始化,可以改为使用指针－－－－－－－－－－－－－－－－－整理
            cout << "此时第" << next_customer+1 << "人进来。   ";
            
            int process_time = random()%20 + 1;
            cout << "预计处理时间为 " << process_time << endl;
 
            
            Queue<int>* minimum = minimum_queue(&queue_1, &queue_2, &queue_3, &queue_4);
            
            //minimum为人数最少的那一列
            
            
            
            //push(int id,int coming_time,int process_time)
            minimum->push(next_customer,array_customer[next_customer],process_time);
            
            //当前来的人处理完毕，指向下一到来的个人
            cout << endl;
            next_customer++;
        }
        
        //该时刻来的人全都处理完毕，整理队列，该滚的滚
        sort_queue(queue_1, queue_2, queue_3, queue_4);
        
        cout << endl << "********************************"<< endl;
    }
    return 0;
}
